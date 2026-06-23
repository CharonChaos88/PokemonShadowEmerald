import re

out_str = ""

states = [
    ("FieldMove", "FieldMove", 32, 32, 512, "sOamTables_32x32", "sAnimTable_FieldMove"),
    ("Surfing", "Surfing", 32, 32, 512, "sOamTables_32x32", "sAnimTable_Surfing"),
    ("MachBike", "MachBike", 32, 32, 512, "sOamTables_32x32", "sAnimTable_MachBike"),
    ("AcroBike", "AcroBike", 32, 32, 512, "sOamTables_32x32", "sAnimTable_AcroBike"),
    ("Fishing", "Fishing", 32, 32, 512, "sOamTables_32x32", "sAnimTable_Fishing"),
    ("Watering", "Watering", 32, 32, 512, "sOamTables_32x32", "sAnimTable_Watering"),
    ("Decorating", "Decorating", 16, 32, 256, "sOamTables_16x32", "sAnimTable_Decorating"),
    ("Underwater", "Underwater", 32, 32, 512, "sOamTables_32x32", "sAnimTable_Surfing"),
]

for char, pal in [("Brendan", "OBJ_EVENT_PAL_TAG_RS_BRENDAN"), ("May", "OBJ_EVENT_PAL_TAG_RS_MAY")]:
    for state, state_name, w, h, size, oam, anims in states:
        out_str += f"""
const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphire{char}{state} = {{
    .tileTag = TAG_NONE,
    .paletteTag = {pal},
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION,
    .size = {size},
    .width = {w},
    .height = {h},
    .paletteSlot = PALSLOT_NPC_SPECIAL,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_{w}x{h},
    .subspriteTables = {oam},
    .anims = {anims},
    .images = sPicTable_RubySapphire{char}{state},
}};
"""

with open("/home/charonchaos/PokemonShadowEmerald/src/data/object_events/object_event_graphics_info.h", "a") as f:
    f.write(out_str)
