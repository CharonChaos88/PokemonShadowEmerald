#!/usr/bin/env python3
"""Tkinter editor for time-of-day wild encounter tables.

Run from the repository root with:
    python3 tools/encounter_editor.py
"""

from __future__ import annotations

import copy
import json
import re
import shutil
from datetime import datetime
from pathlib import Path
import tkinter as tk
from tkinter import filedialog, messagebox, ttk

try:
    from PIL import Image, ImageTk
except ImportError:
    Image = None
    ImageTk = None


def project_root() -> Path:
    return Path(__file__).resolve().parents[1]


def parse_times_of_day(root: Path) -> list[str]:
    rtc_path = root / "include/constants/rtc.h"
    text = rtc_path.read_text(encoding="utf-8")
    match = re.search(r"enum\s+TimeOfDay\s*\{(?P<body>.*?)\}\s*;", text, re.S)
    if not match:
        return ["Morning", "Day", "Evening", "Night"]

    times: list[str] = []
    for ident in re.findall(r"\bTIME_[A-Z0-9_]+\b", match.group("body")):
        if ident == "TIMES_OF_DAY_COUNT":
            continue
        times.append(ident.removeprefix("TIME_").title().replace("_", ""))
    return times or ["Morning", "Day", "Evening", "Night"]


def load_species(root: Path) -> list[str]:
    path = root / "include/constants/species.h"
    if not path.exists():
        return []
    species: list[str] = []
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        match = re.match(r"\s*#define\s+(SPECIES_[A-Z0-9_]+)\b", line)
        if match:
            species.append(match.group(1))
    return species


