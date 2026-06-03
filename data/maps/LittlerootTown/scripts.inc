# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 3 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 4 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 5 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 6 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown/scripts.pory"

# 8 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 9 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 10 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 11 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 12 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 13 "data/maps/LittlerootTown/scripts.pory"

# 14 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 18 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 19 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 22 "data/maps/LittlerootTown/scripts.pory"

# 23 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 24 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 27 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 28 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 29 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 30 "data/maps/LittlerootTown/scripts.pory"

# 31 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 35 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 36 "data/maps/LittlerootTown/scripts.pory"

# 37 "data/maps/LittlerootTown/scripts.pory"

# 38 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 39 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 40 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 41 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 42 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 43 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 44 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 45 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 50 "data/maps/LittlerootTown/scripts.pory"
	end
# 51 "data/maps/LittlerootTown/scripts.pory"

# 52 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 53 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 54 "data/maps/LittlerootTown/scripts.pory"
	return
# 55 "data/maps/LittlerootTown/scripts.pory"

# 56 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 57 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 58 "data/maps/LittlerootTown/scripts.pory"
	return
# 59 "data/maps/LittlerootTown/scripts.pory"

# 60 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 61 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 62 "data/maps/LittlerootTown/scripts.pory"
	return
# 63 "data/maps/LittlerootTown/scripts.pory"

# 64 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 65 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 66 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 67 "data/maps/LittlerootTown/scripts.pory"
	return
# 68 "data/maps/LittlerootTown/scripts.pory"

# 69 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 71 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 72 "data/maps/LittlerootTown/scripts.pory"
	return
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 75 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
# 76 "data/maps/LittlerootTown/scripts.pory"
	return
# 77 "data/maps/LittlerootTown/scripts.pory"

# 78 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 79 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 80 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
# 81 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
# 82 "data/maps/LittlerootTown/scripts.pory"
	return
# 83 "data/maps/LittlerootTown/scripts.pory"

# 84 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 85 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
# 86 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 87 "data/maps/LittlerootTown/scripts.pory"
	return
# 88 "data/maps/LittlerootTown/scripts.pory"

# 89 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 90 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 91 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
# 92 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 93 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 94 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 95 "data/maps/LittlerootTown/scripts.pory"
	return
# 96 "data/maps/LittlerootTown/scripts.pory"

# 97 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 98 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
# 99 "data/maps/LittlerootTown/scripts.pory"
	return
# 100 "data/maps/LittlerootTown/scripts.pory"

# 101 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 102 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
# 103 "data/maps/LittlerootTown/scripts.pory"
	return
# 104 "data/maps/LittlerootTown/scripts.pory"

# 105 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 106 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 107 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 108 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 109 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 110 "data/maps/LittlerootTown/scripts.pory"

# 111 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 112 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 113 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 114 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 115 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 116 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 117 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 118 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 119 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 120 "data/maps/LittlerootTown/scripts.pory"
	end
# 121 "data/maps/LittlerootTown/scripts.pory"

# 122 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 123 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 124 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 125 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 126 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 127 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 128 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 129 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 130 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 131 "data/maps/LittlerootTown/scripts.pory"
	end
# 132 "data/maps/LittlerootTown/scripts.pory"

# 133 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 134 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 135 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 136 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 137 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 138 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 139 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 140 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_MOM
# 141 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitHouse
# 142 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 143 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 144 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 145 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 146 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 147 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 149 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 150 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachDoor
# 151 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 152 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 154 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 155 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomEnterHouse
# 156 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 157 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 159 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 160 "data/maps/LittlerootTown/scripts.pory"
	hideplayer
# 161 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 162 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 163 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 164 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 165 "data/maps/LittlerootTown/scripts.pory"
	return
# 166 "data/maps/LittlerootTown/scripts.pory"

# 167 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 168 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 169 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 170 "data/maps/LittlerootTown/scripts.pory"

# 171 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 172 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 173 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 174 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 175 "data/maps/LittlerootTown/scripts.pory"

# 176 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 177 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 178 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 179 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 180 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 181 "data/maps/LittlerootTown/scripts.pory"

# 182 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 183 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 184 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 185 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 186 "data/maps/LittlerootTown/scripts.pory"

# 187 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 188 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 189 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 190 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 191 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 192 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 193 "data/maps/LittlerootTown/scripts.pory"

# 194 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 195 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 197 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 198 "data/maps/LittlerootTown/scripts.pory"

# 199 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 200 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 201 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 202 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 203 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 204 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 205 "data/maps/LittlerootTown/scripts.pory"

# 206 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 207 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 208 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 209 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
# 210 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 211 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 212 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 213 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 214 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 215 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 216 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 217 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 218 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 219 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 220 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 221 "data/maps/LittlerootTown/scripts.pory"
	end
# 222 "data/maps/LittlerootTown/scripts.pory"

# 223 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 224 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 225 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 226 "data/maps/LittlerootTown/scripts.pory"

# 227 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 228 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_BIRCH
# 229 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_LITTLEROOT_RIVAL
# 230 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 231 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 232 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 233 "data/maps/LittlerootTown/scripts.pory"
	end
# 234 "data/maps/LittlerootTown/scripts.pory"

# 235 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 236 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
# 237 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
# 238 "data/maps/LittlerootTown/scripts.pory"
	end
# 239 "data/maps/LittlerootTown/scripts.pory"

# 240 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 241 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
# 242 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
# 243 "data/maps/LittlerootTown/scripts.pory"
	end
# 244 "data/maps/LittlerootTown/scripts.pory"

# 245 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 246 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 247 "data/maps/LittlerootTown/scripts.pory"
	end
# 248 "data/maps/LittlerootTown/scripts.pory"

# 249 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 250 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 251 "data/maps/LittlerootTown/scripts.pory"
	end
# 252 "data/maps/LittlerootTown/scripts.pory"

# 253 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 254 "data/maps/LittlerootTown/scripts.pory"
	lock
# 255 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 256 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 257 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 258 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 259 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 260 "data/maps/LittlerootTown/scripts.pory"
	release
# 261 "data/maps/LittlerootTown/scripts.pory"
	end
# 262 "data/maps/LittlerootTown/scripts.pory"

# 263 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 264 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 265 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 266 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 267 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 268 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 269 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 270 "data/maps/LittlerootTown/scripts.pory"
	release
# 271 "data/maps/LittlerootTown/scripts.pory"
	end
# 272 "data/maps/LittlerootTown/scripts.pory"

# 273 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 274 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 275 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 276 "data/maps/LittlerootTown/scripts.pory"
	release
# 277 "data/maps/LittlerootTown/scripts.pory"
	end
# 278 "data/maps/LittlerootTown/scripts.pory"

# 279 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 280 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 281 "data/maps/LittlerootTown/scripts.pory"
	release
# 282 "data/maps/LittlerootTown/scripts.pory"
	end
# 283 "data/maps/LittlerootTown/scripts.pory"

# 284 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 285 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 286 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 287 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 288 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 289 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 290 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 291 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 292 "data/maps/LittlerootTown/scripts.pory"
	end
# 293 "data/maps/LittlerootTown/scripts.pory"

# 294 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 295 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 296 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 297 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 298 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 299 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 300 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 301 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 302 "data/maps/LittlerootTown/scripts.pory"
	return
# 303 "data/maps/LittlerootTown/scripts.pory"

# 304 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 305 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 306 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 307 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 308 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 309 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 310 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 311 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 312 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 313 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 317 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 318 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 319 "data/maps/LittlerootTown/scripts.pory"

# 320 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 322 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 323 "data/maps/LittlerootTown/scripts.pory"

# 324 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 325 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 326 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 327 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 328 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 329 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 334 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 335 "data/maps/LittlerootTown/scripts.pory"

# 336 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 337 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 339 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 340 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 341 "data/maps/LittlerootTown/scripts.pory"

# 342 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 343 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 344 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 345 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 346 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 347 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
# 348 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 349 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 350 "data/maps/LittlerootTown/scripts.pory"
	end
# 351 "data/maps/LittlerootTown/scripts.pory"

# 352 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 353 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 354 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 355 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 356 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 357 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 358 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 359 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 360 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 361 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 362 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 363 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 364 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 365 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 366 "data/maps/LittlerootTown/scripts.pory"

# 367 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 368 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 369 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 370 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 371 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 372 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 373 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 374 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 375 "data/maps/LittlerootTown/scripts.pory"

# 376 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 377 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 378 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
# 379 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 380 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 381 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 383 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 384 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 385 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
# 386 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 387 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 388 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 389 "data/maps/LittlerootTown/scripts.pory"
	end
# 390 "data/maps/LittlerootTown/scripts.pory"

# 391 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 392 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 393 "data/maps/LittlerootTown/scripts.pory"
	end
# 394 "data/maps/LittlerootTown/scripts.pory"

# 395 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 396 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 397 "data/maps/LittlerootTown/scripts.pory"
	end
# 398 "data/maps/LittlerootTown/scripts.pory"

# 399 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 400 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 401 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 402 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 403 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 404 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 405 "data/maps/LittlerootTown/scripts.pory"
	end
# 406 "data/maps/LittlerootTown/scripts.pory"

