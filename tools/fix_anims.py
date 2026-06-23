with open("/home/charonchaos/PokemonShadowEmerald/src/data/object_events/object_event_graphics_info.h", "r") as f:
    content = f.read()

replacements = [
    (".anims = sAnimTable_MachBike,", ".anims = sAnimTable_Standard,", "MachBike"),
    (".anims = sAnimTable_Watering,", ".anims = sAnimTable_Standard,", "Watering"),
    (".anims = sAnimTable_Decorating,", ".anims = sAnimTable_Inanimate,", "Decorating"),
    (".inanimate = FALSE,\n    .compressed = FALSE,\n    .tracks = TRACKS_FOOT,\n    .oam = &gObjectEventBaseOam_16x32,\n    .subspriteTables = sOamTables_16x32,\n    .anims = sAnimTable_Inanimate,\n    .images = sPicTable_RubySapphireBrendanDecorating,", 
     ".inanimate = TRUE,\n    .compressed = FALSE,\n    .tracks = TRACKS_FOOT,\n    .oam = &gObjectEventBaseOam_16x32,\n    .subspriteTables = sOamTables_16x32,\n    .anims = sAnimTable_Inanimate,\n    .images = sPicTable_RubySapphireBrendanDecorating,"),
    (".inanimate = FALSE,\n    .compressed = FALSE,\n    .tracks = TRACKS_FOOT,\n    .oam = &gObjectEventBaseOam_16x32,\n    .subspriteTables = sOamTables_16x32,\n    .anims = sAnimTable_Inanimate,\n    .images = sPicTable_RubySapphireMayDecorating,", 
     ".inanimate = TRUE,\n    .compressed = FALSE,\n    .tracks = TRACKS_FOOT,\n    .oam = &gObjectEventBaseOam_16x32,\n    .subspriteTables = sOamTables_16x32,\n    .anims = sAnimTable_Inanimate,\n    .images = sPicTable_RubySapphireMayDecorating,")
]

import re
for old, new, tag in replacements[:3]:
    # only replace when it's inside the RS struct
    content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireBrendan{tag}(.*?){re.escape(old)}", rf"gObjectEventGraphicsInfo_RubySapphireBrendan{tag}\1{new}", content, flags=re.DOTALL)
    content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireMay{tag}(.*?){re.escape(old)}", rf"gObjectEventGraphicsInfo_RubySapphireMay{tag}\1{new}", content, flags=re.DOTALL)

for old, new in replacements[3:]:
    content = content.replace(old, new)

# Wait, what about TRACKS for MachBike? BrendanMachBike uses TRACKS_BIKE_TIRE.
content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireBrendanMachBike(.*?)TRACKS_FOOT", rf"gObjectEventGraphicsInfo_RubySapphireBrendanMachBike\1TRACKS_BIKE_TIRE", content, flags=re.DOTALL)
content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireMayMachBike(.*?)TRACKS_FOOT", rf"gObjectEventGraphicsInfo_RubySapphireMayMachBike\1TRACKS_BIKE_TIRE", content, flags=re.DOTALL)
content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireBrendanAcroBike(.*?)TRACKS_FOOT", rf"gObjectEventGraphicsInfo_RubySapphireBrendanAcroBike\1TRACKS_BIKE_TIRE", content, flags=re.DOTALL)
content = re.sub(rf"gObjectEventGraphicsInfo_RubySapphireMayAcroBike(.*?)TRACKS_FOOT", rf"gObjectEventGraphicsInfo_RubySapphireMayAcroBike\1TRACKS_BIKE_TIRE", content, flags=re.DOTALL)


with open("/home/charonchaos/PokemonShadowEmerald/src/data/object_events/object_event_graphics_info.h", "w") as f:
    f.write(content)
