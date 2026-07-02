with open("/home/charonchaos/PokemonShadowEmerald/src/data/object_events/object_event_graphics_info_pointers.h", "r") as f:
    content = f.read()

externs = """extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireLinkMay;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanFieldMove;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanSurfing;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanMachBike;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanAcroBike;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanFishing;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanWatering;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanDecorating;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireBrendanUnderwater;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayFieldMove;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMaySurfing;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayMachBike;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayAcroBike;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayFishing;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayWatering;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayDecorating;
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireMayUnderwater;"""

pointers = """    [OBJ_EVENT_GFX_LINK_RS_MAY] =              &gObjectEventGraphicsInfo_RubySapphireLinkMay,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_FIELD_MOVE] = &gObjectEventGraphicsInfo_RubySapphireBrendanFieldMove,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_SURFING] = &gObjectEventGraphicsInfo_RubySapphireBrendanSurfing,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_MACH_BIKE] = &gObjectEventGraphicsInfo_RubySapphireBrendanMachBike,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_ACRO_BIKE] = &gObjectEventGraphicsInfo_RubySapphireBrendanAcroBike,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_FISHING] = &gObjectEventGraphicsInfo_RubySapphireBrendanFishing,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_WATERING] = &gObjectEventGraphicsInfo_RubySapphireBrendanWatering,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_DECORATING] = &gObjectEventGraphicsInfo_RubySapphireBrendanDecorating,
    [OBJ_EVENT_GFX_LINK_RS_BRENDAN_UNDERWATER] = &gObjectEventGraphicsInfo_RubySapphireBrendanUnderwater,
    [OBJ_EVENT_GFX_LINK_RS_MAY_FIELD_MOVE] = &gObjectEventGraphicsInfo_RubySapphireMayFieldMove,
    [OBJ_EVENT_GFX_LINK_RS_MAY_SURFING] = &gObjectEventGraphicsInfo_RubySapphireMaySurfing,
    [OBJ_EVENT_GFX_LINK_RS_MAY_MACH_BIKE] = &gObjectEventGraphicsInfo_RubySapphireMayMachBike,
    [OBJ_EVENT_GFX_LINK_RS_MAY_ACRO_BIKE] = &gObjectEventGraphicsInfo_RubySapphireMayAcroBike,
    [OBJ_EVENT_GFX_LINK_RS_MAY_FISHING] = &gObjectEventGraphicsInfo_RubySapphireMayFishing,
    [OBJ_EVENT_GFX_LINK_RS_MAY_WATERING] = &gObjectEventGraphicsInfo_RubySapphireMayWatering,
    [OBJ_EVENT_GFX_LINK_RS_MAY_DECORATING] = &gObjectEventGraphicsInfo_RubySapphireMayDecorating,
    [OBJ_EVENT_GFX_LINK_RS_MAY_UNDERWATER] = &gObjectEventGraphicsInfo_RubySapphireMayUnderwater,"""

content = content.replace("extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphireLinkMay;", externs)
content = content.replace("    [OBJ_EVENT_GFX_LINK_RS_MAY] =              &gObjectEventGraphicsInfo_RubySapphireLinkMay,", pointers)

with open("/home/charonchaos/PokemonShadowEmerald/src/data/object_events/object_event_graphics_info_pointers.h", "w") as f:
    f.write(content)
