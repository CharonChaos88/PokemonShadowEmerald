import sys
from pathlib import Path
sys.path.append('.')

class MockApp:
    def __init__(self):
        from object_event_editor import ObjectEventRepo
        self.repo = ObjectEventRepo()

app = MockApp()
for e in app.repo.entries[:5]:
    pic_table = e.fields.get("images", "")
    import re
    body = app.repo.pic_tables.get(pic_table, "")
    m = re.search(r"(?:gObjectEventPic|gFieldEffectObjectPic)_[A-Za-z0-9_]+", body)
    pic_symbol = m.group(0) if m else ""
    incbin = app.repo.first_incbin_path(pic_symbol)
    path = app.repo.preferred_source_path(pic_symbol, ".png")
    from object_event_editor import ROOT
    full_path = ROOT / path
    print(f"{e.symbol}: table={pic_table} sym={pic_symbol} path={path} is_file={full_path.is_file()}")

