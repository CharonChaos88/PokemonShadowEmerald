# 1 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 2 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_MapScripts::
# 3 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 4 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 5 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 6 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 8 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 9 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 10 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 11 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 12 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Hoenn mons
# 13 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 14 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 15 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 16 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 17 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Never occurs
# 18 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Chose starter
# 19 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 20 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 103
# 21 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 22 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 23 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnTransition:
# 24 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 25 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 26 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 27 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 28 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 29 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 31 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 32 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 33 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 34 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 35 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 36 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 37 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 38 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 39 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 40 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 41 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 42 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 43 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 44 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 45 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 46 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 47 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 48 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 49 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 50 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 51 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 52 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnWarp:
# 53 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 54 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 55 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 56 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 57 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 58 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 59 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 60 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 61 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 62 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 63 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 64 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 65 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 66 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 67 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 68 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_BIRCH
# 69 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 70 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
# 71 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
# 72 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 73 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 79 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 81 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 83 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 84 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 85 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 86 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 87 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
# 88 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
# 89 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
# 90 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
# 91 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
# 92 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
# 93 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 94 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
# 95 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
# 96 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
# 97 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 98 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 99 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnFrame:
# 100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_CUTSCENE, 1, TalktoBirchAboutWhatHappened1
# 102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ The starter is technically given prior to this on Route 101 by special ChooseStarter
# 108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ This is just where the game tells you its yours and lets you nickname it
# 109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PC_ON
# 151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitse
# 152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 186 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 187 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 189 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 192 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 193 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 194 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 195 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 202 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_up
# 203 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 204 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 212 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 214 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 224 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 225 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 226 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 231 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 232 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 233 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 244 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 245 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 246 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
# 248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 250 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 256 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 257 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 258 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
# 259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 262 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 263 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 264 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 265 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 269 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 270 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 272 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 273 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 274 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 275 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5
# 284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 289 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 290 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 291 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 292 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 306 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 309 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 310 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 311 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 312 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 313 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 322 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5
# 325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 330 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 331 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 332 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 333 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 338 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 340 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 342 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 350 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 351 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 352 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 353 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 354 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 356 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 358 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 359 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 364 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 365 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5
# 366 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 367 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 370 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 371 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 372 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 373 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 376 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 377 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 379 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 380 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 391 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 392 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 398 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 399 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 400 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 401 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 404 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 405 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 406 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 407 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 408 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 415 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 416 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 418 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 420 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 421 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 422 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 423 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 427 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch::
# 430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 431 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 432 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 435 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 436 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 437 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 438 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 444 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 445 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 446 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 447 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 448 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 449 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 450 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 456 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 463 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 474 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 480 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 481 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 483 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 485 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 486 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 487 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 488 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 498 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 499 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 500 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 501 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 504 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_left
# 505 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 506 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 507 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
# 508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
# 512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 517 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 518 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 519 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 520 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 523 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 524 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 525 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 526 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 527 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 534 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 535 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 537 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 539 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 540 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 541 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 542 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 543 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 550 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 551 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 553 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 555 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 556 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 557 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 558 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 559 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 566 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 567 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 569 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 571 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 572 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 573 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 574 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 575 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PC::
# 577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 582 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 583 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Book::
# 585 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 587 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 588 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 589 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 590 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 591 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 598 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 599 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 601 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 602 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 604 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 606 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 607 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 608 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 609 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 610 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 611 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 612 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 613 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 614 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 615 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 616 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 617 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 618 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 619 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 620 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 621 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 622 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 623 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 624 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
# 625 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 626 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 627 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 628 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: If you work at POKéMON\n"
# 629 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you'll make\l"
# 630 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "an extremely good TRAINER.\p"
# 631 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, is also studying\n"
# 632 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON while helping me out.\p"
# 633 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
# 634 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a good idea to go see {RIVAL}?$"
# 635 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 636 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 637 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Great!\n"
# 638 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} should be happy, too.\p"
# 639 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Get {RIVAL} to teach you what it\n"
# 640 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "means to be a TRAINER.$"
# 641 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 642 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 643 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, don't be that way.\n"
# 644 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You should go meet my kid.$"
# 645 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 646 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 647 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {RIVAL}?\n"
# 648 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Gone home, I think.\p"
# 649 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or maybe that kid's scrabbling around\n"
# 650 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in tall grass again somewhere…\p"
# 651 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you or your POKéMON get tired,\n"
# 652 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you should get some rest at home.$"
# 653 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 654 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 655 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 656 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL} on\n"
# 657 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "your first try. That's excellent!\p"
# 658 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}'s been helping with my research\n"
# 659 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a long time.\p"
# 660 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} has an extensive history as\n"
# 661 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a TRAINER already.\p"
# 662 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 663 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 664 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéDEX.$"
# 665 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 666 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 667 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"
# 668 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 669 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 670 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 671 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "tool that automatically makes a record\l"
# 672 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of any POKéMON you meet or catch.\p"
# 673 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, goes everywhere\n"
# 674 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "with it.\p"
# 675 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Whenever my kid catches a rare POKéMON\n"
# 676 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and records its data in the POKéDEX,\l"
# 677 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "why, {RIVAL} looks for me while I'm out\l"
# 678 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "doing fieldwork, and shows me.$"
# 679 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 680 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 681 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Countless POKéMON\n"
# 682 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 683 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 684 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 685 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 686 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 687 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 688 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a POKéDEX, too!\p"
# 689 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's great! Just like me!\n"
# 690 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've got something for you, too!$"
# 691 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 692 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 693 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: It's fun if you can get a lot of\n"
# 694 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON!\p"
# 695 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to look all over the place\n"
# 696 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "because I want different POKéMON.\p"
# 697 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cute POKéMON, I'll catch\n"
# 698 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "them with POKé BALLS!$"
# 699 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 700 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 701 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your BAG's full.$"
# 702 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 703 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 704 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I wonder where I should go look\n"
# 705 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for POKéMON next?$"
# 706 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 707 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 708 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Huh…\n"
# 709 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a POKéDEX, too.\p"
# 710 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well then, here.\n"
# 711 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll give you these.$"
# 712 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 713 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 714 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: You know it's more fun to\n"
# 715 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "have a whole bunch of POKéMON.\p"
# 716 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to explore all over the place\n"
# 717 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to find different POKéMON.\p"
# 718 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cool POKéMON, you bet\n"
# 719 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll try to get them with POKé BALLS.$"
# 720 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 721 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 722 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your BAG's full.$"
# 723 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 724 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 725 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Where should I look for\n"
# 726 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON next…$"
# 727 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 728 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 729 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 730 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF must use this for research.$"
# 731 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 732 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 733 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 734 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 735 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 736 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 737 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on POKéMON.$"
# 738 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 739 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 740 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 741 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 742 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 743 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Now…\p"
# 744 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 745 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study POKéMON.\p"
# 746 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 747 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 748 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the HOENN region,\n"
# 749 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also POKéMON from other\l"
# 750 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "regions.\p"
# 751 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It goes to show how rich and varied\n"
# 752 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the natural environments of HOENN\l"
# 753 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "happen to be.\p"
# 754 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's why I think it's necessary for\n"
# 755 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "me to upgrade your POKéDEX to\l"
# 756 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode.\p"
# 757 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, let me see your POKéDEX units.$"
# 758 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 759 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 760 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Eheheh!\p"
# 761 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cool that even my POKéDEX\n"
# 762 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "is getting updated!\p"
# 763 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's because you went out and caught\n"
# 764 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
# 765 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 766 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 767 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: I went out all over HOENN\n"
# 768 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and checked out POKéMON.\p"
# 769 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can thank me for getting\n"
# 770 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode POKéDEX.\p"
# 771 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yep, you're lucky, {PLAYER}!$"
# 772 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 773 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
# 774 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Okay, all done!$"
# 775 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 776 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 777 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 778 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to the NATIONAL Mode!$"
# 779 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 780 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 781 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: But listen.\n"
# 782 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the CHAMPION,\l"
# 783 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 784 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 785 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 786 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 787 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 788 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 789 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 790 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I think I'll take a short break\n"
# 791 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from fieldwork.\p"
# 792 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I think I'll help the PROF here for\n"
# 793 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a while.$"
# 794 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 795 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 796 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: For the time being,\n"
# 797 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm taking a break from fieldwork.\p"
# 798 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll be helping out the PROF here\n"
# 799 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a while.$"
# 800 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 801 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 802 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 803 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your POKéDEX.\p"
# 804 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 805 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 806 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 807 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the HOENN\n"
# 808 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "region's POKéDEX.\p"
# 809 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 810 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 811 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 812 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 813 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare POKéMON only found\n"
# 814 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 815 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 816 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 817 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 818 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 819 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: These are rare POKéMON\n"
# 820 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 821 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 822 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 823 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 824 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 825 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The FIRE POKéMON\n"
# 826 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 827 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 828 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 829 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 830 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 831 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The WATER POKéMON\n"
# 832 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 833 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 834 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 835 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 836 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 837 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The GRASS POKéMON\n"
# 838 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 839 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 840 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 841 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 842 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 843 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Take your time before\n"
# 844 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 845 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable POKéMON.$"
# 846 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 847 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 848 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 849 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: I see!\n"
# 850 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You picked a fine POKéMON!$"
# 851 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 852 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 853 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 854 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from PROF. BIRCH!$"
# 855 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 856 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 857 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 858 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 859 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 860 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 861 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 862 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 863 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the HOENN POKéDEX,\l"
# 864 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 865 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 866 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 867 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 868 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 869 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 870 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 871 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised POKéMON.\n"
# 872 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 873 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 874 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 875 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 876 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 877 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéMON.$"
# 878 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 879 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 880 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, after this…\n"
# 881 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 882 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 883 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 884 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 885 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL POKéDEX?\p"
# 886 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the PROF.$"
# 887 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 888 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 889 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Rather than collecting\n"
# 890 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON, I prefer slowly and \l"
# 891 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 892 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 893 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 894 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 895 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 896 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 897 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 898 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 899 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}!\n"
# 900 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 901 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 902 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 903 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 904 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 905 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 906 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
# 907 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, SCOTT.\p"
# 908 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. TIDAL now.\n"
# 909 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 910 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 911 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 912 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 913 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 914 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "at either SLATEPORT or LILYCOVE.\p"
# 915 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 916 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 917 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 918 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 921 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 922 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 923 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_0
# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_1, MSGBOX_DEFAULT
# 928 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_1
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_1::
# 932 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 933 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_1_Text_0, MSGBOX_DEFAULT
# 937 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_2
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_2::
# 941 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 942 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_2_Text_0, MSGBOX_DEFAULT
# 946 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_3
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_3::
# 950 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 951 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_3_Text_0, MSGBOX_DEFAULT
# 955 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_4
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_4::
# 959 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 960 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_0
# 961 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_UNUSED_0x91F
# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_4_Text_0, MSGBOX_DEFAULT
# 963 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 964 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_MAXIE_LAB
# 965 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_MAXIE_LAB, LittlerootTown_ProfessorBirchsLab_Movement_MaxieEnterLab
# 966 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 967 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 968 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_FaceLeft
# 969 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 970 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 971 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_5
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_5::
# 975 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 976 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_5_Text_0, MSGBOX_DEFAULT
# 979 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_6
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_6::
# 983 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 984 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_MAXIE
# 985 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_6_Text_0, MSGBOX_DEFAULT
# 988 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_7
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_7::
# 992 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 993 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 994 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_7_Text_0, MSGBOX_DEFAULT
# 997 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_8
# 998 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end