# 407 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 408 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 409 "data/maps/LittlerootTown/scripts.pory"
	return
# 410 "data/maps/LittlerootTown/scripts.pory"

# 411 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 412 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 413 "data/maps/LittlerootTown/scripts.pory"
	return
# 414 "data/maps/LittlerootTown/scripts.pory"

# 415 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 416 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 417 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 418 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 419 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 420 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 421 "data/maps/LittlerootTown/scripts.pory"
	end
# 422 "data/maps/LittlerootTown/scripts.pory"

# 423 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 424 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 425 "data/maps/LittlerootTown/scripts.pory"
	return
# 426 "data/maps/LittlerootTown/scripts.pory"

# 427 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 428 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 429 "data/maps/LittlerootTown/scripts.pory"
	return
# 430 "data/maps/LittlerootTown/scripts.pory"

# 431 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 432 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 433 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 434 "data/maps/LittlerootTown/scripts.pory"
	return
# 435 "data/maps/LittlerootTown/scripts.pory"

# 436 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 437 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 438 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 439 "data/maps/LittlerootTown/scripts.pory"
	return
# 440 "data/maps/LittlerootTown/scripts.pory"

# 441 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 442 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
# 443 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 444 "data/maps/LittlerootTown/scripts.pory"
	return
# 445 "data/maps/LittlerootTown/scripts.pory"

# 446 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 447 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
# 448 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 449 "data/maps/LittlerootTown/scripts.pory"
	return
# 450 "data/maps/LittlerootTown/scripts.pory"

# 451 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 452 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 453 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 454 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 455 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 456 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 457 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 458 "data/maps/LittlerootTown/scripts.pory"
	return
# 459 "data/maps/LittlerootTown/scripts.pory"

# 460 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 461 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 462 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 463 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 464 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 465 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 466 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 467 "data/maps/LittlerootTown/scripts.pory"
	return
# 468 "data/maps/LittlerootTown/scripts.pory"

# 469 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 470 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 471 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 472 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 473 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 474 "data/maps/LittlerootTown/scripts.pory"
	return
# 475 "data/maps/LittlerootTown/scripts.pory"

# 476 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 477 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 478 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 479 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 480 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 481 "data/maps/LittlerootTown/scripts.pory"
	return
# 482 "data/maps/LittlerootTown/scripts.pory"

# 483 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 484 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 485 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 486 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 487 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 488 "data/maps/LittlerootTown/scripts.pory"
	return
# 489 "data/maps/LittlerootTown/scripts.pory"

# 490 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 491 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 492 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 493 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 494 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 495 "data/maps/LittlerootTown/scripts.pory"
	return
# 496 "data/maps/LittlerootTown/scripts.pory"

# 497 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 498 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 499 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 500 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 501 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 502 "data/maps/LittlerootTown/scripts.pory"
	return
# 503 "data/maps/LittlerootTown/scripts.pory"

# 504 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 505 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 506 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 507 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 508 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 509 "data/maps/LittlerootTown/scripts.pory"
	return
# 510 "data/maps/LittlerootTown/scripts.pory"

# 511 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 512 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 513 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 514 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 515 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 516 "data/maps/LittlerootTown/scripts.pory"
	return
# 517 "data/maps/LittlerootTown/scripts.pory"

# 518 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 519 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 520 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 521 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 522 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 523 "data/maps/LittlerootTown/scripts.pory"
	return
# 524 "data/maps/LittlerootTown/scripts.pory"

# 525 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 526 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 527 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 528 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 529 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 530 "data/maps/LittlerootTown/scripts.pory"
	return
# 531 "data/maps/LittlerootTown/scripts.pory"

# 532 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 533 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 534 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 535 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 536 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 537 "data/maps/LittlerootTown/scripts.pory"
	return
# 538 "data/maps/LittlerootTown/scripts.pory"

# 539 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 540 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 541 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 542 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 543 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 544 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 545 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 546 "data/maps/LittlerootTown/scripts.pory"
	return
# 547 "data/maps/LittlerootTown/scripts.pory"

# 548 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 549 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 550 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 551 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 552 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 553 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 554 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 555 "data/maps/LittlerootTown/scripts.pory"
	return
# 556 "data/maps/LittlerootTown/scripts.pory"

# 557 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 558 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
# 559 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 560 "data/maps/LittlerootTown/scripts.pory"
	return
# 561 "data/maps/LittlerootTown/scripts.pory"

# 562 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 563 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
# 564 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 565 "data/maps/LittlerootTown/scripts.pory"
	return
# 566 "data/maps/LittlerootTown/scripts.pory"

# 567 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 568 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 569 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 570 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 571 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 572 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 573 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 574 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 575 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 576 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 577 "data/maps/LittlerootTown/scripts.pory"
	return
# 578 "data/maps/LittlerootTown/scripts.pory"

# 579 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 580 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 581 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 582 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 583 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 584 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 585 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 586 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 587 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 588 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 589 "data/maps/LittlerootTown/scripts.pory"
	return
# 590 "data/maps/LittlerootTown/scripts.pory"

# 591 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 592 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 593 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 594 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 595 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 596 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 597 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 598 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 599 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 600 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 601 "data/maps/LittlerootTown/scripts.pory"
	return
# 602 "data/maps/LittlerootTown/scripts.pory"

# 603 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 604 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 605 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 606 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 608 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 609 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 610 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 611 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 612 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 613 "data/maps/LittlerootTown/scripts.pory"
	return
# 614 "data/maps/LittlerootTown/scripts.pory"

# 615 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 616 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 617 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 618 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 619 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 623 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 624 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 625 "data/maps/LittlerootTown/scripts.pory"
	return
# 626 "data/maps/LittlerootTown/scripts.pory"

# 627 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 628 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 629 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 630 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 632 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 634 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 635 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 636 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 637 "data/maps/LittlerootTown/scripts.pory"
	return
# 638 "data/maps/LittlerootTown/scripts.pory"

# 639 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 640 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 641 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 642 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 644 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 645 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 646 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 647 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 648 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 649 "data/maps/LittlerootTown/scripts.pory"
	return
# 650 "data/maps/LittlerootTown/scripts.pory"

# 651 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 652 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 653 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 654 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 656 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 657 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 658 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 659 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 660 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 661 "data/maps/LittlerootTown/scripts.pory"
	return
# 662 "data/maps/LittlerootTown/scripts.pory"

# 663 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 664 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 665 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 666 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 667 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 668 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 669 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 670 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 671 "data/maps/LittlerootTown/scripts.pory"

# 672 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 673 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 674 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 675 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 676 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 677 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 678 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 679 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 680 "data/maps/LittlerootTown/scripts.pory"

# 681 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 682 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 683 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 684 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 685 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 686 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 687 "data/maps/LittlerootTown/scripts.pory"

# 688 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 689 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 690 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 691 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 692 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 693 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 694 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 695 "data/maps/LittlerootTown/scripts.pory"

# 696 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 697 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 698 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 699 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 700 "data/maps/LittlerootTown/scripts.pory"

# 701 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 702 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 703 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 704 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 705 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 706 "data/maps/LittlerootTown/scripts.pory"

# 707 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 708 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 709 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 710 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 711 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 712 "data/maps/LittlerootTown/scripts.pory"

# 713 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 714 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 715 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 716 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 717 "data/maps/LittlerootTown/scripts.pory"

# 718 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 719 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 720 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 721 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 722 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 723 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 724 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 725 "data/maps/LittlerootTown/scripts.pory"

# 726 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 727 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 728 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 729 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 730 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 731 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 732 "data/maps/LittlerootTown/scripts.pory"

# 733 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 734 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 735 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 736 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 737 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 738 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 739 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 740 "data/maps/LittlerootTown/scripts.pory"

# 741 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 742 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 743 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 744 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 745 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 746 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 747 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 748 "data/maps/LittlerootTown/scripts.pory"

# 749 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 750 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 755 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 756 "data/maps/LittlerootTown/scripts.pory"

# 757 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 758 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 759 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 762 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 763 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 764 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 765 "data/maps/LittlerootTown/scripts.pory"

# 766 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 767 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 768 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 769 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 770 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 771 "data/maps/LittlerootTown/scripts.pory"

# 772 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 773 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 774 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 775 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 777 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 778 "data/maps/LittlerootTown/scripts.pory"

# 779 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 783 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 784 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 785 "data/maps/LittlerootTown/scripts.pory"

# 786 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 790 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 791 "data/maps/LittlerootTown/scripts.pory"

# 792 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 793 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 794 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 797 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 798 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 799 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 800 "data/maps/LittlerootTown/scripts.pory"

# 801 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 802 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 803 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 805 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 807 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 808 "data/maps/LittlerootTown/scripts.pory"

# 809 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 810 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 811 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 812 "data/maps/LittlerootTown/scripts.pory"

# 813 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 814 "data/maps/LittlerootTown/scripts.pory"
	lock
# 815 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 816 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 817 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 818 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 819 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 820 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
# 821 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 822 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 823 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 824 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 825 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 826 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
# 827 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 828 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 829 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 830 "data/maps/LittlerootTown/scripts.pory"
	end
