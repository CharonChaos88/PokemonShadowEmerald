import sys
from pathlib import Path
sys.path.append('.')

class MockStringVar:
    def __init__(self, value=""):
        self.value = value
    def get(self):
        return self.value
    def set(self, value):
        self.value = value

class MockApp:
    def __init__(self):
        from object_event_editor import ObjectEventRepo
        self.repo = ObjectEventRepo()
        self.field_vars = {"width": MockStringVar("16"), "height": MockStringVar("32"), "images": MockStringVar("")}
        self.pic_symbol_var = MockStringVar("")
        self.pal_symbol_var = MockStringVar("")
        self.sprite_source_var = MockStringVar("")
        self.palette_source_var = MockStringVar("")
        self.suffix_var = MockStringVar("BrendanNormal")

    def fill_asset_fields(self):
        suffix = self.suffix_var.get() or "NewObject"
        images = self.field_vars["images"].get()
        pic_table = images
        pic_symbol = self.pic_symbol_for_table(pic_table) or f"gObjectEventPic_{suffix}"
        self.pic_symbol_var.set(pic_symbol)
        self.sprite_source_var.set(self.repo.preferred_source_path(pic_symbol, ".png"))

    def pic_symbol_for_table(self, table: str) -> str:
        import re
        body = self.repo.pic_tables.get(table, "")
        m = re.search(r"(?:gObjectEventPic|gFieldEffectObjectPic)_[A-Za-z0-9_]+", body)
        return m.group(0) if m else ""

    def resolve_path(self, value: str) -> Path:
        from object_event_editor import ROOT
        path = Path(value)
        return path if path.is_absolute() else ROOT / path

    def current_asset_paths(self):
        width = int((self.field_vars["width"].get() or "16"), 0)
        height = int((self.field_vars["height"].get() or "32"), 0)
        pic_symbol = self.pic_symbol_var.get().strip()
        pal_symbol = self.pal_symbol_var.get().strip()
        sprite = self.sprite_source_var.get().strip() or self.repo.first_incbin_path(pic_symbol)
        palette = self.palette_source_var.get().strip() or self.repo.first_incbin_path(pal_symbol)
        sprite_path = self.resolve_path(sprite) if sprite else None
        pal_path = self.resolve_path(palette) if palette else None
        frames = 1
        from PIL import Image
        if sprite_path and sprite_path.is_file():
            if sprite_path.suffix.lower() == ".png" and Image is not None:
                img = Image.open(sprite_path)
                frames = max(1, (img.width // width) * (img.height // height))
            else:
                frame_size = max(1, width // 8) * max(1, height // 8) * 32
                frames = max(1, sprite_path.stat().st_size // frame_size)
        return (sprite_path if sprite_path and sprite_path.is_file() else None, pal_path if pal_path and pal_path.is_file() else None, width, height, frames)

app = MockApp()
entry = app.repo.entries[0]
app.suffix_var.set(entry.suffix)
for k in ["width", "height", "images"]:
    if k in entry.fields:
        app.field_vars[k].set(entry.fields[k])

app.fill_asset_fields()
sprite, palette, width, height, frames = app.current_asset_paths()
print("Sprite path output by current_asset_paths:", sprite)
if not sprite:
    print("Sprite is None! Variables:")
    print("pic_symbol:", app.pic_symbol_var.get())
    print("sprite_source_var:", app.sprite_source_var.get())
    print("first_incbin_path:", app.repo.first_incbin_path(app.pic_symbol_var.get()))

