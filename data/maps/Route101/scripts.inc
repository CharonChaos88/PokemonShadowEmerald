# 1 "data/maps/Route101/scripts.pory"

# 2 "data/maps/Route101/scripts.pory"
Route101_MapScripts::
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 4 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 5 "data/maps/Route101/scripts.pory"
	.byte 0
# 6 "data/maps/Route101/scripts.pory"

# 7 "data/maps/Route101/scripts.pory"
Route101_OnTransition:
# 8 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 9 "data/maps/Route101/scripts.pory"
	end
# 10 "data/maps/Route101/scripts.pory"

# 11 "data/maps/Route101/scripts.pory"
Route101_OnFrame:
# 12 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 13 "data/maps/Route101/scripts.pory"
	.2byte 0
# 14 "data/maps/Route101/scripts.pory"

# 15 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 16 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 17 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 18 "data/maps/Route101/scripts.pory"
	end
# 19 "data/maps/Route101/scripts.pory"

# 20 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 21 "data/maps/Route101/scripts.pory"
	lockall
# 22 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 23 "data/maps/Route101/scripts.pory"
	closemessage
# 24 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 25 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 26 "data/maps/Route101/scripts.pory"
	releaseall
# 27 "data/maps/Route101/scripts.pory"
	end
# 28 "data/maps/Route101/scripts.pory"

# 29 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 30 "data/maps/Route101/scripts.pory"
	lockall
# 31 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 32 "data/maps/Route101/scripts.pory"
	closemessage
# 33 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 34 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route101/scripts.pory"
	releaseall
# 36 "data/maps/Route101/scripts.pory"
	end
# 37 "data/maps/Route101/scripts.pory"

# 38 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 39 "data/maps/Route101/scripts.pory"
	lockall
# 40 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 41 "data/maps/Route101/scripts.pory"
	closemessage
# 42 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 43 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route101/scripts.pory"
	releaseall
# 45 "data/maps/Route101/scripts.pory"
	end
# 46 "data/maps/Route101/scripts.pory"

# 47 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 48 "data/maps/Route101/scripts.pory"
	walk_up
# 49 "data/maps/Route101/scripts.pory"
	step_end
# 50 "data/maps/Route101/scripts.pory"

# 51 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 52 "data/maps/Route101/scripts.pory"
	walk_right
# 53 "data/maps/Route101/scripts.pory"
	step_end
# 54 "data/maps/Route101/scripts.pory"

# 55 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 56 "data/maps/Route101/scripts.pory"
	walk_down
# 57 "data/maps/Route101/scripts.pory"
	step_end
# 58 "data/maps/Route101/scripts.pory"

# 59 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 60 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 61 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 62 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 63 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 64 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 65 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 66 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 67 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 68 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 69 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 70 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 71 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 72 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 73 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 74 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 75 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 76 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 77 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 78 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 79 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 80 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 81 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 82 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 83 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 84 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 85 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 86 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 87 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 88 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 89 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 90 "data/maps/Route101/scripts.pory"
	step_end
# 91 "data/maps/Route101/scripts.pory"

# 92 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 93 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 94 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 95 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 96 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 97 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 98 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 99 "data/maps/Route101/scripts.pory"
	step_end
# 100 "data/maps/Route101/scripts.pory"

# 101 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 102 "data/maps/Route101/scripts.pory"
	step_end
# 103 "data/maps/Route101/scripts.pory"

# 104 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 105 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 106 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 107 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 108 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 109 "data/maps/Route101/scripts.pory"
	step_end
# 110 "data/maps/Route101/scripts.pory"

# 111 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 112 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 113 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 116 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 117 "data/maps/Route101/scripts.pory"
	step_end
# 118 "data/maps/Route101/scripts.pory"

# 119 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 120 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 121 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 122 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 123 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 124 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 127 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 128 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 129 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 130 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 131 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 132 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 133 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 134 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 135 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 136 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 137 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 138 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 140 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 141 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 142 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 144 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 146 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 147 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 148 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 150 "data/maps/Route101/scripts.pory"
	step_end
# 151 "data/maps/Route101/scripts.pory"

# 152 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 153 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 154 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 155 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 156 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 159 "data/maps/Route101/scripts.pory"
	step_end
# 160 "data/maps/Route101/scripts.pory"

# 161 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 162 "data/maps/Route101/scripts.pory"
	step_end
# 163 "data/maps/Route101/scripts.pory"

# 164 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 165 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 166 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 167 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 168 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 169 "data/maps/Route101/scripts.pory"
	step_end
# 170 "data/maps/Route101/scripts.pory"

# 171 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 172 "data/maps/Route101/scripts.pory"
	walk_up
# 173 "data/maps/Route101/scripts.pory"
	walk_up
# 174 "data/maps/Route101/scripts.pory"
	step_end