LittlerootTown_ProfessorBirchsLab_Text_Into_8::
# 1004 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1005 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_MAXIE
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_8_Text_0, MSGBOX_DEFAULT
# 1008 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_9
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_9::
# 1012 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1013 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_9_Text_0, MSGBOX_DEFAULT
# 1017 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_10
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_10::
# 1021 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1022 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_MAXIE
# 1023 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_10_Text_0, MSGBOX_DEFAULT
# 1026 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_MAXIE_LAB, Common_Movement_FaceDown
# 1027 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1028 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 1029 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 1030 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, WalkToMaxie1
# 1031 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1032 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 1033 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MaxieGivePlayerMagmaEmblem
	return


MaxieGivePlayerMagmaEmblem::
# 1037 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1038 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM, 1
# 1039 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 1040 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_MAXIE
# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MaxieGivePlayerMagmaEmblem_Text_0, MSGBOX_DEFAULT
# 1044 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_MaxieLeaving
	return


LittlerootTown_ProfessorBirchsLab_MaxieLeaving::
# 1048 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1049 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 1050 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_MAXIE_LAB, LittlerootTown_ProfessorBirchsLab_Movement_MaxieExitsLab
# 1051 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovementall
# 1052 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto FaceBirchToPlayer
	return


LittlerootTown_ProfessorBirchsLab_Text_Into_11::
# 1056 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1057 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1058 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, WalktoBirch
# 1059 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1060 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Into_11_Text_0, MSGBOX_DEFAULT
# 1063 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_UNUSED_0x91F
# 1064 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 1065 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto BirchGiveTeraOrbToPlayer
	return