# 831 "data/maps/LittlerootTown/scripts.pory"

# 832 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 833 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_LITTLEROOT_MOM
# 834 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 835 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 836 "data/maps/LittlerootTown/scripts.pory"
	release
# 837 "data/maps/LittlerootTown/scripts.pory"
	end
# 838 "data/maps/LittlerootTown/scripts.pory"

# 839 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 840 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 841 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 842 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 843 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 844 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 845 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 846 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 847 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 848 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 849 "data/maps/LittlerootTown/scripts.pory"
	return
# 850 "data/maps/LittlerootTown/scripts.pory"

# 851 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 852 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 853 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 854 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 855 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 856 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 857 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 858 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 859 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 860 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 861 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 862 "data/maps/LittlerootTown/scripts.pory"

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 864 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 865 "data/maps/LittlerootTown/scripts.pory"

# 866 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 867 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 868 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 869 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 870 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 871 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 872 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 873 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 874 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 875 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 876 "data/maps/LittlerootTown/scripts.pory"

# 877 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 878 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 879 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 880 "data/maps/LittlerootTown/scripts.pory"

# 881 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 882 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 883 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 884 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 885 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 886 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 887 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 888 "data/maps/LittlerootTown/scripts.pory"

# 889 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 890 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 891 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 892 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 893 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 894 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 895 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 896 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 897 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 898 "data/maps/LittlerootTown/scripts.pory"

# 899 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 900 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 901 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 902 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 903 "data/maps/LittlerootTown/scripts.pory"

# 904 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 905 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 906 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 907 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 908 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 909 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 910 "data/maps/LittlerootTown/scripts.pory"

# 911 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 912 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 913 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 914 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 915 "data/maps/LittlerootTown/scripts.pory"

# 916 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 918 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 919 "data/maps/LittlerootTown/scripts.pory"

# 920 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 921 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 922 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 923 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 924 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 925 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 926 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 927 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 928 "data/maps/LittlerootTown/scripts.pory"

# 929 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 930 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 932 "data/maps/LittlerootTown/scripts.pory"

# 933 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 934 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 935 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 936 "data/maps/LittlerootTown/scripts.pory"

# 937 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 938 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 939 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 940 "data/maps/LittlerootTown/scripts.pory"

# 941 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 942 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 943 "data/maps/LittlerootTown/scripts.pory"

# 944 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 946 "data/maps/LittlerootTown/scripts.pory"

# 947 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 949 "data/maps/LittlerootTown/scripts.pory"

# 950 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 951 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 955 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 956 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 959 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

ItemUse_Jukebox::
# 964 "data/maps/LittlerootTown/scripts.pory"
	lock
# 965 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 966 "data/maps/LittlerootTown/scripts.pory"
	message ItemUse_Jukebox_Text_0
# 967 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 970 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush ItemUse_Jukebox_Text_1, 0
# 971 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush ItemUse_Jukebox_Text_2, 1
# 972 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush ItemUse_Jukebox_Text_3, 2
# 975 "data/maps/LittlerootTown/scripts.pory"
	dynmultistack 17, 0, FALSE, 3, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 977 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ItemUse_Jukebox_1
# 980 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ItemUse_Jukebox_2
# 983 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq ItemUse_Jukebox_3
# 987 "data/maps/LittlerootTown/scripts.pory"
	goto Jukebox_Exit
	return

ItemUse_Jukebox_1:
# 978 "data/maps/LittlerootTown/scripts.pory"
	goto Jukebox_MapMenu
	return

ItemUse_Jukebox_2:
# 981 "data/maps/LittlerootTown/scripts.pory"
	goto Jukebox_BattleMenu
	return

ItemUse_Jukebox_3:
# 984 "data/maps/LittlerootTown/scripts.pory"
	goto Jukebox_ResetDefaults
	return


Jukebox_MapMenu::
# 992 "data/maps/LittlerootTown/scripts.pory"
	message Jukebox_MapMenu_Text_0
# 993 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 996 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_1, 0
# 997 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_2, 1
# 998 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_3, 2
# 999 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_4, 3
# 1000 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_5, 4
# 1001 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_6, 5
# 1002 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_7, 6
# 1003 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_8, 7
# 1004 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_9, 8
# 1005 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_10, 9
# 1006 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_11, 10
# 1007 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_12, 11
# 1008 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_13, 12
# 1009 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_14, 13
# 1010 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_15, 14
# 1011 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_16, 15
# 1012 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_17, 16
# 1013 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_18, 17
# 1014 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_19, 18
# 1015 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_20, 19
# 1016 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_21, 20
# 1017 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_22, 21
# 1018 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_23, 22
# 1019 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_24, 23
# 1020 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_25, 24
# 1021 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_26, 25
# 1022 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_27, 26
# 1023 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_28, 27
# 1024 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_29, 28
# 1025 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_30, 29
# 1026 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_31, 30
# 1027 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_32, 31
# 1028 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_33, 32
# 1029 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_34, 33
# 1030 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_35, 34
# 1031 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_36, 35
# 1032 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_37, 36
# 1033 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_38, 37
# 1034 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_39, 38
# 1035 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_40, 39
# 1036 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_41, 40
# 1037 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_42, 41
# 1038 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_43, 42
# 1039 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_44, 43
# 1040 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_45, 44
# 1041 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_46, 45
# 1042 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_47, 46
# 1043 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_48, 47
# 1044 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_49, 48
# 1045 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_50, 49
# 1046 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_51, 50
# 1047 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_52, 51
# 1048 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_53, 52
# 1049 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_54, 53
# 1050 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_55, 54
# 1051 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_56, 55
# 1052 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_57, 56
# 1053 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_58, 57
# 1054 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_59, 58
# 1055 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_60, 59
# 1056 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_61, 60
# 1057 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_62, 61
# 1058 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_63, 62
# 1061 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_64, 63
# 1062 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_65, 64
# 1063 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_66, 65
# 1064 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_67, 66
# 1065 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_68, 67
# 1066 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_69, 68
# 1067 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_70, 69
# 1068 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_71, 70
# 1069 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_72, 71
# 1070 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_73, 72
# 1071 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_74, 73
# 1072 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_75, 74
# 1073 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_76, 75
# 1074 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_77, 76
# 1075 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_78, 77
# 1076 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_79, 78
# 1077 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_80, 79
# 1078 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_81, 80
# 1079 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_82, 81
# 1080 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_83, 82
# 1081 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_84, 83
# 1082 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_85, 84
# 1083 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_86, 85
# 1084 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_87, 86
# 1085 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_88, 87
# 1086 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_89, 88
# 1087 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_90, 89
# 1088 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_91, 90
# 1089 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_92, 91
# 1090 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_93, 92
# 1091 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_94, 93
# 1092 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_95, 94
# 1093 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_MapMenu_Text_96, 95
# 1096 "data/maps/LittlerootTown/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1098 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq Jukebox_MapMenu_2
Jukebox_MapMenu_1:
# 1103 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Jukebox_MapMenu_5
# 1104 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Jukebox_MapMenu_6
# 1105 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Jukebox_MapMenu_7
# 1106 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq Jukebox_MapMenu_8
# 1107 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq Jukebox_MapMenu_9
# 1108 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq Jukebox_MapMenu_10
# 1109 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq Jukebox_MapMenu_11
# 1110 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq Jukebox_MapMenu_12
# 1111 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq Jukebox_MapMenu_13
# 1112 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq Jukebox_MapMenu_14
# 1113 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq Jukebox_MapMenu_15
# 1114 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq Jukebox_MapMenu_16
# 1115 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq Jukebox_MapMenu_17
# 1116 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq Jukebox_MapMenu_18
# 1117 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq Jukebox_MapMenu_19
# 1118 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq Jukebox_MapMenu_20
# 1119 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq Jukebox_MapMenu_21
# 1120 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq Jukebox_MapMenu_22
# 1121 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq Jukebox_MapMenu_23
# 1122 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq Jukebox_MapMenu_24
# 1123 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq Jukebox_MapMenu_25
# 1124 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq Jukebox_MapMenu_26
# 1125 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq Jukebox_MapMenu_27
# 1126 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq Jukebox_MapMenu_28
# 1127 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq Jukebox_MapMenu_29
# 1128 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_eq Jukebox_MapMenu_30
# 1129 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 26
	goto_if_eq Jukebox_MapMenu_31
# 1130 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 27
	goto_if_eq Jukebox_MapMenu_32
# 1131 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 28
	goto_if_eq Jukebox_MapMenu_33
# 1132 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 29
	goto_if_eq Jukebox_MapMenu_34
# 1133 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_eq Jukebox_MapMenu_35
# 1134 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 31
	goto_if_eq Jukebox_MapMenu_36
# 1135 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_eq Jukebox_MapMenu_37
# 1136 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 33
	goto_if_eq Jukebox_MapMenu_38
# 1137 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 34
	goto_if_eq Jukebox_MapMenu_39
# 1138 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 35
	goto_if_eq Jukebox_MapMenu_40
# 1139 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 36
	goto_if_eq Jukebox_MapMenu_41
# 1140 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 37
	goto_if_eq Jukebox_MapMenu_42
