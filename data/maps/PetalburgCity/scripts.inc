# 1 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_MapScripts::
# 2 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
# 3 "data/maps/PetalburgCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
# 4 "data/maps/PetalburgCity/scripts.pory"
	.byte 0
# 5 "data/maps/PetalburgCity/scripts.pory"

# 6 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnTransition:
# 7 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_VISITED_PETALBURG_CITY
# 8 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
# 9 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_DisableMapNameAndMusic
# 10 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_EventScript_SetGymDoorsUnlocked
# 11 "data/maps/PetalburgCity/scripts.pory"
	end
# 12 "data/maps/PetalburgCity/scripts.pory"

# 13 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
# 14 "data/maps/PetalburgCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_BOY, 5, 11
# 15 "data/maps/PetalburgCity/scripts.pory"
	return
# 16 "data/maps/PetalburgCity/scripts.pory"

# 17 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_DisableMapNameAndMusic::
# 18 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 19 "data/maps/PetalburgCity/scripts.pory"
	savebgm MUS_FOLLOW_ME
# 20 "data/maps/PetalburgCity/scripts.pory"
	return
# 21 "data/maps/PetalburgCity/scripts.pory"

# 22 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_SetGymDoorsUnlocked::
# 23 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 24 "data/maps/PetalburgCity/scripts.pory"
	return
# 25 "data/maps/PetalburgCity/scripts.pory"

# 26 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_OnFrame:
# 27 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
# 28 "data/maps/PetalburgCity/scripts.pory"
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
# 29 "data/maps/PetalburgCity/scripts.pory"
	.2byte 0
# 30 "data/maps/PetalburgCity/scripts.pory"

# 31 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyTutorial::
# 32 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 33 "data/maps/PetalburgCity/scripts.pory"
	special SavePlayerParty
# 34 "data/maps/PetalburgCity/scripts.pory"
	special LoadWallyZigzagoon
# 35 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, PetalburgCity_Movement_WallyTutorialWally
# 36 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
# 37 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 38 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
# 39 "data/maps/PetalburgCity/scripts.pory"
	special StartWallyTutorialBattle
# 40 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
# 41 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLY, Common_Movement_WalkInPlaceFasterLeft, MAP_PETALBURG_CITY
# 42 "data/maps/PetalburgCity/scripts.pory"
	waitmovement LOCALID_PETALBURG_WALLY, MAP_PETALBURG_CITY
# 43 "data/maps/PetalburgCity/scripts.pory"
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
# 44 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 45 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 46 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 47 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 48 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 49 "data/maps/PetalburgCity/scripts.pory"
	special LoadPlayerParty
# 50 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 51 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_GYM, 4, 108
# 52 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 53 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 54 "data/maps/PetalburgCity/scripts.pory"
	end
# 55 "data/maps/PetalburgCity/scripts.pory"

# 56 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WalkToWallyHouse::
# 57 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 58 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 59 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
# 60 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
# 61 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 62 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8004, 7
# 63 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8005, 5
# 64 "data/maps/PetalburgCity/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 65 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 66 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
# 67 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
# 68 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 69 "data/maps/PetalburgCity/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 70 "data/maps/PetalburgCity/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
# 71 "data/maps/PetalburgCity/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 72 "data/maps/PetalburgCity/scripts.pory"
	waitdooranim
# 73 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 74 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 75 "data/maps/PetalburgCity/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 76 "data/maps/PetalburgCity/scripts.pory"
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 2, 4
# 77 "data/maps/PetalburgCity/scripts.pory"
	waitstate
# 78 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 79 "data/maps/PetalburgCity/scripts.pory"
	end
# 80 "data/maps/PetalburgCity/scripts.pory"

# 81 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Boy::
# 82 "data/maps/PetalburgCity/scripts.pory"
	lock
# 83 "data/maps/PetalburgCity/scripts.pory"
	faceplayer
# 84 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
# 85 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 86 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
# 87 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 88 "data/maps/PetalburgCity/scripts.pory"
	release
