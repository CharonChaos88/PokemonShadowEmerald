# 1 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_MapScripts::
# 2 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
# 3 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 4 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 5 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 6 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_OnTransition:
# 7 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PETALBURG_CITY
# 8 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 9 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
# 12 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
# 13 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 14 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 15 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
# 16 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
# 17 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 18 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 19 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Woman::
# 20 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 21 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 22 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
# 23 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsStarterInParty
# 24 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
# 25 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 26 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 27 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 28 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
# 29 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
# 30 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
# 31 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
# 32 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 33 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 34 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
# 36 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
# 37 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 38 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 39 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
# 40 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
# 41 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 42 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 43 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
# 44 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
# 45 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 46 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
# 48 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "That PC-based POKéMON Storage\n"
# 49 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "System…\p"
# 50 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Whoever made it must be some kind\n"
# 51 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "of a scientific wizard!$"
# 52 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
# 54 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "When my POKéMON ate an\n"
# 55 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "ORAN BERRY, it regained HP!$"
# 56 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 57 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
# 58 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "There are many types of POKéMON.\p"
# 59 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "All types have their strengths and\n"
# 60 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "weaknesses against other types.\p"
# 61 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the types of POKéMON,\n"
# 62 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "a battle could be easy or hard.$"
# 63 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 64 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
# 65 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TREECKO\n"
# 66 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a GRASS type.\p"
# 67 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the WATER and\n"
# 68 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "GROUND types.\p"
# 69 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against FIRE-type\n"
# 70 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 71 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 72 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
# 73 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TORCHIC\n"
# 74 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a FIRE type.\p"
# 75 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the GRASS and\n"
# 76 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "BUG types.\p"
# 77 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against WATER-type\n"
# 78 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "POKéMON.$"
# 79 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 80 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
# 81 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your MUDKIP\n"
# 82 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a WATER type.\p"
# 83 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the FIRE type.\p"
# 84 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against GRASS-type\n"
# 85 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "and ELECTRIC-type POKéMON.$"

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
# 90 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	switch VAR_PKMN_LEAGUE_REGISTRATION
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_Nurse_2
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_Nurse_3
	return

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_2:
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration
	return

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_3:
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto PetalburgCity_PokemonCenter_1F_EventScript_Nurse_PostRegistration
# 93 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end


PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration::
# 99 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_0, MSGBOX_YESNO
# 102 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_2
# 111 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_3
	return

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_2:
# 104 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 105 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_1
# 108 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_PKMN_LEAGUE_REGISTRATION, 0
# 109 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_3:
# 112 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 113 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_2
# 116 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_PKMN_LEAGUE_REGISTRATION, 1
# 117 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 118 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end


PetalburgCity_PokemonCenter_1F_EventScript_Nurse_PostRegistration::
# 125 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
# 126 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 127 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 128 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 129 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
	end


PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_0:
# 99 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Pokémon Center!.\n"
	.string "Would you like to register for the\l"
	.string "Pokémon League?$"

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_1:
# 105 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "You have chosen not to register for the\n"
	.string "Pokémon League. You can register\n"
	.string "at any time by speaking to me again.$"

PetalburgCity_PokemonCenter_1F_EventScript_Nurse_LeagueRegistration_Text_2:
# 113 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "You have successfully registered for\nthe"
	.string " Pokémon League!\n You can now challenge the"
	.string "Gym Leaders $"