FaceBirchToPlayer::
# 1069 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, FacePlayer
# 1070 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement LOCALID_BIRCHS_LAB_BIRCH, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
# 1071 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_Text_Into_11
	return


BirchGiveTeraOrbToPlayer::
# 1075 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1076 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_TERA_ORB, 1
# 1077 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 1078 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 1079 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 1080 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 1082 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 1083 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special HealPlayerParty
# 1084 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_MAXIE_LAB, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
# 1085 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end


# 1090 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_MaxieEnterLab:
# 1091 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 1093 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_right
# 1094 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 1097 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
WalkToMaxie1:
# 1098 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 1099 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_up
# 1100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 1103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_MaxieExitsLab:
# 1104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 1107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 1108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 1111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
WalktoBirch:
# 1112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 1113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_up
# 1114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 1117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
FacePlayer:
# 1118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	face_down
# 1119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
# 1124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 1126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 1128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 1129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 1130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 1134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 1135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 1140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_PROFESSOR_ASSISTANT_KEY_ITEMS, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_1
# 1147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_PROFESSOR_ASSISTANT_KEY_ITEMS, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_2
	return

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_1:
# 1142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_Text_0
# 1144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_ZIGZAGOON, NO_PARTY_SCREEN
# 1145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GivePlayerZigzagmerang
# 1146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, GivePlayerExpShare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_2:
# 1148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_Text_1
# 1150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_LINOONE, NO_PARTY_SCREEN
# 1151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, GiveLinoonmerang
# 1152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, DoNotHaveLineooneInParty
	return