# 89 "data/maps/PetalburgCity/scripts.pory"
	end
# 90 "data/maps/PetalburgCity/scripts.pory"

# 91 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallysMom::
# 92 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
# 93 "data/maps/PetalburgCity/scripts.pory"
	end
# 94 "data/maps/PetalburgCity/scripts.pory"

# 95 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHousePlayer:
# 96 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 97 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 98 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 99 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 100 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 101 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 102 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 103 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 104 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 105 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 106 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 107 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 108 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 109 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 110 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 111 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 112 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 113 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 114 "data/maps/PetalburgCity/scripts.pory"

# 115 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHousePlayer:
# 116 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 117 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 118 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 119 "data/maps/PetalburgCity/scripts.pory"

# 120 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkToWallyHouseWallysDad:
# 121 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 122 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 123 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 124 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 125 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 126 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 127 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 128 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 129 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 130 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 131 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 132 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 133 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 134 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 135 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 136 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 137 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 138 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 139 "data/maps/PetalburgCity/scripts.pory"

# 140 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WalkInsideHouseWallysDad:
# 141 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 142 "data/maps/PetalburgCity/scripts.pory"
	set_invisible
# 143 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 144 "data/maps/PetalburgCity/scripts.pory"

# 145 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialPlayer:
# 146 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 147 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 148 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 149 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 150 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 151 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 152 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 153 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 154 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 155 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 156 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 157 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 158 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 159 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 160 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 161 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 162 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 163 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 164 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 165 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 166 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 167 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 168 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 169 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 170 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 171 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 172 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 173 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 174 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 175 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 176 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 177 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 178 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 179 "data/maps/PetalburgCity/scripts.pory"

# 180 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_WallyTutorialWally:
# 181 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 182 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 183 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 184 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 185 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 186 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 187 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 188 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 189 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 190 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 191 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 192 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 193 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 194 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 195 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 196 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 197 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 198 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 199 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 200 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 201 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 202 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 203 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 204 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 205 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 206 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 207 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 208 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 209 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 210 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 211 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 212 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 213 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 214 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 215 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 216 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_right
# 217 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 218 "data/maps/PetalburgCity/scripts.pory"

# 219 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymSign::
# 220 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
# 221 "data/maps/PetalburgCity/scripts.pory"
	end
# 222 "data/maps/PetalburgCity/scripts.pory"

# 223 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_CitySign::
# 224 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
# 225 "data/maps/PetalburgCity/scripts.pory"
	end
# 226 "data/maps/PetalburgCity/scripts.pory"

# 227 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_Gentleman::
# 228 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
# 229 "data/maps/PetalburgCity/scripts.pory"
	end
# 230 "data/maps/PetalburgCity/scripts.pory"

# 231 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_WallyHouseSign::
# 232 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
# 233 "data/maps/PetalburgCity/scripts.pory"
	end
# 234 "data/maps/PetalburgCity/scripts.pory"

# 235 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer0::
# 236 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 237 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 238 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 239 "data/maps/PetalburgCity/scripts.pory"
	end
# 240 "data/maps/PetalburgCity/scripts.pory"

# 241 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer1::
# 242 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 243 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 244 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 245 "data/maps/PetalburgCity/scripts.pory"
	end
# 246 "data/maps/PetalburgCity/scripts.pory"

# 247 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer2::
# 248 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 249 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 250 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 251 "data/maps/PetalburgCity/scripts.pory"
	end
# 252 "data/maps/PetalburgCity/scripts.pory"

# 253 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer3::
# 254 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 255 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 256 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ShowGymToPlayer
# 257 "data/maps/PetalburgCity/scripts.pory"
	end
# 258 "data/maps/PetalburgCity/scripts.pory"

