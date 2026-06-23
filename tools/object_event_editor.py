#!/usr/bin/env python3
"""
Tkinter editor for overworld object event graphics.

Run from the repo root:
    python3 tools/object_event_editor.py
"""

from __future__ import annotations

import os
import re
import shutil
import struct
import sys
import tkinter as tk
from dataclasses import dataclass, field
from pathlib import Path
from tkinter import filedialog, messagebox, ttk

try:
    from PIL import Image, ImageTk
except Exception:  # Pillow is optional.
    Image = None
    ImageTk = None


ROOT = Path(__file__).resolve().parents[1]
INFO_H = ROOT / "src/data/object_events/object_event_graphics_info.h"
GRAPHICS_H = ROOT / "src/data/object_events/object_event_graphics.h"
PIC_TABLES_H = ROOT / "src/data/object_events/object_event_pic_tables.h"
FIELD_EFFECT_OBJECTS_H = ROOT / "src/data/field_effects/field_effect_objects.h"
POINTERS_H = ROOT / "src/data/object_events/object_event_graphics_info_pointers.h"
CONSTANTS_H = ROOT / "include/constants/event_objects.h"
MOVEMENT_C = ROOT / "src/event_object_movement.c"

PIC_DIR = ROOT / "graphics/object_events/pics/custom"
PAL_DIR = ROOT / "graphics/object_events/palettes"

FIELD_ORDER = [
    "tileTag",
    "paletteTag",
    "reflectionPaletteTag",
    "size",
    "width",
    "height",
    "paletteSlot",
    "shadowSize",
    "inanimate",
    "compressed",
    "tracks",
    "oam",
    "subspriteTables",
    "anims",
    "images",
    "affineAnims",
]

SIZE_PRESETS = ("16x16", "16x32", "32x32", "64x64")
SHADOW_SIZE_VALUES = ("SHADOW_SIZE_S", "SHADOW_SIZE_M", "SHADOW_SIZE_L", "SHADOW_SIZE_NONE")
BOOL_VALUES = ("TRUE", "FALSE")
TRACK_VALUES = (
    "TRACKS_NONE",
    "TRACKS_FOOT",
    "TRACKS_BIKE_TIRE",
    "TRACKS_SLITHER",
    "TRACKS_SPOT",
    "TRACKS_BUG",
)


@dataclass
class GraphicsInfo:
    symbol: str
    suffix: str
    fields: dict[str, str] = field(default_factory=dict)
    start: int = 0
    end: int = 0
    gfx_macro: str = ""
    gfx_value: int | None = None


