# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts::
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret::
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp:
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC	
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsMale_Text_0:
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER},\n"
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "how do you like your new room?"
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "$"
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsMale_Text_1:
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "I love my new room, mom! Its pretty\n"
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "cool! despite it being small.\l"
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "I can make this room work for me!$"
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsMale_Text_2:
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good,\n"
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's put away neatly!\l"
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Meet me in the living room.$"
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsFemale_Text_0:
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "I love my new room, mom! Its pretty\n"
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "cute for a small room!\l"
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Besides I can make it work for me!$"
# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{REGION} region map.$"
# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

DadsPackage::
# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lock
# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox DadsPackage_Text_0
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitfanfare
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	giveitem ITEM_SUPER_POTION, 10
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	giveitem ITEM_FULL_HEAL, 10
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	giveitem ITEM_CRAFT_BUNDLE, 1
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq DadsPackage_1
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject LOCALID_DADS_PACKAGE_FEMALE
# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	release
	end

DadsPackage_1:
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject LOCALID_DADS_PACKAGE_MALE
# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	release
	end


DadsPackage_Text_0:
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} obtained Pokédex.$"

PlayersHouse_2F_Text_ClockIsStopped::
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"