# 259 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_ShowGymToPlayer::
# 260 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
# 261 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 262 "data/maps/PetalburgCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 263 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 264 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
# 265 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 266 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
# 267 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 268 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_BoyApproachPlayer0
# 269 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_BoyApproachPlayer1
# 270 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_BoyApproachPlayer2
# 271 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_BoyApproachPlayer3
# 272 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
# 273 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 274 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_LeadPlayerToGym0
# 275 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_LeadPlayerToGym1
# 276 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_LeadPlayerToGym2
# 277 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_LeadPlayerToGym3
# 278 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
# 279 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFasterRight
# 280 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 281 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 282 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
# 283 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 284 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
# 285 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 286 "data/maps/PetalburgCity/scripts.pory"
	fadedefaultbgm
# 287 "data/maps/PetalburgCity/scripts.pory"
	releaseall
# 288 "data/maps/PetalburgCity/scripts.pory"
	end
# 289 "data/maps/PetalburgCity/scripts.pory"

# 290 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer0::
# 291 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
# 292 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 293 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 294 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 295 "data/maps/PetalburgCity/scripts.pory"
	return
# 296 "data/maps/PetalburgCity/scripts.pory"

# 297 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer1::
# 298 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
# 299 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 300 "data/maps/PetalburgCity/scripts.pory"
	return
# 301 "data/maps/PetalburgCity/scripts.pory"

# 302 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer2::
# 303 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
# 304 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 305 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 306 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 307 "data/maps/PetalburgCity/scripts.pory"
	return
# 308 "data/maps/PetalburgCity/scripts.pory"

# 309 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_BoyApproachPlayer3::
# 310 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
# 311 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 312 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 313 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 314 "data/maps/PetalburgCity/scripts.pory"
	return
# 315 "data/maps/PetalburgCity/scripts.pory"

# 316 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym0::
# 317 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
# 318 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
# 319 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 320 "data/maps/PetalburgCity/scripts.pory"
	return
# 321 "data/maps/PetalburgCity/scripts.pory"

# 322 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym1::
# 323 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
# 324 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
# 325 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 326 "data/maps/PetalburgCity/scripts.pory"
	return
# 327 "data/maps/PetalburgCity/scripts.pory"

# 328 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym2::
# 329 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
# 330 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
# 331 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 332 "data/maps/PetalburgCity/scripts.pory"
	return
# 333 "data/maps/PetalburgCity/scripts.pory"

# 334 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_LeadPlayerToGym3::
# 335 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
# 336 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
# 337 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 338 "data/maps/PetalburgCity/scripts.pory"
	return
# 339 "data/maps/PetalburgCity/scripts.pory"

# 340 "data/maps/PetalburgCity/scripts.pory"
@ Unused
# 341 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_Delay48::
# 342 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 343 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 344 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 345 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 346 "data/maps/PetalburgCity/scripts.pory"

# 347 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer0:
# 348 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 349 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 350 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 351 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 352 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 353 "data/maps/PetalburgCity/scripts.pory"

# 354 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer1:
# 355 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 356 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 357 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 358 "data/maps/PetalburgCity/scripts.pory"

# 359 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer2:
# 360 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 361 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 362 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 363 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 364 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 365 "data/maps/PetalburgCity/scripts.pory"

# 366 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyApproachPlayer3:
# 367 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 368 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 369 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 370 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 371 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 372 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 373 "data/maps/PetalburgCity/scripts.pory"

# 374 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym0:
# 375 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 376 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 377 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 378 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 379 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 380 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 381 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 382 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 383 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 384 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 385 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 386 "data/maps/PetalburgCity/scripts.pory"

# 387 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym1:
# 388 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 389 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 390 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 391 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 392 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 393 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 394 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 395 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 396 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 397 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 398 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 399 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 400 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 401 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 402 "data/maps/PetalburgCity/scripts.pory"

# 403 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym2:
# 404 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 405 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 406 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 407 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 408 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 409 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 410 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 411 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 412 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 413 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 414 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 415 "data/maps/PetalburgCity/scripts.pory"