GivePlayerZigzagmerang::
# 1157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GivePlayerZigzagmerang_Text_0
	checkitem ITEM_EXP_SHARE, 1
# 0 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne GivePlayerZigzagmerang_2
# 1163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_ZIGZAGMERANG
# 1164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 1165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_PROFESSOR_ASSISTANT_KEY_ITEMS, 1
GivePlayerZigzagmerang_1:
# 1167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

GivePlayerZigzagmerang_2:
# 1160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GivePlayerZigzagmerang_Text_1
# 1161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_ZIGZAGMERANG
	goto GivePlayerZigzagmerang_1


GivePlayerExpShare::
# 1172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_EXP_SHARE
# 1174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end


GiveLinoonmerang::
# 1179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GiveLinoonmerang_Text_0
# 1181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_LINOONMERANG, 1
# 1182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_EXP_CANDY_S, 10
# 1183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_PROFESSOR_ASSISTANT_KEY_ITEMS, 1
# 1184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GiveLinoonmerang_Text_1
# 1185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


DoNotHaveLineooneInParty::
# 1190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox DoNotHaveLineooneInParty_Text_0
# 1191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


TalktoBirchAboutWhatHappened1::
# 1196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 1198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 1200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox TalktoBirchAboutWhatHappened1_Text_0
# 1201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto BirchTalkingToPlayer
	return


BirchTalkingToPlayer::
# 1205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox BirchTalkingToPlayer_Text_0
# 1208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferpartymonnick STR_VAR_1, 0
# 1209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 1210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox BirchTalkingToPlayer_Text_1
# 1211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto BirchReaction
	return


BirchReaction::
# 1215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PIN
# 1218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_ExclamationMark
# 1219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 48
# 1221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement
# 1222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox BirchReaction_Text_0
# 1223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto ReplyingToBirch
	return


ReplyingToBirch::
# 1227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_NAME_PLAYER
# 1229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox ReplyingToBirch_Text_0
# 1230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto ResearchVirus1
	return


LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
# 1234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 1236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	returnqueststate RESEARCHING_BEV
# 1237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_Birch_2
LittlerootTown_ProfessorBirchsLab_EventScript_Birch_1:
# 1247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 1248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_CUTSCENE, 1, TalktoBirchAboutWhatHappened1
# 1249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 1251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	returnqueststate RESEARCHING_BEV
# 1252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_Birch_5
LittlerootTown_ProfessorBirchsLab_EventScript_Birch_4:
# 1259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 1260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 1261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_2:
# 1238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, CheckPartyHasBevStrainX
# 1239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_Birch_7
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Birch_1

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_5:
# 1253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Birch_Text_1, MSGBOX_YESNO
# 1254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_Birch_9
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Birch_4

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_7:
# 1240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Birch_Text_0
# 1241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	startquest RESEARCHING_BEV
# 1242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	subquestmenu QUEST_MENU_UNLOCK_QUEST, RESEARCHING_BEV, SUBQUEST_WURMPLE
# 1243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_9:
# 1255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Birch_CraftVaccineMenu
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Birch_4


ResearchVirus1::
# 1266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox ResearchVirus1_Text_0
# 1271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto GivePlayerPokeNav
	return


GivePlayerPokeNav::
# 1276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GivePlayerPokeNav_Text_0
# 1279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 1281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 1282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 1283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 1284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setspeaker SP_PROF_BIRCH
# 1285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox GivePlayerPokeNav_Text_1
# 1286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_CUTSCENE, 1
# 1287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	startquest RESEARCHING_BEV
# 1288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


Birch_CraftVaccineMenu::
# 1293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message Birch_CraftVaccineMenu_Text_0
# 1294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	dynmultipush Birch_CraftVaccineMenu_Text_1, 0
# 1296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	dynmultipush Birch_CraftVaccineMenu_Text_2, 1
# 1297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	dynmultipush Birch_CraftVaccineMenu_Text_3, 2
# 1298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	dynmultipush Birch_CraftVaccineMenu_Text_4, 3
# 1299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 1300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Birch_CraftVaccineMenu_1
# 1302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Birch_CraftVaccineMenu_2
# 1304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Birch_CraftVaccineMenu_3
# 1307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox Birch_CraftVaccineMenu_Text_5
# 1308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