# 175 "data/maps/Route101/scripts.pory"

# 176 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 177 "data/maps/Route101/scripts.pory"
	walk_up
# 178 "data/maps/Route101/scripts.pory"
	walk_left
# 179 "data/maps/Route101/scripts.pory"
	walk_up
# 180 "data/maps/Route101/scripts.pory"
	step_end
# 181 "data/maps/Route101/scripts.pory"

# 182 "data/maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 183 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 184 "data/maps/Route101/scripts.pory"
	end
# 185 "data/maps/Route101/scripts.pory"

# 186 "data/maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 187 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 188 "data/maps/Route101/scripts.pory"
	end
# 189 "data/maps/Route101/scripts.pory"

# 190 "data/maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 191 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 192 "data/maps/Route101/scripts.pory"
	end
# 193 "data/maps/Route101/scripts.pory"

# 194 "data/maps/Route101/scripts.pory"

# 195 "data/maps/Route101/scripts.pory"

# 196 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 197 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 198 "data/maps/Route101/scripts.pory"
	return
# 199 "data/maps/Route101/scripts.pory"

# 200 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 201 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 202 "data/maps/Route101/scripts.pory"
	return
# 203 "data/maps/Route101/scripts.pory"

# 204 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 205 "data/maps/Route101/scripts.pory"
	walk_right
# 206 "data/maps/Route101/scripts.pory"
	step_end
# 207 "data/maps/Route101/scripts.pory"

# 208 "data/maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 209 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"
# 210 "data/maps/Route101/scripts.pory"

# 211 "data/maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 212 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 213 "data/maps/Route101/scripts.pory"
	.string "Please! Help!\p"
# 214 "data/maps/Route101/scripts.pory"
	.string "In my BAG!\n"
# 215 "data/maps/Route101/scripts.pory"
	.string "There's a POKé BALL!$"
# 216 "data/maps/Route101/scripts.pory"

# 217 "data/maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 218 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 219 "data/maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 220 "data/maps/Route101/scripts.pory"

# 221 "data/maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 222 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 223 "data/maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 224 "data/maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 225 "data/maps/Route101/scripts.pory"
	.string "You saved me.\n"
# 226 "data/maps/Route101/scripts.pory"
	.string "Thanks a lot!\p"
# 227 "data/maps/Route101/scripts.pory"
	.string "Oh?\p"
# 228 "data/maps/Route101/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 229 "data/maps/Route101/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 230 "data/maps/Route101/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 231 "data/maps/Route101/scripts.pory"

# 232 "data/maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 233 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 234 "data/maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 235 "data/maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 236 "data/maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 237 "data/maps/Route101/scripts.pory"

# 238 "data/maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 239 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 240 "data/maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 241 "data/maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 242 "data/maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 243 "data/maps/Route101/scripts.pory"

# 244 "data/maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 245 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 246 "data/maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_EventScript_BirchsBag::
# 251 "data/maps/Route101/scripts.pory"
	lock
# 252 "data/maps/Route101/scripts.pory"
	faceplayer
# 253 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 254 "data/maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 255 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 256 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE101_ZIGZAGOON
# 257 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_BIRCHBAG
# 258 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 259 "data/maps/Route101/scripts.pory"
	callnative StartNewPokeballCaseUIForBirchBattle
# 260 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 261 "data/maps/Route101/scripts.pory"
	call AfterZigzagoonBattle
# 262 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 263 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 264 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 265 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 266 "data/maps/Route101/scripts.pory"
	checkplayergender
# 267 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 268 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 269 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_BIRCH_LAB_STATE, 2, Won_or_Caught
# 270 "data/maps/Route101/scripts.pory"
	waitstate
# 271 "data/maps/Route101/scripts.pory"
	release
	end


AfterZigzagoonBattle::
# 276 "data/maps/Route101/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_eq AfterZigzagoonBattle_1
	return

AfterZigzagoonBattle_1:
# 277 "data/maps/Route101/scripts.pory"
	call Won_or_Caught
	return


Won_or_Caught::
# 283 "data/maps/Route101/scripts.pory"
	lockall
# 284 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 285 "data/maps/Route101/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 286 "data/maps/Route101/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 287 "data/maps/Route101/scripts.pory"
	compare VAR_ROUTE101_STATE, 3
	goto_if_eq Won_or_Caught_1
	return

Won_or_Caught_1:
# 288 "data/maps/Route101/scripts.pory"
	msgbox Won_or_Caught_Text_0, MSGBOX_DEFAULT
# 290 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 12
	return


Won_or_Caught_Text_0:
# 288 "data/maps/Route101/scripts.pory"
	.string "I need to talk to professor\n"
	.string "Birch about this virus.$"