class EncounterEditor(tk.Tk):
    COLORS = {
        "bg": "#17242d",
        "panel": "#1d2a34",
        "panel_alt": "#22313d",
        "line": "#32424f",
        "line_dark": "#14212a",
        "text": "#b8c0c8",
        "muted": "#8f9aa4",
        "accent": "#9acd32",
        "danger": "#ef6959",
        "select": "#2f4658",
        "entry": "#26343f",
    }

    def __init__(self) -> None:
        super().__init__()
        self.title("Time of Day Wild Encounter Editor")
        self.geometry("1240x720")
        self.minsize(1040, 620)
        self.configure(bg=self.COLORS["bg"])

        self.root_dir = project_root()
        self.json_path = self.root_dir / "src/data/wild_encounters.json"
        self.times = parse_times_of_day(self.root_dir)
        self.species = load_species(self.root_dir)

        self.data: dict = self.read_json()
        self.group_index = tk.IntVar(value=0)
        self.selected_base = tk.StringVar()
        self.status = tk.StringVar(value="")
        self.current_tree: ttk.Treeview | None = None
        self.current_field: str | None = None
        self.widgets: dict[tuple[str, str], dict] = {}
        self.icon_cache: dict[str, tk.PhotoImage] = {}
        self.blank_icon = tk.PhotoImage(width=32, height=32)
        self.cell_editor: tk.Widget | None = None
        self.cell_editor_commit = None
        self.species_suggestion_popup: tk.Toplevel | None = None
        self.species_suggestion_list: tk.Listbox | None = None

        self._configure_style()
        self._build_ui()
        self.populate_after_load()

    @property
    def group(self) -> dict:
        return self.data["wild_encounter_groups"][self.group_index.get()]

    def _configure_style(self) -> None:
        style = ttk.Style(self)
        try:
            style.theme_use("clam")
        except tk.TclError:
            pass

        colors = self.COLORS
        style.configure(".", background=colors["bg"], foreground=colors["text"], fieldbackground=colors["entry"])
        style.configure("TFrame", background=colors["bg"])
        style.configure("Panel.TFrame", background=colors["panel"])
        style.configure("TLabel", background=colors["bg"], foreground=colors["text"])
        style.configure("Muted.TLabel", background=colors["bg"], foreground=colors["muted"])
        style.configure(
            "TButton",
            background=colors["panel_alt"],
            foreground=colors["text"],
            bordercolor=colors["line"],
            focusthickness=0,
            padding=(8, 4),
        )
        style.map("TButton", background=[("active", colors["select"])], foreground=[("disabled", colors["muted"])])
        style.configure("Icon.TButton", padding=(6, 2), width=3)
        style.configure("Add.Icon.TButton", background=colors["accent"], foreground="#10200f")
        style.configure("Remove.Icon.TButton", background=colors["danger"], foreground="#ffffff")
        style.configure("TCheckbutton", background=colors["bg"], foreground=colors["text"])
        style.map("TCheckbutton", background=[("active", colors["bg"])])
        style.configure(
            "TCombobox",
            fieldbackground=colors["entry"],
            background=colors["panel_alt"],
            foreground=colors["text"],
            arrowcolor=colors["text"],
            bordercolor=colors["line"],
            lightcolor=colors["line"],
            darkcolor=colors["line_dark"],
        )
        style.map("TCombobox", fieldbackground=[("readonly", colors["entry"])], foreground=[("readonly", colors["text"])])
        style.configure(
            "TEntry",
            fieldbackground=colors["entry"],
            foreground=colors["text"],
            insertcolor=colors["text"],
            bordercolor=colors["line"],
        )
        style.configure("TNotebook", background=colors["bg"], borderwidth=0)
        style.configure(
            "TNotebook.Tab",
            background=colors["panel"],
            foreground=colors["muted"],
            bordercolor=colors["line"],
            padding=(14, 5),
        )
        style.map(
            "TNotebook.Tab",
            background=[("selected", colors["panel_alt"]), ("active", colors["panel_alt"])],
            foreground=[("selected", colors["text"]), ("active", colors["text"])],
        )
        style.configure(
            "Treeview",
            background=colors["bg"],
            fieldbackground=colors["bg"],
            foreground=colors["text"],
            rowheight=40,
            bordercolor=colors["line_dark"],
            borderwidth=0,
        )
        style.configure(
            "Treeview.Heading",
            background=colors["panel_alt"],
            foreground=colors["text"],
            relief=tk.FLAT,
            padding=(6, 5),
        )
        style.map("Treeview", background=[("selected", colors["select"])], foreground=[("selected", colors["text"])])
        style.configure("Vertical.TScrollbar", background=colors["panel_alt"], troughcolor=colors["bg"], arrowcolor=colors["text"])
        style.configure("Horizontal.TScrollbar", background=colors["panel_alt"], troughcolor=colors["bg"], arrowcolor=colors["text"])

    def _build_ui(self) -> None:
        toolbar = ttk.Frame(self, padding=(30, 18, 18, 8))
        toolbar.pack(side=tk.TOP, fill=tk.X)

        ttk.Label(toolbar, text="Group", style="Muted.TLabel").pack(side=tk.LEFT, padx=(0, 8))
        self.group_combo = ttk.Combobox(toolbar, state="readonly", width=28)
        self.group_combo.pack(side=tk.LEFT)
        self.group_combo.bind("<<ComboboxSelected>>", self.on_group_changed)
        ttk.Button(toolbar, text="+", style="Add.Icon.TButton", command=self.duplicate_all_times).pack(side=tk.LEFT, padx=(12, 4))
        ttk.Button(toolbar, text="-", style="Remove.Icon.TButton", command=self.delete_current_time).pack(side=tk.LEFT)

        ttk.Button(toolbar, text="Configure JSON...", command=self.open_json).pack(side=tk.RIGHT, padx=(8, 0))
        ttk.Button(toolbar, text="Save", command=self.save_json).pack(side=tk.RIGHT, padx=(8, 0))
        ttk.Button(toolbar, text="Reload", command=self.load_json).pack(side=tk.RIGHT)

        mapbar = ttk.Frame(self, padding=(30, 0, 18, 10))
        mapbar.pack(side=tk.TOP, fill=tk.X)
        ttk.Label(mapbar, text="Map/Base", style="Muted.TLabel").pack(side=tk.LEFT, padx=(0, 8))
        self.base_combo = ttk.Combobox(mapbar, textvariable=self.selected_base, state="readonly", width=54)
        self.base_combo.pack(side=tk.LEFT, fill=tk.X, expand=True)
        self.base_combo.bind("<<ComboboxSelected>>", self.on_base_changed)
        ttk.Button(mapbar, text="Copy From...", command=self.copy_into_current_time).pack(side=tk.LEFT, padx=(10, 0))
        ttk.Button(mapbar, text="Create Time", command=self.create_current_time).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Button(mapbar, text="Remove Time", command=self.delete_current_time).pack(side=tk.LEFT, padx=(6, 0))

        self.entry_list = tk.Listbox(self, exportselection=False)

        right = ttk.Frame(self, padding=(30, 0, 18, 8))
        right.pack(fill=tk.BOTH, expand=True)
        self.tabs = ttk.Notebook(right)
        self.tabs.pack(fill=tk.BOTH, expand=True)
        self.tabs.bind("<<NotebookTabChanged>>", lambda _event: self.refresh_current_tab())

        for time_name in self.times:
            frame = ttk.Frame(self.tabs, padding=8)
            self.tabs.add(frame, text=time_name)
            self._build_time_tab(frame, time_name)

        bottom = ttk.Frame(self, padding=(30, 0, 18, 10))
        bottom.pack(side=tk.BOTTOM, fill=tk.X)
        ttk.Label(bottom, textvariable=self.status).pack(anchor=tk.W)

    def _build_time_tab(self, parent: ttk.Frame, time_name: str) -> None:
        header = ttk.Frame(parent, padding=(0, 10, 0, 6))
        header.pack(fill=tk.X)
        label = ttk.Label(header, text="")
        label.pack(side=tk.LEFT)
        ttk.Button(header, text="Copy From...", command=self.copy_into_current_time).pack(side=tk.RIGHT)

        self.widgets[(time_name, "_header")] = {"status": label}
        field_tabs = ttk.Notebook(parent)
        field_tabs.pack(fill=tk.BOTH, expand=True)
        for field in self.fields_from_data():
            field_frame = ttk.Frame(field_tabs, padding=0)
            field_tabs.add(field_frame, text=field["type"])
            self._build_field_editor(field_frame, time_name, field)

    def _build_field_editor(self, parent: ttk.Frame, time_name: str, field: dict) -> None:
        field_type = field["type"]
        frame = ttk.Frame(parent, padding=(0, 8, 0, 0))
        frame.pack(fill=tk.BOTH, expand=True)

        top = ttk.Frame(frame)
        top.pack(fill=tk.X)
        enabled = tk.BooleanVar()
        rate = tk.StringVar()
        ttk.Checkbutton(top, text="Use Table", variable=enabled, command=self.apply_current_field).pack(side=tk.LEFT)
        ttk.Button(top, text="Resize Slots", command=lambda f=field_type: self.resize_field(f)).pack(side=tk.LEFT, padx=(16, 0))

        table_frame = ttk.Frame(frame)
        table_frame.pack(fill=tk.BOTH, expand=True, pady=(8, 8))
        columns = ("slot", "species", "min", "max", "chance", "ratio", "rate")
        tree = ttk.Treeview(table_frame, columns=columns, show="headings", height=max(12, len(field.get("encounter_rates", []))))
        tree.configure(show="tree headings")
        tree.heading("#0", text="")
        tree.heading("slot", text="Slot")
        tree.heading("species", text="Species")
        tree.heading("min", text="Min Level")
        tree.heading("max", text="Max Level")
        tree.heading("chance", text="Encounter Chance")
        tree.heading("ratio", text="Slot Ratio")
        tree.heading("rate", text="Encounter Rate")
        tree.column("#0", width=82, anchor=tk.CENTER, stretch=False)
        tree.column("slot", width=48, anchor=tk.W, stretch=False)
        tree.column("species", width=280, stretch=True)
        tree.column("min", width=130, anchor=tk.W, stretch=False)
        tree.column("max", width=130, anchor=tk.W, stretch=False)
        tree.column("chance", width=130, anchor=tk.W, stretch=False)
        tree.column("ratio", width=90, anchor=tk.W, stretch=False)
        tree.column("rate", width=120, anchor=tk.W, stretch=False)
        yscroll = ttk.Scrollbar(table_frame, orient=tk.VERTICAL, command=tree.yview)
        xscroll = ttk.Scrollbar(table_frame, orient=tk.HORIZONTAL, command=tree.xview)
        tree.configure(yscrollcommand=yscroll.set, xscrollcommand=xscroll.set)
        tree.tag_configure("odd", background=self.COLORS["bg"])
        tree.tag_configure("even", background=self.COLORS["panel"])
        tree.grid(row=0, column=0, sticky="nsew")
        yscroll.grid(row=0, column=1, sticky="ns")
        xscroll.grid(row=1, column=0, sticky="ew")
        table_frame.columnconfigure(0, weight=1)
        table_frame.rowconfigure(0, weight=1)
        tree.bind("<<TreeviewSelect>>", lambda _event, t=time_name, f=field_type: self.on_mon_select(t, f))
        tree.bind("<FocusIn>", lambda _event, f=field_type, tr=tree: self.set_current_field(f, tr))
        tree.bind("<Button-1>", lambda event, t=time_name, f=field_type: self.on_tree_click(event, t, f))

        edit = ttk.Frame(frame, padding=(0, 0, 0, 8))
        edit.pack(fill=tk.X)
        min_level = tk.StringVar(value="2")
        max_level = tk.StringVar(value="2")
        species = tk.StringVar(value="SPECIES_NONE")
        ttk.Label(edit, text="Min:").pack(side=tk.LEFT)
        ttk.Entry(edit, textvariable=min_level, width=6).pack(side=tk.LEFT, padx=(4, 10))
        ttk.Label(edit, text="Max:").pack(side=tk.LEFT)
        ttk.Entry(edit, textvariable=max_level, width=6).pack(side=tk.LEFT, padx=(4, 10))
        ttk.Label(edit, text="Species:").pack(side=tk.LEFT)
        species_combo = ttk.Combobox(edit, textvariable=species, values=self.species, width=34)
        species_combo.bind(
            "<KeyRelease>",
            lambda event, combo=species_combo, variable=species: self.update_species_suggestions(event, combo, variable),
        )
        species_combo.bind("<<ComboboxSelected>>", lambda _event, combo=species_combo: combo.icursor(tk.END))
        species_combo.pack(side=tk.LEFT, padx=(4, 10), fill=tk.X, expand=True)
        ttk.Button(edit, text="Update Slot", command=lambda f=field_type: self.update_selected_mon(f)).pack(side=tk.LEFT)
        ttk.Button(edit, text="Add Slot", command=lambda f=field_type: self.add_mon(f)).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Button(edit, text="Remove Slot", command=lambda f=field_type: self.remove_selected_mon(f)).pack(side=tk.LEFT, padx=(6, 0))

        self.widgets[(time_name, field_type)] = {
            "enabled": enabled,
            "rate": rate,
            "tree": tree,
            "min": min_level,
            "max": max_level,
            "species": species,
            "expected": len(field.get("encounter_rates", [])),
            "rates": field.get("encounter_rates", []),
        }

    def fields_from_data(self) -> list[dict]:
        if not self.data:
            return []
        groups = self.data.get("wild_encounter_groups", [])
        if not groups:
            return []
        return groups[self.group_index.get()].get("fields", [])

    def open_json(self) -> None:
        chosen = filedialog.askopenfilename(
            initialdir=self.root_dir / "src/data",
            title="Open wild_encounters.json",
            filetypes=[("JSON", "*.json"), ("All files", "*.*")],
        )
        if chosen:
            self.json_path = Path(chosen)
            self.load_json()

    def read_json(self) -> dict:
        with self.json_path.open(encoding="utf-8") as file:
            return json.load(file)

    def load_json(self) -> None:
        self.data = self.read_json()
        self.populate_after_load()

    def populate_after_load(self) -> None:
        group_labels = [
            f"{idx}: {group.get('label', '(no label)')}"
            for idx, group in enumerate(self.data.get("wild_encounter_groups", []))
        ]
        self.group_combo["values"] = group_labels
        self.group_combo.current(min(self.group_index.get(), len(group_labels) - 1))
        self.refresh_bases()
        self.set_status(f"Loaded: {self.json_path}")

    def save_json(self) -> None:
        self.apply_current_field()
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        backup = self.json_path.with_suffix(self.json_path.suffix + f".tod_editor_{timestamp}.bak")
        shutil.copy2(self.json_path, backup)
        with self.json_path.open("w", encoding="utf-8") as file:
            json.dump(self.data, file, indent=2)
            file.write("\n")
        self.set_status(f"Saved. Backup created at {backup}")
        messagebox.showinfo("Saved", f"wild_encounters.json saved.\nBackup:\n{backup}")
        self.refresh_bases()

    def refresh_bases(self) -> None:
        bases = []
        for base_key, entries in self.base_entries().items():
            first = entries[0]
            bases.append(f"{first.get('map', '(no map)')} | {base_key}")
        self.base_combo["values"] = bases
        if bases:
            if self.selected_base.get() not in bases:
                self.selected_base.set(bases[0])
            self.base_combo.set(self.selected_base.get())
        self.refresh_entry_list()
        self.refresh_current_tab()

    def base_entries(self) -> dict[str, list[dict]]:
        result: dict[str, list[dict]] = {}
        for entry in self.group.get("encounters", []):
            base_key, _time_name = self.split_label(entry.get("base_label", ""))
            result.setdefault(base_key, []).append(entry)
        return result

    def selected_base_key(self) -> str | None:
        value = self.selected_base.get()
        if " | " not in value:
            return None
        return value.split(" | ", 1)[1]

    def split_label(self, label: str) -> tuple[str, str | None]:
        for suffix in self.times:
            marker = "_" + suffix
            if label.endswith(marker):
                return label[: -len(marker)], suffix
        return label, self.times[0] if self.times else None

    def selected_time(self) -> str:
        return self.tabs.tab(self.tabs.select(), "text")

    def selected_entry(self, time_name: str | None = None) -> dict | None:
        base_key = self.selected_base_key()
        if not base_key:
            return None
        time_name = time_name or self.selected_time()
        for entry in self.base_entries().get(base_key, []):
            entry_base, entry_time = self.split_label(entry.get("base_label", ""))
            if entry_base == base_key and entry_time == time_name:
                return entry
        return None

    def on_group_changed(self, _event=None) -> None:
        self.group_index.set(self.group_combo.current())
        self.refresh_bases()

    def on_base_changed(self, _event=None) -> None:
        self.refresh_entry_list()
        self.refresh_current_tab()

    def refresh_entry_list(self) -> None:
        self.entry_list.delete(0, tk.END)
        base_key = self.selected_base_key()
        if not base_key:
            return
        for entry in self.base_entries().get(base_key, []):
            _base, time_name = self.split_label(entry.get("base_label", ""))
            self.entry_list.insert(tk.END, f"{time_name}: {entry.get('base_label')} ({entry.get('map', '')})")

    def on_entry_list_select(self, _event=None) -> None:
        selection = self.entry_list.curselection()
        if not selection:
            return
        text = self.entry_list.get(selection[0])
        time_name = text.split(":", 1)[0]
        if time_name in self.times:
            self.tabs.select(self.times.index(time_name))

    def refresh_current_tab(self) -> None:
        self.close_cell_editor()
        for time_name in self.times:
            entry = self.selected_entry(time_name)
            header = self.widgets.get((time_name, "_header"), {})
            label = header.get("status")
            if label:
                label.configure(text=self.entry_summary(entry, time_name))
            for field in self.fields_from_data():
                self.refresh_field(time_name, field["type"], entry)

    def entry_summary(self, entry: dict | None, time_name: str) -> str:
        if not entry:
            return f"{time_name}: no entry for this map. Use 'Create Time'."
        return f"{time_name}: {entry.get('base_label')} in {entry.get('map', '(no map)')}"

    def refresh_field(self, time_name: str, field_type: str, entry: dict | None) -> None:
        widgets = self.widgets.get((time_name, field_type))
        if not widgets:
            return
        tree: ttk.Treeview = widgets["tree"]
        tree.delete(*tree.get_children())
        table = entry.get(field_type) if entry else None
        widgets["enabled"].set(bool(table))
        widgets["rate"].set(str(table.get("encounter_rate", 0)) if table else "")
        mons = table.get("mons", []) if table else []
        rates = widgets.get("rates", [])
        encounter_rate = table.get("encounter_rate", "") if table else ""
        for idx, mon in enumerate(mons):
            ratio = rates[idx] if idx < len(rates) else ""
            chance = f"{ratio:.2f}%" if isinstance(ratio, (int, float)) else ""
            species = mon.get("species", "SPECIES_NONE")
            rate_text = encounter_rate if idx == 0 else ""
            tree.insert(
                "",
                tk.END,
                values=(
                    idx,
                    species,
                    mon.get("min_level", 2),
                    mon.get("max_level", 100),
                    chance,
                    ratio,
                    rate_text,
                ),
                image=self.species_icon(species),
                tags=("even" if idx % 2 else "odd",),
            )

    def set_current_field(self, field_type: str, tree: ttk.Treeview) -> None:
        self.current_field = field_type
        self.current_tree = tree

    def current_widgets(self, field_type: str | None = None) -> dict | None:
        return self.widgets.get((self.selected_time(), field_type or self.current_field or ""))

    def on_tree_click(self, event: tk.Event, time_name: str, field_type: str) -> None:
        tree: ttk.Treeview = event.widget
        row_id = tree.identify_row(event.y)
        column = tree.identify_column(event.x)
        self.close_cell_editor()
        self.set_current_field(field_type, tree)
        if not row_id:
            return
        tree.selection_set(row_id)
        tree.focus(row_id)
        if column == "#2":
            self.edit_species_cell(tree, row_id, column, time_name, field_type)
        elif column in {"#3", "#4"}:
            key = "min_level" if column == "#3" else "max_level"
            self.edit_number_cell(tree, row_id, column, time_name, field_type, key, 1, 100)
        elif column == "#7" and int(tree.item(row_id, "values")[0]) == 0:
            self.edit_number_cell(tree, row_id, column, time_name, field_type, "encounter_rate", 0, 100)

    def edit_species_cell(self, tree: ttk.Treeview, row_id: str, column: str, time_name: str, field_type: str) -> None:
        bbox = tree.bbox(row_id, column)
        if not bbox:
            return
        x, y, width, height = bbox
        values = list(tree.item(row_id, "values"))
        variable = tk.StringVar(value=values[1])
        combo = ttk.Combobox(tree, textvariable=variable, values=self.species)
        combo.place(x=x, y=y, width=width, height=height)
        combo.bind(
            "<KeyRelease>",
            lambda event, widget=combo, var=variable: self.update_species_suggestions(event, widget, var),
        )

        def commit(_event=None) -> None:
            if self.cell_editor is not combo:
                return
            species = self.normalize_species(variable.get())
            self.update_mon_value(time_name, field_type, int(values[0]), "species", species)
            values[1] = species
            tree.item(row_id, values=values, image=self.species_icon(species))
            self.close_cell_editor(commit=False)

        combo.bind("<<ComboboxSelected>>", commit)
        combo.bind("<Return>", commit)
        combo.bind("<Escape>", lambda _event: self.close_cell_editor(commit=False))
        combo.focus_set()
        combo.icursor(tk.END)
        self.cell_editor = combo
        self.cell_editor_commit = commit

    def edit_number_cell(
        self,
        tree: ttk.Treeview,
        row_id: str,
        column: str,
        time_name: str,
        field_type: str,
        key: str,
        from_: int,
        to: int,
    ) -> None:
        bbox = tree.bbox(row_id, column)
        if not bbox:
            return
        x, y, width, height = bbox
        values = list(tree.item(row_id, "values"))
        value_index = {"min_level": 2, "max_level": 3, "encounter_rate": 6}[key]
        variable = tk.StringVar(value=values[value_index])
        spinbox = ttk.Spinbox(tree, textvariable=variable, from_=from_, to=to, width=6)
        spinbox.place(x=x, y=y, width=width, height=height)

        def commit(_event=None) -> None:
            if self.cell_editor is not spinbox:
                return
            value = self.parse_int(variable.get(), from_)
            value = max(from_, min(to, value))
            index = int(values[0])
            self.update_mon_value(time_name, field_type, index, key, value)
            if key == "encounter_rate":
                widgets = self.widgets.get((time_name, field_type))
                if widgets:
                    widgets["rate"].set(str(value))
                values[value_index] = value
            else:
                entry = self.selected_entry(time_name)
                mons = entry.get(field_type, {}).get("mons", []) if entry else []
                mon = mons[index] if index < len(mons) else {}
                values[2] = mon.get("min_level", value)
                values[3] = mon.get("max_level", value)
            tree.item(row_id, values=values)
            self.close_cell_editor(commit=False)

        spinbox.bind("<Return>", commit)
        spinbox.bind("<FocusOut>", commit)
        spinbox.bind("<Escape>", lambda _event: self.close_cell_editor(commit=False))
        spinbox.focus_set()
        spinbox.selection_range(0, tk.END)
        self.cell_editor = spinbox
        self.cell_editor_commit = commit

    def update_mon_value(self, time_name: str, field_type: str, index: int, key: str, value: int | str) -> None:
        entry = self.selected_entry(time_name)
        widgets = self.widgets.get((time_name, field_type))
        if not entry or not widgets:
            return
        table = entry.setdefault(field_type, {"encounter_rate": self.parse_int(widgets["rate"].get(), 0), "mons": []})
        widgets["enabled"].set(True)
        if key == "encounter_rate":
            table["encounter_rate"] = int(value)
            return
        while len(table["mons"]) <= index:
            table["mons"].append(self.default_mon())
        mon = table["mons"][index]
        mon[key] = value
        if key == "min_level" and mon.get("max_level", value) < value:
            mon["max_level"] = value
        if key == "max_level" and value < mon.get("min_level", value):
            mon["min_level"] = value

    def normalize_species(self, species: str) -> str:
        species = species.strip() or "SPECIES_NONE"
        if not species.startswith("SPECIES_"):
            species = "SPECIES_" + species.upper()
        return species

    def close_cell_editor(self, commit: bool = True) -> None:
        self.close_species_suggestions()
        if commit and self.cell_editor_commit:
            commit_callback = self.cell_editor_commit
            self.cell_editor_commit = None
            commit_callback()
            return
        if self.cell_editor and self.cell_editor.winfo_exists():
            self.cell_editor.destroy()
        self.cell_editor = None
        self.cell_editor_commit = None

    def ensure_current_entry(self) -> dict | None:
        entry = self.selected_entry()
        if entry:
            return entry
        self.create_current_time()
        return self.selected_entry()

    def apply_current_field(self) -> None:
        entry = self.selected_entry()
        if not entry:
            return
        for field in self.fields_from_data():
            field_type = field["type"]
            widgets = self.widgets.get((self.selected_time(), field_type))
            if not widgets:
                continue
            if not widgets["enabled"].get():
                entry.pop(field_type, None)
                continue
            table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
            table["encounter_rate"] = self.parse_int(widgets["rate"].get(), 0)

    def create_current_time(self) -> None:
        base_key = self.selected_base_key()
        if not base_key:
            return
        time_name = self.selected_time()
        if self.selected_entry(time_name):
            self.set_status(f"{time_name} already exists for {base_key}.")
            return
        source = self.first_entry_for_base(base_key)
        if not source:
            return
        new_entry = copy.deepcopy(source)
        new_entry["base_label"] = base_key if time_name == self.times[0] else f"{base_key}_{time_name}"
        self.group["encounters"].append(new_entry)
        self.refresh_bases()
        self.set_status(f"Created {new_entry['base_label']}.")

    def duplicate_all_times(self) -> None:
        base_key = self.selected_base_key()
        if not base_key:
            return
        source = self.first_entry_for_base(base_key)
        if not source:
            return
        existing = {self.split_label(entry.get("base_label", ""))[1] for entry in self.base_entries().get(base_key, [])}
        created = []
        for idx, time_name in enumerate(self.times):
            if time_name in existing:
                continue
            new_entry = copy.deepcopy(source)
            new_entry["base_label"] = base_key if idx == 0 else f"{base_key}_{time_name}"
            self.group["encounters"].append(new_entry)
            created.append(new_entry["base_label"])
        self.refresh_bases()
        self.set_status("Created: " + ", ".join(created) if created else "All times already existed.")

    def copy_into_current_time(self) -> None:
        entry = self.ensure_current_entry()
        base_key = self.selected_base_key()
        if not entry or not base_key:
            return
        options = [time for time in self.times if time != self.selected_time() and self.selected_entry(time)]
        if not options:
            messagebox.showinfo("Copy", "There is no other existing time to copy for this map.")
            return
        dialog = CopyDialog(self, options)
        self.wait_window(dialog)
        if not dialog.result:
            return
        source = self.selected_entry(dialog.result)
        keep_label = entry["base_label"]
        keep_map = entry.get("map")
        entry.clear()
        entry.update(copy.deepcopy(source))
        entry["base_label"] = keep_label
        if keep_map:
            entry["map"] = keep_map
        self.refresh_current_tab()
        self.set_status(f"{keep_label} received encounters from {dialog.result}.")

    def delete_current_time(self) -> None:
        entry = self.selected_entry()
        if not entry:
            return
        if not messagebox.askyesno("Remove", f"Remove {entry.get('base_label')}?"):
            return
        self.group["encounters"].remove(entry)
        self.refresh_bases()

    def first_entry_for_base(self, base_key: str) -> dict | None:
        entries = self.base_entries().get(base_key, [])
        return entries[0] if entries else None

    def on_mon_select(self, time_name: str, field_type: str) -> None:
        widgets = self.widgets[(time_name, field_type)]
        tree: ttk.Treeview = widgets["tree"]
        self.set_current_field(field_type, tree)
        selected = tree.selection()
        if not selected:
            return
        values = tree.item(selected[0], "values")
        widgets["species"].set(values[1])
        widgets["min"].set(values[2])
        widgets["max"].set(values[3])

    def update_selected_mon(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        tree: ttk.Treeview = widgets["tree"]
        selected = tree.selection()
        if not selected:
            messagebox.showinfo("Update Slot", "Select a slot first.")
            return
        index = int(tree.item(selected[0], "values")[0])
        table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
        while len(table["mons"]) <= index:
            table["mons"].append(self.default_mon())
        table["mons"][index] = self.mon_from_widgets(widgets)
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()

    def add_mon(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
        table["mons"].append(self.mon_from_widgets(widgets))
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()

    def remove_selected_mon(self, field_type: str) -> None:
        entry = self.selected_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets or field_type not in entry:
            return
        tree: ttk.Treeview = widgets["tree"]
        selected = tree.selection()
        if not selected:
            return
        index = int(tree.item(selected[0], "values")[0])
        mons = entry[field_type].setdefault("mons", [])
        if 0 <= index < len(mons):
            mons.pop(index)
        self.refresh_current_tab()

    def resize_field(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        table = entry.setdefault(field_type, {"encounter_rate": self.parse_int(widgets["rate"].get(), 0), "mons": []})
        expected = widgets["expected"]
        while len(table["mons"]) < expected:
            table["mons"].append(self.default_mon())
        del table["mons"][expected:]
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()
        self.set_status(f"{field_type} resized to {expected} slots.")

    def mon_from_widgets(self, widgets: dict) -> dict:
        min_level = self.parse_int(widgets["min"].get(), 2)
        max_level = self.parse_int(widgets["max"].get(), min_level)
        if max_level < min_level:
            max_level = min_level
        species = widgets["species"].get().strip() or "SPECIES_NONE"
        species = self.normalize_species(species)
        return {"min_level": min_level, "max_level": max_level, "species": species}

    def update_species_suggestions(self, event: tk.Event, combo: ttk.Combobox, variable: tk.StringVar) -> None:
        if event.keysym in {"Up", "Left", "Right", "Return", "Tab", "Shift_L", "Shift_R", "Control_L", "Control_R"}:
            return
        if event.keysym == "Escape":
            self.close_species_suggestions()
            return
        cursor = combo.index(tk.INSERT)
        typed = variable.get()
        suggestions = self.match_species(typed)
        combo.configure(values=suggestions)
        combo.focus_set()
        combo.icursor(cursor)
        if typed.strip() and suggestions:
            self.show_species_suggestions(combo, variable, suggestions)
        else:
            self.close_species_suggestions()

    def show_species_suggestions(self, combo: ttk.Combobox, variable: tk.StringVar, suggestions: list[str]) -> None:
        if not self.species_suggestion_popup or not self.species_suggestion_popup.winfo_exists():
            popup = tk.Toplevel(self)
            popup.overrideredirect(True)
            popup.configure(bg=self.COLORS["line"])
            listbox = tk.Listbox(
                popup,
                bg=self.COLORS["entry"],
                fg=self.COLORS["text"],
                selectbackground=self.COLORS["select"],
                selectforeground=self.COLORS["text"],
                highlightthickness=1,
                highlightbackground=self.COLORS["line"],
                activestyle="none",
            )
            listbox.pack(fill=tk.BOTH, expand=True)
            self.species_suggestion_popup = popup
            self.species_suggestion_list = listbox

        assert self.species_suggestion_popup is not None
        assert self.species_suggestion_list is not None
        self.species_suggestion_list.delete(0, tk.END)
        for species in suggestions[:12]:
            self.species_suggestion_list.insert(tk.END, species)

        def choose(_event=None) -> None:
            selection = self.species_suggestion_list.curselection()
            if not selection:
                return
            variable.set(self.species_suggestion_list.get(selection[0]))
            self.close_species_suggestions()
            combo.focus_set()
            combo.icursor(tk.END)
            combo.event_generate("<<ComboboxSelected>>")

        self.species_suggestion_list.bind("<ButtonRelease-1>", choose)
        self.species_suggestion_list.bind("<Return>", choose)
        self.species_suggestion_list.bind("<Escape>", lambda _event: self.close_species_suggestions())

        x = combo.winfo_rootx()
        y = combo.winfo_rooty() + combo.winfo_height()
        width = max(combo.winfo_width(), 220)
        height = min(12, len(suggestions)) * 22
        self.species_suggestion_popup.geometry(f"{width}x{height}+{x}+{y}")
        self.species_suggestion_popup.deiconify()
        combo.focus_set()

    def close_species_suggestions(self) -> None:
        if self.species_suggestion_popup and self.species_suggestion_popup.winfo_exists():
            self.species_suggestion_popup.destroy()
        self.species_suggestion_popup = None
        self.species_suggestion_list = None

    def match_species(self, text: str) -> list[str]:
        query = text.strip().upper()
        if not query:
            return self.species
        query_name = query.removeprefix("SPECIES_")
        query_compact = re.sub(r"[^A-Z0-9]", "", query_name)
        matches: list[str] = []
        for species in self.species:
            species_upper = species.upper()
            species_name = species_upper.removeprefix("SPECIES_")
            species_compact = re.sub(r"[^A-Z0-9]", "", species_name)
            if query in species_upper or query_name in species_name or query_compact in species_compact:
                matches.append(species)
        return matches

    def species_icon(self, species: str) -> tk.PhotoImage:
        species = species.strip()
        if not species or species == "SPECIES_NONE":
            return self.blank_icon
        if species not in self.icon_cache:
            icon_path = self.species_icon_path(species)
            if icon_path:
                try:
                    self.icon_cache[species] = self.load_icon_frame(icon_path)
                except (OSError, ValueError, tk.TclError):
                    self.icon_cache[species] = self.blank_icon
            else:
                self.icon_cache[species] = self.blank_icon
        return self.icon_cache[species]

    def load_icon_frame(self, icon_path: Path) -> tk.PhotoImage:
        if Image and ImageTk:
            with Image.open(icon_path) as source:
                frame = source.crop((0, 0, min(32, source.width), min(32, source.height)))
                if frame.mode == "P":
                    alpha = frame.point(lambda pixel: 0 if pixel == 0 else 255, "L")
                    frame = frame.convert("RGBA")
                    frame.putalpha(alpha)
                else:
                    frame = frame.convert("RGBA")
                if frame.size != (32, 32):
                    canvas = Image.new("RGBA", (32, 32), (0, 0, 0, 0))
                    canvas.paste(frame, (0, 0), frame)
                    frame = canvas
                return ImageTk.PhotoImage(frame)

        source = tk.PhotoImage(file=str(icon_path))
        frame = tk.PhotoImage(width=32, height=32)
        frame.tk.call(frame, "copy", source, "-from", 0, 0, min(32, source.width()), min(32, source.height()), "-to", 0, 0)
        transparent_color = source.get(0, 0)
        for y in range(frame.height()):
            for x in range(frame.width()):
                if frame.get(x, y) == transparent_color:
                    frame.transparency_set(x, y, True)
        return frame

    def species_icon_path(self, species: str) -> Path | None:
        base_dir = self.root_dir / "graphics/pokemon"
        name = species.removeprefix("SPECIES_").lower()
        tokens = name.split("_")
        candidates = [base_dir / name / "icon.png"]

        form_suffixes = ("alola", "galar", "hisui", "paldea", "mega", "mega_x", "mega_y", "gmax", "primal")
        for suffix in form_suffixes:
            suffix_tokens = suffix.split("_")
            if len(tokens) > len(suffix_tokens) and tokens[-len(suffix_tokens) :] == suffix_tokens:
                candidates.append(base_dir / "_".join(tokens[: -len(suffix_tokens)]) / suffix / "icon.png")
        for path in candidates:
            if path.exists():
                return path
        return None

    def default_mon(self) -> dict:
        return {"min_level": 2, "max_level": 2, "species": "SPECIES_NONE"}

    def parse_int(self, value: str, default: int) -> int:
        try:
            return int(value)
        except (TypeError, ValueError):
            return default

    def set_status(self, text: str) -> None:
        self.status.set(text)


class CopyDialog(tk.Toplevel):
    def __init__(self, parent: tk.Tk, options: list[str]) -> None:
        super().__init__(parent)
        self.title("Copy Encounters")
        self.resizable(False, False)
        self.result: str | None = None
        self.choice = tk.StringVar(value=options[0])
        self.transient(parent)
        self.grab_set()

        frame = ttk.Frame(self, padding=14)
        frame.pack(fill=tk.BOTH, expand=True)
        ttk.Label(frame, text="Copy encounters from which time?").pack(anchor=tk.W)
        ttk.Combobox(frame, textvariable=self.choice, values=options, state="readonly", width=24).pack(fill=tk.X, pady=(8, 12))
        buttons = ttk.Frame(frame)
        buttons.pack(fill=tk.X)
        ttk.Button(buttons, text="Cancel", command=self.destroy).pack(side=tk.RIGHT)
        ttk.Button(buttons, text="Copy", command=self.accept).pack(side=tk.RIGHT, padx=(0, 8))

    def accept(self) -> None:
        self.result = self.choice.get()
        self.destroy()


if __name__ == "__main__":
    app = EncounterEditor()
    app.mainloop()