# 1141 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 38
	goto_if_eq Jukebox_MapMenu_43
# 1142 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 39
	goto_if_eq Jukebox_MapMenu_44
# 1143 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 40
	goto_if_eq Jukebox_MapMenu_45
# 1144 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 41
	goto_if_eq Jukebox_MapMenu_46
# 1145 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 42
	goto_if_eq Jukebox_MapMenu_47
# 1146 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 43
	goto_if_eq Jukebox_MapMenu_48
# 1147 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 44
	goto_if_eq Jukebox_MapMenu_49
# 1148 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 45
	goto_if_eq Jukebox_MapMenu_50
# 1149 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 46
	goto_if_eq Jukebox_MapMenu_51
# 1150 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 47
	goto_if_eq Jukebox_MapMenu_52
# 1151 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 48
	goto_if_eq Jukebox_MapMenu_53
# 1152 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 49
	goto_if_eq Jukebox_MapMenu_54
# 1153 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 50
	goto_if_eq Jukebox_MapMenu_55
# 1154 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 51
	goto_if_eq Jukebox_MapMenu_56
# 1155 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 52
	goto_if_eq Jukebox_MapMenu_57
# 1156 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 53
	goto_if_eq Jukebox_MapMenu_58
# 1157 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 54
	goto_if_eq Jukebox_MapMenu_59
# 1158 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 55
	goto_if_eq Jukebox_MapMenu_60
# 1159 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 56
	goto_if_eq Jukebox_MapMenu_61
# 1160 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 57
	goto_if_eq Jukebox_MapMenu_62
# 1161 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 58
	goto_if_eq Jukebox_MapMenu_63
# 1162 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 59
	goto_if_eq Jukebox_MapMenu_64
# 1163 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 60
	goto_if_eq Jukebox_MapMenu_65
# 1164 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 61
	goto_if_eq Jukebox_MapMenu_66
# 1165 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 62
	goto_if_eq Jukebox_MapMenu_67
# 1166 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 63
	goto_if_eq Jukebox_MapMenu_68
# 1167 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 64
	goto_if_eq Jukebox_MapMenu_69
# 1168 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 65
	goto_if_eq Jukebox_MapMenu_70
# 1169 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 66
	goto_if_eq Jukebox_MapMenu_71
# 1170 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 67
	goto_if_eq Jukebox_MapMenu_72
# 1171 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 68
	goto_if_eq Jukebox_MapMenu_73
# 1172 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 69
	goto_if_eq Jukebox_MapMenu_74
# 1173 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 70
	goto_if_eq Jukebox_MapMenu_75
# 1174 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 71
	goto_if_eq Jukebox_MapMenu_76
# 1175 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 72
	goto_if_eq Jukebox_MapMenu_77
# 1176 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 73
	goto_if_eq Jukebox_MapMenu_78
# 1177 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 74
	goto_if_eq Jukebox_MapMenu_79
# 1178 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 75
	goto_if_eq Jukebox_MapMenu_80
# 1179 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 76
	goto_if_eq Jukebox_MapMenu_81
# 1180 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 77
	goto_if_eq Jukebox_MapMenu_82
# 1181 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 78
	goto_if_eq Jukebox_MapMenu_83
# 1182 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 79
	goto_if_eq Jukebox_MapMenu_84
# 1183 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 80
	goto_if_eq Jukebox_MapMenu_85
# 1184 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 81
	goto_if_eq Jukebox_MapMenu_86
# 1185 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 82
	goto_if_eq Jukebox_MapMenu_87
# 1186 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 83
	goto_if_eq Jukebox_MapMenu_88
# 1187 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 84
	goto_if_eq Jukebox_MapMenu_89
# 1188 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 85
	goto_if_eq Jukebox_MapMenu_90
# 1189 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 86
	goto_if_eq Jukebox_MapMenu_91
# 1190 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 87
	goto_if_eq Jukebox_MapMenu_92
# 1191 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 88
	goto_if_eq Jukebox_MapMenu_93
# 1192 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 89
	goto_if_eq Jukebox_MapMenu_94
# 1193 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 90
	goto_if_eq Jukebox_MapMenu_95
# 1194 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 91
	goto_if_eq Jukebox_MapMenu_96
# 1195 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 92
	goto_if_eq Jukebox_MapMenu_97
# 1196 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 93
	goto_if_eq Jukebox_MapMenu_98
# 1197 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 94
	goto_if_eq Jukebox_MapMenu_99
# 1198 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 95
	goto_if_eq Jukebox_MapMenu_100
Jukebox_MapMenu_4:
# 1200 "data/maps/LittlerootTown/scripts.pory"
	copyvar VAR_0x8004, VAR_JUKEBOX_MAP_OVERRIDE
# 1201 "data/maps/LittlerootTown/scripts.pory"
	playbgm VAR_0x8004, FALSE
# 1203 "data/maps/LittlerootTown/scripts.pory"
	msgbox Jukebox_MapMenu_Text_97, MSGBOX_DEFAULT
# 1204 "data/maps/LittlerootTown/scripts.pory"
	release
	return

Jukebox_MapMenu_2:
# 1099 "data/maps/LittlerootTown/scripts.pory"
	goto ItemUse_Jukebox
	goto Jukebox_MapMenu_1

Jukebox_MapMenu_5:
# 1103 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_LITTLEROOT_TEST
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_6:
# 1104 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_GSC_ROUTE38
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_7:
# 1105 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_C_COMM_CENTER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_8:
# 1106 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_GSC_PEWTER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_9:
# 1107 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE101
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_10:
# 1108 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE110
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_11:
# 1109 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE120
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_12:
# 1110 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_PETALBURG
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_13:
# 1111 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_OLDALE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_14:
# 1112 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_GYM
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_15:
# 1113 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SURF
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_16:
# 1114 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_PETALBURG_WOODS
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_17:
# 1115 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_LILYCOVE_MUSEUM
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_18:
# 1116 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE122
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_19:
# 1117 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_OCEANIC_MUSEUM
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_20:
# 1118 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ABANDONED_SHIP
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_21:
# 1119 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_FORTREE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_22:
# 1120 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_BIRCH_LAB
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_23:
# 1121 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_TOWER_RS
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_24:
# 1122 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_CAVE_OF_ORIGIN
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_25:
# 1123 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROULETTE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_26:
# 1124 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_VERDANTURF
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_27:
# 1125 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RUSTBORO
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_28:
# 1126 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_POKE_CENTER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_29:
# 1127 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE104
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_30:
# 1128 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE119
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_31:
# 1129 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_CYCLING
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_32:
# 1130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_POKE_MART
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_33:
# 1131 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_LITTLEROOT
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_34:
# 1132 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_MT_CHIMNEY
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_35:
# 1133 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_LILYCOVE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_36:
# 1134 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_DESERT
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_37:
# 1135 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_UNDERWATER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_38:
# 1136 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ROUTE113
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_39:
# 1137 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_EVER_GRANDE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_40:
# 1138 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_CABLE_CAR
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_41:
# 1139 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_GAME_CORNER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_42:
# 1140 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_DEWFORD
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_43:
# 1141 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SAFARI_ZONE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_44:
# 1142 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_VICTORY_ROAD
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_45:
# 1143 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_AQUA_MAGMA_HIDEOUT
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_46:
# 1144 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SAILING
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_47:
# 1145 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_MT_PYRE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_48:
# 1146 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SLATEPORT
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_49:
# 1147 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_MT_PYRE_EXTERIOR
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_50:
# 1148 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SCHOOL
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_51:
# 1149 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_FALLARBOR
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_52:
# 1150 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SEALED_CHAMBER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_53:
# 1151 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_CONTEST
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_54:
# 1152 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_ABNORMAL_WEATHER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_55:
# 1153 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_WEATHER_GROUDON
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_56:
# 1154 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_SOOTOPOLIS
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_57:
# 1155 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_TRICK_HOUSE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_58:
# 1156 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_CONTEST_LOBBY
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_59:
# 1157 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_FRONTIER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_60:
# 1158 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_ARENA
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_61:
# 1159 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_PYRAMID
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_62:
# 1160 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_PALACE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_63:
# 1161 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_TOWER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_64:
# 1162 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_DOME
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_65:
# 1163 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_PIKE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_66:
# 1164 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_FACTORY
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_67:
# 1165 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_B_DOME_LOBBY
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_68:
# 1166 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_GAME_CORNER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_69:
# 1167 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_ROCKET_HIDEOUT
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_70:
# 1168 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_GYM
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_71:
# 1169 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_CINNABAR
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_72:
# 1170 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_LAVENDER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_73:
# 1171 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_CYCLING
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_74:
# 1172 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_VIRIDIAN_FOREST
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_75:
# 1173 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_MT_MOON
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_76:
# 1174 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_POKE_MANSION
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_77:
# 1175 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_ROUTE1
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_78:
# 1176 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_ROUTE24
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_79:
# 1177 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_ROUTE3
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_80:
# 1178 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_ROUTE11
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_81:
# 1179 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_VICTORY_ROAD
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_82:
# 1180 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_PALLET
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_83:
# 1181 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_OAK_LAB
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_84:
# 1182 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_POKE_CENTER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_85:
# 1183 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SS_ANNE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_86:
# 1184 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SURF
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_87:
# 1185 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_POKE_TOWER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_88:
# 1186 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SILPH
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_89:
# 1187 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_FUCHSIA
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_90:
# 1188 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_CELADON
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_91:
# 1189 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_VERMILLION
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_92:
# 1190 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_PEWTER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_93:
# 1191 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_CAVE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_94:
# 1192 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_ROUTE
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_95:
# 1193 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_DUNGEON
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_96:
# 1194 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_123
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_97:
# 1195 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_45
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_98:
# 1196 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SEVII_67
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_99:
# 1197 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_TRAINER_TOWER
	goto Jukebox_MapMenu_4

