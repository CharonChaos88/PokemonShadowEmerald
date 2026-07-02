out_str_externs = ""
out_str_pointers = ""

states = [
    "FieldMove", "Surfing", "MachBike", "AcroBike", 
    "Fishing", "Watering", "Decorating", "Underwater"
]

for char, char_upper in [("Brendan", "BRENDAN"), ("May", "MAY")]:
    for state in states:
        state_upper = ""
        if state == "FieldMove": state_upper = "FIELD_MOVE"
        elif state == "Surfing": state_upper = "SURFING"
        elif state == "MachBike": state_upper = "MACH_BIKE"
        elif state == "AcroBike": state_upper = "ACRO_BIKE"
        elif state == "Fishing": state_upper = "FISHING"
        elif state == "Watering": state_upper = "WATERING"
        elif state == "Decorating": state_upper = "DECORATING"
        elif state == "Underwater": state_upper = "UNDERWATER"

        out_str_externs += f"extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RubySapphire{char}{state};\n"
        out_str_pointers += f"    [OBJ_EVENT_GFX_LINK_RS_{char_upper}_{state_upper}] = &gObjectEventGraphicsInfo_RubySapphire{char}{state},\n"

print("EXTERNS:")
print(out_str_externs)
print("POINTERS:")
print(out_str_pointers)
