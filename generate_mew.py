import struct

PID = 0
TID = 20078
SID = 0

species = 151
item = 0
exp = 1250 
pp_bonuses = 0
friendship = 120
unknown = 0
growth_data = struct.pack('<HHIBBH', species, item, exp, pp_bonuses, friendship, unknown)

moves = [1, 144, 0, 0]
pp = [35, 10, 0, 0]
attacks_data = struct.pack('<HHHHBBBB', moves[0], moves[1], moves[2], moves[3], pp[0], pp[1], pp[2], pp[3])

hp_ev = 0
atk_ev = 0
def_ev = 0
spd_ev = 0
spatk_ev = 0
spdef_ev = 0
coolness = 0
beauty = 0
cuteness = 0
smartness = 0
toughness = 0
feel = 0
evs_data = struct.pack('<BBBBBBBBBBBB', hp_ev, atk_ev, def_ev, spd_ev, spatk_ev, spdef_ev, coolness, beauty, cuteness, smartness, toughness, feel)

pokerus = 0
met_location = 0xFF 
origins_info = 10 | (4 << 7) | (4 << 11)
ivs_word = 0 
ribbons_word = 0
misc_data = struct.pack('<BBHII', pokerus, met_location, origins_info, ivs_word, ribbons_word)

secure_data = growth_data + attacks_data + evs_data + misc_data

chk = 0
for i in range(0, 48, 2):
    chk += struct.unpack('<H', secure_data[i:i+2])[0]
chk &= 0xFFFF

nickname = b'\xC1\xBF\xD1\xFF\x00\x00\x00\x00\x00\x00'
ot_name = b'\xBB\xEF\xCC\xBB\xFF\x00\x00'

language_byte = 2
flags_byte = 2
markings_byte = 0
hplost_byte = 0

box_pokemon = struct.pack('<II10sBB7sBHH', PID, TID | (SID << 16), nickname, language_byte, flags_byte, ot_name, markings_byte, chk, hplost_byte) + secure_data

status = 0
level = 10
mail = 0
hp = 40
max_hp = 40
atk = 25
defense = 25
spd = 25
spatk = 25
spdef = 25

battle_data = struct.pack('<IBBHHHHHHH', status, level, mail, hp, max_hp, atk, defense, spd, spatk, spdef)

full_pokemon = box_pokemon + battle_data

print(', '.join([hex(b) for b in full_pokemon]))