Jukebox_MapMenu_100:
# 1198 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, MUS_RG_SLOW_PALLET
	goto Jukebox_MapMenu_4


Jukebox_BattleMenu::
# 1208 "data/maps/LittlerootTown/scripts.pory"
	message Jukebox_BattleMenu_Text_0
# 1209 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1212 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_1, 0
# 1213 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_2, 1
# 1214 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_3, 2
# 1215 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_4, 3
# 1216 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_5, 4
# 1217 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_6, 5
# 1218 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_7, 6
# 1219 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_8, 7
# 1220 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_9, 8
# 1221 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_10, 9
# 1222 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_11, 10
# 1223 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_12, 11
# 1224 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_13, 12
# 1225 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_14, 13
# 1226 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_15, 14
# 1227 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_16, 15
# 1230 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_17, 16
# 1231 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_18, 17
# 1232 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_19, 18
# 1233 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_20, 19
# 1234 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_21, 20
# 1235 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_22, 21
# 1236 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_23, 22
# 1239 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_24, 23
# 1240 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_25, 24
# 1241 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_26, 25
# 1242 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_27, 26
# 1243 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_28, 27
# 1244 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_29, 28
# 1245 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_30, 29
# 1246 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_31, 30
# 1247 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_32, 31
# 1248 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_33, 32
# 1249 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_34, 33
# 1250 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_35, 34
# 1251 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_36, 35
# 1252 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_37, 36
# 1253 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_38, 37
# 1254 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_39, 38
# 1255 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_40, 39
# 1256 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_41, 40
# 1257 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_42, 41
# 1258 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_43, 42
# 1259 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_44, 43
# 1260 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_45, 44
# 1261 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_46, 45
# 1262 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_47, 46
# 1263 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_48, 47
# 1264 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_49, 48
# 1265 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_50, 49
# 1266 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_51, 50
# 1267 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_52, 51
# 1268 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_53, 52
# 1269 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_54, 53
# 1272 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_55, 54
# 1273 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_56, 55
# 1274 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_57, 56
# 1275 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_58, 57
# 1276 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_59, 58
# 1277 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_60, 59
# 1278 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_61, 60
# 1279 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_62, 61
# 1280 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_63, 62
# 1281 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_64, 63
# 1282 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_65, 64
# 1283 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_66, 65
# 1284 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_67, 66
# 1285 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_68, 67
# 1286 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_69, 68
# 1287 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_70, 69
# 1288 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_71, 70
# 1289 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_72, 71
# 1290 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush Jukebox_BattleMenu_Text_73, 72
# 1292 "data/maps/LittlerootTown/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1294 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq Jukebox_BattleMenu_2
Jukebox_BattleMenu_1:
# 1299 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Jukebox_BattleMenu_5
# 1300 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Jukebox_BattleMenu_6
# 1301 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Jukebox_BattleMenu_7
# 1302 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq Jukebox_BattleMenu_8
# 1303 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq Jukebox_BattleMenu_9
# 1304 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq Jukebox_BattleMenu_10
# 1305 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq Jukebox_BattleMenu_11
# 1306 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq Jukebox_BattleMenu_12
# 1307 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq Jukebox_BattleMenu_13
# 1308 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq Jukebox_BattleMenu_14
# 1309 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq Jukebox_BattleMenu_15
# 1310 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq Jukebox_BattleMenu_16
# 1311 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq Jukebox_BattleMenu_17
# 1312 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq Jukebox_BattleMenu_18
# 1313 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq Jukebox_BattleMenu_19
# 1314 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq Jukebox_BattleMenu_20
# 1315 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq Jukebox_BattleMenu_21
# 1316 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq Jukebox_BattleMenu_22
# 1317 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq Jukebox_BattleMenu_23
# 1318 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq Jukebox_BattleMenu_24
# 1319 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq Jukebox_BattleMenu_25
# 1320 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq Jukebox_BattleMenu_26
# 1321 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq Jukebox_BattleMenu_27
# 1322 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq Jukebox_BattleMenu_28
# 1323 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq Jukebox_BattleMenu_29
# 1324 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_eq Jukebox_BattleMenu_30
# 1325 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 26
	goto_if_eq Jukebox_BattleMenu_31
# 1326 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 27
	goto_if_eq Jukebox_BattleMenu_32
# 1327 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 28
	goto_if_eq Jukebox_BattleMenu_33
# 1328 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 29
	goto_if_eq Jukebox_BattleMenu_34
# 1329 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_eq Jukebox_BattleMenu_35
# 1330 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 31
	goto_if_eq Jukebox_BattleMenu_36
# 1331 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_eq Jukebox_BattleMenu_37
# 1332 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 33
	goto_if_eq Jukebox_BattleMenu_38
# 1333 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 34
	goto_if_eq Jukebox_BattleMenu_39
# 1334 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 35
	goto_if_eq Jukebox_BattleMenu_40
# 1335 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 36
	goto_if_eq Jukebox_BattleMenu_41
# 1336 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 37
	goto_if_eq Jukebox_BattleMenu_42
# 1337 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 38
	goto_if_eq Jukebox_BattleMenu_43
# 1338 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 39
	goto_if_eq Jukebox_BattleMenu_44
# 1339 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 40
	goto_if_eq Jukebox_BattleMenu_45
# 1340 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 41
	goto_if_eq Jukebox_BattleMenu_46
# 1341 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 42
	goto_if_eq Jukebox_BattleMenu_47
# 1342 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 43
	goto_if_eq Jukebox_BattleMenu_48
# 1343 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 44
	goto_if_eq Jukebox_BattleMenu_49
# 1344 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 45
	goto_if_eq Jukebox_BattleMenu_50
# 1345 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 46
	goto_if_eq Jukebox_BattleMenu_51
# 1346 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 47
	goto_if_eq Jukebox_BattleMenu_52
# 1347 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 48
	goto_if_eq Jukebox_BattleMenu_53
# 1348 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 49
	goto_if_eq Jukebox_BattleMenu_54
# 1349 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 50
	goto_if_eq Jukebox_BattleMenu_55
# 1350 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 51
	goto_if_eq Jukebox_BattleMenu_56
# 1351 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 52
	goto_if_eq Jukebox_BattleMenu_57
# 1352 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 53
	goto_if_eq Jukebox_BattleMenu_58
# 1353 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 54
	goto_if_eq Jukebox_BattleMenu_59
# 1354 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 55
	goto_if_eq Jukebox_BattleMenu_60
# 1355 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 56
	goto_if_eq Jukebox_BattleMenu_61
# 1356 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 57
	goto_if_eq Jukebox_BattleMenu_62
# 1357 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 58
	goto_if_eq Jukebox_BattleMenu_63
# 1358 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 59
	goto_if_eq Jukebox_BattleMenu_64
# 1359 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 60
	goto_if_eq Jukebox_BattleMenu_65
# 1360 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 61
	goto_if_eq Jukebox_BattleMenu_66
# 1361 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 62
	goto_if_eq Jukebox_BattleMenu_67
# 1362 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 63
	goto_if_eq Jukebox_BattleMenu_68
# 1363 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 64
	goto_if_eq Jukebox_BattleMenu_69
# 1364 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 65
	goto_if_eq Jukebox_BattleMenu_70
# 1365 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 66
	goto_if_eq Jukebox_BattleMenu_71
# 1366 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 67
	goto_if_eq Jukebox_BattleMenu_72
# 1367 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 68
	goto_if_eq Jukebox_BattleMenu_73
# 1368 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 69
	goto_if_eq Jukebox_BattleMenu_74
# 1369 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 70
	goto_if_eq Jukebox_BattleMenu_75
# 1370 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 71
	goto_if_eq Jukebox_BattleMenu_76
# 1371 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 72
	goto_if_eq Jukebox_BattleMenu_77
Jukebox_BattleMenu_4:
# 1373 "data/maps/LittlerootTown/scripts.pory"
	msgbox Jukebox_BattleMenu_Text_74, MSGBOX_DEFAULT
# 1374 "data/maps/LittlerootTown/scripts.pory"
	release
	return

Jukebox_BattleMenu_2:
# 1295 "data/maps/LittlerootTown/scripts.pory"
	goto ItemUse_Jukebox
	goto Jukebox_BattleMenu_1