# 416 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkToGym3:
# 417 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 418 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 419 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 420 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 421 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 422 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 423 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 424 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 425 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 426 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 427 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 428 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 429 "data/maps/PetalburgCity/scripts.pory"

# 430 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_BoyWalkAway:
# 431 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 432 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 433 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 434 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 435 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 436 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 437 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 438 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 439 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 440 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 441 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 442 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 443 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 444 "data/maps/PetalburgCity/scripts.pory"

# 445 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym0:
# 446 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 447 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 448 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 449 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 450 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 451 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 452 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 453 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 454 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 455 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 456 "data/maps/PetalburgCity/scripts.pory"

# 457 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym1:
# 458 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 459 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 460 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 461 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 462 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 463 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 464 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 465 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 466 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 467 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 468 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 469 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 470 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 471 "data/maps/PetalburgCity/scripts.pory"

# 472 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym2:
# 473 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 474 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 475 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 476 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 477 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 478 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 479 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 480 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 481 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 482 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 483 "data/maps/PetalburgCity/scripts.pory"

# 484 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWalkToGym3:
# 485 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 486 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 487 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 488 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 489 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 490 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 491 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 492 "data/maps/PetalburgCity/scripts.pory"
	walk_right
# 493 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 494 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 495 "data/maps/PetalburgCity/scripts.pory"
	step_end
# 496 "data/maps/PetalburgCity/scripts.pory"

# 497 "data/maps/PetalburgCity/scripts.pory"

# 498 "data/maps/PetalburgCity/scripts.pory"

# 499 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_EventScript_GymBoy::
# 500 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
# 501 "data/maps/PetalburgCity/scripts.pory"
	end
# 502 "data/maps/PetalburgCity/scripts.pory"

# 503 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WhereIsWally:
# 504 "data/maps/PetalburgCity/scripts.pory"
	.string "Where has our WALLY gone?\p"
# 505 "data/maps/PetalburgCity/scripts.pory"
	.string "We have to leave for VERDANTURF TOWN\n"
# 506 "data/maps/PetalburgCity/scripts.pory"
	.string "very soon…$"
# 507 "data/maps/PetalburgCity/scripts.pory"

# 508 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_AreYouRookieTrainer:
# 509 "data/maps/PetalburgCity/scripts.pory"
	.string "Hiya! Are you maybe…\n"
# 510 "data/maps/PetalburgCity/scripts.pory"
	.string "A rookie TRAINER?\p"
# 511 "data/maps/PetalburgCity/scripts.pory"
	.string "Do you know what POKéMON TRAINERS\n"
# 512 "data/maps/PetalburgCity/scripts.pory"
	.string "do when they reach a new town?\p"
# 513 "data/maps/PetalburgCity/scripts.pory"
	.string "They first check what kind of GYM\n"
# 514 "data/maps/PetalburgCity/scripts.pory"
	.string "is in the town.$"
# 515 "data/maps/PetalburgCity/scripts.pory"

# 516 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsPetalburgGym:
# 517 "data/maps/PetalburgCity/scripts.pory"
	.string "See? This is PETALBURG CITY's GYM.$"
# 518 "data/maps/PetalburgCity/scripts.pory"

# 519 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_ThisIsGymSign:
# 520 "data/maps/PetalburgCity/scripts.pory"
	.string "This is the GYM's sign. Look for it\n"
# 521 "data/maps/PetalburgCity/scripts.pory"
	.string "whenever you're looking for a GYM.$"
# 522 "data/maps/PetalburgCity/scripts.pory"

# 523 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WaterReflection:
# 524 "data/maps/PetalburgCity/scripts.pory"
	.string "My face is reflected in the water.\p"
# 525 "data/maps/PetalburgCity/scripts.pory"
	.string "It's a shining grin full of hope…\p"
# 526 "data/maps/PetalburgCity/scripts.pory"
	.string "Or it could be a look of somber silence\n"
# 527 "data/maps/PetalburgCity/scripts.pory"
	.string "struggling with fear…\p"