Birch_CraftVaccineMenu_1:
# 1301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto CraftCasilcoonVaccine
	return

Birch_CraftVaccineMenu_2:
# 1303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto CraftButterdrillVaccine
	return

Birch_CraftVaccineMenu_3:
# 1305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto CraftDustoxiflyVaccine
	return


CraftCasilcoonVaccine::
# 1314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_SILCOON_SHELL, 5
# 1315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftCasilcoonVaccine_2
CraftCasilcoonVaccine_1:
# 1316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_CASCOON_SHELL, 5
# 1317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftCasilcoonVaccine_5
CraftCasilcoonVaccine_4:
# 1318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_SILCOON_SAMPLE, 1
# 1319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftCasilcoonVaccine_8
CraftCasilcoonVaccine_7:
# 1320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_CASCOON_SAMPLE, 1
# 1321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftCasilcoonVaccine_11
CraftCasilcoonVaccine_10:
# 1323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_SILCOON_SHELL, 5
# 1324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_CASCOON_SHELL, 5
# 1325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_SILCOON_SAMPLE, 1
# 1326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_CASCOON_SAMPLE, 1
# 1327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_CASILCOON_VACCINE, 1
# 1328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CraftCasilcoonVaccine_Text_0
# 1329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CraftCasilcoonVaccine_2:
# 1315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftCasilcoonVaccine_1

CraftCasilcoonVaccine_5:
# 1317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftCasilcoonVaccine_4

CraftCasilcoonVaccine_8:
# 1319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftCasilcoonVaccine_7

CraftCasilcoonVaccine_11:
# 1321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftCasilcoonVaccine_10


CraftButterdrillVaccine::
# 1334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_METAPOD_SHELL, 1
# 1335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftButterdrillVaccine_2
CraftButterdrillVaccine_1:
# 1336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_KAKUNA_SHELL, 1
# 1337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftButterdrillVaccine_5
CraftButterdrillVaccine_4:
# 1338 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_BUTTERFREE_SAMPLE, 1
# 1339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftButterdrillVaccine_8
CraftButterdrillVaccine_7:
# 1340 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_BEEDRILL_SAMPLE, 1
# 1341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftButterdrillVaccine_11
CraftButterdrillVaccine_10:
# 1343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_METAPOD_SHELL, 1
# 1344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_KAKUNA_SHELL, 1
# 1345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_BUTTERFREE_SAMPLE, 1
# 1346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_BEEDRILL_SAMPLE, 1
# 1347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_BUTTERDRILL_VACCINE, 1
# 1348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CraftButterdrillVaccine_Text_0
# 1349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CraftButterdrillVaccine_2:
# 1335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftButterdrillVaccine_1

CraftButterdrillVaccine_5:
# 1337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftButterdrillVaccine_4

CraftButterdrillVaccine_8:
# 1339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftButterdrillVaccine_7

CraftButterdrillVaccine_11:
# 1341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftButterdrillVaccine_10


CraftDustoxiflyVaccine::
# 1354 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_BEAUTIFLY_SAMPLE, 1
# 1355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftDustoxiflyVaccine_2
CraftDustoxiflyVaccine_1:
# 1356 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_DUSTOX_SAMPLE, 1
# 1357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CraftDustoxiflyVaccine_5
CraftDustoxiflyVaccine_4:
# 1359 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_BEAUTIFLY_SAMPLE, 1
# 1360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeitem ITEM_DUSTOX_SAMPLE, 1
# 1361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_DUSTOXIFLY_VACCINE, 1
# 1362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CraftDustoxiflyVaccine_Text_0
# 1363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CraftDustoxiflyVaccine_2:
# 1355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftDustoxiflyVaccine_1

CraftDustoxiflyVaccine_5:
# 1357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto MissingIngredients
	goto CraftDustoxiflyVaccine_4


MissingIngredients::
# 1368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MissingIngredients_Text_0
# 1369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


BadEggVirusQuestNPC::
# 1374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 1375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 1378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_quest_complete RESEARCHING_BEV, BadEggVirusQuestAllDone
# 1381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 0, CheckSubquest0
# 1382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 1, CheckSubquest1
# 1383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 2, CheckSubquest2
# 1384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 3, CheckSubquest3
# 1385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 4, CheckSubquest4
# 1386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 5, CheckSubquest5
# 1387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 6, CheckSubquest6
# 1388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 7, CheckSubquest7
# 1389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 8, CheckSubquest8
# 1390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_subquest_not_complete RESEARCHING_BEV, 9, CheckSubquest9
# 1393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox BadEggVirusQuestNPC_Text_0, MSGBOX_DEFAULT
# 1394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completequest RESEARCHING_BEV
# 1395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