Jukebox_BattleMenu_5:
# 1299 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_WILD
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_6:
# 1300 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_TRAINER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_7:
# 1301 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_GYM_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_8:
# 1302 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_RIVAL
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_9:
# 1303 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_ELITE_FOUR
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_10:
# 1304 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_CHAMPION
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_11:
# 1305 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_AQUA_MAGMA
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_12:
# 1306 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_AQUA_MAGMA_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_13:
# 1307 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_KYOGRE_GROUDON
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_14:
# 1308 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_RAYQUAZA
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_15:
# 1309 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_REGI
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_16:
# 1310 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_MEW
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_17:
# 1311 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VS_FRONTIER_BRAIN
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_18:
# 1312 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_C_VS_LEGEND_BEAST
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_19:
# 1313 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_INTRO_BATTLE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_20:
# 1314 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_B_PYRAMID_TOP
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_21:
# 1315 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_TRAINER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_22:
# 1316 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_WILD
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_23:
# 1317 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_GYM_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_24:
# 1318 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_CHAMPION
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_25:
# 1319 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_DEOXYS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_26:
# 1320 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_MEWTWO
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_27:
# 1321 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VS_LEGEND
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_28:
# 1322 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VICTORY_WILD
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_29:
# 1323 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VICTORY_GYM_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_30:
# 1324 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VICTORY_LEAGUE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_31:
# 1325 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_VICTORY_AQUA_MAGMA
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_32:
# 1326 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_GIRL
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_33:
# 1327 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_MALE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_34:
# 1328 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_SWIMMER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_35:
# 1329 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_RICH
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_36:
# 1330 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_FEMALE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_37:
# 1331 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_MAY
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_38:
# 1332 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_INTENSE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_39:
# 1333 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_COOL
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_40:
# 1334 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_AQUA
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_41:
# 1335 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_BRENDAN
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_42:
# 1336 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_SUSPICIOUS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_43:
# 1337 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_MAGMA
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_44:
# 1338 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_TWINS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_45:
# 1339 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_ELITE_FOUR
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_46:
# 1340 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_HIKER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_47:
# 1341 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_INTERVIEWER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_48:
# 1342 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_ENCOUNTER_CHAMPION
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_49:
# 1343 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_INTRO_FIGHT
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_50:
# 1344 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_ROCKET
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_51:
# 1345 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_GIRL
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_52:
# 1346 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_BOY
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_53:
# 1347 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VICTORY_TRAINER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_54:
# 1348 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VICTORY_WILD
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_55:
# 1349 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_VICTORY_GYM_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_56:
# 1350 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_RIVAL
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_57:
# 1351 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_GYM_LEADER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_58:
# 1352 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_ENCOUNTER_DEOXYS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_59:
# 1353 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_TITLE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_60:
# 1354 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_INTRO
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_61:
# 1355 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_CREDITS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_62:
# 1356 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_END
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_63:
# 1357 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RAYQUAZA_APPEARS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_64:
# 1358 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_INTRO_FIGHT
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_65:
# 1359 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_TITLE
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_66:
# 1360 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_HALL_OF_FAME
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_67:
# 1361 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_CREDITS
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_68:
# 1362 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_GAME_FREAK
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_69:
# 1363 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_NEW_GAME_INSTRUCT
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_70:
# 1364 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_NEW_GAME_INTRO
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_71:
# 1365 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_NEW_GAME_EXIT
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_72:
# 1366 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_UNION_ROOM
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_73:
# 1367 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_NET_CENTER
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_74:
# 1368 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_MYSTERY_GIFT
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_75:
# 1369 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_BERRY_PICK
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_76:
# 1370 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_TEACHY_TV_SHOW
	goto Jukebox_BattleMenu_4

Jukebox_BattleMenu_77:
# 1371 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, MUS_RG_TEACHY_TV_MENU
	goto Jukebox_BattleMenu_4


Jukebox_ResetDefaults::
# 1378 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_MAP_OVERRIDE, 0
# 1379 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_JUKEBOX_BATTLE_OVERRIDE, 0
# 1382 "data/maps/LittlerootTown/scripts.pory"
	playbgm MUS_DUMMY, FALSE
# 1383 "data/maps/LittlerootTown/scripts.pory"
	fadedefaultbgm
# 1385 "data/maps/LittlerootTown/scripts.pory"
	msgbox Jukebox_ResetDefaults_Text_0, MSGBOX_DEFAULT
# 1386 "data/maps/LittlerootTown/scripts.pory"
	release
	return


Jukebox_Exit::
# 1390 "data/maps/LittlerootTown/scripts.pory"
	release
	return


EventScript_SpeedUpConfig::
# 1394 "data/maps/LittlerootTown/scripts.pory"
	lock
# 1395 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1397 "data/maps/LittlerootTown/scripts.pory"
	message EventScript_SpeedUpConfig_Text_0
# 1398 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1402 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush EventScript_SpeedUpConfig_Text_1, 0
# 1403 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush EventScript_SpeedUpConfig_Text_2, 1
# 1404 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush EventScript_SpeedUpConfig_Text_3, 2
# 1405 "data/maps/LittlerootTown/scripts.pory"
	dynmultipush EventScript_SpeedUpConfig_Text_4, 3
# 1408 "data/maps/LittlerootTown/scripts.pory"
	dynmultistack 17, 0, FALSE, 5, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1411 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EventScript_SpeedUpConfig_2
EventScript_SpeedUpConfig_1:
# 1417 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_SpeedUpConfig_5
# 1421 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_SpeedUpConfig_6
# 1425 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EventScript_SpeedUpConfig_7
# 1429 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq EventScript_SpeedUpConfig_8
EventScript_SpeedUpConfig_4:
# 1433 "data/maps/LittlerootTown/scripts.pory"
	release
	end

EventScript_SpeedUpConfig_2:
# 1413 "data/maps/LittlerootTown/scripts.pory"
	goto EventScript_SpeedUpConfig_Exit
	goto EventScript_SpeedUpConfig_1

EventScript_SpeedUpConfig_5:
# 1418 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OVERWORLD_SPEEDUP, 0
# 1419 "data/maps/LittlerootTown/scripts.pory"
	msgbox EventScript_SpeedUpConfig_Text_5, MSGBOX_DEFAULT
	goto EventScript_SpeedUpConfig_4

EventScript_SpeedUpConfig_6:
# 1422 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OVERWORLD_SPEEDUP, 1
# 1423 "data/maps/LittlerootTown/scripts.pory"
	msgbox EventScript_SpeedUpConfig_Text_6, MSGBOX_DEFAULT
	goto EventScript_SpeedUpConfig_4

EventScript_SpeedUpConfig_7:
# 1426 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OVERWORLD_SPEEDUP, 2
# 1427 "data/maps/LittlerootTown/scripts.pory"
	msgbox EventScript_SpeedUpConfig_Text_7, MSGBOX_DEFAULT
	goto EventScript_SpeedUpConfig_4

EventScript_SpeedUpConfig_8:
# 1430 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OVERWORLD_SPEEDUP, 3
# 1431 "data/maps/LittlerootTown/scripts.pory"
	msgbox EventScript_SpeedUpConfig_Text_8, MSGBOX_DEFAULT
	goto EventScript_SpeedUpConfig_4


EventScript_SpeedUpConfig_Exit::
# 1438 "data/maps/LittlerootTown/scripts.pory"
	release
	end


ItemUse_Jukebox_Text_0:
# 966 "data/maps/LittlerootTown/scripts.pory"
	.string "Where would you like to change music?$"

ItemUse_Jukebox_Text_1:
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "Overworld Map Music$"

ItemUse_Jukebox_Text_2:
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Music$"

ItemUse_Jukebox_Text_3:
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "Restore Game Defaults$"

Jukebox_MapMenu_Text_0:
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "Choose an Overworld vibe:$"

Jukebox_MapMenu_Text_1:
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "Littleroot Town (Test)$"

Jukebox_MapMenu_Text_2:
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "GSC Route 38 (Test)$"

Jukebox_MapMenu_Text_3:
# 998 "data/maps/LittlerootTown/scripts.pory"
	.string "C Comm Center (Test)$"

Jukebox_MapMenu_Text_4:
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "GSC Pewter (Test)$"

Jukebox_MapMenu_Text_5:
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 101$"

Jukebox_MapMenu_Text_6:
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 110$"

Jukebox_MapMenu_Text_7:
# 1002 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 120$"

Jukebox_MapMenu_Text_8:
# 1003 "data/maps/LittlerootTown/scripts.pory"
	.string "Petalburg City$"

Jukebox_MapMenu_Text_9:
# 1004 "data/maps/LittlerootTown/scripts.pory"
	.string "Oldale Town$"

Jukebox_MapMenu_Text_10:
# 1005 "data/maps/LittlerootTown/scripts.pory"
	.string "Gym Theme$"

Jukebox_MapMenu_Text_11:
# 1006 "data/maps/LittlerootTown/scripts.pory"
	.string "Surf Theme$"

Jukebox_MapMenu_Text_12:
# 1007 "data/maps/LittlerootTown/scripts.pory"
	.string "Petalburg Woods$"

Jukebox_MapMenu_Text_13:
# 1008 "data/maps/LittlerootTown/scripts.pory"
	.string "Lilycove Museum$"

Jukebox_MapMenu_Text_14:
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 122$"

