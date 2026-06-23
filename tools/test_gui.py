import sys
import tkinter as tk
from pathlib import Path
sys.path.append('.')
from object_event_editor import ObjectEventEditor

app = ObjectEventEditor()
app.update()

# Select the first item in the listbox
app.listbox.selection_set(0)
app.select_current()
app.update()

sprite, palette, width, height, frames = app.current_asset_paths()
print("Sprite:", sprite)
print("Palette:", palette)
print("Width:", width, "Height:", height, "Frames:", frames)