BadEggVirusQuestAllDone::
# 1402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox BadEggVirusQuestAllDone_Text_0, MSGBOX_DEFAULT
# 1403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


CheckSubquest0::
# 1409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest0_2
# 1417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest0_Text_1, MSGBOX_DEFAULT
CheckSubquest0_1:
# 1419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest0_2:
# 1411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest0_Text_0, MSGBOX_DEFAULT
# 1412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 0
# 1413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
	goto CheckSubquest0_1


CheckSubquest1::
# 1424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_SILCOON
# 1425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest1_2
CheckSubquest1_1:
# 1428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_CASCOON
# 1429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest1_5
CheckSubquest1_4:
# 1433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest1_Text_0, MSGBOX_DEFAULT
# 1434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest1_2:
# 1426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Subquest1_Evolved
	goto CheckSubquest1_1

CheckSubquest1_5:
# 1430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Subquest1_Evolved
	goto CheckSubquest1_4


Subquest1_Evolved::
# 1439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox Subquest1_Evolved_Text_0, MSGBOX_DEFAULT
# 1440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 1
# 1443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


CheckSubquest2::
# 1448 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1450 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_CATERPIE
# 1451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_2
CheckSubquest2_1:
# 1452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_METAPOD
# 1453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_5
CheckSubquest2_4:
# 1454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_BUTTERFREE
# 1455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_8
CheckSubquest2_7:
# 1457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WEEDLE
# 1458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_11
CheckSubquest2_10:
# 1459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_KAKUNA
# 1460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_14
CheckSubquest2_13:
# 1461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_BEEDRILL
# 1462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_17
CheckSubquest2_16:
# 1464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_PINECO
# 1465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_20
CheckSubquest2_19:
# 1466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_FORRETRESS
# 1467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_23
CheckSubquest2_22:
# 1468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_SCATTERBUG
# 1469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_26
CheckSubquest2_25:
# 1470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_SPINARAK
# 1471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_29
CheckSubquest2_28:
# 1472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_ARIADOS
# 1473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest2_32
CheckSubquest2_31:
# 1475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, 3
	goto_if_ge CheckSubquest2_35
# 1482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest2_Text_1
CheckSubquest2_34:
# 1484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest2_2:
# 1451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_1

CheckSubquest2_5:
# 1453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_4

CheckSubquest2_8:
# 1455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_7

CheckSubquest2_11:
# 1458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_10

CheckSubquest2_14:
# 1460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_13

CheckSubquest2_17:
# 1462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_16

CheckSubquest2_20:
# 1465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_19

CheckSubquest2_23:
# 1467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_22

CheckSubquest2_26:
# 1469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_25

CheckSubquest2_29:
# 1471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_28

CheckSubquest2_32:
# 1473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_TEMP_1, 1
	goto CheckSubquest2_31

CheckSubquest2_35:
# 1476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest2_Text_0, MSGBOX_DEFAULT
# 1477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 2
	goto CheckSubquest2_34


CheckSubquest3::
# 1489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_SILCOON_SAMPLE, 6
# 1490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest3_2
CheckSubquest3_1:
# 1502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest3_Text_1
# 1503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest3_2:
# 1491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_CASCOON_SAMPLE, 6
# 1492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest3_4
	goto CheckSubquest3_1

CheckSubquest3_4:
# 1493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest3_Text_0, MSGBOX_DEFAULT
# 1494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 3
# 1497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


CheckSubquest4::
# 1508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_SILCOON_SHELL, 30
# 1509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest4_2
CheckSubquest4_1:
# 1521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest4_Text_1
# 1522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest4_2:
# 1510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkitem ITEM_CASCOON_SHELL, 30
# 1511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest4_4
	goto CheckSubquest4_1

CheckSubquest4_4:
# 1512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest4_Text_0, MSGBOX_DEFAULT
# 1513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 4
# 1516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


CheckSubquest5::
# 1528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest5_2
# 1536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest5_Text_1
CheckSubquest5_1:
# 1538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest5_2:
# 1530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest5_Text_0, MSGBOX_DEFAULT
# 1531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 5
# 1532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
	goto CheckSubquest5_1


CheckSubquest6::
# 1544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest6_2
# 1552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest6_Text_1
CheckSubquest6_1:
# 1554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest6_2:
# 1546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest6_Text_0, MSGBOX_DEFAULT
# 1547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 6
# 1548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
	goto CheckSubquest6_1