Jukebox_MapMenu_Text_15:
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "Oceanic Museum$"

Jukebox_MapMenu_Text_16:
# 1011 "data/maps/LittlerootTown/scripts.pory"
	.string "Abandoned Ship$"

Jukebox_MapMenu_Text_17:
# 1012 "data/maps/LittlerootTown/scripts.pory"
	.string "Fortree City$"

Jukebox_MapMenu_Text_18:
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "Birch Lab$"

Jukebox_MapMenu_Text_19:
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Tower (R/S)$"

Jukebox_MapMenu_Text_20:
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "Cave of Origin$"

Jukebox_MapMenu_Text_21:
# 1016 "data/maps/LittlerootTown/scripts.pory"
	.string "Roulette$"

Jukebox_MapMenu_Text_22:
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "Verdanturf Town$"

Jukebox_MapMenu_Text_23:
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Rustboro City$"

Jukebox_MapMenu_Text_24:
# 1019 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon Center$"

Jukebox_MapMenu_Text_25:
# 1020 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 104$"

Jukebox_MapMenu_Text_26:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 119$"

Jukebox_MapMenu_Text_27:
# 1022 "data/maps/LittlerootTown/scripts.pory"
	.string "Cycling Theme$"

Jukebox_MapMenu_Text_28:
# 1023 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon Mart$"

Jukebox_MapMenu_Text_29:
# 1024 "data/maps/LittlerootTown/scripts.pory"
	.string "Littleroot Town$"

Jukebox_MapMenu_Text_30:
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "Mt. Chimney$"

Jukebox_MapMenu_Text_31:
# 1026 "data/maps/LittlerootTown/scripts.pory"
	.string "Lilycove City$"

Jukebox_MapMenu_Text_32:
# 1027 "data/maps/LittlerootTown/scripts.pory"
	.string "Desert Theme$"

Jukebox_MapMenu_Text_33:
# 1028 "data/maps/LittlerootTown/scripts.pory"
	.string "Underwater Theme$"

Jukebox_MapMenu_Text_34:
# 1029 "data/maps/LittlerootTown/scripts.pory"
	.string "Route 113$"

Jukebox_MapMenu_Text_35:
# 1030 "data/maps/LittlerootTown/scripts.pory"
	.string "Ever Grande City$"

Jukebox_MapMenu_Text_36:
# 1031 "data/maps/LittlerootTown/scripts.pory"
	.string "Cable Car$"

Jukebox_MapMenu_Text_37:
# 1032 "data/maps/LittlerootTown/scripts.pory"
	.string "Game Corner$"

Jukebox_MapMenu_Text_38:
# 1033 "data/maps/LittlerootTown/scripts.pory"
	.string "Dewford Town$"

Jukebox_MapMenu_Text_39:
# 1034 "data/maps/LittlerootTown/scripts.pory"
	.string "Safari Zone$"

Jukebox_MapMenu_Text_40:
# 1035 "data/maps/LittlerootTown/scripts.pory"
	.string "Victory Road$"

Jukebox_MapMenu_Text_41:
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "Aqua/Magma Hideout$"

Jukebox_MapMenu_Text_42:
# 1037 "data/maps/LittlerootTown/scripts.pory"
	.string "Sailing Theme$"

Jukebox_MapMenu_Text_43:
# 1038 "data/maps/LittlerootTown/scripts.pory"
	.string "Mt. Pyre$"

Jukebox_MapMenu_Text_44:
# 1039 "data/maps/LittlerootTown/scripts.pory"
	.string "Slateport City$"

Jukebox_MapMenu_Text_45:
# 1040 "data/maps/LittlerootTown/scripts.pory"
	.string "Mt. Pyre Exterior$"

Jukebox_MapMenu_Text_46:
# 1041 "data/maps/LittlerootTown/scripts.pory"
	.string "Trainer School$"

Jukebox_MapMenu_Text_47:
# 1042 "data/maps/LittlerootTown/scripts.pory"
	.string "Fallarbor Town$"

Jukebox_MapMenu_Text_48:
# 1043 "data/maps/LittlerootTown/scripts.pory"
	.string "Sealed Chamber$"

Jukebox_MapMenu_Text_49:
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "Contest Theme$"

Jukebox_MapMenu_Text_50:
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "Abnormal Weather$"

Jukebox_MapMenu_Text_51:
# 1046 "data/maps/LittlerootTown/scripts.pory"
	.string "Weather Groudon$"

Jukebox_MapMenu_Text_52:
# 1047 "data/maps/LittlerootTown/scripts.pory"
	.string "Sootopolis City$"

Jukebox_MapMenu_Text_53:
# 1048 "data/maps/LittlerootTown/scripts.pory"
	.string "Trick House$"

Jukebox_MapMenu_Text_54:
# 1049 "data/maps/LittlerootTown/scripts.pory"
	.string "Contest Lobby$"

Jukebox_MapMenu_Text_55:
# 1050 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Frontier$"

Jukebox_MapMenu_Text_56:
# 1051 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Arena$"

Jukebox_MapMenu_Text_57:
# 1052 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Pyramid Floor$"

Jukebox_MapMenu_Text_58:
# 1053 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Palace$"

Jukebox_MapMenu_Text_59:
# 1054 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Tower (Emerald)$"

Jukebox_MapMenu_Text_60:
# 1055 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Dome$"

Jukebox_MapMenu_Text_61:
# 1056 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Pike$"

Jukebox_MapMenu_Text_62:
# 1057 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Factory$"

Jukebox_MapMenu_Text_63:
# 1058 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Dome Lobby$"

Jukebox_MapMenu_Text_64:
# 1061 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Game Corner$"

Jukebox_MapMenu_Text_65:
# 1062 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Rocket Hideout$"

Jukebox_MapMenu_Text_66:
# 1063 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Gym Theme$"

Jukebox_MapMenu_Text_67:
# 1064 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Cinnabar Island$"

Jukebox_MapMenu_Text_68:
# 1065 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Lavender Town$"

Jukebox_MapMenu_Text_69:
# 1066 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Cycling Theme$"

Jukebox_MapMenu_Text_70:
# 1067 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Viridian Forest$"

Jukebox_MapMenu_Text_71:
# 1068 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Mt. Moon$"

Jukebox_MapMenu_Text_72:
# 1069 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Pokémon Mansion$"

Jukebox_MapMenu_Text_73:
# 1070 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Route 1$"

Jukebox_MapMenu_Text_74:
# 1071 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Route 24$"

Jukebox_MapMenu_Text_75:
# 1072 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Route 3$"

Jukebox_MapMenu_Text_76:
# 1073 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Route 11$"

Jukebox_MapMenu_Text_77:
# 1074 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Victory Road$"

Jukebox_MapMenu_Text_78:
# 1075 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Pallet Town$"

Jukebox_MapMenu_Text_79:
# 1076 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Oak Lab$"

Jukebox_MapMenu_Text_80:
# 1077 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Pokémon Center$"

Jukebox_MapMenu_Text_81:
# 1078 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: S.S. Anne$"

Jukebox_MapMenu_Text_82:
# 1079 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Surf Theme$"

Jukebox_MapMenu_Text_83:
# 1080 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Pokémon Tower$"

Jukebox_MapMenu_Text_84:
# 1081 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Silph Co.$"

Jukebox_MapMenu_Text_85:
# 1082 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Fuchsia / Cerulean$"

Jukebox_MapMenu_Text_86:
# 1083 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Celadon City$"

Jukebox_MapMenu_Text_87:
# 1084 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Vermilion City$"

Jukebox_MapMenu_Text_88:
# 1085 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Pewter Town$"

Jukebox_MapMenu_Text_89:
# 1086 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii Cave$"

Jukebox_MapMenu_Text_90:
# 1087 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii Route$"

Jukebox_MapMenu_Text_91:
# 1088 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii Dungeon$"

Jukebox_MapMenu_Text_92:
# 1089 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii 1/2/3$"

Jukebox_MapMenu_Text_93:
# 1090 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii 4/5$"

Jukebox_MapMenu_Text_94:
# 1091 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Sevii 6/7$"

Jukebox_MapMenu_Text_95:
# 1092 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Trainer Tower$"

Jukebox_MapMenu_Text_96:
# 1093 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Slow Pallet Town$"

Jukebox_MapMenu_Text_97:
# 1203 "data/maps/LittlerootTown/scripts.pory"
	.string "Overworld music updated!$"

Jukebox_BattleMenu_Text_0:
# 1208 "data/maps/LittlerootTown/scripts.pory"
	.string "Choose a Battle theme:$"

Jukebox_BattleMenu_Text_1:
# 1212 "data/maps/LittlerootTown/scripts.pory"
	.string "Wild Pokémon Battle$"

Jukebox_BattleMenu_Text_2:
# 1213 "data/maps/LittlerootTown/scripts.pory"
	.string "Trainer Battle$"

Jukebox_BattleMenu_Text_3:
# 1214 "data/maps/LittlerootTown/scripts.pory"
	.string "Gym Leader Battle$"

Jukebox_BattleMenu_Text_4:
# 1215 "data/maps/LittlerootTown/scripts.pory"
	.string "Rival Battle$"