# 528 "data/maps/PetalburgCity/scripts.pory"
	.string "What do you see reflected in your face?$"
# 529 "data/maps/PetalburgCity/scripts.pory"

# 530 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_FullPartyExplanation:
# 531 "data/maps/PetalburgCity/scripts.pory"
	.string "Let's say you have six POKéMON.\n"
# 532 "data/maps/PetalburgCity/scripts.pory"
	.string "If you catch another one…\p"
# 533 "data/maps/PetalburgCity/scripts.pory"
	.string "It is automatically sent to a STORAGE\n"
# 534 "data/maps/PetalburgCity/scripts.pory"
	.string "BOX over a PC connection.$"
# 535 "data/maps/PetalburgCity/scripts.pory"

# 536 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_GymSign:
# 537 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\n"
# 538 "data/maps/PetalburgCity/scripts.pory"
	.string "LEADER: NORMAN\l"
# 539 "data/maps/PetalburgCity/scripts.pory"
	.string "“A man in pursuit of power!”$"
# 540 "data/maps/PetalburgCity/scripts.pory"

# 541 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_CitySign:
# 542 "data/maps/PetalburgCity/scripts.pory"
	.string "PETALBURG CITY\n"
# 543 "data/maps/PetalburgCity/scripts.pory"
	.string "“Where people mingle with nature.”$"
# 544 "data/maps/PetalburgCity/scripts.pory"

# 545 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Text_WallyHouseSign:
# 546 "data/maps/PetalburgCity/scripts.pory"
	.string "WALLY'S HOUSE$"

PetalburgCity_EventScript_Scott0::
# 551 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 552 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 553 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 0
# 554 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 10
# 555 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
	end


PetalburgCity_EventScript_Scott1::
# 560 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 561 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 562 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 1
# 563 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 11
# 564 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
	end


PetalburgCity_EventScript_Scott2::
# 569 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 570 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 571 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 2
# 572 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 12
# 573 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
	end


PetalburgCity_EventScript_Scott3::
# 578 "data/maps/PetalburgCity/scripts.pory"
	lockall
# 579 "data/maps/PetalburgCity/scripts.pory"
	addobject LOCALID_PETALBURG_SCOTT
# 580 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_0x8008, 3
# 581 "data/maps/PetalburgCity/scripts.pory"
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 13
# 582 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_Scott
	end


PetalburgCity_EventScript_Scott::
# 587 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
# 588 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 589 "data/maps/PetalburgCity/scripts.pory"
	playse SE_PIN
# 590 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_ExclamationMark
# 591 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 592 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_Delay48
# 593 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 594 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
# 595 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 597 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 598 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_STATE, 1
# 599 "data/maps/PetalburgCity/scripts.pory"
	setspeaker SP_NAME_UNKNOWN
# 600 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_EventScript_Scott_Text_0
# 601 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 602 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 603 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 604 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 605 "data/maps/PetalburgCity/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 606 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_EventScript_Scott_Text_1
# 607 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 608 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 609 "data/maps/PetalburgCity/scripts.pory"
	setspeaker SP_NAME_UNKNOWN
# 610 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_EventScript_Scott_Text_2
# 611 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 612 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 613 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
# 614 "data/maps/PetalburgCity/scripts.pory"
	delay 30
# 615 "data/maps/PetalburgCity/scripts.pory"
	setspeaker SP_NAME_UNKNOWN
# 616 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_EventScript_Scott_Text_3
# 617 "data/maps/PetalburgCity/scripts.pory"
	closemessage
# 618 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_ScottExit0
# 619 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_ScottExit1
# 620 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_ScottExit2
# 621 "data/maps/PetalburgCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_ScottExit3
# 622 "data/maps/PetalburgCity/scripts.pory"
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
# 623 "data/maps/PetalburgCity/scripts.pory"
	removeobject LOCALID_PETALBURG_SCOTT
# 624 "data/maps/PetalburgCity/scripts.pory"
	goto PetalburgCity_EventScript_ScottEnd
	return