CheckSubquest7::
# 1560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest7_2
# 1568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest6_Text_1
CheckSubquest7_1:
# 1570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest7_2:
# 1562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest7_Text_0, MSGBOX_DEFAULT
# 1563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 7
# 1564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
	goto CheckSubquest7_1


CheckSubquest8::
# 1576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest8_2
# 1584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest6_Text_1
CheckSubquest8_1:
# 1586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest8_2:
# 1578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest8_Text_0, MSGBOX_DEFAULT
# 1579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 8
# 1580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
	goto CheckSubquest8_1


CheckSubquest9::
# 1592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkspecies SPECIES_WURMPLE
# 1593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CheckSubquest9_2
# 1603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest6_Text_1
CheckSubquest9_1:
# 1605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

CheckSubquest9_2:
# 1594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest9_Text_0, MSGBOX_DEFAULT
# 1595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	completesubquest RESEARCHING_BEV, 9
# 1596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 1600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox CheckSubquest9_Text_1, MSGBOX_DEFAULT
	goto CheckSubquest9_1


LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_0:
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "???$"

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent_Text_1:
# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ah, you must be {PLAYER}{KUN}!\n"
	.string "Welcome to my lab!\l"
	.string "I am Professor Birch.\n$"

LittlerootTown_ProfessorBirchsLab_Text_Into_1_Text_0:
# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I see you found my bag.\n"
	.string "I am glad you got your starter.\l"
	.string "Did you hear about the news earlier?$"

LittlerootTown_ProfessorBirchsLab_Text_Into_2_Text_0:
# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's what I came here for!\n"
	.string "What the hell is going on?\l"
	.string "Is this virus serious?$"

LittlerootTown_ProfessorBirchsLab_Text_Into_3_Text_0:
# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I don't know much about it yet,\n"
	.string "but it seems to be spreading fast.\l"
	.string "I need your help to find out more.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_4_Text_0:
# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Professor Birch, the man I want to see.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_5_Text_0:
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Maxie? What are you doing here?\n"
	.string "Are you here about the virus?$"

LittlerootTown_ProfessorBirchsLab_Text_Into_6_Text_0:
# 985 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I want to help you, Professor Birch.\n"
	.string "I know a lot about viruses I can help.\l"
	.string "Let Team Magma help you.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_7_Text_0:
# 994 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I don't know if I can trust you, Maxie.\n"
	.string "But I could use all the help I can get.\l"
	.string "Let's work together.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_8_Text_0:
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Great! I'll get to work right away!\n"
	.string "Let's find out more about this virus!$"

LittlerootTown_ProfessorBirchsLab_Text_Into_9_Text_0:
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "On one condition,\n"
	.string "{PLAYER} must assist you.\l"
	.string "Or the deal is off.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_10_Text_0:
# 1023 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Deal. {PLAYER},\n"
	.string "Welcome to Team Magma!\l"
	.string "Here's your Magma Emblem.$"

MaxieGivePlayerMagmaEmblem_Text_0:
# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going back to\n"
	.string "the HQ. I'll return\l"
	.string "as soon as possible.$"

LittlerootTown_ProfessorBirchsLab_Text_Into_11_Text_0:
# 1060 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Good luck on your investigation!\n"
	.string "Come back if something happens.\l"
	.string "{PLAYER} Take this with you.$"

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_Text_0:
# 1142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hello I am the assistant of Professor\n"
	.string "Birch. You must be {PLAYER}. I make\l"
	.string "key items based on Pokémon Do you\l"
	.string "happen to have a Zigzagoon?$"

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter_Text_1:
# 1148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Welcome back {PLAYER}! I have\n"
	.string "another upgrade for that Zigzagmerang.\l"
	.string "Its called a Linoonmerang. Did you\l"
	.string "evolved your Zigzagoon into a Linoone?$"

GivePlayerZigzagmerang_Text_0:
# 1158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well done! Here's the Key Item and an\n"
	.string "Exp Share.$"

GivePlayerZigzagmerang_Text_1:
# 1160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well done! Here's the Key Item.$"

GiveLinoonmerang_Text_0:
# 1180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well done! Here's the upgraded Key Item$"

GiveLinoonmerang_Text_1:
# 1184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "This gives you 35% chance to get 3\n"
	.string "items in one battle. It also stacks with\l"
	.string "the Zigzagmerang.$"

DoNotHaveLineooneInParty_Text_0:
# 1190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You do not have Linoone in your party.\n"
	.string "Come back when you have found one.$"

TalktoBirchAboutWhatHappened1_Text_0:
# 1200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Professor, we have a problem. Its bad.$"

BirchTalkingToPlayer_Text_0:
# 1207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What's wrong {PLAYER}?$"

BirchTalkingToPlayer_Text_1:
# 1210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{STR_VAR_1} got infected with\n"
	.string "Pokérus.$"