Jukebox_BattleMenu_Text_5:
# 1216 "data/maps/LittlerootTown/scripts.pory"
	.string "Elite Four Battle$"

Jukebox_BattleMenu_Text_6:
# 1217 "data/maps/LittlerootTown/scripts.pory"
	.string "Champion Battle$"

Jukebox_BattleMenu_Text_7:
# 1218 "data/maps/LittlerootTown/scripts.pory"
	.string "Team Aqua/Magma Grunt$"

Jukebox_BattleMenu_Text_8:
# 1219 "data/maps/LittlerootTown/scripts.pory"
	.string "Aqua/Magma Boss$"

Jukebox_BattleMenu_Text_9:
# 1220 "data/maps/LittlerootTown/scripts.pory"
	.string "Groudon/Kyogre$"

Jukebox_BattleMenu_Text_10:
# 1221 "data/maps/LittlerootTown/scripts.pory"
	.string "Rayquaza Theme$"

Jukebox_BattleMenu_Text_11:
# 1222 "data/maps/LittlerootTown/scripts.pory"
	.string "Regi Trio Theme$"

Jukebox_BattleMenu_Text_12:
# 1223 "data/maps/LittlerootTown/scripts.pory"
	.string "Mew Battle Theme$"

Jukebox_BattleMenu_Text_13:
# 1224 "data/maps/LittlerootTown/scripts.pory"
	.string "Frontier Brain Theme$"

Jukebox_BattleMenu_Text_14:
# 1225 "data/maps/LittlerootTown/scripts.pory"
	.string "Legendary Beast (Test)$"

Jukebox_BattleMenu_Text_15:
# 1226 "data/maps/LittlerootTown/scripts.pory"
	.string "Intro Battle Theme$"

Jukebox_BattleMenu_Text_16:
# 1227 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle Pyramid Top$"

Jukebox_BattleMenu_Text_17:
# 1230 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Trainer Battle$"

Jukebox_BattleMenu_Text_18:
# 1231 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Wild Pokémon$"

Jukebox_BattleMenu_Text_19:
# 1232 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Gym Leader$"

Jukebox_BattleMenu_Text_20:
# 1233 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Champion Battle$"

Jukebox_BattleMenu_Text_21:
# 1234 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Deoxys Battle$"

Jukebox_BattleMenu_Text_22:
# 1235 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Mewtwo Battle$"

Jukebox_BattleMenu_Text_23:
# 1236 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Kanto Legendary$"

Jukebox_BattleMenu_Text_24:
# 1239 "data/maps/LittlerootTown/scripts.pory"
	.string "Victory: Wild Pokémon$"

Jukebox_BattleMenu_Text_25:
# 1240 "data/maps/LittlerootTown/scripts.pory"
	.string "Victory: Gym Leader$"

Jukebox_BattleMenu_Text_26:
# 1241 "data/maps/LittlerootTown/scripts.pory"
	.string "Victory: Elite Four$"

Jukebox_BattleMenu_Text_27:
# 1242 "data/maps/LittlerootTown/scripts.pory"
	.string "Victory: Team Aqua/Magma$"

Jukebox_BattleMenu_Text_28:
# 1243 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Girl$"

Jukebox_BattleMenu_Text_29:
# 1244 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Male$"

Jukebox_BattleMenu_Text_30:
# 1245 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Swimmer$"

Jukebox_BattleMenu_Text_31:
# 1246 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Rich Guy$"

Jukebox_BattleMenu_Text_32:
# 1247 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Female$"

Jukebox_BattleMenu_Text_33:
# 1248 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: May$"

Jukebox_BattleMenu_Text_34:
# 1249 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Intense$"

Jukebox_BattleMenu_Text_35:
# 1250 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Cool Trainer$"

Jukebox_BattleMenu_Text_36:
# 1251 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Team Aqua$"

Jukebox_BattleMenu_Text_37:
# 1252 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Brendan$"

Jukebox_BattleMenu_Text_38:
# 1253 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Suspicious$"

Jukebox_BattleMenu_Text_39:
# 1254 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Team Magma$"

Jukebox_BattleMenu_Text_40:
# 1255 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Twins$"

Jukebox_BattleMenu_Text_41:
# 1256 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Elite Four$"

Jukebox_BattleMenu_Text_42:
# 1257 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Hiker$"

Jukebox_BattleMenu_Text_43:
# 1258 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Interviewer$"

Jukebox_BattleMenu_Text_44:
# 1259 "data/maps/LittlerootTown/scripts.pory"
	.string "Encounter: Champion$"

Jukebox_BattleMenu_Text_45:
# 1260 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Battle Intro Fight$"

Jukebox_BattleMenu_Text_46:
# 1261 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Rocket$"

Jukebox_BattleMenu_Text_47:
# 1262 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Girl$"

Jukebox_BattleMenu_Text_48:
# 1263 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Boy$"

Jukebox_BattleMenu_Text_49:
# 1264 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Victory Trainer$"

Jukebox_BattleMenu_Text_50:
# 1265 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Victory Wild$"

Jukebox_BattleMenu_Text_51:
# 1266 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Victory Gym Leader$"

Jukebox_BattleMenu_Text_52:
# 1267 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Rival$"

Jukebox_BattleMenu_Text_53:
# 1268 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Gym Leader$"

Jukebox_BattleMenu_Text_54:
# 1269 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Encounter Deoxys$"

Jukebox_BattleMenu_Text_55:
# 1272 "data/maps/LittlerootTown/scripts.pory"
	.string "Hoenn Game Title$"

Jukebox_BattleMenu_Text_56:
# 1273 "data/maps/LittlerootTown/scripts.pory"
	.string "Game Intro Speeches$"

Jukebox_BattleMenu_Text_57:
# 1274 "data/maps/LittlerootTown/scripts.pory"
	.string "Game Credits$"

Jukebox_BattleMenu_Text_58:
# 1275 "data/maps/LittlerootTown/scripts.pory"
	.string "The End Scene$"

Jukebox_BattleMenu_Text_59:
# 1276 "data/maps/LittlerootTown/scripts.pory"
	.string "Rayquaza Cutscene$"

Jukebox_BattleMenu_Text_60:
# 1277 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Game Intro Fight$"

Jukebox_BattleMenu_Text_61:
# 1278 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Main Title Theme$"

Jukebox_BattleMenu_Text_62:
# 1279 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Hall of Fame Credits$"

Jukebox_BattleMenu_Text_63:
# 1280 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Game Credits Layout$"

Jukebox_BattleMenu_Text_64:
# 1281 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Game Freak Logo$"

Jukebox_BattleMenu_Text_65:
# 1282 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: New Game Info Instruct$"

Jukebox_BattleMenu_Text_66:
# 1283 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: New Game Intro Scene$"

Jukebox_BattleMenu_Text_67:
# 1284 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: New Game Exit Options$"

Jukebox_BattleMenu_Text_68:
# 1285 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Union Room Layout$"

Jukebox_BattleMenu_Text_69:
# 1286 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Wireless Net Center$"

Jukebox_BattleMenu_Text_70:
# 1287 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Mystery Gift System$"

Jukebox_BattleMenu_Text_71:
# 1288 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Berry Pick Minigame$"

Jukebox_BattleMenu_Text_72:
# 1289 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Teachy TV Show Theme$"

Jukebox_BattleMenu_Text_73:
# 1290 "data/maps/LittlerootTown/scripts.pory"
	.string "RG: Teachy TV Main Menu$"

Jukebox_BattleMenu_Text_74:
# 1373 "data/maps/LittlerootTown/scripts.pory"
	.string "Battle music updated!$"

Jukebox_ResetDefaults_Text_0:
# 1385 "data/maps/LittlerootTown/scripts.pory"
	.string "Music choices restored to original\ngame defaults.$"

EventScript_SpeedUpConfig_Text_0:
# 1397 "data/maps/LittlerootTown/scripts.pory"
	.string "Choose an Overworld Speed:$"

EventScript_SpeedUpConfig_Text_1:
# 1402 "data/maps/LittlerootTown/scripts.pory"
	.string "Disable Speedup$"

EventScript_SpeedUpConfig_Text_2:
# 1403 "data/maps/LittlerootTown/scripts.pory"
	.string "2x Speed$"

EventScript_SpeedUpConfig_Text_3:
# 1404 "data/maps/LittlerootTown/scripts.pory"
	.string "4x Speed$"

EventScript_SpeedUpConfig_Text_4:
# 1405 "data/maps/LittlerootTown/scripts.pory"
	.string "8x Speed$"

EventScript_SpeedUpConfig_Text_5:
# 1419 "data/maps/LittlerootTown/scripts.pory"
	.string "Overworld speedup disabled.$"

EventScript_SpeedUpConfig_Text_6:
# 1423 "data/maps/LittlerootTown/scripts.pory"
	.string "Speed set to 2x.$"

EventScript_SpeedUpConfig_Text_7:
# 1427 "data/maps/LittlerootTown/scripts.pory"
	.string "Speed set to 4x.$"

EventScript_SpeedUpConfig_Text_8:
# 1431 "data/maps/LittlerootTown/scripts.pory"
	.string "Speed set to 8x.$"