class ObjectEventRepo:
    def __init__(self) -> None:
        self.entries: list[GraphicsInfo] = []
        self.defines: dict[str, int] = {}
        self.pointers: dict[str, str] = {}
        self.incbin: dict[str, list[str]] = {}
        self.pic_tables: dict[str, str] = {}
        self.pal_tags: dict[str, int] = {}
        self.reload()

    def reload(self) -> None:
        self.defines = self._parse_defines()
        self.pointers = self._parse_pointers()
        self.incbin = self._parse_incbins()
        self.pic_tables = self._parse_pic_tables()
        self.pal_tags = self._parse_pal_tags()
        self.entries = self._parse_infos()
        by_symbol = {v: k for k, v in self.pointers.items()}
        for entry in self.entries:
            entry.gfx_macro = by_symbol.get(entry.symbol, "")
            entry.gfx_value = self.defines.get(entry.gfx_macro)

    def _read(self, path: Path) -> str:
        return path.read_text(encoding="utf-8")

    def _write(self, path: Path, text: str) -> None:
        path.write_text(text, encoding="utf-8")

    def _parse_defines(self) -> dict[str, int]:
        text = self._read(CONSTANTS_H)
        out: dict[str, int] = {}
        for name, value in re.findall(r"^#define\s+(OBJ_EVENT_GFX_[A-Z0-9_]+)\s+(\d+)\b", text, re.M):
            out[name] = int(value)
        return out

    def _parse_pal_tags(self) -> dict[str, int]:
        text = self._read(CONSTANTS_H)
        out: dict[str, int] = {}
        for name, value in re.findall(r"^#define\s+(OBJ_EVENT_PAL_TAG_[A-Z0-9_]+)\s+(0x[0-9A-Fa-f]+|\d+)\b", text, re.M):
            try:
                out[name] = int(value, 0)
            except ValueError:
                pass
        return out

    def _parse_pointers(self) -> dict[str, str]:
        text = self._read(POINTERS_H)
        return dict(re.findall(r"\[(OBJ_EVENT_GFX_[A-Z0-9_]+)\]\s*=\s*&([A-Za-z0-9_]+)", text))

    def _parse_incbins(self) -> dict[str, list[str]]:
        text = self._read(GRAPHICS_H)
        out: dict[str, list[str]] = {}
        pat = re.compile(r"const\s+u(?:16|32)\s+([A-Za-z0-9_]+)\[\]\s*=\s*(?:INCBIN|INCGFX)_U(?:16|32)\(([^;]+?)\);")
        for symbol, args in pat.findall(text):
            out[symbol] = re.findall(r'"([^"]+)"', args)
        return out

    def _parse_pic_tables(self) -> dict[str, str]:
        out: dict[str, str] = {}
        pat = re.compile(r"(?:static\s+)?const\s+struct\s+SpriteFrameImage\s+([A-Za-z0-9_]+)\[\]\s*=\s*\{(.*?)\};", re.S)
        for path in (PIC_TABLES_H, FIELD_EFFECT_OBJECTS_H):
            if path.exists():
                out.update({name: body for name, body in pat.findall(self._read(path))})
        return out

    def _parse_infos(self) -> list[GraphicsInfo]:
        text = self._read(INFO_H)
        pat = re.compile(r"const\s+struct\s+ObjectEventGraphicsInfo\s+(gObjectEventGraphicsInfo_([A-Za-z0-9_]+))\s*=\s*\{(.*?)\};", re.S)
        entries: list[GraphicsInfo] = []
        for match in pat.finditer(text):
            fields = dict(re.findall(r"\.([A-Za-z0-9_]+)\s*=\s*([^,\n]+),", match.group(3)))
            entries.append(GraphicsInfo(match.group(1), match.group(2), fields, match.start(), match.end()))
        return entries

    def build_info_block(self, entry: GraphicsInfo) -> str:
        lines = [f"const struct ObjectEventGraphicsInfo {entry.symbol} = {{"]
        for key in FIELD_ORDER:
            value = entry.fields.get(key, "")
            if value:
                lines.append(f"    .{key} = {value},")
        lines.append("};")
        return "\n".join(lines)

    def save_info(self, entry: GraphicsInfo, original_symbol: str | None = None) -> None:
        text = self._read(INFO_H)
        symbol = original_symbol or entry.symbol
        pat = re.compile(rf"const\s+struct\s+ObjectEventGraphicsInfo\s+{re.escape(symbol)}\s*=\s*\{{.*?\}};", re.S)
        new_block = self.build_info_block(entry)
        if pat.search(text):
            text = pat.sub(new_block, text, count=1)
        else:
            text = text.rstrip() + "\n\n" + new_block + "\n"
        self._write(INFO_H, text)

    def add_or_update_pointer(self, gfx_macro: str, symbol: str) -> None:
        text = self._read(POINTERS_H)
        extern = f"extern const struct ObjectEventGraphicsInfo {symbol};"
        if extern not in text:
            marker = "const struct ObjectEventGraphicsInfo *const gObjectEventGraphicsInfoPointers"
            text = text.replace(marker, extern + "\n\n" + marker, 1)
        line_re = re.compile(rf"^\s*\[{re.escape(gfx_macro)}\]\s*=.*?,\s*$", re.M)
        line = f"    [{gfx_macro}] = &{symbol},"
        if line_re.search(text):
            text = line_re.sub(line, text, count=1)
        else:
            text = text.replace("\n};", "\n" + line + "\n};", 1)
        self._write(POINTERS_H, text)

    def add_gfx_define(self, gfx_macro: str) -> int:
        text = self._read(CONSTANTS_H)
        if gfx_macro in self.defines:
            return self.defines[gfx_macro]
        num_match = re.search(r"^#define\s+NUM_OBJ_EVENT_GFX\s+(\d+)\b", text, re.M)
        if not num_match:
            raise RuntimeError("NUM_OBJ_EVENT_GFX not found in event_objects.h.")
        next_value = int(num_match.group(1)) if num_match else (max(self.defines.values(), default=-1) + 1)
        define = f"#define {gfx_macro:<43} {next_value}"
        text = text.replace(num_match.group(0), define + "\n" + f"#define NUM_OBJ_EVENT_GFX                        {next_value + 1}", 1)
        self._write(CONSTANTS_H, text)
        self.defines[gfx_macro] = next_value
        return next_value

    def add_pal_tag(self, tag_macro: str, preferred: str = "") -> int:
        text = self._read(CONSTANTS_H)
        if tag_macro in self.pal_tags:
            return self.pal_tags[tag_macro]
        if preferred.strip():
            value = int(preferred.strip(), 0)
        else:
            used = [v for v in self.pal_tags.values() if 0x116B <= v < 0x11FF]
            value = (max(used) + 1) if used else 0x116B
            if value >= 0x11FF:
                raise RuntimeError("No free palette tags between 0x116B and OBJ_EVENT_PAL_TAG_NONE.")
        define = f"#define {tag_macro:<43} 0x{value:04X}"
        anchor = "// Used as a placeholder follower graphic"
        text = text.replace(anchor, define + "\n" + anchor, 1)
        self._write(CONSTANTS_H, text)
        self.pal_tags[tag_macro] = value
        return value

    def add_graphics_incbin(self, symbol: str, rel_path: str, kind: str) -> bool:
        text = self._read(GRAPHICS_H)
        ctype = "u16" if kind == "pal" else "u32"
        inc = "INCBIN_U16" if kind == "pal" else "INCBIN_U32"
        line = f'const {ctype} {symbol}[] = {inc}("{rel_path}");'
        pat = re.compile(rf'const\s+u(?:16|32)\s+{re.escape(symbol)}\[\]\s*=\s*(?:INCBIN|INCGFX)_U(?:16|32)\([^;]+\);')
        if pat.search(text):
            return False
        self._write(GRAPHICS_H, text.rstrip() + "\n" + line + "\n")
        self.incbin[symbol] = [rel_path]
        return True

    def add_sprite_palette(self, pal_symbol: str, tag_macro: str) -> None:
        text = self._read(MOVEMENT_C)
        if re.search(rf"\{{\s*{re.escape(pal_symbol)}\s*,\s*{re.escape(tag_macro)}\s*\}}", text):
            return
        line = f"    {{{pal_symbol},{' ' * max(1, 38 - len(pal_symbol))}{tag_macro}}},"
        anchor = re.compile(r"\n\s*\n#if IS_FRLG")
        if anchor.search(text):
            text = anchor.sub("\n" + line + "\n#if IS_FRLG", text, count=1)
        else:
            text = text.replace("static const struct SpritePalette sObjectEventSpritePalettes[] = {\n", "static const struct SpritePalette sObjectEventSpritePalettes[] = {\n" + line + "\n", 1)
        self._write(MOVEMENT_C, text)

    def add_pic_table(self, table: str, pic_symbol: str, width: int, height: int, frames: int | None = None) -> None:
        text = self._read(PIC_TABLES_H)
        if re.search(rf"\b{re.escape(table)}\[\]", text):
            return
        tiles_w = max(1, width // 8)
        tiles_h = max(1, height // 8)
        if frames is None:
            path = self.first_incbin_path(pic_symbol)
            size = (ROOT / path).stat().st_size if path and (ROOT / path).is_file() else width * height // 2
            frame_size = tiles_w * tiles_h * 32
            frames = max(1, size // frame_size)
        body = f"static const struct SpriteFrameImage {table}[] = {{\n"
        body += f"    overworld_ascending_frames({pic_symbol}, {tiles_w}, {tiles_h}),\n"
        body += "};"
        self._write(PIC_TABLES_H, text.rstrip() + "\n\n" + body + "\n")

    def first_incbin_path(self, symbol: str) -> str:
        paths = self.incbin.get(symbol, [])
        return paths[0] if paths else ""

    def preferred_source_path(self, symbol: str, source_ext: str) -> str:
        incbin = self.first_incbin_path(symbol)
        if not incbin:
            return ""
        path = ROOT / incbin
        sibling = path.with_suffix(source_ext)
        return sibling.relative_to(ROOT).as_posix() if sibling.is_file() else incbin


def pascal_case(text: str) -> str:
    parts = re.findall(r"[A-Za-z0-9]+", text)
    return "".join(p[:1].upper() + p[1:] for p in parts) or "NewObject"


def macro_case(text: str) -> str:
    parts = re.findall(r"[A-Z]+(?=[A-Z][a-z]|\d|\b)|[A-Z]?[a-z]+|\d+", text.replace("_", " "))
    return "_".join(p.upper() for p in parts) or "NEW_OBJECT"


def suffix_from_pal_tag(tag_macro: str, fallback: str) -> str:
    prefix = "OBJ_EVENT_PAL_TAG_"
    if tag_macro.startswith(prefix):
        return pascal_case(tag_macro[len(prefix):].lower())
    return pascal_case(fallback)


def replace_suffix_token(value: str, old_suffix: str, new_suffix: str) -> str:
    if not value:
        return value
    old_macro = macro_case(old_suffix)
    new_macro = macro_case(new_suffix)
    value = value.replace(old_suffix, new_suffix)
    value = value.replace(old_macro, new_macro)
    return value


def gba_to_rgb(value: int) -> str:
    r = (value & 0x1F) * 255 // 31
    g = ((value >> 5) & 0x1F) * 255 // 31
    b = ((value >> 10) & 0x1F) * 255 // 31
    return f"#{r:02x}{g:02x}{b:02x}"


def load_palette(path: Path) -> list[str]:
    if path.suffix.lower() == ".pal":
        return load_jasc_palette(path)
    data = path.read_bytes()
    values = list(struct.unpack("<" + "H" * min(16, len(data) // 2), data[:32]))
    colors = [gba_to_rgb(v) for v in values]
    return (colors + ["#ff00ff"] * 16)[:16]


def load_jasc_palette(path: Path) -> list[str]:
    lines = [line.strip() for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]
    if len(lines) >= 4 and lines[0] == "JASC-PAL":
        count = int(lines[2])
        color_lines = lines[3:3 + count]
    else:
        color_lines = lines
    colors: list[str] = []
    for line in color_lines[:16]:
        nums = [int(part) for part in re.findall(r"\d+", line)[:3]]
        if len(nums) == 3:
            colors.append(f"#{nums[0]:02x}{nums[1]:02x}{nums[2]:02x}")
    return (colors + ["#ff00ff"] * 16)[:16]


def write_gbapal_from_pal(src: Path, dst: Path) -> None:
    colors = load_jasc_palette(src)
    data = bytearray()
    for color in colors[:16]:
        r = int(color[1:3], 16)
        g = int(color[3:5], 16)
        b = int(color[5:7], 16)
        value = (r * 31 // 255) | ((g * 31 // 255) << 5) | ((b * 31 // 255) << 10)
        data += struct.pack("<H", value)
    dst.write_bytes(data)


def render_4bpp(path: Path, pal_path: Path | None, width: int, height: int, frame: int, scale: int = 4) -> tk.PhotoImage:
    colors = load_palette(pal_path) if pal_path and pal_path.is_file() else ["#ff00ff"] + ["#000000"] * 15
    data = path.read_bytes()
    tiles_w = max(1, width // 8)
    tiles_h = max(1, height // 8)
    frame_size = tiles_w * tiles_h * 32
    offset = max(0, min(frame, max(0, len(data) // frame_size - 1))) * frame_size
    img = tk.PhotoImage(width=width * scale, height=height * scale)
    transparent = colors[0]
    
    # building the image data block
    lines = []
    for py in range(height * scale):
        tile_y = (py // scale) // 8
        y = (py // scale) % 8
        row_colors = []
        for px in range(width * scale):
            tile_x = (px // scale) // 8
            x = (px // scale) % 8
            tile_off = offset + (tile_y * tiles_w + tile_x) * 32
            if tile_off + 32 <= len(data):
                byte = data[tile_off + y * 4 + x // 2]
                idx = (byte & 0x0F) if x % 2 == 0 else (byte >> 4)
                color = transparent if idx == 0 else colors[idx]
            else:
                color = transparent
            row_colors.append(color)
        lines.append("{" + " ".join(row_colors) + "}")
    
    img.put(" ".join(lines))
    return img


def render_png(path: Path, width: int, height: int, frame: int, scale: int = 4) -> tk.PhotoImage:
    if Image is None or ImageTk is None:
        raise RuntimeError("Pillow is not installed; PNG preview unavailable.")
    img = Image.open(path).convert("RGBA")
    cols = max(1, img.width // width)
    rows = max(1, img.height // height)
    frames = max(1, cols * rows)
    frame %= frames
    x = (frame % cols) * width
    y = (frame // cols) * height
    frame_img = img.crop((x, y, x + width, y + height))
    frame_img = frame_img.resize((width * scale, height * scale), Image.Resampling.NEAREST)
    return ImageTk.PhotoImage(frame_img)


def convert_png_to_4bpp(src: Path, dst_4bpp: Path, width: int, height: int, palette_path: Path | None = None) -> None:
    if Image is None:
        raise RuntimeError("Pillow is not installed. Use .4bpp/.gbapal files or install Pillow.")
    img = Image.open(src).convert("RGBA")
    if img.width % width or img.height % height:
        raise RuntimeError("PNG width/height must be a multiple of the object event width/height.")
    palette: list[tuple[int, int, int, int]] = []
    if palette_path and palette_path.is_file():
        for color in load_palette(palette_path):
            palette.append((int(color[1:3], 16), int(color[3:5], 16), int(color[5:7], 16), 255))
    colors: list[tuple[int, int, int, int]] = []
    pixels = list(img.getdata())
    if not palette:
        for px in pixels:
            if px[3] == 0:
                px = (0, 0, 0, 0)
            if px not in colors:
                colors.append(px)
        if len(colors) > 16:
            img = img.convert("P", palette=Image.ADAPTIVE, colors=16).convert("RGBA")
            pixels = list(img.getdata())
            colors = []
            for px in pixels:
                if px[3] == 0:
                    px = (0, 0, 0, 0)
                if px not in colors:
                    colors.append(px)
        if (0, 0, 0, 0) in colors:
            colors.remove((0, 0, 0, 0))
        palette = [(0, 0, 0, 0)] + colors[:15]
        palette += [(0, 0, 0, 255)] * (16 - len(palette))
    if img.width % 8 or img.height % 8:
        raise RuntimeError("PNG image width and height must be multiples of 8.")
    rgb_palette = [(r, g, b) for r, g, b, _a in palette[:16]]

    def nearest_index(px: tuple[int, int, int, int]) -> int:
        if px[3] == 0:
            return 0
        rgb = px[:3]
        if rgb in rgb_palette:
            return rgb_palette.index(rgb)
        return min(range(len(rgb_palette)), key=lambda i: sum((rgb[j] - rgb_palette[i][j]) ** 2 for j in range(3)))

    indices = [nearest_index(p) for p in pixels]
    out = bytearray()
    cols = img.width // width
    rows = img.height // height
    for frame in range(cols * rows):
        base_x = (frame % cols) * width
        base_y = (frame // cols) * height
        for ty in range(height // 8):
            for tx in range(width // 8):
                for y in range(8):
                    yy = base_y + ty * 8 + y
                    for x in range(0, 8, 2):
                        xx = base_x + tx * 8 + x
                        p0 = indices[yy * img.width + xx]
                        p1 = indices[yy * img.width + xx + 1]
                        out.append((p1 << 4) | p0)
    dst_4bpp.write_bytes(out)


def write_gbapal_from_png(src: Path, dst: Path) -> None:
    if Image is None:
        raise RuntimeError("Pillow is not installed; cannot extract palette from PNG.")
    img = Image.open(src).convert("RGBA")
    colors: list[tuple[int, int, int, int]] = []
    for px in img.getdata():
        if px[3] == 0:
            px = (0, 0, 0, 0)
        if px not in colors:
            colors.append(px)
    if (0, 0, 0, 0) in colors:
        colors.remove((0, 0, 0, 0))
    palette = [(0, 0, 0, 0)] + colors[:15]
    palette += [(0, 0, 0, 255)] * (16 - len(palette))
    data = bytearray()
    for r, g, b, _a in palette[:16]:
        value = (r * 31 // 255) | ((g * 31 // 255) << 5) | ((b * 31 // 255) << 10)
        data += struct.pack("<H", value)
    dst.write_bytes(data)


def output_binary_path(src: Path, ext: str, default_dir: Path, suffix: str) -> Path:
    try:
        rel = src.resolve().relative_to(ROOT)
        if rel.parts[:2] == ("graphics", "object_events"):
            return src.with_suffix(ext)
    except ValueError:
        pass
    return default_dir / (macro_case(suffix).lower() + ext)


class ObjectEventEditor(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("Object Event Graphics Editor")
        self.geometry("1180x760")
        self.repo = ObjectEventRepo()
        self.current: GraphicsInfo | None = None
        self.original_symbol = ""
        self.frame = 0
        self.preview_image: tk.PhotoImage | None = None
        self.field_vars: dict[str, tk.StringVar] = {}
        self.size_preset_var = tk.StringVar(value="16x32")
        self._build_ui()
        self.refresh_list()

    def object_exists(self, symbol: str) -> bool:
        return any(entry.symbol == symbol for entry in self.repo.entries)

    def make_unique_suffix(self, base_suffix: str) -> str:
        base_suffix = pascal_case(base_suffix)
        taken_symbols = {entry.symbol for entry in self.repo.entries}
        taken_macros = set(self.repo.defines)
        suffix = base_suffix
        index = 2
        while (
            f"gObjectEventGraphicsInfo_{suffix}" in taken_symbols
            or f"OBJ_EVENT_GFX_{macro_case(suffix)}" in taken_macros
        ):
            suffix = f"{base_suffix}{index}"
            index += 1
        return suffix

    def apply_suffix_to_identity(self, suffix: str, old_suffix: str | None = None, update_references: bool = False) -> None:
        old_suffix = old_suffix or pascal_case(self.suffix_var.get())
        suffix = pascal_case(suffix)
        self.suffix_var.set(suffix)
        self.symbol_var.set(f"gObjectEventGraphicsInfo_{suffix}")
        self.gfx_macro_var.set(f"OBJ_EVENT_GFX_{macro_case(suffix)}")
        if update_references and old_suffix != suffix:
            for key in ("images", "paletteTag"):
                self.field_vars[key].set(replace_suffix_token(self.field_vars[key].get(), old_suffix, suffix))
            for var in (
                self.pic_symbol_var,
                self.pic_table_var,
                self.pal_symbol_var,
                self.pal_tag_var,
                self.sprite_source_var,
                self.palette_source_var,
            ):
                var.set(replace_suffix_token(var.get(), old_suffix, suffix))

    def select_entry_by_symbol(self, symbol: str) -> None:
        self.search_var.set("")
        self.refresh_list()
        for index, entry in enumerate(self.visible_entries):
            if entry.symbol == symbol:
                self.listbox.selection_clear(0, tk.END)
                self.listbox.selection_set(index)
                self.listbox.see(index)
                self.load_entry(entry)
                break

    def _build_ui(self) -> None:
        self.columnconfigure(1, weight=1)
        self.rowconfigure(0, weight=1)

        left = ttk.Frame(self, padding=8)
        left.grid(row=0, column=0, sticky="ns")
        ttk.Label(left, text="Object events").pack(anchor="w")
        self.search_var = tk.StringVar()
        self.search_var.trace_add("write", lambda *_: self.refresh_list())
        ttk.Entry(left, textvariable=self.search_var, width=34).pack(fill="x", pady=(2, 6))
        self.listbox = tk.Listbox(left, width=42, height=34)
        self.listbox.pack(fill="both", expand=True)
        self.listbox.bind("<<ListboxSelect>>", lambda _e: self.select_current())
        row = ttk.Frame(left)
        row.pack(fill="x", pady=6)
        ttk.Button(row, text="Reload", command=self.reload).pack(side="left")
        ttk.Button(row, text="New", command=self.new_entry).pack(side="left", padx=4)
        ttk.Button(row, text="Duplicate", command=self.duplicate_entry).pack(side="left")

        main = ttk.Frame(self, padding=8)
        main.grid(row=0, column=1, sticky="nsew")
        main.columnconfigure(0, weight=1)
        main.columnconfigure(1, weight=1)
        main.rowconfigure(1, weight=1)

        top = ttk.LabelFrame(main, text="Info", padding=8)
        top.grid(row=0, column=0, columnspan=2, sticky="ew")
        for i in range(6):
            top.columnconfigure(i, weight=1)
        self.suffix_var = tk.StringVar()
        self.symbol_var = tk.StringVar()
        self.gfx_macro_var = tk.StringVar()
        ttk.Label(top, text="Name/sufix").grid(row=0, column=0, sticky="w")
        ttk.Entry(top, textvariable=self.suffix_var).grid(row=1, column=0, sticky="ew", padx=(0, 8))
        ttk.Label(top, text="Struct").grid(row=0, column=1, sticky="w")
        ttk.Entry(top, textvariable=self.symbol_var).grid(row=1, column=1, sticky="ew", padx=(0, 8))
        ttk.Label(top, text="OBJ_EVENT_GFX").grid(row=0, column=2, sticky="w")
        ttk.Entry(top, textvariable=self.gfx_macro_var).grid(row=1, column=2, sticky="ew", padx=(0, 8))
        ttk.Button(top, text="Save Existing", command=self.save_existing).grid(row=1, column=3, sticky="ew", padx=(0, 8))
        ttk.Button(top, text="Save as New", command=self.add_new).grid(row=1, column=4, sticky="ew")

        form = ttk.LabelFrame(main, text="ObjectEventGraphicsInfo", padding=8)
        form.grid(row=1, column=0, sticky="nsew", padx=(0, 8), pady=8)
        for i in range(4):
            form.columnconfigure(i, weight=1)
        for idx, key in enumerate(FIELD_ORDER):
            var = tk.StringVar()
            self.field_vars[key] = var
            label = "size preset" if key == "width" else key
            ttk.Label(form, text=label).grid(row=idx, column=0, sticky="w")
            if key == "width":
                combo = ttk.Combobox(form, textvariable=self.size_preset_var, values=SIZE_PRESETS, state="readonly")
                combo.grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)
                combo.bind("<<ComboboxSelected>>", lambda _e: self.apply_size_preset())
            elif key in {"height", "oam", "subspriteTables"}:
                ttk.Entry(form, textvariable=var, state="readonly").grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)
            elif key == "shadowSize":
                ttk.Combobox(form, textvariable=var, values=SHADOW_SIZE_VALUES, state="readonly").grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)
            elif key in {"inanimate", "compressed"}:
                ttk.Combobox(form, textvariable=var, values=BOOL_VALUES, state="readonly").grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)
            elif key == "tracks":
                ttk.Combobox(form, textvariable=var, values=TRACK_VALUES, state="readonly").grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)
            else:
                ttk.Entry(form, textvariable=var).grid(row=idx, column=1, columnspan=3, sticky="ew", pady=1)

        right = ttk.Frame(main)
        right.grid(row=1, column=1, sticky="nsew", pady=8)
        right.columnconfigure(0, weight=1)

        preview = ttk.LabelFrame(right, text="Sprite sheet preview", padding=8)
        preview.grid(row=0, column=0, sticky="ew")
        self.canvas = tk.Canvas(preview, width=260, height=260, background="#303030", highlightthickness=0)
        self.canvas.grid(row=0, column=0, columnspan=4, pady=(0, 8))
        ttk.Button(preview, text="<", command=lambda: self.move_frame(-1)).grid(row=1, column=0, sticky="ew")
        self.frame_label = ttk.Label(preview, text="Frame 0/0", anchor="center")
        self.frame_label.grid(row=1, column=1, columnspan=2, sticky="ew", padx=8)
        ttk.Button(preview, text=">", command=lambda: self.move_frame(1)).grid(row=1, column=3, sticky="ew")
        ttk.Button(preview, text="Refresh preview", command=self.update_preview).grid(row=2, column=0, columnspan=4, sticky="ew", pady=(8, 0))

        assets = ttk.LabelFrame(right, text="Change/add sprite and palette", padding=8)
        assets.grid(row=1, column=0, sticky="nsew", pady=(8, 0))
        assets.columnconfigure(1, weight=1)
        self.sprite_source_var = tk.StringVar()
        self.palette_source_var = tk.StringVar()
        self.pic_symbol_var = tk.StringVar()
        self.pal_symbol_var = tk.StringVar()
        self.pic_table_var = tk.StringVar()
        self.pal_tag_var = tk.StringVar()
        self.pal_tag_value_var = tk.StringVar()
        labels = [
            ("Sprite file .png/.4bpp", self.sprite_source_var, self.pick_sprite),
            ("Palette file .pal/.gbapal", self.palette_source_var, self.pick_palette),
            ("Sprite Symbol", self.pic_symbol_var, None),
            ("sPicTable Table", self.pic_table_var, None),
            ("Palette Symbol", self.pal_symbol_var, None),
            ("Palette tag", self.pal_tag_var, None),
            ("Optional tag value", self.pal_tag_value_var, None),
        ]
        for r, (label, var, cmd) in enumerate(labels):
            ttk.Label(assets, text=label).grid(row=r, column=0, sticky="w", pady=2)
            ttk.Entry(assets, textvariable=var).grid(row=r, column=1, sticky="ew", pady=2)
            if cmd:
                ttk.Button(assets, text="...", width=3, command=cmd).grid(row=r, column=2, padx=(4, 0))
        ttk.Button(assets, text="Apply files/symbols to form", command=self.apply_assets_to_form).grid(row=len(labels), column=0, columnspan=3, sticky="ew", pady=(8, 0))

        self.status_var = tk.StringVar(value="Ready.")
        ttk.Label(main, textvariable=self.status_var, anchor="w").grid(row=2, column=0, columnspan=2, sticky="ew")

    def reload(self) -> None:
        self.repo.reload()
        self.refresh_list()
        self.status_var.set("Files reloaded.")

    def refresh_list(self) -> None:
        q = self.search_var.get().lower()
        self.listbox.delete(0, tk.END)
        self.visible_entries = [e for e in self.repo.entries if q in e.symbol.lower() or q in e.gfx_macro.lower()]
        for e in self.visible_entries:
            ident = f"{e.gfx_value:03d}" if e.gfx_value is not None else "---"
            self.listbox.insert(tk.END, f"{ident}  {e.gfx_macro or '(no macro)'}  ->  {e.symbol}")

    def select_current(self) -> None:
        sel = self.listbox.curselection()
        if not sel:
            return
        self.load_entry(self.visible_entries[sel[0]])

    def load_entry(self, entry: GraphicsInfo) -> None:
        self.current = GraphicsInfo(entry.symbol, entry.suffix, dict(entry.fields), entry.start, entry.end, entry.gfx_macro, entry.gfx_value)
        self.original_symbol = entry.symbol
        self.suffix_var.set(entry.suffix)
        self.symbol_var.set(entry.symbol)
        self.gfx_macro_var.set(entry.gfx_macro)
        for key, var in self.field_vars.items():
            var.set(entry.fields.get(key, ""))
        self.sync_size_preset_from_fields()
        self.fill_asset_fields()
        self.frame = 0
        self.update_preview()

    def sync_size_preset_from_fields(self) -> None:
        width = self.field_vars["width"].get()
        height = self.field_vars["height"].get()
        preset = f"{width}x{height}"
        if preset in SIZE_PRESETS:
            self.size_preset_var.set(preset)

    def apply_size_preset(self) -> None:
        preset = self.size_preset_var.get()
        if "x" not in preset:
            return
        width, height = preset.split("x", 1)
        self.field_vars["width"].set(width)
        self.field_vars["height"].set(height)
        self.field_vars["oam"].set(f"&gObjectEventBaseOam_{preset}")
        self.field_vars["subspriteTables"].set(f"sOamTables_{preset}")
        self.update_preview()

    def fill_asset_fields(self) -> None:
        suffix = self.suffix_var.get() or "NewObject"
        images = self.field_vars["images"].get()
        pic_table = images
        self.pic_table_var.set(pic_table or f"sPicTable_{suffix}")
        pic_symbol = self.pic_symbol_for_table(pic_table) or f"gObjectEventPic_{suffix}"
        self.pic_symbol_var.set(pic_symbol)
        self.sprite_source_var.set(self.repo.preferred_source_path(pic_symbol, ".png"))
        pal_tag = self.field_vars["paletteTag"].get() or f"OBJ_EVENT_PAL_TAG_{macro_case(suffix)}"
        self.pal_tag_var.set(pal_tag)
        pal_symbol = self.palette_symbol_for_tag(pal_tag) or f"gObjectEventPal_{suffix}"
        self.pal_symbol_var.set(pal_symbol)
        self.palette_source_var.set(self.repo.preferred_source_path(pal_symbol, ".pal"))

    def pic_symbol_for_table(self, table: str) -> str:
        body = self.repo.pic_tables.get(table, "")
        m = re.search(r"(?:gObjectEventPic|gFieldEffectObjectPic)_[A-Za-z0-9_]+", body)
        return m.group(0) if m else ""

    def palette_symbol_for_tag(self, tag: str) -> str:
        text = MOVEMENT_C.read_text(encoding="utf-8")
        m = re.search(r"\{\s*([A-Za-z0-9_]+)\s*,\s*" + re.escape(tag) + r"\s*\}", text)
        return m.group(1) if m else ""

    def new_entry(self) -> None:
        suffix = self.make_unique_suffix("NewObject")
        defaults = {
            "tileTag": "TAG_NONE",
            "paletteTag": f"OBJ_EVENT_PAL_TAG_{macro_case(suffix)}",
            "reflectionPaletteTag": "OBJ_EVENT_PAL_TAG_NONE",
            "size": "256",
            "width": "16",
            "height": "32",
            "paletteSlot": "PALSLOT_NPC_1",
            "shadowSize": "SHADOW_SIZE_M",
            "inanimate": "FALSE",
            "compressed": "FALSE",
            "tracks": "TRACKS_FOOT",
            "oam": "&gObjectEventBaseOam_16x32",
            "subspriteTables": "sOamTables_16x32",
            "anims": "sAnimTable_Standard",
            "images": f"sPicTable_{suffix}",
            "affineAnims": "gDummySpriteAffineAnimTable",
        }
        entry = GraphicsInfo(f"gObjectEventGraphicsInfo_{suffix}", suffix, defaults, gfx_macro=f"OBJ_EVENT_GFX_{macro_case(suffix)}")
        self.load_entry(entry)
        self.original_symbol = ""

    def duplicate_entry(self) -> None:
        if not self.current:
            return
        suffix = self.make_unique_suffix(self.suffix_var.get() + "Copy")
        self.apply_suffix_to_identity(suffix)
        self.original_symbol = ""
        self.status_var.set("Duplicated in form; use 'Save as New'.")

    def pick_sprite(self) -> None:
        path = filedialog.askopenfilename(filetypes=[("Sprites", "*.4bpp *.png"), ("All", "*")])
        if path:
            self.sprite_source_var.set(path)

    def pick_palette(self) -> None:
        path = filedialog.askopenfilename(filetypes=[("Palettes", "*.pal *.gbapal"), ("All", "*")])
        if path:
            self.palette_source_var.set(path)

    def collect_entry(self) -> GraphicsInfo:
        suffix = pascal_case(self.suffix_var.get())
        symbol = self.symbol_var.get().strip() or f"gObjectEventGraphicsInfo_{suffix}"
        fields = {key: var.get().strip() for key, var in self.field_vars.items() if var.get().strip()}
        return GraphicsInfo(symbol, suffix, fields, gfx_macro=self.gfx_macro_var.get().strip())

    def apply_assets_to_form(self) -> None:
        if self.pic_table_var.get().strip():
            self.field_vars["images"].set(self.pic_table_var.get().strip())
        if self.pal_tag_var.get().strip():
            self.field_vars["paletteTag"].set(self.pal_tag_var.get().strip())
        width = self.field_vars["width"].get().strip()
        height = self.field_vars["height"].get().strip()
        if width and height:
            preset = f"{width}x{height}"
            if preset in SIZE_PRESETS:
                self.size_preset_var.set(preset)
                self.apply_size_preset()
            else:
                self.field_vars["oam"].set(f"&gObjectEventBaseOam_{preset}")
                self.field_vars["subspriteTables"].set(f"sOamTables_{preset}")
        self.update_preview()

    def save_existing(self) -> None:
        if not self.original_symbol:
            messagebox.showinfo("New object event", "This form does not exist yet. Use 'Save as New'.")
            return
        entry = self.collect_entry()
        self.write_assets(entry)
        self.repo.save_info(entry, self.original_symbol)
        if entry.gfx_macro:
            self.repo.add_or_update_pointer(entry.gfx_macro, entry.symbol)
        self.reload()
        self.status_var.set(f"Saved: {entry.symbol}")

    def add_new(self) -> None:
        self.repo.reload()
        entry = self.collect_entry()
        if not entry.gfx_macro:
            entry.gfx_macro = f"OBJ_EVENT_GFX_{macro_case(entry.suffix)}"
            self.gfx_macro_var.set(entry.gfx_macro)
        if self.object_exists(entry.symbol) or entry.gfx_macro in self.repo.defines:
            base_suffix = entry.suffix + ("Copy" if self.original_symbol else "")
            suffix = self.make_unique_suffix(base_suffix)
            old_suffix = entry.suffix
            self.apply_suffix_to_identity(suffix, old_suffix, update_references=not self.original_symbol)
            entry = self.collect_entry()
            self.status_var.set(f"Existing name detected; creating as {entry.gfx_macro}.")
        self.write_assets(entry)
        self.repo.add_gfx_define(entry.gfx_macro)
        self.repo.save_info(entry)
        self.repo.add_or_update_pointer(entry.gfx_macro, entry.symbol)
        self.reload()
        self.select_entry_by_symbol(entry.symbol)
        self.status_var.set(f"Added: {entry.gfx_macro} -> {entry.symbol}")

    def write_assets(self, entry: GraphicsInfo) -> None:
        suffix = pascal_case(self.suffix_var.get())
        pic_symbol = self.pic_symbol_var.get().strip() or f"gObjectEventPic_{suffix}"
        pic_table = self.pic_table_var.get().strip() or f"sPicTable_{suffix}"
        pal_tag = entry.fields.get("paletteTag", "").strip() or self.pal_tag_var.get().strip() or f"OBJ_EVENT_PAL_TAG_{macro_case(suffix)}"
        original_pal_tag = self.current.fields.get("paletteTag", "") if self.current else ""
        pal_symbol = self.pal_symbol_var.get().strip() or f"gObjectEventPal_{suffix}"
        if pal_tag != original_pal_tag and self.palette_symbol_for_tag(original_pal_tag) == pal_symbol:
            pal_symbol = f"gObjectEventPal_{suffix_from_pal_tag(pal_tag, suffix)}"
            self.pal_symbol_var.set(pal_symbol)
        self.pal_tag_var.set(pal_tag)
        sprite_src = self.sprite_source_var.get().strip()
        pal_src = self.palette_source_var.get().strip()
        width = int(entry.fields.get("width", "16"), 0)
        height = int(entry.fields.get("height", "32"), 0)

        if pal_tag.startswith("OBJ_EVENT_PAL_TAG_"):
            self.repo.add_pal_tag(pal_tag, self.pal_tag_value_var.get())

        if sprite_src and pic_symbol not in self.repo.incbin:
            PIC_DIR.mkdir(parents=True, exist_ok=True)
            src = self.resolve_path(sprite_src)
            dst_4bpp = output_binary_path(src, ".4bpp", PIC_DIR, suffix)
            if src.suffix.lower() == ".png":
                pal_path = self.resolve_path(pal_src) if pal_src else None
                convert_png_to_4bpp(src, dst_4bpp, width, height, pal_path)
            else:
                if src.resolve() != dst_4bpp.resolve():
                    shutil.copyfile(src, dst_4bpp)
            rel = dst_4bpp.relative_to(ROOT).as_posix()
            self.repo.add_graphics_incbin(pic_symbol, rel, "pic")

        if pal_src:
            PAL_DIR.mkdir(parents=True, exist_ok=True)
            src = self.resolve_path(pal_src)
            dst = output_binary_path(src, ".gbapal", PAL_DIR, suffix)
            if src.resolve() != dst.resolve():
                if src.suffix.lower() == ".pal":
                    write_gbapal_from_pal(src, dst)
                else:
                    shutil.copyfile(src, dst)
            rel = dst.relative_to(ROOT).as_posix()
            self.repo.add_graphics_incbin(pal_symbol, rel, "pal")
            self.repo.add_sprite_palette(pal_symbol, pal_tag)
        elif sprite_src and Path(sprite_src).suffix.lower() == ".png":
            PAL_DIR.mkdir(parents=True, exist_ok=True)
            src = self.resolve_path(sprite_src)
            dst = PAL_DIR / (macro_case(suffix).lower() + ".gbapal")
            write_gbapal_from_png(src, dst)
            rel = dst.relative_to(ROOT).as_posix()
            self.repo.add_graphics_incbin(pal_symbol, rel, "pal")
            self.repo.add_sprite_palette(pal_symbol, pal_tag)

        self.repo.add_pic_table(pic_table, pic_symbol, width, height)
        entry.fields["images"] = pic_table
        entry.fields["paletteTag"] = pal_tag

    def resolve_path(self, value: str) -> Path:
        path = Path(value)
        return path if path.is_absolute() else ROOT / path

    def current_asset_paths(self) -> tuple[Path | None, Path | None, int, int, int]:
        width = int((self.field_vars["width"].get() or "16"), 0)
        height = int((self.field_vars["height"].get() or "32"), 0)
        pic_symbol = self.pic_symbol_var.get().strip()
        pal_symbol = self.pal_symbol_var.get().strip()
        sprite = self.sprite_source_var.get().strip() or self.repo.first_incbin_path(pic_symbol)
        palette = self.palette_source_var.get().strip() or self.repo.first_incbin_path(pal_symbol)
        sprite_path = self.resolve_path(sprite) if sprite else None
        pal_path = self.resolve_path(palette) if palette else None
        frames = 1
        if sprite_path and sprite_path.is_file():
            if sprite_path.suffix.lower() == ".png" and Image is not None:
                img = Image.open(sprite_path)
                frames = max(1, (img.width // width) * (img.height // height))
            else:
                frame_size = max(1, width // 8) * max(1, height // 8) * 32
                frames = max(1, sprite_path.stat().st_size // frame_size)
        return (sprite_path if sprite_path and sprite_path.is_file() else None, pal_path if pal_path and pal_path.is_file() else None, width, height, frames)

    def update_preview(self) -> None:
        self.canvas.delete("all")
        sprite, palette, width, height, frames = self.current_asset_paths()
        if not sprite:
            self.canvas.create_text(130, 130, fill="#f0f0f0", text="Sprite not found")
            self.frame_label.config(text="Frame 0/0")
            return
        self.frame %= frames
        try:
            scale = max(1, min(8, 220 // max(width, height)))
            if sprite.suffix.lower() == ".png":
                self.preview_image = render_png(sprite, width, height, self.frame, scale)
            else:
                self.preview_image = render_4bpp(sprite, palette, width, height, self.frame, scale)
            self.canvas.create_image(130, 130, image=self.preview_image)
            self.frame_label.config(text=f"Frame {self.frame + 1}/{frames}")
        except Exception as exc:
            self.canvas.create_text(130, 130, fill="#f0f0f0", text=str(exc), width=230)

    def move_frame(self, delta: int) -> None:
        _sprite, _palette, _width, _height, frames = self.current_asset_paths()
        self.frame = (self.frame + delta) % max(1, frames)
        self.update_preview()


def main() -> int:
    missing = [p for p in [INFO_H, GRAPHICS_H, PIC_TABLES_H, FIELD_EFFECT_OBJECTS_H, POINTERS_H, CONSTANTS_H, MOVEMENT_C] if not p.exists()]
    if missing:
        print("Expected files not found:")
        for path in missing:
            print(" -", path)
        return 1
    app = ObjectEventEditor()
    app.mainloop()
    return 0


if __name__ == "__main__":
    sys.exit(main())