PetalburgCity_EventScript_ScottEnd::
# 627 "data/maps/PetalburgCity/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 628 "data/maps/PetalburgCity/scripts.pory"
	msgbox PetalburgCity_EventScript_ScottEnd_Text_0
# 629 "data/maps/PetalburgCity/scripts.pory"
	release
	end


PetalburgCity_EventScript_ScottExit0::
# 634 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
# 635 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit0
# 636 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
	return


PetalburgCity_EventScript_ScottExit1::
# 640 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
# 641 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit1
# 642 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
	return


PetalburgCity_EventScript_ScottExit2::
# 647 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
# 648 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit2
# 649 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
	return


PetalburgCity_EventScript_ScottExit3::
# 653 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
# 654 "data/maps/PetalburgCity/scripts.pory"
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit3
# 655 "data/maps/PetalburgCity/scripts.pory"
	waitmovement 0
	return


# 659 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottStartWalkLeft:
# 660 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 661 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 662 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 663 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 664 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 666 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottApproachPlayer:
# 667 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 668 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 669 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 670 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 671 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 673 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit0:
# 674 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 675 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 676 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 677 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 678 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 679 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 680 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 681 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 682 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 683 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 684 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 685 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 686 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 687 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 690 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit0:
# 691 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 692 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 693 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 694 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 695 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 696 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 697 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 699 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit1:
# 700 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 701 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 702 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 703 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 704 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 705 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 706 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 707 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 708 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 709 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 710 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 711 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 712 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 715 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit1:
# 716 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 717 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 718 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 719 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 720 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 721 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 724 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit2:
# 725 "data/maps/PetalburgCity/scripts.pory"
	walk_down
# 726 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 727 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 728 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 729 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 730 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 731 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 732 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 733 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 734 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 735 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 736 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 737 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 740 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit2:
# 741 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 742 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_down
# 743 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 744 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 745 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 746 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 748 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_ScottExit3:
# 749 "data/maps/PetalburgCity/scripts.pory"
	walk_up
# 750 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 751 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 752 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 753 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 754 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 755 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 756 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 757 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 758 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 759 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 760 "data/maps/PetalburgCity/scripts.pory"
	walk_left
# 761 "data/maps/PetalburgCity/scripts.pory"
	step_end

# 763 "data/maps/PetalburgCity/scripts.pory"
PetalburgCity_Movement_PlayerWatchScottExit3:
# 764 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 765 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_up
# 766 "data/maps/PetalburgCity/scripts.pory"
	delay_16
# 767 "data/maps/PetalburgCity/scripts.pory"
	delay_8
# 768 "data/maps/PetalburgCity/scripts.pory"
	walk_in_place_faster_left
# 769 "data/maps/PetalburgCity/scripts.pory"
	step_end

PetalburgCity_EventScript_Scott_Text_0:
# 600 "data/maps/PetalburgCity/scripts.pory"
	.string "Hm... You look pretty clean for a Team\n"
	.string "Magma grunt.$"

PetalburgCity_EventScript_Scott_Text_1:
# 606 "data/maps/PetalburgCity/scripts.pory"
	.string "Yeah, what's your point?$"

PetalburgCity_EventScript_Scott_Text_2:
# 610 "data/maps/PetalburgCity/scripts.pory"
	.string "Your uniform is a bit too clean for a\n"
	.string "Team Magma grunt. I think you might\l"
	.string "just joined Team Magma recently.$"

PetalburgCity_EventScript_Scott_Text_3:
# 616 "data/maps/PetalburgCity/scripts.pory"
	.string "I was just wondering if you were a\n"
	.string "Pokémon Trainer. I was hoping to find\l"
	.string "some talented trainers. However, it\l"
	.string "looks like I am wasting my time here. I\l"
	.string "will be on my way now.$"

PetalburgCity_EventScript_ScottEnd_Text_0:
# 628 "data/maps/PetalburgCity/scripts.pory"
	.string "What a weirdo...$"
