import sys
from pathlib import Path
sys.path.append('.')
from object_event_editor import ObjectEventRepo

repo = ObjectEventRepo()
print("Entries count:", len(repo.entries))
if len(repo.entries) > 0:
    entry = repo.entries[0]
    print("Entry symbol:", entry.symbol)
    pic_table = entry.fields.get("images", "")
    print("Pic table:", pic_table)
    # Find pic symbol
    import re
    body = repo.pic_tables.get(pic_table, "")
    m = re.search(r"(?:gObjectEventPic|gFieldEffectObjectPic)_[A-Za-z0-9_]+", body)
    pic_symbol = m.group(0) if m else ""
    print("Pic symbol:", pic_symbol)
    incbin = repo.first_incbin_path(pic_symbol)
    print("Incbin:", incbin)
    pref = repo.preferred_source_path(pic_symbol, ".png")
    print("Preferred:", pref)
    p = Path(__file__).resolve().parents[1] / pref
    print("Exists?", p.exists())
    print("Is file?", p.is_file())