BirchReaction_Text_0:
# 1222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Really!?$"

ReplyingToBirch_Text_0:
# 1229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yeah! I don't know if its infected with\n"
	.string "the virus on the news.$"

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_Text_0:
# 1240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ah! One of your Pokémon seems to be\n"
	.string "infected with Strain X of the Bad Egg\l"
	.string "Virus!\p"
	.string "I've been looking into this phenomenon.\n"
	.string "Will you help me research it?$"

LittlerootTown_ProfessorBirchsLab_EventScript_Birch_Text_1:
# 1253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ah, {PLAYER}! Did you need me to\n"
	.string "synthesize a vaccine from your\l"
	.string "samples?$"

ResearchVirus1_Text_0:
# 1268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well, for starters we know it comes from\n"
	.string "Pokerus which is actually a beneficial\l"
	.string "virus. It seems like your Pokémon got\l"
	.string "exposed the wild. You need to do\l"
	.string "research so we can study this virus.\l"
	.string "Before you do that let me give you\l"
	.string "something to communicate with you.$"

GivePlayerPokeNav_Text_0:
# 1278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} recieved the PokeNav App\n"
	.string "from Professor Birch.$"

GivePlayerPokeNav_Text_1:
# 1285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Its the PokéNav but now its an app on\n"
	.string "your tablet.$"

Birch_CraftVaccineMenu_Text_0:
# 1293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Which vaccine should I synthesize?$"

Birch_CraftVaccineMenu_Text_1:
# 1295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Casilcoon Vaccine$"

Birch_CraftVaccineMenu_Text_2:
# 1296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Butterdrill Vaccine$"

Birch_CraftVaccineMenu_Text_3:
# 1297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Dustoxifly Vaccine$"

Birch_CraftVaccineMenu_Text_4:
# 1298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Cancel$"

Birch_CraftVaccineMenu_Text_5:
# 1307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let me know if you change your mind.$"

CraftCasilcoonVaccine_Text_0:
# 1328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here is your Casilcoon Vaccine!$"

CraftButterdrillVaccine_Text_0:
# 1348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here is your Butterdrill Vaccine!$"

CraftDustoxiflyVaccine_Text_0:
# 1362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here is your Dustoxifly Vaccine!$"

MissingIngredients_Text_0:
# 1368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You don't have the necessary shells and\n"
	.string "samples for this vaccine.$"

BadEggVirusQuestNPC_Text_0:
# 1393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You have completed all 10 tasks!\nThe Bad Egg Virus research is complete!$"

BadEggVirusQuestAllDone_Text_0:
# 1402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to you, the Bad Egg Virus\nhas been fully researched!$"

CheckSubquest0_Text_0:
# 1411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Wow, you caught a Wurmple!$"

CheckSubquest0_Text_1:
# 1417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your first task, please catch a\n"
	.string "Wurmple and show it to me!$"

CheckSubquest1_Text_0:
# 1433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your second task, please evolve\n"
	.string "your Wurmple into Silcoon or Cascoon!$"

Subquest1_Evolved_Text_0:
# 1439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Excellent! You evolved your Wurmple!$"

CheckSubquest2_Text_0:
# 1476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You found three different Bug-types!$"

CheckSubquest2_Text_1:
# 1482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your third task, go to the Petalburg\n"
	.string "Woods and find three different bug\l"
	.string "type Pokémon that's not part of the\l"
	.string "Wurmple family.$"

CheckSubquest3_Text_0:
# 1493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh! You collected all the samples!$"

CheckSubquest3_Text_1:
# 1502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your fourth task, take 6 samples\n"
	.string "from Silcoon and 6 from Cascoon. If you\l"
	.string "don't have one or the other there's\l"
	.string "plenty in the Petalburg Woods.$"

CheckSubquest4_Text_0:
# 1512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Incredible! You've collected\nenough shells!$"

CheckSubquest4_Text_1:
# 1521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your fifth task, please collect 30\n"
	.string "Silcoon Shells and 30 Cascoon Shells!$"

CheckSubquest5_Text_0:
# 1530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You completed the sixth task!$"

CheckSubquest5_Text_1:
# 1536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your fourth task, Talk to the\n"
	.string "professor. Its time to make the\l"
	.string "vaccines. Make six vaccines.$"

CheckSubquest6_Text_0:
# 1546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You completed the seventh task!$"

CheckSubquest6_Text_1:
# 1552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "For your fourth task, please do that!$"

CheckSubquest7_Text_0:
# 1562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You completed the eighth task!$"

CheckSubquest8_Text_0:
# 1578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You completed the ninth task!$"

CheckSubquest9_Text_0:
# 1594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You completed the final task!$"

CheckSubquest9_Text_1:
# 1600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Talk to me again to finalize the research!$"
