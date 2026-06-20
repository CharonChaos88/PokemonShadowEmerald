# 1 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_MapScripts::
# 2 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
# 3 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 4 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 5 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 6 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_OnTransition:
# 7 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_OLDALE_TOWN
# 8 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 9 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
# 13 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 15 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 16 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 17 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 18 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 19 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
# 20 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
# 21 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Boy::
# 24 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
# 25 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_Girl::
# 28 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 29 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 30 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
# 31 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
# 32 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 33 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 34 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 35 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
# 36 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
# 37 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
# 38 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	end
# 39 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 40 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
# 41 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "That PC in the corner there is\n"
# 42 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "for any POKéMON TRAINER to use.\p"
# 43 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Naturally, that means you're welcome\n"
# 44 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "to use it, too.$"
# 45 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 46 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
# 47 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "POKéMON CENTERS are great!\p"
# 48 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You can use their services as much\n"
# 49 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "as you like, and it's all for free.\l"
# 50 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You never have to worry!$"
# 51 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 52 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
# 53 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The POKéMON WIRELESS CLUB on\n"
# 54 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "the second floor was built recently.\p"
# 55 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "But they say they're still making\n"
# 56 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "adjustments.$"
# 57 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
# 59 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The POKéMON WIRELESS CLUB on\n"
# 60 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "the second floor was built recently.\p"
# 61 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I traded POKéMON right away.$"

IntroCheck::
# 67 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_MEGA_ALAKAZAM_INTRO, IntroCheck_1
# 70 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_MEGA_ALAKAZAM_INTRO, IntroCheck_4
	return

IntroCheck_1:
# 68 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MegaAlakazamIntro
	return

IntroCheck_4:
# 71 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium
	return


MegaAlakazamIntro::
# 78 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_UNKNOWN
# 79 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamIntro_Text_0
# 80 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PlayerTalkingToMegaAlakazam
	return


PlayerTalkingToMegaAlakazam::
# 84 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 85 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playse SE_PIN
# 86 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitse
# 87 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmovement
# 88 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	delay 48
# 89 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker PlayerTalkingToMegaAlakazam_Text_0
# 90 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox PlayerTalkingToMegaAlakazam_Text_1
# 91 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MegaAlakazamTalkingtoPlayer1
	return


MegaAlakazamTalkingtoPlayer1::
# 96 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_UNKNOWN
# 97 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_0
# 98 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_1
# 99 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_2
# 100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_3
# 102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker PlayerTalkingToMegaAlakazam_Text_0
# 103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_4
# 104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_5
# 106 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_6
# 107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MegaAlakazamTalkingtoPlayer1_Text_7
# 108 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_WISDOM_SPOON, 1
# 109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_INTRO, 1
# 110 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_MOVE_TUTOR, 1
# 111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_ITEM_SHOP, 1
# 112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_CRAFT_ITEMS, 1
# 113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_WONDER_TRADE, 1
# 114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_POKEMON_INFUSION, 1
# 115 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_MEGA_ALAKAZAM_INTRO
# 116 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_MEGA_ALAKAZAM_INTRO, MegaAlakazamTalkingtoPlayer1_1
	return

MegaAlakazamTalkingtoPlayer1_1:
# 117 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium
# 118 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


PokemonCompendium::
# 125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox PokemonCompendium_Text_0
# 129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultichoice 17, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, PokemonCompendium_Text_1, PokemonCompendium_Text_2, PokemonCompendium_Text_3, PokemonCompendium_Text_4, PokemonCompendium_Text_5, PokemonCompendium_Text_6
# 145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 0, PokemonCompendium_3
# 148 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 1, PokemonCompendium_4
# 150 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 2, PokemonCompendium_5
# 152 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 3, PokemonCompendium_6
# 154 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 4, PokemonCompendium_7
# 156 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 5, PokemonCompendium_8
PokemonCompendium_1:
# 159 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, WisdomExitScript
	return

PokemonCompendium_3:
# 147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	goto PokemonCompendium_1

PokemonCompendium_4:
# 149 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenu
	goto PokemonCompendium_1

PokemonCompendium_5:
# 151 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Wonder_Trade
	goto PokemonCompendium_1

PokemonCompendium_6:
# 153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Cacoon_Ritual
	goto PokemonCompendium_1

PokemonCompendium_7:
# 155 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	goto PokemonCompendium_1

PokemonCompendium_8:
# 157 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto WisdomExitScript
	goto PokemonCompendium_1


MoveTutorMenu::
# 162 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_MEGA_ALAKAZAM_MOVE_TUTOR, 1
	goto_if_eq MoveTutorMenu_1
# 170 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenuBadgeList
	return

MoveTutorMenu_1:
# 163 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MoveTutorMenu_Text_0
# 167 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_MOVE_TUTOR, 2
# 168 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenuBadgeList
	return


OtherServices::
# 178 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox OtherServices_Text_0, MSGBOX_YESNO
# 179 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq OtherServices_1
# 183 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto WisdomExitScript
# 184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_MOVETUTOR_SET
	return

OtherServices_1:
# 180 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_MOVETUTOR_SET
# 181 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	return


MoveTutorQuestion::
# 189 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MoveTutorQuestion_Text_0, MSGBOX_YESNO
# 190 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MoveTutorQuestion_1
# 196 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MoveTutorQuestion_2
	return

MoveTutorQuestion_1:
# 191 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special ChooseMonForMoveTutor
# 192 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutorMenuBadgeList
# 193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 194 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	return
# 195 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_MOVETUTOR_SET, MoveTutorMenuBadgeList
	return

MoveTutorQuestion_2:
# 197 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenuBadgeList
# 198 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_MOVETUTOR_SET
	return


WisdomExitScript::
# 202 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 203 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox WisdomExitScript_Text_0
# 204 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_MOVETUTOR_SET
# 205 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


PokemonCompendium2::
# 211 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 214 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultichoice 17, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, PokemonCompendium_Text_1, PokemonCompendium_Text_2, PokemonCompendium_Text_3, PokemonCompendium_Text_4, PokemonCompendium_Text_5, PokemonCompendium_Text_6
# 230 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 231 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 0, PokemonCompendium2_3
# 233 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 1, PokemonCompendium2_4
# 235 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 2, PokemonCompendium2_5
# 237 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 3, PokemonCompendium2_6
# 239 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 4, PokemonCompendium2_7
# 241 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 5, PokemonCompendium2_8
PokemonCompendium2_1:
# 244 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, WisdomExitScript
	return

PokemonCompendium2_3:
# 232 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	goto PokemonCompendium2_1

PokemonCompendium2_4:
# 234 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenu
	goto PokemonCompendium2_1

PokemonCompendium2_5:
# 236 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Wonder_Trade
	goto PokemonCompendium2_1

PokemonCompendium2_6:
# 238 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Cacoon_Ritual
	goto PokemonCompendium2_1

PokemonCompendium2_7:
# 240 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	goto PokemonCompendium2_1

PokemonCompendium2_8:
# 242 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto WisdomExitScript
	goto PokemonCompendium2_1


PokemonCompendium3::
# 249 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultichoice 17, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, PokemonCompendium_Text_1, PokemonCompendium_Text_2, PokemonCompendium_Text_3, PokemonCompendium_Text_4, PokemonCompendium_Text_5, PokemonCompendium_Text_6
# 265 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 266 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 0, PokemonCompendium3_3
# 268 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 1, PokemonCompendium3_4
# 270 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 2, PokemonCompendium3_5
# 272 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 3, PokemonCompendium3_6
# 274 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 4, PokemonCompendium3_7
# 276 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 5, PokemonCompendium3_8
PokemonCompendium3_1:
# 279 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, WisdomExitScript
	return

PokemonCompendium3_3:
# 267 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	goto PokemonCompendium3_1

PokemonCompendium3_4:
# 269 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenu
	goto PokemonCompendium3_1

PokemonCompendium3_5:
# 271 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Wonder_Trade
	goto PokemonCompendium3_1

PokemonCompendium3_6:
# 273 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Cacoon_Ritual
	goto PokemonCompendium3_1

PokemonCompendium3_7:
# 275 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	goto PokemonCompendium3_1

PokemonCompendium3_8:
# 277 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto WisdomExitScript
	goto PokemonCompendium3_1


ItemShopMenu::
# 283 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_MEGA_ALAKAZAM_ITEM_SHOP, 1
	goto_if_eq ItemShopMenu_1
# 289 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return

ItemShopMenu_1:
# 284 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 285 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox FirstTimeItemShop, MSGBOX_DEFAULT
# 286 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_MEGA_ALAKAZAM_ITEM_SHOP, 2
# 287 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


ItemShopMenuList::
# 294 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultichoice 17, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, ItemShopMenuList_Text_0, ItemShopMenuList_Text_1, ItemShopMenuList_Text_2, ItemShopMenuList_Text_3, ItemShopMenuList_Text_4, ItemShopMenuList_Text_5, ItemShopMenuList_Text_6, ItemShopMenuList_Text_7, ItemShopMenuList_Text_8, ItemShopMenuList_Text_9, ItemShopMenuList_Text_10
# 314 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 315 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 0, ItemShopMenuList_3
# 317 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 1, ItemShopMenuList_4
# 319 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 2, ItemShopMenuList_5
# 321 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 3, ItemShopMenuList_6
# 323 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 4, ItemShopMenuList_7
# 325 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 5, ItemShopMenuList_8
# 327 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 6, ItemShopMenuList_9
# 329 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 7, ItemShopMenuList_10
# 331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 8, ItemShopMenuList_11
# 333 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 9, ItemShopMenuList_12
# 335 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 10, ItemShopMenuList_13
ItemShopMenuList_1:
# 338 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, PokemonCompendium2
	return

ItemShopMenuList_3:
# 316 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto NoBadgeItemShop
	goto ItemShopMenuList_1

ItemShopMenuList_4:
# 318 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_5:
# 320 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto KnuckleBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_6:
# 322 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto DynamoBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_7:
# 324 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto HeatBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_8:
# 326 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto BalanceBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_9:
# 328 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto FeatherBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_10:
# 330 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MindBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_11:
# 332 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto RainBadgeItemShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_12:
# 334 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto ItemShopMenuList_1

ItemShopMenuList_13:
# 336 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	goto ItemShopMenuList_1


NoBadgeItemShop::
# 344 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 345 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message NoBadgeItemShop_Text_0
# 346 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart NoBadgeShop
# 347 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
NoBadgeShop:
# 351 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 352 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POTION
# 353 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_AWAKENING
# 354 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 355 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 356 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 357 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 358 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

StoneBadgeItemShopMenu::
# 362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 363 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, StoneBadgeItemShopMenu_1
# 369 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneBadgeItemShop
	return

StoneBadgeItemShopMenu_1:
# 365 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 366 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox StoneBadgeItemShopMenu_Text_0
# 367 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


StoneBadgeItemShop::
# 374 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 375 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message StoneBadgeItemShop_Text_0
# 376 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 377 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart StoneBadgeShop
# 378 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 382 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
StoneBadgeShop:
# 383 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 384 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 385 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 386 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_AWAKENING
# 387 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 388 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 389 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 390 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 391 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEL
# 392 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ETHER
	.2byte ITEM_NONE

KnuckleBadgeItemShopMenu::
# 396 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 397 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, KnuckleBadgeItemShopMenu_1
# 403 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto KnuckleBadgeItemShop
	return

KnuckleBadgeItemShopMenu_1:
# 399 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 400 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox KnuckleBadgeItemShopMenu_Text_0
# 401 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


KnuckleBadgeItemShop::
# 408 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 409 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message KnuckleBadgeItemShop_Text_0
# 410 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 411 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart KnuckleBadgeShop
# 412 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 416 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
KnuckleBadgeShop:
# 417 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 418 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 419 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 420 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 421 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 422 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 423 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 424 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 425 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ELIXIR
	.2byte ITEM_NONE

DynamoBadgeItemShopMenu::
# 429 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 430 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, DynamoBadgeItemShopMenu_1
# 436 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto DynamoBadgeItemShop
	return

DynamoBadgeItemShopMenu_1:
# 432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox DynamoBadgeItemShopMenu_Text_0
# 434 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


DynamoBadgeItemShop::
# 441 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message DynamoBadgeItemShop_Text_0
# 443 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart DynamoBadgeShop
# 445 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 449 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
DynamoBadgeShop:
# 450 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 451 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 452 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 454 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 455 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 456 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 457 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 458 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 459 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 460 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ELIXIR
# 461 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_NONE

HeatBadgeItemShopMenu::
# 465 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 466 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, HeatBadgeItemShopMenu_1
# 472 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto HeatBadgeItemShop
	return

HeatBadgeItemShopMenu_1:
# 468 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 469 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox HeatBadgeItemShopMenu_Text_0
# 470 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


HeatBadgeItemShop::
# 477 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 478 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message HeatBadgeItemShop_Text_0
# 479 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 480 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart HeatBadgeShop
# 481 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 485 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
HeatBadgeShop:
# 486 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 487 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 488 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 489 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 490 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 491 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 492 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NET_BALL
# 493 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 494 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 495 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 496 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 497 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 498 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 499 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ELIXIR
# 500 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_NONE

BalanceBadgeItemShopMenu::
# 504 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 505 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, BalanceBadgeItemShopMenu_1
# 511 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto BalanceBadgeItemShop
	return

BalanceBadgeItemShopMenu_1:
# 507 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 508 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox BalanceBadgeItemShopMenu_Text_0
# 509 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


BalanceBadgeItemShop::
# 516 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message BalanceBadgeItemShop_Text_0
# 518 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 519 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart BalanceBadgeShop
# 520 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
BalanceBadgeShop:
# 525 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 526 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 527 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 528 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 529 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 530 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 531 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NET_BALL
# 532 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 533 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 534 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 535 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 536 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 537 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 538 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 539 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 540 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 541 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE

FeatherBadgeItemShopMenu::
# 545 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 546 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, FeatherBadgeItemShopMenu_1
# 552 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto FeatherBadgeItemShop
	return

FeatherBadgeItemShopMenu_1:
# 548 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 549 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox FeatherBadgeItemShopMenu_Text_0
# 550 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


FeatherBadgeItemShop::
# 557 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 558 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message FeatherBadgeItemShop_Text_0
# 559 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 560 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart FeatherBadgeShop
# 561 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 565 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
FeatherBadgeShop:
# 566 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 567 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 568 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 569 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 570 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 571 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 572 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NET_BALL
# 573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 574 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 575 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 576 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 577 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 578 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 579 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 580 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 581 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 582 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE

MindBadgeItemShopMenu::
# 587 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 588 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, MindBadgeItemShopMenu_1
# 594 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MindBadgeItemShop
	return

MindBadgeItemShopMenu_1:
# 590 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 591 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MindBadgeItemShopMenu_Text_0
# 592 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


MindBadgeItemShop::
# 599 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 600 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message MindBadgeItemShop_Text_0
# 601 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 602 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart MindBadgeShop
# 603 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 607 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
MindBadgeShop:
# 608 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 609 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 610 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 611 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 612 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 613 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 614 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NET_BALL
# 615 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 616 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 617 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 618 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 619 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 620 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 621 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 622 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 623 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE

RainBadgeItemShopMenu::
# 628 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 629 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE08_GET, RainBadgeItemShopMenu_1
# 635 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto RainBadgeItemShop
	return

RainBadgeItemShopMenu_1:
# 631 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox RainBadgeItemShopMenu_Text_0
# 633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


RainBadgeItemShop::
# 640 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 641 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	message RainBadgeItemShop_Text_0
# 642 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 643 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	pokemart RainBadgeShop
# 644 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ItemShopMenuList
	return


	.align 2
# 648 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
RainBadgeShop:
# 649 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 650 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 651 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 652 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 653 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 654 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 655 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 656 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_PP_UP
	.2byte ITEM_NONE

EvolutionStoneShopMenu::
# 660 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 661 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 664 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_0, ITEM_FIRE_STONE
# 665 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_1, ITEM_WATER_STONE
# 666 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_2, ITEM_THUNDER_STONE
# 667 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_3, ITEM_LEAF_STONE
# 668 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_4, ITEM_ICE_STONE
# 669 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_5, ITEM_MOON_STONE
# 670 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_6, ITEM_SUN_STONE
# 671 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_7, ITEM_SHINY_STONE
# 672 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_8, ITEM_DUSK_STONE
# 673 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush EvolutionStoneShopMenu_Text_9, ITEM_DAWN_STONE
# 676 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 11, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_SHOW_ITEM
# 679 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EvolutionStoneShopMenu_2
EvolutionStoneShopMenu_1:
# 684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_FIRE_STONE
	goto_if_eq EvolutionStoneShopMenu_5
# 685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_WATER_STONE
	goto_if_eq EvolutionStoneShopMenu_6
# 686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_THUNDER_STONE
	goto_if_eq EvolutionStoneShopMenu_7
# 687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_LEAF_STONE
	goto_if_eq EvolutionStoneShopMenu_8
# 688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_ICE_STONE
	goto_if_eq EvolutionStoneShopMenu_9
# 689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_MOON_STONE
	goto_if_eq EvolutionStoneShopMenu_10
# 690 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_SUN_STONE
	goto_if_eq EvolutionStoneShopMenu_11
# 691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_SHINY_STONE
	goto_if_eq EvolutionStoneShopMenu_12
# 692 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_DUSK_STONE
	goto_if_eq EvolutionStoneShopMenu_13
# 693 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, ITEM_DAWN_STONE
	goto_if_eq EvolutionStoneShopMenu_14
EvolutionStoneShopMenu_4:
# 698 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_FIRE_STONE
	goto_if_eq EvolutionStoneShopMenu_26
# 716 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_WATER_STONE
	goto_if_eq EvolutionStoneShopMenu_27
# 734 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_THUNDER_STONE
	goto_if_eq EvolutionStoneShopMenu_28
# 752 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_LEAF_STONE
	goto_if_eq EvolutionStoneShopMenu_29
# 770 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_ICE_STONE
	goto_if_eq EvolutionStoneShopMenu_30
# 788 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_MOON_STONE
	goto_if_eq EvolutionStoneShopMenu_31
# 806 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_SUN_STONE
	goto_if_eq EvolutionStoneShopMenu_32
# 824 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_SHINY_STONE
	goto_if_eq EvolutionStoneShopMenu_33
# 842 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_DUSK_STONE
	goto_if_eq EvolutionStoneShopMenu_34
# 860 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, ITEM_DAWN_STONE
	goto_if_eq EvolutionStoneShopMenu_35
EvolutionStoneShopMenu_25:
# 877 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end

EvolutionStoneShopMenu_2:
# 680 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	goto EvolutionStoneShopMenu_1

EvolutionStoneShopMenu_5:
# 684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_FIRE_STONE
# 684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FIRE_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_6:
# 685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_WATER_STONE
# 685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_WATER_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_7:
# 686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_THUNDER_STONE
# 686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_THUNDER_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_8:
# 687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_LEAF_STONE
# 687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_LEAF_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_9:
# 688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_ICE_STONE
# 688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ICE_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_10:
# 689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_MOON_STONE
# 689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_MOON_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_11:
# 690 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_SUN_STONE
# 690 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SUN_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_12:
# 691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_SHINY_STONE
# 691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SHINY_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_13:
# 692 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_DUSK_STONE
# 692 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_DUSK_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_14:
# 693 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, ITEM_DAWN_STONE
# 693 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_DAWN_STONE
	goto EvolutionStoneShopMenu_4

EvolutionStoneShopMenu_26:
# 699 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 700 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_10, MSGBOX_YESNO
# 701 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_46
# 712 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_27:
# 717 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 718 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_13, MSGBOX_YESNO
# 719 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_49
# 730 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_28:
# 735 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 736 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_16, MSGBOX_YESNO
# 737 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_52
# 748 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_29:
# 753 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 754 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_19, MSGBOX_YESNO
# 755 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_55
# 766 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_30:
# 771 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 772 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_22, MSGBOX_YESNO
# 773 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_58
# 784 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_31:
# 789 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 790 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_24, MSGBOX_YESNO
# 791 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_61
# 802 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_32:
# 807 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 808 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_26, MSGBOX_YESNO
# 809 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_64
# 820 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_33:
# 825 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 826 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_28, MSGBOX_YESNO
# 827 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_67
# 838 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_34:
# 843 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 844 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_30, MSGBOX_YESNO
# 845 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_70
# 856 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_35:
# 861 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 862 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_32, MSGBOX_YESNO
# 863 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EvolutionStoneShopMenu_73
# 874 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_46:
	checkitem ITEM_RED_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_77
EvolutionStoneShopMenu_76:
# 707 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_12
# 708 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_FIRE_STONE
# 709 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_RED_SHARD, 1
# 710 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_49:
	checkitem ITEM_BLUE_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_80
EvolutionStoneShopMenu_79:
# 725 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_15
# 726 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_WATER_STONE
# 727 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLUE_SHARD, 1
# 728 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_52:
	checkitem ITEM_YELLOW_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_83
EvolutionStoneShopMenu_82:
# 743 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_18
# 744 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_THUNDER_STONE
# 745 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_YELLOW_SHARD, 1
# 746 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_55:
	checkitem ITEM_GREEN_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_86
EvolutionStoneShopMenu_85:
# 761 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_21
# 762 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_LEAF_STONE
# 763 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_GREEN_SHARD, 1
# 764 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_58:
	checkitem ITEM_BLUE_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_89
EvolutionStoneShopMenu_88:
# 779 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_23
# 780 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_ICE_STONE
# 781 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLUE_SHARD, 1
# 782 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_61:
	checkitem ITEM_BLUE_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_92
EvolutionStoneShopMenu_91:
# 797 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_25
# 798 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_MOON_STONE
# 799 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLUE_SHARD, 1
# 800 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_64:
	checkitem ITEM_RED_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_95
EvolutionStoneShopMenu_94:
# 815 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_27
# 816 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 817 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_RED_SHARD, 1
# 818 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_67:
	checkitem ITEM_YELLOW_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_98
EvolutionStoneShopMenu_97:
# 833 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_29
# 834 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SHINY_STONE
# 835 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_YELLOW_SHARD, 1
# 836 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_70:
	checkitem ITEM_GREEN_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_101
EvolutionStoneShopMenu_100:
# 851 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_31
# 852 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_DUSK_STONE
# 853 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_GREEN_SHARD, 1
# 854 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_73:
	checkitem ITEM_YELLOW_SHARD, 1
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EvolutionStoneShopMenu_104
EvolutionStoneShopMenu_103:
# 869 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_33
# 870 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_DAWN_STONE
# 871 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_YELLOW_SHARD, 1
# 872 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneVerifyMenu
	goto EvolutionStoneShopMenu_25

EvolutionStoneShopMenu_77:
# 703 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 704 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_11
# 705 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_76

EvolutionStoneShopMenu_80:
# 721 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 722 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_14
# 723 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_79

EvolutionStoneShopMenu_83:
# 739 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 740 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_17
# 741 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_82

EvolutionStoneShopMenu_86:
# 757 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 758 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_20
# 759 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_85

EvolutionStoneShopMenu_89:
# 775 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 776 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_14
# 777 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_88

EvolutionStoneShopMenu_92:
# 793 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 794 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_14
# 795 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_91

EvolutionStoneShopMenu_95:
# 811 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 812 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_11
# 813 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_94

EvolutionStoneShopMenu_98:
# 829 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 830 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_17
# 831 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_97

EvolutionStoneShopMenu_101:
# 847 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 848 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_20
# 849 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_100

EvolutionStoneShopMenu_104:
# 865 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 866 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox EvolutionStoneShopMenu_Text_17
# 867 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	goto EvolutionStoneShopMenu_103


StoneVerifyMenu::
# 882 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 883 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox StoneVerifyMenu_Text_0, MSGBOX_YESNO
# 884 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq StoneVerifyMenu_1
# 887 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	return

StoneVerifyMenu_1:
# 885 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto EvolutionStoneShopMenu
	return


MoveTutorMenuBadgeList::
# 892 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultichoice 17, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, ItemShopMenuList_Text_0, ItemShopMenuList_Text_1, ItemShopMenuList_Text_2, ItemShopMenuList_Text_3, ItemShopMenuList_Text_4, ItemShopMenuList_Text_5, ItemShopMenuList_Text_6, ItemShopMenuList_Text_7, ItemShopMenuList_Text_8, ItemShopMenuList_Text_10
# 911 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_RESULT
# 912 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 0, MoveTutorMenuBadgeList_3
# 914 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 1, MoveTutorMenuBadgeList_4
# 916 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 2, MoveTutorMenuBadgeList_5
# 918 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 3, MoveTutorMenuBadgeList_6
# 920 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 4, MoveTutorMenuBadgeList_7
# 922 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 5, MoveTutorMenuBadgeList_8
# 924 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 6, MoveTutorMenuBadgeList_9
# 926 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 7, MoveTutorMenuBadgeList_10
# 928 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 8, MoveTutorMenuBadgeList_11
# 930 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case 9, MoveTutorMenuBadgeList_12
MoveTutorMenuBadgeList_1:
# 933 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, PokemonCompendium2
	return

MoveTutorMenuBadgeList_3:
# 913 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto NoBadgesMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_4:
# 915 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto StoneBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_5:
# 917 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto KnuckleBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_6:
# 919 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto DynamoBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_7:
# 921 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto HeatBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_8:
# 923 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto BalanceBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_9:
# 925 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto FeatherBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_10:
# 927 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MindBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_11:
# 929 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto RainBadgeMoveTutor
	goto MoveTutorMenuBadgeList_1

MoveTutorMenuBadgeList_12:
# 931 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium3
	goto MoveTutorMenuBadgeList_1


NoBadgesMoveTutor::
# 938 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 939 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 940 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 944 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_0, MOVE_SWORDS_DANCE
# 945 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_1, MOVE_NASTY_PLOT
# 946 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_2, MOVE_ROCK_POLISH
# 947 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_3, MOVE_DRAGON_DANCE
# 948 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_4, MOVE_ACUPRESSURE
# 949 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_5, MOVE_COACHING
# 950 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_6, MOVE_GEAR_UP
# 951 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_7, MOVE_DECORATE
# 952 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_8, MOVE_ROTOTILLER
# 953 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_9, MOVE_SPICY_EXTRACT
# 954 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_10, MOVE_SWAGGER
# 955 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_11, MOVE_FLOWER_SHIELD
# 956 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_12, MOVE_MAGNETIC_FLUX
# 957 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_13, MOVE_FLATTER
# 958 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_14, MOVE_AROMATIC_MIST
# 959 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_15, MOVE_COIL
# 960 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_16, MOVE_MEDITATE
# 961 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_17, MOVE_BELLY_DRUM
# 962 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_18, MOVE_NO_RETREAT
# 963 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_19, MOVE_CLANGOROUS_SOUL
# 964 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_20, MOVE_FILLET_AWAY
# 965 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_21, MOVE_GROWTH
# 966 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_22, MOVE_HONE_CLAWS
# 967 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_23, MOVE_HOWL
# 968 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_24, MOVE_SHARPEN
# 969 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_25, MOVE_SHELL_SMASH
# 970 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_26, MOVE_SHIFT_GEAR
# 971 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_27, MOVE_TIDY_UP
# 972 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_28, MOVE_VICTORY_DANCE
# 973 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_29, MOVE_ACID_ARMOR
# 974 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_30, MOVE_BARRIER
# 975 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_31, MOVE_BULK_UP
# 976 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_32, MOVE_COSMIC_POWER
# 977 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_33, MOVE_COTTON_GUARD
# 978 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_34, MOVE_DEFEND_ORDER
# 979 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_35, MOVE_DEFENSE_CURL
# 980 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_36, MOVE_HARDEN
# 981 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_37, MOVE_IRON_DEFENSE
# 982 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_38, MOVE_SHELTER
# 983 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_39, MOVE_STOCKPILE
# 984 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_40, MOVE_WITHDRAW
# 985 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_41, MOVE_STUFF_CHEEKS
# 986 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_42, MOVE_AMNESIA
# 987 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_43, MOVE_CALM_MIND
# 988 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_44, MOVE_GEOMANCY
# 989 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_45, MOVE_QUIVER_DANCE
# 990 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_46, MOVE_TAIL_GLOW
# 991 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_47, MOVE_TAKE_HEART
# 992 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_48, MOVE_WORK_UP
# 993 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_49, MOVE_CHARGE
# 994 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_50, MOVE_DOUBLE_TEAM
# 995 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_51, MOVE_MINIMIZE
# 996 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_52, MOVE_AGILITY
# 997 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_53, MOVE_AUTOTOMIZE
# 998 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_54, MOVE_FLASH
# 999 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_55, MOVE_KINESIS
# 1000 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_56, MOVE_SAND_ATTACK
# 1001 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_57, MOVE_SMOKESCREEN
# 1002 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_58, MOVE_GROWL
# 1003 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_59, MOVE_CHARM
# 1004 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_60, MOVE_BABY_DOLL_EYES
# 1005 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_61, MOVE_FEATHER_DANCE
# 1006 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_62, MOVE_MEMENTO
# 1007 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_63, MOVE_NOBLE_ROAR
# 1008 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_64, MOVE_STRENGTH_SAP
# 1009 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_65, MOVE_TEARFUL_LOOK
# 1010 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_66, MOVE_TICKLE
# 1011 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_67, MOVE_VENOM_DRENCH
# 1012 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_68, MOVE_LEER
# 1013 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_69, MOVE_OCTOLOCK
# 1014 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_70, MOVE_SCREECH
# 1015 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_71, MOVE_TAIL_WHIP
# 1016 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_72, MOVE_SWEET_SCENT
# 1017 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_73, MOVE_CAPTIVATE
# 1018 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_74, MOVE_CONFIDE
# 1019 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_75, MOVE_EERIE_IMPULSE
# 1020 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_76, MOVE_PARTING_SHOT
# 1021 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_77, MOVE_FAKE_TEARS
# 1022 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_78, MOVE_METAL_SOUND
# 1023 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_79, MOVE_COTTON_SPORE
# 1024 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_80, MOVE_SCARY_FACE
# 1025 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_81, MOVE_STICKY_WEB
# 1026 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_82, MOVE_STEALTH_ROCK
# 1027 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_83, MOVE_SPIKES
# 1028 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_84, MOVE_TOXIC_SPIKES
# 1029 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_85, MOVE_SUBSTITUTE
# 1030 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_86, MOVE_ENDURE
# 1031 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_87, MOVE_FOLLOW_ME
# 1032 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_88, MOVE_SAFEGUARD
# 1033 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_89, MOVE_DEFOG
# 1034 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_90, MOVE_KINGS_SHIELD
# 1035 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_91, MOVE_PROTECT
# 1036 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_92, MOVE_DETECT
# 1037 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_93, MOVE_BANEFUL_BUNKER
# 1038 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_94, MOVE_BURNING_BULWARK
# 1039 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_95, MOVE_OBSTRUCT
# 1040 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_96, MOVE_CRAFTY_SHIELD
# 1041 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_97, MOVE_MAT_BLOCK
# 1042 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_98, MOVE_SILK_TRAP
# 1043 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_99, MOVE_QUICK_GUARD
# 1044 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_100, MOVE_WIDE_GUARD
# 1045 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_101, MOVE_SPIKY_SHIELD
# 1046 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_102, MOVE_THUNDER_WAVE
# 1047 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_103, MOVE_GLARE
# 1048 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_104, MOVE_STUN_SPORE
# 1049 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_105, MOVE_WILL_O_WISP
# 1050 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_106, MOVE_POISON_GAS
# 1051 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_107, MOVE_TOXIC
# 1052 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_108, MOVE_TOXIC_THREAD
# 1053 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_109, MOVE_HYPNOSIS
# 1054 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_110, MOVE_GRASS_WHISTLE
# 1055 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_111, MOVE_LOVELY_KISS
# 1056 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_112, MOVE_SING
# 1057 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_113, MOVE_SLEEP_POWDER
# 1058 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_114, MOVE_SPORE
# 1059 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_115, MOVE_TEETER_DANCE
# 1060 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_116, MOVE_CONFUSE_RAY
# 1061 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_117, MOVE_SUPERSONIC
# 1062 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_118, MOVE_ATTRACT
# 1063 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_119, MOVE_METRONOME
# 1064 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_120, MOVE_TRICK_ROOM
# 1065 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_121, MOVE_TAILWIND
# 1066 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_122, MOVE_RECYCLE
# 1067 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_123, MOVE_HEAL_BELL
# 1068 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_124, MOVE_LIGHT_SCREEN
# 1069 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_125, MOVE_REFLECT
# 1070 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush NoBadgesMoveTutor_Text_123, MOVE_HEAL_BELL
# 1073 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1077 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SWORDS_DANCE
	goto_if_eq NoBadgesMoveTutor_2
# 1078 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NASTY_PLOT
	goto_if_eq NoBadgesMoveTutor_3
# 1079 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_POLISH
	goto_if_eq NoBadgesMoveTutor_4
# 1080 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DRAGON_DANCE
	goto_if_eq NoBadgesMoveTutor_5
# 1081 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ACUPRESSURE
	goto_if_eq NoBadgesMoveTutor_6
# 1082 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COACHING
	goto_if_eq NoBadgesMoveTutor_7
# 1083 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GEAR_UP
	goto_if_eq NoBadgesMoveTutor_8
# 1084 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DECORATE
	goto_if_eq NoBadgesMoveTutor_9
# 1085 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROTOTILLER
	goto_if_eq NoBadgesMoveTutor_10
# 1086 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPICY_EXTRACT
	goto_if_eq NoBadgesMoveTutor_11
# 1087 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SWAGGER
	goto_if_eq NoBadgesMoveTutor_12
# 1088 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLOWER_SHIELD
	goto_if_eq NoBadgesMoveTutor_13
# 1089 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MAGNETIC_FLUX
	goto_if_eq NoBadgesMoveTutor_14
# 1090 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLATTER
	goto_if_eq NoBadgesMoveTutor_15
# 1091 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AROMATIC_MIST
	goto_if_eq NoBadgesMoveTutor_16
# 1092 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COIL
	goto_if_eq NoBadgesMoveTutor_17
# 1093 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEDITATE
	goto_if_eq NoBadgesMoveTutor_18
# 1094 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BELLY_DRUM
	goto_if_eq NoBadgesMoveTutor_19
# 1095 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NO_RETREAT
	goto_if_eq NoBadgesMoveTutor_20
# 1096 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CLANGOROUS_SOUL
	goto_if_eq NoBadgesMoveTutor_21
# 1097 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FILLET_AWAY
	goto_if_eq NoBadgesMoveTutor_22
# 1098 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GROWTH
	goto_if_eq NoBadgesMoveTutor_23
# 1099 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HONE_CLAWS
	goto_if_eq NoBadgesMoveTutor_24
# 1100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HOWL
	goto_if_eq NoBadgesMoveTutor_25
# 1101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHARPEN
	goto_if_eq NoBadgesMoveTutor_26
# 1102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHELL_SMASH
	goto_if_eq NoBadgesMoveTutor_27
# 1103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHIFT_GEAR
	goto_if_eq NoBadgesMoveTutor_28
# 1104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TIDY_UP
	goto_if_eq NoBadgesMoveTutor_29
# 1105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_VICTORY_DANCE
	goto_if_eq NoBadgesMoveTutor_30
# 1106 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ACID_ARMOR
	goto_if_eq NoBadgesMoveTutor_31
# 1107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BARRIER
	goto_if_eq NoBadgesMoveTutor_32
# 1108 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULK_UP
	goto_if_eq NoBadgesMoveTutor_33
# 1109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COSMIC_POWER
	goto_if_eq NoBadgesMoveTutor_34
# 1110 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COTTON_GUARD
	goto_if_eq NoBadgesMoveTutor_35
# 1111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DEFEND_ORDER
	goto_if_eq NoBadgesMoveTutor_36
# 1112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DEFENSE_CURL
	goto_if_eq NoBadgesMoveTutor_37
# 1113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HARDEN
	goto_if_eq NoBadgesMoveTutor_38
# 1114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_IRON_DEFENSE
	goto_if_eq NoBadgesMoveTutor_39
# 1115 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHELTER
	goto_if_eq NoBadgesMoveTutor_40
# 1116 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STOCKPILE
	goto_if_eq NoBadgesMoveTutor_41
# 1117 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WITHDRAW
	goto_if_eq NoBadgesMoveTutor_42
# 1118 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STUFF_CHEEKS
	goto_if_eq NoBadgesMoveTutor_43
# 1119 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AMNESIA
	goto_if_eq NoBadgesMoveTutor_44
# 1120 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CALM_MIND
	goto_if_eq NoBadgesMoveTutor_45
# 1121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GEOMANCY
	goto_if_eq NoBadgesMoveTutor_46
# 1122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_QUIVER_DANCE
	goto_if_eq NoBadgesMoveTutor_47
# 1123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TAIL_GLOW
	goto_if_eq NoBadgesMoveTutor_48
# 1124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TAKE_HEART
	goto_if_eq NoBadgesMoveTutor_49
# 1125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WORK_UP
	goto_if_eq NoBadgesMoveTutor_50
# 1126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CHARGE
	goto_if_eq NoBadgesMoveTutor_51
# 1127 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DOUBLE_TEAM
	goto_if_eq NoBadgesMoveTutor_52
# 1128 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MINIMIZE
	goto_if_eq NoBadgesMoveTutor_53
# 1129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AGILITY
	goto_if_eq NoBadgesMoveTutor_54
# 1130 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AUTOTOMIZE
	goto_if_eq NoBadgesMoveTutor_55
# 1131 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLASH
	goto_if_eq NoBadgesMoveTutor_56
# 1132 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_KINESIS
	goto_if_eq NoBadgesMoveTutor_57
# 1133 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SAND_ATTACK
	goto_if_eq NoBadgesMoveTutor_58
# 1134 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SMOKESCREEN
	goto_if_eq NoBadgesMoveTutor_59
# 1135 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GROWL
	goto_if_eq NoBadgesMoveTutor_60
# 1136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CHARM
	goto_if_eq NoBadgesMoveTutor_61
# 1137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BABY_DOLL_EYES
	goto_if_eq NoBadgesMoveTutor_62
# 1138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FEATHER_DANCE
	goto_if_eq NoBadgesMoveTutor_63
# 1139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEMENTO
	goto_if_eq NoBadgesMoveTutor_64
# 1140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NOBLE_ROAR
	goto_if_eq NoBadgesMoveTutor_65
# 1141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STRENGTH_SAP
	goto_if_eq NoBadgesMoveTutor_66
# 1142 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TEARFUL_LOOK
	goto_if_eq NoBadgesMoveTutor_67
# 1143 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TICKLE
	goto_if_eq NoBadgesMoveTutor_68
# 1144 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_VENOM_DRENCH
	goto_if_eq NoBadgesMoveTutor_69
# 1145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LEER
	goto_if_eq NoBadgesMoveTutor_70
# 1146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_OCTOLOCK
	goto_if_eq NoBadgesMoveTutor_71
# 1147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SCREECH
	goto_if_eq NoBadgesMoveTutor_72
# 1148 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TAIL_WHIP
	goto_if_eq NoBadgesMoveTutor_73
# 1149 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SWEET_SCENT
	goto_if_eq NoBadgesMoveTutor_74
# 1150 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CAPTIVATE
	goto_if_eq NoBadgesMoveTutor_75
# 1151 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CONFIDE
	goto_if_eq NoBadgesMoveTutor_76
# 1152 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_EERIE_IMPULSE
	goto_if_eq NoBadgesMoveTutor_77
# 1153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PARTING_SHOT
	goto_if_eq NoBadgesMoveTutor_78
# 1154 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FAKE_TEARS
	goto_if_eq NoBadgesMoveTutor_79
# 1155 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_METAL_SOUND
	goto_if_eq NoBadgesMoveTutor_80
# 1156 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COTTON_SPORE
	goto_if_eq NoBadgesMoveTutor_81
# 1157 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SCARY_FACE
	goto_if_eq NoBadgesMoveTutor_82
# 1158 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STICKY_WEB
	goto_if_eq NoBadgesMoveTutor_83
# 1159 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STEALTH_ROCK
	goto_if_eq NoBadgesMoveTutor_84
# 1160 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPIKES
	goto_if_eq NoBadgesMoveTutor_85
# 1161 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TOXIC_SPIKES
	goto_if_eq NoBadgesMoveTutor_86
# 1162 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SUBSTITUTE
	goto_if_eq NoBadgesMoveTutor_87
# 1163 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ENDURE
	goto_if_eq NoBadgesMoveTutor_88
# 1164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FOLLOW_ME
	goto_if_eq NoBadgesMoveTutor_89
# 1165 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SAFEGUARD
	goto_if_eq NoBadgesMoveTutor_90
# 1166 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DEFOG
	goto_if_eq NoBadgesMoveTutor_91
# 1167 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_KINGS_SHIELD
	goto_if_eq NoBadgesMoveTutor_92
# 1168 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PROTECT
	goto_if_eq NoBadgesMoveTutor_93
# 1169 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DETECT
	goto_if_eq NoBadgesMoveTutor_94
# 1170 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BANEFUL_BUNKER
	goto_if_eq NoBadgesMoveTutor_95
# 1171 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BURNING_BULWARK
	goto_if_eq NoBadgesMoveTutor_96
# 1172 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_OBSTRUCT
	goto_if_eq NoBadgesMoveTutor_97
# 1173 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CRAFTY_SHIELD
	goto_if_eq NoBadgesMoveTutor_98
# 1174 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MAT_BLOCK
	goto_if_eq NoBadgesMoveTutor_99
# 1175 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SILK_TRAP
	goto_if_eq NoBadgesMoveTutor_100
# 1176 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_QUICK_GUARD
	goto_if_eq NoBadgesMoveTutor_101
# 1177 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WIDE_GUARD
	goto_if_eq NoBadgesMoveTutor_102
# 1178 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPIKY_SHIELD
	goto_if_eq NoBadgesMoveTutor_103
# 1179 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THUNDER_WAVE
	goto_if_eq NoBadgesMoveTutor_104
# 1180 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GLARE
	goto_if_eq NoBadgesMoveTutor_105
# 1181 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STUN_SPORE
	goto_if_eq NoBadgesMoveTutor_106
# 1182 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WILL_O_WISP
	goto_if_eq NoBadgesMoveTutor_107
# 1183 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_POISON_GAS
	goto_if_eq NoBadgesMoveTutor_108
# 1184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TOXIC
	goto_if_eq NoBadgesMoveTutor_109
# 1185 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TOXIC_THREAD
	goto_if_eq NoBadgesMoveTutor_110
# 1186 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HYPNOSIS
	goto_if_eq NoBadgesMoveTutor_111
# 1187 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GRASS_WHISTLE
	goto_if_eq NoBadgesMoveTutor_112
# 1188 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LOVELY_KISS
	goto_if_eq NoBadgesMoveTutor_113
# 1189 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SING
	goto_if_eq NoBadgesMoveTutor_114
# 1190 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SLEEP_POWDER
	goto_if_eq NoBadgesMoveTutor_115
# 1191 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPORE
	goto_if_eq NoBadgesMoveTutor_116
# 1192 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TEETER_DANCE
	goto_if_eq NoBadgesMoveTutor_117
# 1193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CONFUSE_RAY
	goto_if_eq NoBadgesMoveTutor_118
# 1194 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SUPERSONIC
	goto_if_eq NoBadgesMoveTutor_119
# 1195 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ATTRACT
	goto_if_eq NoBadgesMoveTutor_120
# 1196 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_METRONOME
	goto_if_eq NoBadgesMoveTutor_121
# 1197 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TRICK_ROOM
	goto_if_eq NoBadgesMoveTutor_122
# 1198 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TAILWIND
	goto_if_eq NoBadgesMoveTutor_123
# 1199 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_RECYCLE
	goto_if_eq NoBadgesMoveTutor_124
# 1200 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LIGHT_SCREEN
	goto_if_eq NoBadgesMoveTutor_125
# 1201 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_REFLECT
	goto_if_eq NoBadgesMoveTutor_126
# 1202 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HEAL_BELL
	goto_if_eq NoBadgesMoveTutor_127
NoBadgesMoveTutor_1:
# 1208 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1209 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

NoBadgesMoveTutor_2:
# 1077 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
# 1077 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SWORDS_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_3:
# 1078 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NASTY_PLOT
# 1078 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NASTY_PLOT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_4:
# 1079 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_POLISH
# 1079 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_POLISH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_5:
# 1080 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DRAGON_DANCE
# 1080 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DRAGON_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_6:
# 1081 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ACUPRESSURE
# 1081 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ACUPRESSURE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_7:
# 1082 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COACHING
# 1082 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COACHING
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_8:
# 1083 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GEAR_UP
# 1083 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GEAR_UP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_9:
# 1084 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DECORATE
# 1084 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DECORATE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_10:
# 1085 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROTOTILLER
# 1085 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROTOTILLER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_11:
# 1086 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPICY_EXTRACT
# 1086 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPICY_EXTRACT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_12:
# 1087 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SWAGGER
# 1087 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SWAGGER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_13:
# 1088 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLOWER_SHIELD
# 1088 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLOWER_SHIELD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_14:
# 1089 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MAGNETIC_FLUX
# 1089 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MAGNETIC_FLUX
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_15:
# 1090 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLATTER
# 1090 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLATTER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_16:
# 1091 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AROMATIC_MIST
# 1091 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AROMATIC_MIST
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_17:
# 1092 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COIL
# 1092 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COIL
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_18:
# 1093 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEDITATE
# 1093 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEDITATE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_19:
# 1094 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BELLY_DRUM
# 1094 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BELLY_DRUM
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_20:
# 1095 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NO_RETREAT
# 1095 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NO_RETREAT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_21:
# 1096 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CLANGOROUS_SOUL
# 1096 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CLANGOROUS_SOUL
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_22:
# 1097 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FILLET_AWAY
# 1097 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FILLET_AWAY
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_23:
# 1098 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GROWTH
# 1098 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GROWTH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_24:
# 1099 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HONE_CLAWS
# 1099 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HONE_CLAWS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_25:
# 1100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HOWL
# 1100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HOWL
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_26:
# 1101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHARPEN
# 1101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHARPEN
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_27:
# 1102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHELL_SMASH
# 1102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHELL_SMASH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_28:
# 1103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHIFT_GEAR
# 1103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHIFT_GEAR
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_29:
# 1104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TIDY_UP
# 1104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TIDY_UP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_30:
# 1105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_VICTORY_DANCE
# 1105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_VICTORY_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_31:
# 1106 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ACID_ARMOR
# 1106 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ACID_ARMOR
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_32:
# 1107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BARRIER
# 1107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BARRIER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_33:
# 1108 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULK_UP
# 1108 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULK_UP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_34:
# 1109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COSMIC_POWER
# 1109 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COSMIC_POWER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_35:
# 1110 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COTTON_GUARD
# 1110 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COTTON_GUARD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_36:
# 1111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DEFEND_ORDER
# 1111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DEFEND_ORDER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_37:
# 1112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
# 1112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DEFENSE_CURL
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_38:
# 1113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HARDEN
# 1113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HARDEN
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_39:
# 1114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_IRON_DEFENSE
# 1114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_IRON_DEFENSE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_40:
# 1115 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHELTER
# 1115 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHELTER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_41:
# 1116 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STOCKPILE
# 1116 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STOCKPILE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_42:
# 1117 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WITHDRAW
# 1117 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WITHDRAW
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_43:
# 1118 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STUFF_CHEEKS
# 1118 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STUFF_CHEEKS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_44:
# 1119 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AMNESIA
# 1119 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AMNESIA
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_45:
# 1120 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CALM_MIND
# 1120 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CALM_MIND
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_46:
# 1121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GEOMANCY
# 1121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GEOMANCY
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_47:
# 1122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_QUIVER_DANCE
# 1122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_QUIVER_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_48:
# 1123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TAIL_GLOW
# 1123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TAIL_GLOW
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_49:
# 1124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TAKE_HEART
# 1124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TAKE_HEART
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_50:
# 1125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WORK_UP
# 1125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WORK_UP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_51:
# 1126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CHARGE
# 1126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CHARGE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_52:
# 1127 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DOUBLE_TEAM
# 1127 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DOUBLE_TEAM
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_53:
# 1128 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MINIMIZE
# 1128 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MINIMIZE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_54:
# 1129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AGILITY
# 1129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AGILITY
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_55:
# 1130 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AUTOTOMIZE
# 1130 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AUTOTOMIZE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_56:
# 1131 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLASH
# 1131 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLASH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_57:
# 1132 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_KINESIS
# 1132 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_KINESIS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_58:
# 1133 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SAND_ATTACK
# 1133 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SAND_ATTACK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_59:
# 1134 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SMOKESCREEN
# 1134 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SMOKESCREEN
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_60:
# 1135 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GROWL
# 1135 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GROWL
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_61:
# 1136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CHARM
# 1136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CHARM
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_62:
# 1137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BABY_DOLL_EYES
# 1137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BABY_DOLL_EYES
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_63:
# 1138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FEATHER_DANCE
# 1138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FEATHER_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_64:
# 1139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEMENTO
# 1139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEMENTO
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_65:
# 1140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NOBLE_ROAR
# 1140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NOBLE_ROAR
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_66:
# 1141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STRENGTH_SAP
# 1141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STRENGTH_SAP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_67:
# 1142 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TEARFUL_LOOK
# 1142 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TEARFUL_LOOK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_68:
# 1143 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TICKLE
# 1143 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TICKLE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_69:
# 1144 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_VENOM_DRENCH
# 1144 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_VENOM_DRENCH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_70:
# 1145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LEER
# 1145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LEER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_71:
# 1146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_OCTOLOCK
# 1146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_OCTOLOCK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_72:
# 1147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SCREECH
# 1147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SCREECH
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_73:
# 1148 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TAIL_WHIP
# 1148 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TAIL_WHIP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_74:
# 1149 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SWEET_SCENT
# 1149 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SWEET_SCENT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_75:
# 1150 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CAPTIVATE
# 1150 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CAPTIVATE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_76:
# 1151 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CONFIDE
# 1151 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CONFIDE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_77:
# 1152 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_EERIE_IMPULSE
# 1152 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EERIE_IMPULSE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_78:
# 1153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PARTING_SHOT
# 1153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PARTING_SHOT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_79:
# 1154 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FAKE_TEARS
# 1154 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FAKE_TEARS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_80:
# 1155 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_METAL_SOUND
# 1155 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_METAL_SOUND
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_81:
# 1156 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COTTON_SPORE
# 1156 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COTTON_SPORE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_82:
# 1157 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SCARY_FACE
# 1157 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SCARY_FACE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_83:
# 1158 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STICKY_WEB
# 1158 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STICKY_WEB
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_84:
# 1159 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STEALTH_ROCK
# 1159 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STEALTH_ROCK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_85:
# 1160 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPIKES
# 1160 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPIKES
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_86:
# 1161 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TOXIC_SPIKES
# 1161 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TOXIC_SPIKES
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_87:
# 1162 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SUBSTITUTE
# 1162 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SUBSTITUTE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_88:
# 1163 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ENDURE
# 1163 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ENDURE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_89:
# 1164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FOLLOW_ME
# 1164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FOLLOW_ME
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_90:
# 1165 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SAFEGUARD
# 1165 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SAFEGUARD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_91:
# 1166 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DEFOG
# 1166 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DEFOG
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_92:
# 1167 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_KINGS_SHIELD
# 1167 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_KINGS_SHIELD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_93:
# 1168 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PROTECT
# 1168 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PROTECT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_94:
# 1169 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DETECT
# 1169 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DETECT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_95:
# 1170 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BANEFUL_BUNKER
# 1170 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BANEFUL_BUNKER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_96:
# 1171 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BURNING_BULWARK
# 1171 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BURNING_BULWARK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_97:
# 1172 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_OBSTRUCT
# 1172 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_OBSTRUCT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_98:
# 1173 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CRAFTY_SHIELD
# 1173 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CRAFTY_SHIELD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_99:
# 1174 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MAT_BLOCK
# 1174 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MAT_BLOCK
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_100:
# 1175 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SILK_TRAP
# 1175 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SILK_TRAP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_101:
# 1176 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_QUICK_GUARD
# 1176 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_QUICK_GUARD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_102:
# 1177 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WIDE_GUARD
# 1177 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WIDE_GUARD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_103:
# 1178 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPIKY_SHIELD
# 1178 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPIKY_SHIELD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_104:
# 1179 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
# 1179 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THUNDER_WAVE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_105:
# 1180 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GLARE
# 1180 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GLARE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_106:
# 1181 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STUN_SPORE
# 1181 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STUN_SPORE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_107:
# 1182 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WILL_O_WISP
# 1182 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WILL_O_WISP
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_108:
# 1183 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_POISON_GAS
# 1183 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POISON_GAS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_109:
# 1184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TOXIC
# 1184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TOXIC
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_110:
# 1185 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TOXIC_THREAD
# 1185 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TOXIC_THREAD
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_111:
# 1186 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HYPNOSIS
# 1186 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HYPNOSIS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_112:
# 1187 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GRASS_WHISTLE
# 1187 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GRASS_WHISTLE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_113:
# 1188 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LOVELY_KISS
# 1188 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LOVELY_KISS
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_114:
# 1189 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SING
# 1189 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SING
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_115:
# 1190 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SLEEP_POWDER
# 1190 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SLEEP_POWDER
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_116:
# 1191 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPORE
# 1191 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPORE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_117:
# 1192 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TEETER_DANCE
# 1192 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TEETER_DANCE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_118:
# 1193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CONFUSE_RAY
# 1193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CONFUSE_RAY
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_119:
# 1194 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SUPERSONIC
# 1194 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SUPERSONIC
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_120:
# 1195 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ATTRACT
# 1195 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ATTRACT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_121:
# 1196 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_METRONOME
# 1196 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_METRONOME
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_122:
# 1197 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TRICK_ROOM
# 1197 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TRICK_ROOM
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_123:
# 1198 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TAILWIND
# 1198 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TAILWIND
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_124:
# 1199 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_RECYCLE
# 1199 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_RECYCLE
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_125:
# 1200 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LIGHT_SCREEN
# 1200 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LIGHT_SCREEN
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_126:
# 1201 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_REFLECT
# 1201 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_REFLECT
	goto NoBadgesMoveTutor_1

NoBadgesMoveTutor_127:
# 1202 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HEAL_BELL
# 1202 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HEAL_BELL
	goto NoBadgesMoveTutor_1


StoneBadgeMoveTutor::
# 1213 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1214 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1215 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, StoneBadgeMoveTutor_1
# 1222 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_0, MOVE_MACH_PUNCH
# 1223 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_1, MOVE_BULLET_PUNCH
# 1224 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_2, MOVE_ICE_SHARD
# 1225 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_3, MOVE_SHADOW_SNEAK
# 1226 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_4, MOVE_ROCK_SMASH
# 1227 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_5, MOVE_CUT
# 1228 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_6, MOVE_FALSE_SWIPE
# 1229 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_7, MOVE_TACKLE
# 1230 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_8, MOVE_POUND
# 1231 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_9, MOVE_SCRATCH
# 1232 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_10, MOVE_DOUBLE_SLAP
# 1233 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_11, MOVE_COMET_PUNCH
# 1234 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_12, MOVE_FURY_CUTTER
# 1235 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_13, MOVE_ROLLOUT
# 1236 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_14, MOVE_ECHOED_VOICE
# 1237 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_15, MOVE_EMBER
# 1238 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_16, MOVE_WATER_GUN
# 1239 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_17, MOVE_THUNDERSHOCK
# 1240 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_18, MOVE_GUST
# 1241 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_19, MOVE_CONFUSION
# 1242 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_20, MOVE_MEGA_DRAIN
# 1243 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_21, MOVE_SMOG
# 1246 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1249 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MACH_PUNCH
	goto_if_eq StoneBadgeMoveTutor_5
# 1250 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULLET_PUNCH
	goto_if_eq StoneBadgeMoveTutor_6
# 1251 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICE_SHARD
	goto_if_eq StoneBadgeMoveTutor_7
# 1252 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHADOW_SNEAK
	goto_if_eq StoneBadgeMoveTutor_8
# 1253 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_SMASH
	goto_if_eq StoneBadgeMoveTutor_9
# 1254 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CUT
	goto_if_eq StoneBadgeMoveTutor_10
# 1255 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FALSE_SWIPE
	goto_if_eq StoneBadgeMoveTutor_11
# 1256 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TACKLE
	goto_if_eq StoneBadgeMoveTutor_12
# 1257 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_POUND
	goto_if_eq StoneBadgeMoveTutor_13
# 1258 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SCRATCH
	goto_if_eq StoneBadgeMoveTutor_14
# 1259 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DOUBLE_SLAP
	goto_if_eq StoneBadgeMoveTutor_15
# 1260 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COMET_PUNCH
	goto_if_eq StoneBadgeMoveTutor_16
# 1261 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FURY_CUTTER
	goto_if_eq StoneBadgeMoveTutor_17
# 1262 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROLLOUT
	goto_if_eq StoneBadgeMoveTutor_18
# 1263 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ECHOED_VOICE
	goto_if_eq StoneBadgeMoveTutor_19
# 1264 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_EMBER
	goto_if_eq StoneBadgeMoveTutor_20
# 1265 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WATER_GUN
	goto_if_eq StoneBadgeMoveTutor_21
# 1266 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THUNDERSHOCK
	goto_if_eq StoneBadgeMoveTutor_22
# 1267 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GUST
	goto_if_eq StoneBadgeMoveTutor_23
# 1268 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CONFUSION
	goto_if_eq StoneBadgeMoveTutor_24
# 1269 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEGA_DRAIN
	goto_if_eq StoneBadgeMoveTutor_25
# 1270 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SMOG
	goto_if_eq StoneBadgeMoveTutor_26
# 1271 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FAIRY_WIND
	goto_if_eq StoneBadgeMoveTutor_27
StoneBadgeMoveTutor_4:
# 1273 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1274 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

StoneBadgeMoveTutor_1:
# 1216 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1217 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox StoneBadgeItemShopMenu_Text_0
# 1218 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

StoneBadgeMoveTutor_5:
# 1249 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MACH_PUNCH
# 1249 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MACH_PUNCH
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_6:
# 1250 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULLET_PUNCH
# 1250 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULLET_PUNCH
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_7:
# 1251 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICE_SHARD
# 1251 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICE_SHARD
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_8:
# 1252 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHADOW_SNEAK
# 1252 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHADOW_SNEAK
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_9:
# 1253 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_SMASH
# 1253 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_SMASH
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_10:
# 1254 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CUT
# 1254 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CUT
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_11:
# 1255 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FALSE_SWIPE
# 1255 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FALSE_SWIPE
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_12:
# 1256 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TACKLE
# 1256 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TACKLE
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_13:
# 1257 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_POUND
# 1257 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POUND
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_14:
# 1258 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SCRATCH
# 1258 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SCRATCH
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_15:
# 1259 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DOUBLE_SLAP
# 1259 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DOUBLE_SLAP
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_16:
# 1260 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COMET_PUNCH
# 1260 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COMET_PUNCH
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_17:
# 1261 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FURY_CUTTER
# 1261 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FURY_CUTTER
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_18:
# 1262 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROLLOUT
# 1262 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROLLOUT
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_19:
# 1263 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
# 1263 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ECHOED_VOICE
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_20:
# 1264 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_EMBER
# 1264 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EMBER
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_21:
# 1265 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WATER_GUN
# 1265 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WATER_GUN
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_22:
# 1266 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDERSHOCK
# 1266 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THUNDERSHOCK
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_23:
# 1267 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GUST
# 1267 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GUST
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_24:
# 1268 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CONFUSION
# 1268 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CONFUSION
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_25:
# 1269 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_DRAIN
# 1269 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEGA_DRAIN
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_26:
# 1270 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SMOG
# 1270 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SMOG
	goto StoneBadgeMoveTutor_4

StoneBadgeMoveTutor_27:
# 1271 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FAIRY_WIND
# 1271 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FAIRY_WIND
	goto StoneBadgeMoveTutor_4


KnuckleBadgeMoveTutor::
# 1279 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1280 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1281 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, KnuckleBadgeMoveTutor_1
# 1287 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_0, MOVE_FAKE_OUT
# 1288 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_14, MOVE_ECHOED_VOICE
# 1289 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_1, MOVE_FLAME_CHARGE
# 1290 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_2, MOVE_INCINERATE
# 1291 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_3, MOVE_AQUA_JET
# 1292 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_4, MOVE_CHILLING_WATER
# 1293 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_5, MOVE_SPARK
# 1294 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_6, MOVE_CHARGE_BEAM
# 1295 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_7, MOVE_RAZOR_LEAF
# 1296 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_8, MOVE_MAGICAL_LEAF
# 1297 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_9, MOVE_AVALANCHE
# 1298 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_10, MOVE_ICY_WIND
# 1299 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_11, MOVE_KARATE_CHOP
# 1300 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_12, MOVE_VACUUM_WAVE
# 1301 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_13, MOVE_POISON_FANG
# 1302 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_21, MOVE_SMOG
# 1303 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_14, MOVE_SAND_TOMB
# 1304 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_15, MOVE_MUD_SLAP
# 1305 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_16, MOVE_DUAL_WINGBEAT
# 1306 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_17, MOVE_AIR_CUTTER
# 1307 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_18, MOVE_PSYCHO_CUT
# 1308 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_19, MOVE_CONFUSION
# 1309 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_19, MOVE_POUNCE
# 1310 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_20, MOVE_STRUGGLE_BUG
# 1311 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_21, MOVE_SMACK_DOWN
# 1312 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_22, MOVE_ANCIENT_POWER
# 1313 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_23, MOVE_LICK
# 1314 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_24, MOVE_NIGHT_SHADE
# 1315 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_25, MOVE_DUAL_CHOP
# 1316 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_26, MOVE_TWISTER
# 1317 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_27, MOVE_PAYBACK
# 1318 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_28, MOVE_SNARL
# 1319 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_1, MOVE_BULLET_PUNCH
# 1320 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_29, MOVE_MIRROR_SHOT
# 1321 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_30, MOVE_DISARMING_VOICE
# 1322 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_31, MOVE_FAIRY_WIND
# 1326 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1330 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FAKE_OUT
	goto_if_eq KnuckleBadgeMoveTutor_5
# 1331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ECHOED_VOICE
	goto_if_eq KnuckleBadgeMoveTutor_6
# 1332 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLAME_CHARGE
	goto_if_eq KnuckleBadgeMoveTutor_7
# 1333 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_INCINERATE
	goto_if_eq KnuckleBadgeMoveTutor_8
# 1334 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AQUA_JET
	goto_if_eq KnuckleBadgeMoveTutor_9
# 1335 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CHILLING_WATER
	goto_if_eq KnuckleBadgeMoveTutor_10
# 1336 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPARK
	goto_if_eq KnuckleBadgeMoveTutor_11
# 1337 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CHARGE_BEAM
	goto_if_eq KnuckleBadgeMoveTutor_12
# 1338 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_RAZOR_LEAF
	goto_if_eq KnuckleBadgeMoveTutor_13
# 1339 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MAGICAL_LEAF
	goto_if_eq KnuckleBadgeMoveTutor_14
# 1340 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AVALANCHE
	goto_if_eq KnuckleBadgeMoveTutor_15
# 1341 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICY_WIND
	goto_if_eq KnuckleBadgeMoveTutor_16
# 1342 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_KARATE_CHOP
	goto_if_eq KnuckleBadgeMoveTutor_17
# 1343 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_VACUUM_WAVE
	goto_if_eq KnuckleBadgeMoveTutor_18
# 1344 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_POISON_FANG
	goto_if_eq KnuckleBadgeMoveTutor_19
# 1345 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SMOG
	goto_if_eq KnuckleBadgeMoveTutor_20
# 1346 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SAND_TOMB
	goto_if_eq KnuckleBadgeMoveTutor_21
# 1347 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MUD_SLAP
	goto_if_eq KnuckleBadgeMoveTutor_22
# 1348 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPARK
	goto_if_eq KnuckleBadgeMoveTutor_23
# 1349 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DUAL_WINGBEAT
	goto_if_eq KnuckleBadgeMoveTutor_24
# 1350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AIR_CUTTER
	goto_if_eq KnuckleBadgeMoveTutor_25
# 1351 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MAGICAL_LEAF
	goto_if_eq KnuckleBadgeMoveTutor_26
# 1352 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PSYCHO_CUT
	goto_if_eq KnuckleBadgeMoveTutor_27
# 1353 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CONFUSION
	goto_if_eq KnuckleBadgeMoveTutor_28
# 1354 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_KARATE_CHOP
	goto_if_eq KnuckleBadgeMoveTutor_29
# 1355 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_POUNCE
	goto_if_eq KnuckleBadgeMoveTutor_30
# 1356 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STRUGGLE_BUG
	goto_if_eq KnuckleBadgeMoveTutor_31
# 1357 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SMACK_DOWN
	goto_if_eq KnuckleBadgeMoveTutor_32
# 1358 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ANCIENT_POWER
	goto_if_eq KnuckleBadgeMoveTutor_33
# 1359 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LICK
	goto_if_eq KnuckleBadgeMoveTutor_34
# 1360 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NIGHT_SHADE
	goto_if_eq KnuckleBadgeMoveTutor_35
# 1361 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DUAL_CHOP
	goto_if_eq KnuckleBadgeMoveTutor_36
# 1362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TWISTER
	goto_if_eq KnuckleBadgeMoveTutor_37
# 1363 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PAYBACK
	goto_if_eq KnuckleBadgeMoveTutor_38
# 1364 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SNARL
	goto_if_eq KnuckleBadgeMoveTutor_39
# 1365 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULLET_PUNCH
	goto_if_eq KnuckleBadgeMoveTutor_40
# 1366 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MIRROR_SHOT
	goto_if_eq KnuckleBadgeMoveTutor_41
# 1367 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DISARMING_VOICE
	goto_if_eq KnuckleBadgeMoveTutor_42
# 1368 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FAIRY_WIND
	goto_if_eq KnuckleBadgeMoveTutor_43
KnuckleBadgeMoveTutor_4:
# 1370 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1371 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

KnuckleBadgeMoveTutor_1:
# 1282 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1283 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox KnuckleBadgeItemShopMenu_Text_0
# 1284 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

KnuckleBadgeMoveTutor_5:
# 1330 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FAKE_OUT
# 1330 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FAKE_OUT
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_6:
# 1331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
# 1331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ECHOED_VOICE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_7:
# 1332 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLAME_CHARGE
# 1332 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLAME_CHARGE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_8:
# 1333 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_INCINERATE
# 1333 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_INCINERATE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_9:
# 1334 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AQUA_JET
# 1334 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AQUA_JET
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_10:
# 1335 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CHILLING_WATER
# 1335 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CHILLING_WATER
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_11:
# 1336 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPARK
# 1336 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPARK
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_12:
# 1337 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CHARGE_BEAM
# 1337 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CHARGE_BEAM
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_13:
# 1338 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_RAZOR_LEAF
# 1338 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_RAZOR_LEAF
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_14:
# 1339 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MAGICAL_LEAF
# 1339 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MAGICAL_LEAF
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_15:
# 1340 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AVALANCHE
# 1340 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AVALANCHE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_16:
# 1341 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICY_WIND
# 1341 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICY_WIND
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_17:
# 1342 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_KARATE_CHOP
# 1342 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_KARATE_CHOP
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_18:
# 1343 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_VACUUM_WAVE
# 1343 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_VACUUM_WAVE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_19:
# 1344 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_POISON_FANG
# 1344 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POISON_FANG
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_20:
# 1345 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SMOG
# 1345 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SMOG
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_21:
# 1346 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SAND_TOMB
# 1346 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SAND_TOMB
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_22:
# 1347 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MUD_SLAP
# 1347 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MUD_SLAP
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_23:
# 1348 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPARK
# 1348 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPARK
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_24:
# 1349 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DUAL_WINGBEAT
# 1349 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DUAL_WINGBEAT
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_25:
# 1350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AIR_CUTTER
# 1350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AIR_CUTTER
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_26:
# 1351 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MAGICAL_LEAF
# 1351 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MAGICAL_LEAF
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_27:
# 1352 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCHO_CUT
# 1352 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PSYCHO_CUT
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_28:
# 1353 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CONFUSION
# 1353 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CONFUSION
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_29:
# 1354 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_KARATE_CHOP
# 1354 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_KARATE_CHOP
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_30:
# 1355 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_POUNCE
# 1355 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POUNCE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_31:
# 1356 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STRUGGLE_BUG
# 1356 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STRUGGLE_BUG
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_32:
# 1357 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SMACK_DOWN
# 1357 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SMACK_DOWN
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_33:
# 1358 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ANCIENT_POWER
# 1358 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ANCIENT_POWER
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_34:
# 1359 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LICK
# 1359 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LICK
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_35:
# 1360 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NIGHT_SHADE
# 1360 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NIGHT_SHADE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_36:
# 1361 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DUAL_CHOP
# 1361 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DUAL_CHOP
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_37:
# 1362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TWISTER
# 1362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TWISTER
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_38:
# 1363 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PAYBACK
# 1363 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PAYBACK
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_39:
# 1364 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SNARL
# 1364 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SNARL
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_40:
# 1365 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULLET_PUNCH
# 1365 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULLET_PUNCH
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_41:
# 1366 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MIRROR_SHOT
# 1366 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MIRROR_SHOT
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_42:
# 1367 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DISARMING_VOICE
# 1367 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DISARMING_VOICE
	goto KnuckleBadgeMoveTutor_4

KnuckleBadgeMoveTutor_43:
# 1368 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FAIRY_WIND
# 1368 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FAIRY_WIND
	goto KnuckleBadgeMoveTutor_4


DynamoBadgeMoveTutor::
# 1376 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1377 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1378 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, DynamoBadgeMoveTutor_1
# 1385 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_0, MOVE_FLAME_WHEEL
# 1386 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_1, MOVE_WATER_PULSE
# 1387 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_2, MOVE_BITE
# 1388 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_5, MOVE_SPARK
# 1389 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_3, MOVE_FORCE_PALM
# 1390 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_4, MOVE_AERIAL_ACE
# 1391 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_5, MOVE_SHADOW_CLAW
# 1392 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_6, MOVE_BULLDOZE
# 1393 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_7, MOVE_ROCK_TOMB
# 1394 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_8, MOVE_BUG_BITE
# 1395 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_9, MOVE_PLUCK
# 1396 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_10, MOVE_SMART_STRIKE
# 1397 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_11, MOVE_METAL_CLAW
# 1398 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_12, MOVE_STOMP
# 1399 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_13, MOVE_COVET
# 1400 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_14, MOVE_SHOCK_WAVE
# 1401 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_15, MOVE_SWIFT
# 1402 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_10, MOVE_ICY_WIND
# 1403 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_16, MOVE_MUD_SHOT
# 1404 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_20, MOVE_MEGA_DRAIN
# 1405 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_17, MOVE_ACID_SPRAY
# 1406 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_28, MOVE_SNARL
# 1407 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_18, MOVE_PSYBEAM
# 1408 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_30, MOVE_DISARMING_VOICE
# 1409 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_19, MOVE_OMINOUS_WIND
# 1410 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_22, MOVE_ANCIENT_POWER
# 1411 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_20, MOVE_SILVER_WIND
# 1412 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_21, MOVE_CLEAR_SMOG
# 1413 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_22, MOVE_HEX
# 1414 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_23, MOVE_BULLET_SEED
# 1415 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_24, MOVE_ICICLE_SPEAR
# 1416 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_25, MOVE_ROCK_BLAST
# 1417 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_26, MOVE_ARM_THRUST
# 1418 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_27, MOVE_FURY_SWIPES
# 1421 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1424 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLAME_WHEEL
	goto_if_eq DynamoBadgeMoveTutor_5
# 1425 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WATER_PULSE
	goto_if_eq DynamoBadgeMoveTutor_6
# 1426 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BITE
	goto_if_eq DynamoBadgeMoveTutor_7
# 1427 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SPARK
	goto_if_eq DynamoBadgeMoveTutor_8
# 1428 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FORCE_PALM
	goto_if_eq DynamoBadgeMoveTutor_9
# 1429 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AERIAL_ACE
	goto_if_eq DynamoBadgeMoveTutor_10
# 1430 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHADOW_CLAW
	goto_if_eq DynamoBadgeMoveTutor_11
# 1431 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULLDOZE
	goto_if_eq DynamoBadgeMoveTutor_12
# 1432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_TOMB
	goto_if_eq DynamoBadgeMoveTutor_13
# 1433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BUG_BITE
	goto_if_eq DynamoBadgeMoveTutor_14
# 1434 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PLUCK
	goto_if_eq DynamoBadgeMoveTutor_15
# 1435 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SMART_STRIKE
	goto_if_eq DynamoBadgeMoveTutor_16
# 1436 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_METAL_CLAW
	goto_if_eq DynamoBadgeMoveTutor_17
# 1437 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STOMP
	goto_if_eq DynamoBadgeMoveTutor_18
# 1438 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_COVET
	goto_if_eq DynamoBadgeMoveTutor_19
# 1439 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHOCK_WAVE
	goto_if_eq DynamoBadgeMoveTutor_20
# 1440 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SWIFT
	goto_if_eq DynamoBadgeMoveTutor_21
# 1441 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICY_WIND
	goto_if_eq DynamoBadgeMoveTutor_22
# 1442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MUD_SHOT
	goto_if_eq DynamoBadgeMoveTutor_23
# 1443 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEGA_DRAIN
	goto_if_eq DynamoBadgeMoveTutor_24
# 1444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ACID_SPRAY
	goto_if_eq DynamoBadgeMoveTutor_25
# 1445 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SNARL
	goto_if_eq DynamoBadgeMoveTutor_26
# 1446 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PSYBEAM
	goto_if_eq DynamoBadgeMoveTutor_27
# 1447 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DISARMING_VOICE
	goto_if_eq DynamoBadgeMoveTutor_28
# 1448 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_OMINOUS_WIND
	goto_if_eq DynamoBadgeMoveTutor_29
# 1449 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ANCIENT_POWER
	goto_if_eq DynamoBadgeMoveTutor_30
# 1450 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SILVER_WIND
	goto_if_eq DynamoBadgeMoveTutor_31
# 1451 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CLEAR_SMOG
	goto_if_eq DynamoBadgeMoveTutor_32
# 1452 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HEX
	goto_if_eq DynamoBadgeMoveTutor_33
# 1453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULLET_SEED
	goto_if_eq DynamoBadgeMoveTutor_34
# 1454 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICICLE_SPEAR
	goto_if_eq DynamoBadgeMoveTutor_35
# 1455 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_BLAST
	goto_if_eq DynamoBadgeMoveTutor_36
# 1456 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ARM_THRUST
	goto_if_eq DynamoBadgeMoveTutor_37
# 1457 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FURY_SWIPES
	goto_if_eq DynamoBadgeMoveTutor_38
DynamoBadgeMoveTutor_4:
# 1459 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1460 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

DynamoBadgeMoveTutor_1:
# 1379 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1380 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox DynamoBadgeItemShopMenu_Text_0
# 1381 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

DynamoBadgeMoveTutor_5:
# 1424 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLAME_WHEEL
# 1424 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLAME_WHEEL
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_6:
# 1425 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WATER_PULSE
# 1425 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WATER_PULSE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_7:
# 1426 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BITE
# 1426 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BITE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_8:
# 1427 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SPARK
# 1427 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SPARK
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_9:
# 1428 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FORCE_PALM
# 1428 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FORCE_PALM
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_10:
# 1429 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AERIAL_ACE
# 1429 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AERIAL_ACE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_11:
# 1430 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHADOW_CLAW
# 1430 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHADOW_CLAW
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_12:
# 1431 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULLDOZE
# 1431 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULLDOZE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_13:
# 1432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_TOMB
# 1432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_TOMB
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_14:
# 1433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BUG_BITE
# 1433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BUG_BITE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_15:
# 1434 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PLUCK
# 1434 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PLUCK
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_16:
# 1435 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SMART_STRIKE
# 1435 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SMART_STRIKE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_17:
# 1436 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_METAL_CLAW
# 1436 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_METAL_CLAW
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_18:
# 1437 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STOMP
# 1437 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STOMP
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_19:
# 1438 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_COVET
# 1438 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_COVET
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_20:
# 1439 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHOCK_WAVE
# 1439 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHOCK_WAVE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_21:
# 1440 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SWIFT
# 1440 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SWIFT
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_22:
# 1441 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICY_WIND
# 1441 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICY_WIND
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_23:
# 1442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MUD_SHOT
# 1442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MUD_SHOT
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_24:
# 1443 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_DRAIN
# 1443 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEGA_DRAIN
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_25:
# 1444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ACID_SPRAY
# 1444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ACID_SPRAY
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_26:
# 1445 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SNARL
# 1445 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SNARL
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_27:
# 1446 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYBEAM
# 1446 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PSYBEAM
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_28:
# 1447 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DISARMING_VOICE
# 1447 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DISARMING_VOICE
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_29:
# 1448 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_OMINOUS_WIND
# 1448 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_OMINOUS_WIND
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_30:
# 1449 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ANCIENT_POWER
# 1449 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ANCIENT_POWER
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_31:
# 1450 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SILVER_WIND
# 1450 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SILVER_WIND
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_32:
# 1451 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CLEAR_SMOG
# 1451 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CLEAR_SMOG
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_33:
# 1452 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HEX
# 1452 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HEX
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_34:
# 1453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULLET_SEED
# 1453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULLET_SEED
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_35:
# 1454 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICICLE_SPEAR
# 1454 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICICLE_SPEAR
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_36:
# 1455 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_BLAST
# 1455 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_BLAST
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_37:
# 1456 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ARM_THRUST
# 1456 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ARM_THRUST
	goto DynamoBadgeMoveTutor_4

DynamoBadgeMoveTutor_38:
# 1457 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FURY_SWIPES
# 1457 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FURY_SWIPES
	goto DynamoBadgeMoveTutor_4


HeatBadgeMoveTutor::
# 1466 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1467 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1468 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, HeatBadgeMoveTutor_1
# 1475 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_0, MOVE_FIRE_PUNCH
# 1476 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_1, MOVE_ICE_PUNCH
# 1477 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_2, MOVE_THUNDER_PUNCH
# 1478 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_17, MOVE_AIR_CUTTER
# 1479 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_1, MOVE_WATER_PULSE
# 1480 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_8, MOVE_BUG_BITE
# 1481 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_9, MOVE_PLUCK
# 1482 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_2, MOVE_BITE
# 1483 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_3, MOVE_HEART_STAMP
# 1484 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_12, MOVE_STOMP
# 1487 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_4, MOVE_FLAME_BURST
# 1488 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_5, MOVE_BUBBLE_BEAM
# 1489 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_6, MOVE_AURORA_BEAM
# 1490 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_14, MOVE_SHOCK_WAVE
# 1491 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush StoneBadgeMoveTutor_Text_20, MOVE_MEGA_DRAIN
# 1492 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_16, MOVE_MUD_SHOT
# 1493 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_7, MOVE_ROCK_TOMB
# 1494 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_6, MOVE_BULLDOZE
# 1497 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_7, MOVE_KNOCK_OFF
# 1498 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_8, MOVE_THIEF
# 1499 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_9, MOVE_RAPID_SPIN
# 1500 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush HeatBadgeMoveTutor_Text_10, MOVE_NUZZLE
# 1503 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1506 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FIRE_PUNCH
	goto_if_eq HeatBadgeMoveTutor_5
# 1507 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICE_PUNCH
	goto_if_eq HeatBadgeMoveTutor_6
# 1508 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THUNDER_PUNCH
	goto_if_eq HeatBadgeMoveTutor_7
# 1509 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AIR_CUTTER
	goto_if_eq HeatBadgeMoveTutor_8
# 1510 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WATER_PULSE
	goto_if_eq HeatBadgeMoveTutor_9
# 1511 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BUG_BITE
	goto_if_eq HeatBadgeMoveTutor_10
# 1512 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PLUCK
	goto_if_eq HeatBadgeMoveTutor_11
# 1513 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BITE
	goto_if_eq HeatBadgeMoveTutor_12
# 1514 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HEART_STAMP
	goto_if_eq HeatBadgeMoveTutor_13
# 1515 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STOMP
	goto_if_eq HeatBadgeMoveTutor_14
# 1516 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLAME_BURST
	goto_if_eq HeatBadgeMoveTutor_15
# 1517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BUBBLE_BEAM
	goto_if_eq HeatBadgeMoveTutor_16
# 1518 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AURORA_BEAM
	goto_if_eq HeatBadgeMoveTutor_17
# 1519 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHOCK_WAVE
	goto_if_eq HeatBadgeMoveTutor_18
# 1520 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEGA_DRAIN
	goto_if_eq HeatBadgeMoveTutor_19
# 1521 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MUD_SHOT
	goto_if_eq HeatBadgeMoveTutor_20
# 1522 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_TOMB
	goto_if_eq HeatBadgeMoveTutor_21
# 1523 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BULLDOZE
	goto_if_eq HeatBadgeMoveTutor_22
# 1524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_KNOCK_OFF
	goto_if_eq HeatBadgeMoveTutor_23
# 1525 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THIEF
	goto_if_eq HeatBadgeMoveTutor_24
# 1526 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_RAPID_SPIN
	goto_if_eq HeatBadgeMoveTutor_25
# 1527 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NUZZLE
	goto_if_eq HeatBadgeMoveTutor_26
HeatBadgeMoveTutor_4:
# 1529 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1530 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

HeatBadgeMoveTutor_1:
# 1469 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1470 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox HeatBadgeItemShopMenu_Text_0
# 1471 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

HeatBadgeMoveTutor_5:
# 1506 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
# 1506 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FIRE_PUNCH
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_6:
# 1507 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICE_PUNCH
# 1507 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICE_PUNCH
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_7:
# 1508 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
# 1508 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THUNDER_PUNCH
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_8:
# 1509 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AIR_CUTTER
# 1509 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AIR_CUTTER
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_9:
# 1510 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WATER_PULSE
# 1510 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WATER_PULSE
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_10:
# 1511 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BUG_BITE
# 1511 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BUG_BITE
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_11:
# 1512 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PLUCK
# 1512 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PLUCK
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_12:
# 1513 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BITE
# 1513 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BITE
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_13:
# 1514 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HEART_STAMP
# 1514 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HEART_STAMP
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_14:
# 1515 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STOMP
# 1515 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STOMP
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_15:
# 1516 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLAME_BURST
# 1516 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLAME_BURST
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_16:
# 1517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BUBBLE_BEAM
# 1517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BUBBLE_BEAM
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_17:
# 1518 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AURORA_BEAM
# 1518 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AURORA_BEAM
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_18:
# 1519 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHOCK_WAVE
# 1519 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHOCK_WAVE
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_19:
# 1520 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_DRAIN
# 1520 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEGA_DRAIN
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_20:
# 1521 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MUD_SHOT
# 1521 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MUD_SHOT
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_21:
# 1522 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_TOMB
# 1522 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_TOMB
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_22:
# 1523 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BULLDOZE
# 1523 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BULLDOZE
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_23:
# 1524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_KNOCK_OFF
# 1524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_KNOCK_OFF
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_24:
# 1525 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THIEF
# 1525 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THIEF
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_25:
# 1526 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_RAPID_SPIN
# 1526 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_RAPID_SPIN
	goto HeatBadgeMoveTutor_4

HeatBadgeMoveTutor_26:
# 1527 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NUZZLE
# 1527 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NUZZLE
	goto HeatBadgeMoveTutor_4


BalanceBadgeMoveTutor::
# 1535 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1536 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1537 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, BalanceBadgeMoveTutor_1
# 1544 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_0, MOVE_U_TURN
# 1545 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_1, MOVE_VOLT_SWITCH
# 1546 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_2, MOVE_NIGHT_SLASH
# 1547 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_18, MOVE_PSYCHO_CUT
# 1548 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_3, MOVE_SLASH
# 1549 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_5, MOVE_SHADOW_CLAW
# 1552 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_4, MOVE_DRAIN_PUNCH
# 1553 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_5, MOVE_BRICK_BREAK
# 1554 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_6, MOVE_ROCK_SLIDE
# 1555 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_7, MOVE_CRUNCH
# 1556 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_8, MOVE_POISON_JAB
# 1557 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_9, MOVE_SEED_BOMB
# 1558 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_10, MOVE_ZEN_HEADBUTT
# 1559 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_11, MOVE_IRON_HEAD
# 1560 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_12, MOVE_LASH_OUT
# 1561 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_13, MOVE_STOMPING_TANTRUM
# 1562 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush BalanceBadgeMoveTutor_Text_14, MOVE_EXTREME_SPEED
# 1565 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1568 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_U_TURN
	goto_if_eq BalanceBadgeMoveTutor_5
# 1569 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_VOLT_SWITCH
	goto_if_eq BalanceBadgeMoveTutor_6
# 1570 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_NIGHT_SLASH
	goto_if_eq BalanceBadgeMoveTutor_7
# 1571 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PSYCHO_CUT
	goto_if_eq BalanceBadgeMoveTutor_8
# 1572 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SLASH
	goto_if_eq BalanceBadgeMoveTutor_9
# 1573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHADOW_CLAW
	goto_if_eq BalanceBadgeMoveTutor_10
# 1574 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DRAIN_PUNCH
	goto_if_eq BalanceBadgeMoveTutor_11
# 1575 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BRICK_BREAK
	goto_if_eq BalanceBadgeMoveTutor_12
# 1576 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ROCK_SLIDE
	goto_if_eq BalanceBadgeMoveTutor_13
# 1577 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CRUNCH
	goto_if_eq BalanceBadgeMoveTutor_14
# 1578 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_POISON_JAB
	goto_if_eq BalanceBadgeMoveTutor_15
# 1579 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SEED_BOMB
	goto_if_eq BalanceBadgeMoveTutor_16
# 1580 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ZEN_HEADBUTT
	goto_if_eq BalanceBadgeMoveTutor_17
# 1581 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_IRON_HEAD
	goto_if_eq BalanceBadgeMoveTutor_18
# 1582 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LASH_OUT
	goto_if_eq BalanceBadgeMoveTutor_19
# 1583 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_STOMPING_TANTRUM
	goto_if_eq BalanceBadgeMoveTutor_20
# 1584 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_EXTREME_SPEED
	goto_if_eq BalanceBadgeMoveTutor_21
BalanceBadgeMoveTutor_4:
# 1587 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1589 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

BalanceBadgeMoveTutor_1:
# 1538 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1539 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox BalanceBadgeItemShopMenu_Text_0
# 1540 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

BalanceBadgeMoveTutor_5:
# 1568 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_U_TURN
# 1568 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_U_TURN
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_6:
# 1569 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_VOLT_SWITCH
# 1569 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_VOLT_SWITCH
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_7:
# 1570 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_NIGHT_SLASH
# 1570 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_NIGHT_SLASH
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_8:
# 1571 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCHO_CUT
# 1571 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PSYCHO_CUT
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_9:
# 1572 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SLASH
# 1572 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SLASH
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_10:
# 1573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHADOW_CLAW
# 1573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHADOW_CLAW
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_11:
# 1574 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DRAIN_PUNCH
# 1574 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DRAIN_PUNCH
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_12:
# 1575 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BRICK_BREAK
# 1575 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BRICK_BREAK
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_13:
# 1576 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
# 1576 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_SLIDE
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_14:
# 1577 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CRUNCH
# 1577 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CRUNCH
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_15:
# 1578 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_POISON_JAB
# 1578 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POISON_JAB
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_16:
# 1579 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SEED_BOMB
# 1579 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SEED_BOMB
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_17:
# 1580 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ZEN_HEADBUTT
# 1580 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ZEN_HEADBUTT
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_18:
# 1581 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_IRON_HEAD
# 1581 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_IRON_HEAD
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_19:
# 1582 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LASH_OUT
# 1582 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LASH_OUT
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_20:
# 1583 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_STOMPING_TANTRUM
# 1583 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_STOMPING_TANTRUM
	goto BalanceBadgeMoveTutor_4

BalanceBadgeMoveTutor_21:
# 1584 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_EXTREME_SPEED
# 1584 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EXTREME_SPEED
	goto BalanceBadgeMoveTutor_4


FeatherBadgeMoveTutor::
# 1594 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1595 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1596 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, FeatherBadgeMoveTutor_1
# 1603 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_0, MOVE_AIR_SLASH
# 1604 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_1, MOVE_HYPER_VOICE
# 1605 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_2, MOVE_BUG_BUZZ
# 1606 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_3, MOVE_AURA_SPHERE
# 1607 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_16, MOVE_DUAL_WINGBEAT
# 1608 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_4, MOVE_FLY
# 1609 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_5, MOVE_BOUNCE
# 1612 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_6, MOVE_SCORCHING_SANDS
# 1613 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_7, MOVE_TERRAIN_PULSE
# 1614 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_8, MOVE_WEATHER_BALL
# 1615 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush KnuckleBadgeMoveTutor_Text_10, MOVE_ICY_WIND
# 1616 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_9, MOVE_ELECTROWEB
# 1617 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush DynamoBadgeMoveTutor_Text_22, MOVE_HEX
# 1618 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_10, MOVE_MYSTICAL_FIRE
# 1621 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AIR_SLASH
	goto_if_eq FeatherBadgeMoveTutor_5
# 1625 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HYPER_VOICE
	goto_if_eq FeatherBadgeMoveTutor_6
# 1626 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BUG_BUZZ
	goto_if_eq FeatherBadgeMoveTutor_7
# 1627 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_AURA_SPHERE
	goto_if_eq FeatherBadgeMoveTutor_8
# 1628 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DUAL_WINGBEAT
	goto_if_eq FeatherBadgeMoveTutor_9
# 1629 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLY
	goto_if_eq FeatherBadgeMoveTutor_10
# 1630 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BOUNCE
	goto_if_eq FeatherBadgeMoveTutor_11
# 1631 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SCORCHING_SANDS
	goto_if_eq FeatherBadgeMoveTutor_12
# 1632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_TERRAIN_PULSE
	goto_if_eq FeatherBadgeMoveTutor_13
# 1633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WEATHER_BALL
	goto_if_eq FeatherBadgeMoveTutor_14
# 1634 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICY_WIND
	goto_if_eq FeatherBadgeMoveTutor_15
# 1635 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ELECTROWEB
	goto_if_eq FeatherBadgeMoveTutor_16
# 1636 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HEX
	goto_if_eq FeatherBadgeMoveTutor_17
# 1637 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MYSTICAL_FIRE
	goto_if_eq FeatherBadgeMoveTutor_18
FeatherBadgeMoveTutor_4:
# 1640 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1641 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

FeatherBadgeMoveTutor_1:
# 1597 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1598 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox FeatherBadgeItemShopMenu_Text_0
# 1599 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

FeatherBadgeMoveTutor_5:
# 1624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AIR_SLASH
# 1624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AIR_SLASH
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_6:
# 1625 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HYPER_VOICE
# 1625 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HYPER_VOICE
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_7:
# 1626 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BUG_BUZZ
# 1626 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BUG_BUZZ
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_8:
# 1627 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_AURA_SPHERE
# 1627 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AURA_SPHERE
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_9:
# 1628 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DUAL_WINGBEAT
# 1628 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DUAL_WINGBEAT
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_10:
# 1629 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLY
# 1629 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLY
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_11:
# 1630 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BOUNCE
# 1630 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BOUNCE
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_12:
# 1631 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SCORCHING_SANDS
# 1631 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SCORCHING_SANDS
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_13:
# 1632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_TERRAIN_PULSE
# 1632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_TERRAIN_PULSE
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_14:
# 1633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WEATHER_BALL
# 1633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WEATHER_BALL
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_15:
# 1634 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICY_WIND
# 1634 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICY_WIND
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_16:
# 1635 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ELECTROWEB
# 1635 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ELECTROWEB
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_17:
# 1636 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HEX
# 1636 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HEX
	goto FeatherBadgeMoveTutor_4

FeatherBadgeMoveTutor_18:
# 1637 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MYSTICAL_FIRE
# 1637 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MYSTICAL_FIRE
	goto FeatherBadgeMoveTutor_4


MindBadgeMoveTutor::
# 1646 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1647 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1648 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, MindBadgeMoveTutor_1
# 1655 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_0, MOVE_PSYCHIC
# 1656 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_1, MOVE_SHADOW_BALL
# 1657 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_2, MOVE_DARK_PULSE
# 1658 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_3, MOVE_ENERGY_BALL
# 1659 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_4, MOVE_EARTH_POWER
# 1660 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_5, MOVE_FLASH_CANNON
# 1661 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_6, MOVE_SLUDGE_BOMB
# 1662 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_7, MOVE_DRAGON_PULSE
# 1663 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_8, MOVE_DAZZLING_GLEAM
# 1666 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_9, MOVE_PSYCHIC_FANGS
# 1667 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_10, MOVE_PLAY_ROUGH
# 1668 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_11, MOVE_LIQUIDATION
# 1669 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_12, MOVE_HIGH_HORSEPOWER
# 1670 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_13, MOVE_THROAT_CHOP
# 1673 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1676 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PSYCHIC
	goto_if_eq MindBadgeMoveTutor_5
# 1677 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SHADOW_BALL
	goto_if_eq MindBadgeMoveTutor_6
# 1678 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DARK_PULSE
	goto_if_eq MindBadgeMoveTutor_7
# 1679 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ENERGY_BALL
	goto_if_eq MindBadgeMoveTutor_8
# 1680 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_EARTH_POWER
	goto_if_eq MindBadgeMoveTutor_9
# 1681 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLASH_CANNON
	goto_if_eq MindBadgeMoveTutor_10
# 1682 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SLUDGE_BOMB
	goto_if_eq MindBadgeMoveTutor_11
# 1683 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DRAGON_PULSE
	goto_if_eq MindBadgeMoveTutor_12
# 1684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DAZZLING_GLEAM
	goto_if_eq MindBadgeMoveTutor_13
# 1685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PSYCHIC_FANGS
	goto_if_eq MindBadgeMoveTutor_14
# 1686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_PLAY_ROUGH
	goto_if_eq MindBadgeMoveTutor_15
# 1687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_LIQUIDATION
	goto_if_eq MindBadgeMoveTutor_16
# 1688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HIGH_HORSEPOWER
	goto_if_eq MindBadgeMoveTutor_17
# 1689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THROAT_CHOP
	goto_if_eq MindBadgeMoveTutor_18
MindBadgeMoveTutor_4:
# 1691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1692 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

MindBadgeMoveTutor_1:
# 1649 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1650 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MindBadgeItemShopMenu_Text_0
# 1651 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

MindBadgeMoveTutor_5:
# 1676 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCHIC
# 1676 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PSYCHIC
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_6:
# 1677 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SHADOW_BALL
# 1677 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SHADOW_BALL
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_7:
# 1678 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DARK_PULSE
# 1678 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DARK_PULSE
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_8:
# 1679 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ENERGY_BALL
# 1679 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ENERGY_BALL
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_9:
# 1680 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_EARTH_POWER
# 1680 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EARTH_POWER
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_10:
# 1681 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLASH_CANNON
# 1681 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLASH_CANNON
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_11:
# 1682 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SLUDGE_BOMB
# 1682 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SLUDGE_BOMB
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_12:
# 1683 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DRAGON_PULSE
# 1683 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DRAGON_PULSE
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_13:
# 1684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DAZZLING_GLEAM
# 1684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DAZZLING_GLEAM
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_14:
# 1685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCHIC_FANGS
# 1685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PSYCHIC_FANGS
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_15:
# 1686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_PLAY_ROUGH
# 1686 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_PLAY_ROUGH
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_16:
# 1687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_LIQUIDATION
# 1687 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_LIQUIDATION
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_17:
# 1688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HIGH_HORSEPOWER
# 1688 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HIGH_HORSEPOWER
	goto MindBadgeMoveTutor_4

MindBadgeMoveTutor_18:
# 1689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THROAT_CHOP
# 1689 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THROAT_CHOP
	goto MindBadgeMoveTutor_4


RainBadgeMoveTutor::
# 1697 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1698 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1699 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE08_GET, RainBadgeMoveTutor_1
# 1706 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_0, MOVE_FLAMETHROWER
# 1707 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_1, MOVE_ICE_BEAM
# 1708 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_2, MOVE_THUNDERBOLT
# 1709 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_3, MOVE_SURF
# 1710 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_4, MOVE_MOONBLAST
# 1711 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush FeatherBadgeMoveTutor_Text_2, MOVE_BUG_BUZZ
# 1714 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_5, MOVE_CLOSE_COMBAT
# 1715 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_6, MOVE_SUPERPOWER
# 1716 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_7, MOVE_EARTHQUAKE
# 1717 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_8, MOVE_FLARE_BLITZ
# 1718 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_9, MOVE_WAVE_CRASH
# 1719 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_10, MOVE_WOOD_HAMMER
# 1720 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_11, MOVE_BRAVE_BIRD
# 1721 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_12, MOVE_DOUBLE_EDGE
# 1722 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_13, MOVE_OUTRAGE
# 1723 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_14, MOVE_MEGAHORN
# 1724 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_15, MOVE_GUNK_SHOT
# 1725 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_16, MOVE_HURRICANE
# 1728 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush RainBadgeMoveTutor_Text_17, MOVE_HYDRO_PUMP
# 1729 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 17, 0, FALSE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 1732 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLAMETHROWER
	goto_if_eq RainBadgeMoveTutor_5
# 1733 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_ICE_BEAM
	goto_if_eq RainBadgeMoveTutor_6
# 1734 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_THUNDERBOLT
	goto_if_eq RainBadgeMoveTutor_7
# 1735 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SURF
	goto_if_eq RainBadgeMoveTutor_8
# 1736 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MOONBLAST
	goto_if_eq RainBadgeMoveTutor_9
# 1737 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BUG_BUZZ
	goto_if_eq RainBadgeMoveTutor_10
# 1738 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_CLOSE_COMBAT
	goto_if_eq RainBadgeMoveTutor_11
# 1739 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_SUPERPOWER
	goto_if_eq RainBadgeMoveTutor_12
# 1740 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_EARTHQUAKE
	goto_if_eq RainBadgeMoveTutor_13
# 1741 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_FLARE_BLITZ
	goto_if_eq RainBadgeMoveTutor_14
# 1742 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WAVE_CRASH
	goto_if_eq RainBadgeMoveTutor_15
# 1743 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_WOOD_HAMMER
	goto_if_eq RainBadgeMoveTutor_16
# 1744 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_BRAVE_BIRD
	goto_if_eq RainBadgeMoveTutor_17
# 1745 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_DOUBLE_EDGE
	goto_if_eq RainBadgeMoveTutor_18
# 1746 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_OUTRAGE
	goto_if_eq RainBadgeMoveTutor_19
# 1747 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_MEGAHORN
	goto_if_eq RainBadgeMoveTutor_20
# 1748 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_GUNK_SHOT
	goto_if_eq RainBadgeMoveTutor_21
# 1749 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HURRICANE
	goto_if_eq RainBadgeMoveTutor_22
# 1750 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MOVE_HYDRO_PUMP
	goto_if_eq RainBadgeMoveTutor_23
RainBadgeMoveTutor_4:
# 1752 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 127, MoveTutorMenuBadgeList
# 1753 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorQuestion
	return

RainBadgeMoveTutor_1:
# 1700 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1701 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox RainBadgeItemShopMenu_Text_0
# 1702 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto MoveTutorMenu
	return

RainBadgeMoveTutor_5:
# 1732 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLAMETHROWER
# 1732 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLAMETHROWER
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_6:
# 1733 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_ICE_BEAM
# 1733 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ICE_BEAM
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_7:
# 1734 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDERBOLT
# 1734 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_THUNDERBOLT
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_8:
# 1735 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SURF
# 1735 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SURF
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_9:
# 1736 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MOONBLAST
# 1736 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MOONBLAST
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_10:
# 1737 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BUG_BUZZ
# 1737 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BUG_BUZZ
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_11:
# 1738 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_CLOSE_COMBAT
# 1738 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CLOSE_COMBAT
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_12:
# 1739 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_SUPERPOWER
# 1739 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_SUPERPOWER
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_13:
# 1740 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_EARTHQUAKE
# 1740 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EARTHQUAKE
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_14:
# 1741 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_FLARE_BLITZ
# 1741 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_FLARE_BLITZ
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_15:
# 1742 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WAVE_CRASH
# 1742 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WAVE_CRASH
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_16:
# 1743 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_WOOD_HAMMER
# 1743 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_WOOD_HAMMER
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_17:
# 1744 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_BRAVE_BIRD
# 1744 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BRAVE_BIRD
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_18:
# 1745 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_DOUBLE_EDGE
# 1745 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_DOUBLE_EDGE
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_19:
# 1746 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_OUTRAGE
# 1746 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_OUTRAGE
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_20:
# 1747 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGAHORN
# 1747 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_MEGAHORN
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_21:
# 1748 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_GUNK_SHOT
# 1748 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_GUNK_SHOT
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_22:
# 1749 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HURRICANE
# 1749 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HURRICANE
	goto RainBadgeMoveTutor_4

RainBadgeMoveTutor_23:
# 1750 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8005, MOVE_HYDRO_PUMP
# 1750 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	buffermovename STR_VAR_1, MOVE_HYDRO_PUMP
	goto RainBadgeMoveTutor_4


Wonder_Trade::
# 1777 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, Wonder_Trade_1
# 1804 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1805 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox StoneBadgeItemShopMenu_Text_0
# 1806 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto OtherServices
	return

Wonder_Trade_1:
# 1778 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	getpartysize
# 1779 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_End
# 1780 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	chooseboxmon SELECT_PC_MON_WONDER_TRADE
# 1781 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 1784 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 255, EventScript_End
# 1786 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lockall
# 1787 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	delay 20
# 1788 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Wonder_Trade_Text_0
# 1789 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 1791 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_0x8004
# 1792 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special CreateWonderTradePokemon
# 1793 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playse SE_PC_LOGIN
# 1794 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitse
# 1795 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playse SE_DING_DONG
# 1796 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Wonder_Trade_Text_1
# 1797 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 1798 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 1799 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 1801 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special DoInGameTradeScene
# 1802 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto WonderTradeAgain
	return


WonderTradeAgain::
# 1811 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1812 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox WonderTradeAgain_Text_0, MSGBOX_YESNO
# 1813 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq WonderTradeAgain_1
# 1816 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	return

WonderTradeAgain_1:
# 1814 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Wonder_Trade
	return


TeraTypeChangerMenu::
# 1821 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 1822 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 1825 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1826 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraTypeChangerMenu_Text_0
# 1827 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 1828 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq TeraTypeChangerMenu_2
TeraTypeChangerMenu_1:
# 1832 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 1833 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq TeraTypeChangerMenu_5
TeraTypeChangerMenu_4:
# 1840 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_2, TYPE_NORMAL
# 1841 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_3, TYPE_FIGHTING
# 1842 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_4, TYPE_FLYING
# 1843 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_5, TYPE_POISON
# 1844 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_6, TYPE_GROUND
# 1845 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_7, TYPE_ROCK
# 1846 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_8, TYPE_BUG
# 1847 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_9, TYPE_GHOST
# 1848 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_10, TYPE_STEEL
# 1849 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_11, TYPE_FIRE
# 1850 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_12, TYPE_WATER
# 1851 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_13, TYPE_GRASS
# 1852 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_14, TYPE_ELECTRIC
# 1853 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush MindBadgeMoveTutor_Text_0, TYPE_PSYCHIC
# 1854 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_15, TYPE_ICE
# 1855 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_16, TYPE_DRAGON
# 1856 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_17, TYPE_DARK
# 1857 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush TeraTypeChangerMenu_Text_18, TYPE_FAIRY
# 1860 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 19, 0, FALSE, 6, FALSE, VAR_0x800A, 0
# 1863 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq TeraTypeChangerMenu_8
TeraTypeChangerMenu_7:
# 1867 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 1870 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_NORMAL
	goto_if_eq TeraTypeChangerMenu_11
# 1871 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FIGHTING
	goto_if_eq TeraTypeChangerMenu_12
# 1872 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FLYING
	goto_if_eq TeraTypeChangerMenu_13
# 1873 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_POISON
	goto_if_eq TeraTypeChangerMenu_14
# 1874 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GROUND
	goto_if_eq TeraTypeChangerMenu_15
# 1875 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ROCK
	goto_if_eq TeraTypeChangerMenu_16
# 1876 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_BUG
	goto_if_eq TeraTypeChangerMenu_17
# 1877 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GHOST
	goto_if_eq TeraTypeChangerMenu_18
# 1878 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_STEEL
	goto_if_eq TeraTypeChangerMenu_19
# 1879 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FIRE
	goto_if_eq TeraTypeChangerMenu_20
# 1880 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_WATER
	goto_if_eq TeraTypeChangerMenu_21
# 1881 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GRASS
	goto_if_eq TeraTypeChangerMenu_22
# 1882 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ELECTRIC
	goto_if_eq TeraTypeChangerMenu_23
# 1883 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_PSYCHIC
	goto_if_eq TeraTypeChangerMenu_24
# 1884 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ICE
	goto_if_eq TeraTypeChangerMenu_25
# 1885 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_DRAGON
	goto_if_eq TeraTypeChangerMenu_26
# 1886 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_DARK
	goto_if_eq TeraTypeChangerMenu_27
# 1887 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FAIRY
	goto_if_eq TeraTypeChangerMenu_28
TeraTypeChangerMenu_10:
# 1890 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	bufferitemname STR_VAR_1, VAR_0x8006
# 1893 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1894 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraTypeChangerMenu_Text_19, MSGBOX_YESNO
# 1896 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TeraTypeChangerMenu_47
# 1931 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	return

TeraTypeChangerMenu_2:
# 1829 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	goto TeraTypeChangerMenu_1

TeraTypeChangerMenu_5:
# 1834 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1835 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraTypeChangerMenu_Text_1
# 1836 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	goto TeraTypeChangerMenu_4

TeraTypeChangerMenu_8:
# 1864 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	goto TeraTypeChangerMenu_7

TeraTypeChangerMenu_11:
# 1870 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_NORMAL_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_12:
# 1871 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_FIGHTING_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_13:
# 1872 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_FLYING_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_14:
# 1873 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_POISON_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_15:
# 1874 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_GROUND_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_16:
# 1875 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_ROCK_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_17:
# 1876 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_BUG_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_18:
# 1877 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_GHOST_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_19:
# 1878 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_STEEL_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_20:
# 1879 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_FIRE_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_21:
# 1880 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_WATER_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_22:
# 1881 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_GRASS_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_23:
# 1882 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_ELECTRIC_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_24:
# 1883 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_PSYCHIC_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_25:
# 1884 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_ICE_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_26:
# 1885 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_DRAGON_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_27:
# 1886 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_DARK_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_28:
# 1887 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8006, ITEM_FAIRY_TERA_SHARD
	goto TeraTypeChangerMenu_10

TeraTypeChangerMenu_47:
	checkitem VAR_0x8006, 100
# 0 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TeraTypeChangerMenu_51
TeraTypeChangerMenu_50:
# 1903 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraTypeChangerMenu_Text_21
# 1904 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	removeitem VAR_0x8006, 100
# 1907 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_NORMAL
	goto_if_eq TeraTypeChangerMenu_54
# 1908 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FIGHTING
	goto_if_eq TeraTypeChangerMenu_55
# 1909 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FLYING
	goto_if_eq TeraTypeChangerMenu_56
# 1910 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_POISON
	goto_if_eq TeraTypeChangerMenu_57
# 1911 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GROUND
	goto_if_eq TeraTypeChangerMenu_58
# 1912 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ROCK
	goto_if_eq TeraTypeChangerMenu_59
# 1913 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_BUG
	goto_if_eq TeraTypeChangerMenu_60
# 1914 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GHOST
	goto_if_eq TeraTypeChangerMenu_61
# 1915 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_STEEL
	goto_if_eq TeraTypeChangerMenu_62
# 1916 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FIRE
	goto_if_eq TeraTypeChangerMenu_63
# 1917 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_WATER
	goto_if_eq TeraTypeChangerMenu_64
# 1918 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_GRASS
	goto_if_eq TeraTypeChangerMenu_65
# 1919 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ELECTRIC
	goto_if_eq TeraTypeChangerMenu_66
# 1920 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_PSYCHIC
	goto_if_eq TeraTypeChangerMenu_67
# 1921 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_ICE
	goto_if_eq TeraTypeChangerMenu_68
# 1922 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_DRAGON
	goto_if_eq TeraTypeChangerMenu_69
# 1923 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_DARK
	goto_if_eq TeraTypeChangerMenu_70
# 1924 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_0x8005, TYPE_FAIRY
	goto_if_eq TeraTypeChangerMenu_71
TeraTypeChangerMenu_53:
# 1926 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playse SE_SUCCESS
# 1927 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitse
# 1928 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraVerifyMenu
	return

TeraTypeChangerMenu_51:
# 1898 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1899 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraTypeChangerMenu_Text_20
# 1900 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	goto TeraTypeChangerMenu_50

TeraTypeChangerMenu_54:
# 1907 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_NORMAL, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_55:
# 1908 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_FIGHTING, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_56:
# 1909 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_FLYING, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_57:
# 1910 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_POISON, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_58:
# 1911 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_GROUND, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_59:
# 1912 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_ROCK, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_60:
# 1913 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_BUG, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_61:
# 1914 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_GHOST, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_62:
# 1915 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_STEEL, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_63:
# 1916 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_FIRE, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_64:
# 1917 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_WATER, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_65:
# 1918 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_GRASS, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_66:
# 1919 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_ELECTRIC, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_67:
# 1920 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_PSYCHIC, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_68:
# 1921 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_ICE, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_69:
# 1922 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_DRAGON, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_70:
# 1923 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_DARK, VAR_0x8004
	goto TeraTypeChangerMenu_53

TeraTypeChangerMenu_71:
# 1924 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setteratype TYPE_FAIRY, VAR_0x8004
	goto TeraTypeChangerMenu_53


TeraVerifyMenu::
# 1936 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1937 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox TeraVerifyMenu_Text_0, MSGBOX_YESNO
# 1938 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq TeraVerifyMenu_1
# 1941 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	return

TeraVerifyMenu_1:
# 1939 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto TeraTypeChangerMenu
	return


Cacoon_Ritual::
# 1947 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lockall
# 1948 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1949 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Cacoon_Ritual_Text_0
# 1950 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	chooseboxmon SELECT_PC_MON_REDUCE_BEV_PERCENTAGE
# 1951 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 1952 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 255, PokemonCompendium2
# 1955 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8007, VAR_0x8004
# 1956 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8008, VAR_MON_BOX_ID
# 1957 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8009, VAR_MON_BOX_POS
# 1959 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Cacoon_Ritual_Text_1
# 1960 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	chooseboxmon SELECT_PC_MON_RITUAL
# 1961 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 1962 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 255, PokemonCompendium2
# 1966 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_MON_BOX_ID
# 1967 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	copyvar VAR_0x8006, VAR_MON_BOX_POS
# 1970 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	callnative PerformCocoonRitual
# 1971 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Ritual_Failed
# 1973 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1974 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1975 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Cacoon_Ritual_Text_2
# 1976 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 1977 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto RitualAgain
	return


RitualAgain::
# 1981 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lockall
# 1982 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox RitualAgain_Text_0, MSGBOX_YESNO
# 1983 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RitualAgain_1
# 1986 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto PokemonCompendium2
	return

RitualAgain_1:
# 1984 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto Cacoon_Ritual
	return


Ritual_Failed::
# 1991 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lockall
# 1992 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker SP_NAME_WISDOM
# 1993 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Ritual_Failed_Text_0
	return


MysteryManGreeting::
# 2033 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2034 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MysteryManGreeting_Text_1, MSGBOX_YESNO
# 2035 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MysteryManGreeting_1
# 2046 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2047 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MysteryManGreeting_Text_3
# 2048 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end

MysteryManGreeting_1:
# 2036 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MysteryManGreeting_Text_2
# 2037 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special EnterCode
# 2038 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 2039 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	special GetCodeFeedback
# 2040 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
# 2041 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, IncorrectCode
# 2042 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Demo2Code
# 2043 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 2, ShinyStarterWithZigzagoon
	end


IncorrectCode::
# 2055 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2056 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox IncorrectCode_Text_0
# 2057 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ComebackWithCode
	return


ComebackWithCode::
# 2061 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2062 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MysteryManGreeting_Text_3
# 2063 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


Demo2Code::
# 2068 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_MYSTERY_GIFT_16, Demo2Code_1
# 2075 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2076 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Demo2Code_Text_1
# 2077 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2078 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2079 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 2080 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	giveitempack ITEM_GREAT_BALL, 10, ITEM_HYPER_POTION, 10, ITEM_FIRE_STONE, 10, ITEM_WATER_STONE, 10, ITEM_THUNDER_STONE, 10, ITEM_LEAF_STONE, 10, ITEM_SUN_STONE, 10, ITEM_MOON_STONE, 10, ITEM_ICE_STONE, 10, ITEM_DUSK_STONE, 10, ITEM_SHINY_STONE, 10, ITEM_DAWN_STONE, 10, ITEM_JOLLY_MINT, 10, ITEM_ADAMANT_MINT, 10, ITEM_BOLD_MINT, 10, ITEM_NAIVE_MINT, 10, ITEM_MODEST_MINT, 10, ITEM_HASTY_MINT, 10, ITEM_RELAXED_MINT, 10, ITEM_LAX_MINT, 10, ITEM_TIMID_MINT, 10, ITEM_GENTLE_MINT, 10, ITEM_NAUGHTY_MINT, 10, ITEM_BRAVE_MINT, 10, ITEM_MILD_MINT, 10, ITEM_CALM_MINT, 10, ITEM_IMPISH_MINT, 10, ITEM_LONELY_MINT, 10, ITEM_RASH_MINT, 10, ITEM_SASSY_MINT, 10, ITEM_SERIOUS_MINT, 10, ITEM_CAREFUL_MINT, 10, ITEM_LINKING_CORD, 10, ITEM_BOTTLE_CAP, 10
# 2081 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Demo2Code_5
# 2085 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_MYSTERY_GIFT_16
Demo2Code_4:
# 2087 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ComebackWithCode
	return

Demo2Code_1:
# 2069 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2070 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Demo2Code_Text_0
# 2071 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_TOO_BAD
# 2072 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2073 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ComebackWithCode
	return

Demo2Code_5:
# 2082 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2083 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Demo2Code_Text_2
	goto Demo2Code_4


ShinyStarterWithZigzagoon::
# 2092 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_MYSTERY_GIFT_17, ShinyStarterWithZigzagoon_1
# 2099 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarterWithZigzagoon_Text_0
# 2101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2102 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarterWithZigzagoon_Text_1
# 2104 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_ZIGZAGOON, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, MAX_PER_STAT_IVS, MAX_PER_STAT_IVS, MAX_PER_STAT_IVS, MAX_PER_STAT_IVS, MAX_PER_STAT_IVS, MAX_PER_STAT_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
# 2105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ShinyStarterMenu
	return

ShinyStarterWithZigzagoon_1:
# 2093 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setspeaker MysteryManGreeting_Text_0
# 2094 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox Demo2Code_Text_0
# 2095 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_TOO_BAD
# 2096 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2097 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ComebackWithCode
	return


ShinyStarterMenu::
# 2111 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	lock
# 2112 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 2113 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 2114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarterMenu_Text_0
# 2115 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2116 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2117 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	goto ShinyStarters
	return


ShinyStarters::
# 2121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_0, SPECIES_BULBASAUR
# 2122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_1, SPECIES_CHARMANDER
# 2123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_2, SPECIES_SQUIRTLE
# 2124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_3, SPECIES_CHIKORITA
# 2125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_4, SPECIES_CYNDAQUIL
# 2126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_5, SPECIES_TOTODILE
# 2127 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_6, SPECIES_TREECKO
# 2128 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_7, SPECIES_TORCHIC
# 2129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_8, SPECIES_MUDKIP
# 2130 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_9, SPECIES_TURTWIG
# 2131 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_10, SPECIES_CHIMCHAR
# 2132 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_11, SPECIES_PIPLUP
# 2133 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_12, SPECIES_SNIVY
# 2134 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_13, SPECIES_TEPIG
# 2135 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_14, SPECIES_OSHAWOTT
# 2136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_15, SPECIES_CHESPIN
# 2137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_16, SPECIES_FENNEKIN
# 2138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_17, SPECIES_FROAKIE
# 2139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_18, SPECIES_ROWLET
# 2140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_19, SPECIES_LITTEN
# 2141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_20, SPECIES_POPPLIO
# 2142 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_21, SPECIES_GROOKEY
# 2143 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_22, SPECIES_SCORBUNNY
# 2144 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_23, SPECIES_SOBBLE
# 2145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_24, SPECIES_SPRIGATITO
# 2146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_25, SPECIES_FUECOCO
# 2147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultipush ShinyStarters_Text_26, SPECIES_QUAXLY
# 2148 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	dynmultistack 0, 0, TRUE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_NONE
# 2150 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_BULBASAUR
	goto_if_eq ShinyStarters_2
ShinyStarters_1:
# 2155 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_5
# 2160 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_6
ShinyStarters_4:
# 2162 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_10
ShinyStarters_9:
# 2170 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_CHARMANDER
	goto_if_eq ShinyStarters_13
ShinyStarters_12:
# 2175 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_16
# 2180 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_17
ShinyStarters_15:
# 2182 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_21
ShinyStarters_20:
# 2190 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_SQUIRTLE
	goto_if_eq ShinyStarters_24
ShinyStarters_23:
# 2195 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_27
# 2200 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_28
ShinyStarters_26:
# 2202 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_32
ShinyStarters_31:
# 2210 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_CHIKORITA
	goto_if_eq ShinyStarters_35
ShinyStarters_34:
# 2214 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_38
# 2219 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_39
ShinyStarters_37:
# 2221 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_43
ShinyStarters_42:
# 2229 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_CYNDAQUIL
	goto_if_eq ShinyStarters_46
ShinyStarters_45:
# 2233 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_49
# 2238 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_50
ShinyStarters_48:
# 2240 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_54
ShinyStarters_53:
# 2248 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_TOTODILE
	goto_if_eq ShinyStarters_57
ShinyStarters_56:
# 2253 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_60
# 2258 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_61
ShinyStarters_59:
# 2260 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_65
ShinyStarters_64:
# 2269 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_TREECKO
	goto_if_eq ShinyStarters_68
ShinyStarters_67:
# 2273 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_71
# 2278 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_72
ShinyStarters_70:
# 2280 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_76
ShinyStarters_75:
# 2288 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_TORCHIC
	goto_if_eq ShinyStarters_79
ShinyStarters_78:
# 2293 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_82
# 2298 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_83
ShinyStarters_81:
# 2300 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_87
ShinyStarters_86:
# 2308 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_MUDKIP
	goto_if_eq ShinyStarters_90
ShinyStarters_89:
# 2313 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_93
# 2318 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_94
ShinyStarters_92:
# 2320 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_98
ShinyStarters_97:
# 2328 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_TURTWIG
	goto_if_eq ShinyStarters_101
ShinyStarters_100:
# 2333 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_104
# 2337 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_105
ShinyStarters_103:
# 2339 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_109
ShinyStarters_108:
# 2347 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_CHIMCHAR
	goto_if_eq ShinyStarters_112
ShinyStarters_111:
# 2353 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_115
# 2358 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_116
ShinyStarters_114:
# 2360 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_120
ShinyStarters_119:
# 2368 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_PIPLUP
	goto_if_eq ShinyStarters_123
ShinyStarters_122:
# 2374 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_126
# 2379 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_127
ShinyStarters_125:
# 2381 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_131
ShinyStarters_130:
# 2389 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_SNIVY
	goto_if_eq ShinyStarters_134
ShinyStarters_133:
# 2394 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_137
# 2399 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_138
ShinyStarters_136:
# 2401 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_142
ShinyStarters_141:
# 2409 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_TEPIG
	goto_if_eq ShinyStarters_145
ShinyStarters_144:
# 2414 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_148
# 2419 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_149
ShinyStarters_147:
# 2421 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_153
ShinyStarters_152:
# 2429 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_OSHAWOTT
	goto_if_eq ShinyStarters_156
ShinyStarters_155:
# 2435 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_159
# 2440 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_160
ShinyStarters_158:
# 2442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_164
ShinyStarters_163:
# 2450 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_CHESPIN
	goto_if_eq ShinyStarters_167
ShinyStarters_166:
# 2455 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_170
# 2460 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_171
ShinyStarters_169:
# 2462 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_175
ShinyStarters_174:
# 2470 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_FENNEKIN
	goto_if_eq ShinyStarters_178
ShinyStarters_177:
# 2475 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_181
# 2480 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_182
ShinyStarters_180:
# 2482 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_186
ShinyStarters_185:
# 2490 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_FROAKIE
	goto_if_eq ShinyStarters_189
ShinyStarters_188:
# 2495 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_192
# 2500 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_193
ShinyStarters_191:
# 2502 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_197
ShinyStarters_196:
# 2510 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_ROWLET
	goto_if_eq ShinyStarters_200
ShinyStarters_199:
# 2515 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_203
# 2520 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_204
ShinyStarters_202:
# 2522 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_208
ShinyStarters_207:
# 2530 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_LITTEN
	goto_if_eq ShinyStarters_211
ShinyStarters_210:
# 2535 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_214
# 2540 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_215
ShinyStarters_213:
# 2542 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_219
ShinyStarters_218:
# 2550 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_POPPLIO
	goto_if_eq ShinyStarters_222
ShinyStarters_221:
# 2555 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_225
# 2560 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_226
ShinyStarters_224:
# 2562 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_230
ShinyStarters_229:
# 2570 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_GROOKEY
	goto_if_eq ShinyStarters_233
ShinyStarters_232:
# 2575 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_236
# 2580 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_237
ShinyStarters_235:
# 2582 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_241
ShinyStarters_240:
# 2590 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_SCORBUNNY
	goto_if_eq ShinyStarters_244
ShinyStarters_243:
# 2595 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_247
# 2600 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_248
ShinyStarters_246:
# 2602 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_252
ShinyStarters_251:
# 2610 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_SOBBLE
	goto_if_eq ShinyStarters_255
ShinyStarters_254:
# 2615 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_258
# 2620 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_259
ShinyStarters_257:
# 2622 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_263
ShinyStarters_262:
# 2630 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_SPRIGATITO
	goto_if_eq ShinyStarters_266
ShinyStarters_265:
# 2635 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_269
# 2640 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_270
ShinyStarters_268:
# 2642 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_274
ShinyStarters_273:
# 2650 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_FUECOCO
	goto_if_eq ShinyStarters_277
ShinyStarters_276:
# 2655 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_280
# 2658 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_281
ShinyStarters_279:
# 2660 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_285
ShinyStarters_284:
# 2668 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_QUAXLY
	goto_if_eq ShinyStarters_288
ShinyStarters_287:
# 2673 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyStarters_291
# 2678 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShinyStarters_292
ShinyStarters_290:
# 2680 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ShinyStarters_295
	return

ShinyStarters_2:
# 2151 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_BULBASAUR, 10, 3
# 2152 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
# 2153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_27, MSGBOX_YESNO
# 2154 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_1

ShinyStarters_5:
# 2156 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2157 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_6:
# 2161 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_BULBASAUR, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_4

ShinyStarters_10:
# 2163 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_28
# 2165 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2166 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2167 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_9

ShinyStarters_13:
# 2171 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
# 2172 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_CHARMANDER, 10, 3
# 2173 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_29, MSGBOX_YESNO
# 2174 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_12

ShinyStarters_16:
# 2176 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2177 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_17:
# 2181 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_CHARMANDER, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_15

ShinyStarters_21:
# 2183 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_30
# 2185 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2186 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2187 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_20

ShinyStarters_24:
# 2191 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
# 2192 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_SQUIRTLE, 10, 3
# 2193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_31, MSGBOX_YESNO
# 2194 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_23

ShinyStarters_27:
# 2196 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2197 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_28:
# 2201 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_SQUIRTLE, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_26

ShinyStarters_32:
# 2203 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2204 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_32
# 2205 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2206 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2207 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_31

ShinyStarters_35:
# 2211 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_CHIKORITA, CRY_MODE_NORMAL
# 2212 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 2213 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_33, MSGBOX_YESNO
	goto ShinyStarters_34

ShinyStarters_38:
# 2215 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2216 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_39:
# 2220 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_CHIKORITA, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_37

ShinyStarters_43:
# 2222 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2223 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_34
# 2224 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2225 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2226 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_42

ShinyStarters_46:
# 2230 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
# 2231 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 2232 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_35, MSGBOX_YESNO
	goto ShinyStarters_45

ShinyStarters_49:
# 2234 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2235 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_50:
# 2239 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_CYNDAQUIL, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_48

ShinyStarters_54:
# 2241 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2242 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_36
# 2243 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2244 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2245 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_53

ShinyStarters_57:
# 2249 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_TOTODILE, CRY_MODE_NORMAL
# 2250 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 2251 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_37, MSGBOX_YESNO
# 2252 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_56

ShinyStarters_60:
# 2254 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2255 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_61:
# 2259 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_TOTODILE, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_59

ShinyStarters_65:
# 2261 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2262 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_38
# 2263 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2264 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2266 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_64

ShinyStarters_68:
# 2270 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_TREECKO, 10, 3
# 2271 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_TREECKO, CRY_MODE_NORMAL
# 2272 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_39, MSGBOX_YESNO
	goto ShinyStarters_67

ShinyStarters_71:
# 2274 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2275 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_72:
# 2279 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_TREECKO, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_70

ShinyStarters_76:
# 2281 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2282 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_40
# 2283 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2284 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2285 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_75

ShinyStarters_79:
# 2289 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_TORCHIC, CRY_MODE_NORMAL
# 2290 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_TORCHIC, 10, 3
# 2291 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_41, MSGBOX_YESNO
# 2292 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_78

ShinyStarters_82:
# 2294 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2295 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_83:
# 2299 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_TORCHIC, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_81

ShinyStarters_87:
# 2301 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2302 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_42
# 2303 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2304 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2305 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_86

ShinyStarters_90:
# 2309 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_MUDKIP, CRY_MODE_NORMAL
# 2310 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_MUDKIP, 10, 3
# 2311 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_43, MSGBOX_YESNO
# 2312 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_89

ShinyStarters_93:
# 2314 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2315 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_94:
# 2319 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_MUDKIP, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_92

ShinyStarters_98:
# 2321 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2322 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_44
# 2323 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2324 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2325 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_97

ShinyStarters_101:
# 2329 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_TURTWIG, CRY_MODE_NORMAL
# 2330 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_TURTWIG, 10, 3
# 2331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_45, MSGBOX_YESNO
# 2332 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_100

ShinyStarters_104:
# 2334 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2335 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_105:
# 2338 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_TURTWIG, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_103

ShinyStarters_109:
# 2340 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2341 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_46
# 2342 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2343 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2344 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_108

ShinyStarters_112:
# 2348 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_NORMAL
# 2349 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_CHIMCHAR, 10, 3
# 2350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_47, MSGBOX_YESNO
# 2351 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2352 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_111

ShinyStarters_115:
# 2354 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2355 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_116:
# 2359 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 0, SPECIES_CHIMCHAR, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_114

ShinyStarters_120:
# 2361 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_48
# 2363 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2364 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2365 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_119

ShinyStarters_123:
# 2369 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_PIPLUP, CRY_MODE_NORMAL
# 2370 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_PIPLUP, 10, 3
# 2371 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_49, MSGBOX_YESNO
# 2372 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2373 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_122

ShinyStarters_126:
# 2375 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2376 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_127:
# 2380 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_PIPLUP, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_125

ShinyStarters_131:
# 2382 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2383 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_50
# 2384 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2385 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2386 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_130

ShinyStarters_134:
# 2390 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
# 2391 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_SNIVY, 10, 3
# 2392 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_51, MSGBOX_YESNO
# 2393 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_133

ShinyStarters_137:
# 2395 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2396 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_138:
# 2400 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_SNIVY, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_136

ShinyStarters_142:
# 2402 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2403 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_52
# 2404 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2405 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2406 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_141

ShinyStarters_145:
# 2410 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_TEPIG, CRY_MODE_NORMAL
# 2411 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_TEPIG, 10, 3
# 2412 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_53, MSGBOX_YESNO
# 2413 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_144

ShinyStarters_148:
# 2415 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2416 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_149:
# 2420 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_TEPIG, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_147

ShinyStarters_153:
# 2422 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2423 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_54
# 2424 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2425 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2426 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_152

ShinyStarters_156:
# 2430 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_NORMAL
# 2431 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_OSHAWOTT, 10, 3
# 2432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_55, MSGBOX_YESNO
# 2433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2434 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_155

ShinyStarters_159:
# 2436 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2437 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_160:
# 2441 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_OSHAWOTT, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_158

ShinyStarters_164:
# 2443 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_56
# 2445 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2446 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2447 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_163

ShinyStarters_167:
# 2451 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_CHESPIN, CRY_MODE_NORMAL
# 2452 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_CHESPIN, 10, 3
# 2453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_57, MSGBOX_YESNO
# 2454 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_166

ShinyStarters_170:
# 2456 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2457 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_171:
# 2461 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_CHESPIN, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_169

ShinyStarters_175:
# 2463 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2464 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_58
# 2465 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2466 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2467 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_174

ShinyStarters_178:
# 2471 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_FENNEKIN, CRY_MODE_NORMAL
# 2472 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_FENNEKIN, 10, 3
# 2473 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_59, MSGBOX_YESNO
# 2474 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_177

ShinyStarters_181:
# 2476 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2477 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_182:
# 2481 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_FENNEKIN, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_180

ShinyStarters_186:
# 2483 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2484 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_60
# 2485 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2486 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2487 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_185

ShinyStarters_189:
# 2491 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
# 2492 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_FROAKIE, 10, 3
# 2493 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_61, MSGBOX_YESNO
# 2494 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_188

ShinyStarters_192:
# 2496 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2497 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_193:
# 2501 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_FROAKIE, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_191

ShinyStarters_197:
# 2503 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2504 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_62
# 2505 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2506 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2507 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_196

ShinyStarters_200:
# 2511 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_ROWLET, CRY_MODE_NORMAL
# 2512 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_ROWLET, 10, 3
# 2513 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_63, MSGBOX_YESNO
# 2514 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_199

ShinyStarters_203:
# 2516 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_204:
# 2521 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_ROWLET, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_202

ShinyStarters_208:
# 2523 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_64
# 2525 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2526 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2527 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_207

ShinyStarters_211:
# 2531 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_LITTEN, CRY_MODE_NORMAL
# 2532 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_LITTEN, 10, 3
# 2533 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_65, MSGBOX_YESNO
# 2534 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_210

ShinyStarters_214:
# 2536 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2537 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_215:
# 2541 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_LITTEN, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_213

ShinyStarters_219:
# 2543 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2544 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_66
# 2545 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2546 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2547 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_218

ShinyStarters_222:
# 2551 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
# 2552 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_POPPLIO, 10, 3
# 2553 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_67, MSGBOX_YESNO
# 2554 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_221

ShinyStarters_225:
# 2556 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2557 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_226:
# 2561 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_POPPLIO, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_224

ShinyStarters_230:
# 2563 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2564 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_68
# 2565 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2566 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2567 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_229

ShinyStarters_233:
# 2571 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_GROOKEY, CRY_MODE_NORMAL
# 2572 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_GROOKEY, 10, 3
# 2573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_69, MSGBOX_YESNO
# 2574 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_232

ShinyStarters_236:
# 2576 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2577 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_237:
# 2581 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_GROOKEY, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_235

ShinyStarters_241:
# 2583 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2584 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_70
# 2585 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2586 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2587 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_240

ShinyStarters_244:
# 2591 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SCORBUNNY, CRY_MODE_NORMAL
# 2592 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_SCORBUNNY, 10, 3
# 2593 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_71, MSGBOX_YESNO
# 2594 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_243

ShinyStarters_247:
# 2596 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2597 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_248:
# 2601 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_SCORBUNNY, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_246

ShinyStarters_252:
# 2603 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2604 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_72
# 2605 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2606 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2607 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_251

ShinyStarters_255:
# 2611 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SOBBLE, CRY_MODE_NORMAL
# 2612 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_SOBBLE, 10, 3
# 2613 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_73, MSGBOX_YESNO
# 2614 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_254

ShinyStarters_258:
# 2616 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2617 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_259:
# 2621 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_SOBBLE, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_257

ShinyStarters_263:
# 2623 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_74
# 2625 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2626 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2627 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_262

ShinyStarters_266:
# 2631 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_SPRIGATITO, CRY_MODE_NORMAL
# 2632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_SPRIGATITO, 10, 3
# 2633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_75, MSGBOX_YESNO
# 2634 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_265

ShinyStarters_269:
# 2636 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2637 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_270:
# 2641 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_SPRIGATITO, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_268

ShinyStarters_274:
# 2643 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2644 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_76
# 2645 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2646 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2647 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_273

ShinyStarters_277:
# 2651 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_FUECOCO, CRY_MODE_NORMAL
# 2652 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_FUECOCO, 10, 3
# 2653 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_77, MSGBOX_YESNO
# 2654 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_276

ShinyStarters_280:
# 2656 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2657 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	goto ShinyStarters_279

ShinyStarters_281:
# 2659 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_FUECOCO, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_279

ShinyStarters_285:
# 2661 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2662 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_78
# 2663 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2664 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2665 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	goto ShinyStarters_284

ShinyStarters_288:
# 2669 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playmoncry SPECIES_QUAXLY, CRY_MODE_NORMAL
# 2670 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	showmonpic SPECIES_QUAXLY, 10, 3
# 2671 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_79, MSGBOX_YESNO
# 2672 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
	goto ShinyStarters_287

ShinyStarters_291:
# 2674 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2675 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call ShinyStarterMenu
	return

ShinyStarters_292:
# 2679 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	createmon 0, 6, SPECIES_QUAXLY, 5, ITEM_NONE, BALL_CHERISH, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS, 0, 0, 10
	goto ShinyStarters_290

ShinyStarters_295:
# 2681 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_EVOLVED
# 2682 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox ShinyStarters_Text_80
# 2683 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 2684 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2685 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call NicknamePartyMon2
	return


NicknameBoxMon2::
# 2691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox NicknameBoxMon2_Text_0, MSGBOX_YESNO
# 2692 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2693 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2694 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon2_2
NicknameBoxMon2_1:
# 2699 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox NicknameBoxMon2_Text_1
	return

NicknameBoxMon2_2:
# 2695 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 2696 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 2697 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	goto NicknameBoxMon2_1


NicknamePartyMon2::
# 2703 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox NicknamePartyMon2_Text_0, MSGBOX_YESNO
# 2704 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 2705 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon2_1
# 2712 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NicknamePartyMon2_2
	return

NicknamePartyMon2_1:
# 2706 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 2707 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 2708 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 2709 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2710 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end

NicknamePartyMon2_2:
# 2713 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 2714 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 2715 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	hidemonpic
# 2716 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


EventScript_MichaelMysteryGift::
# 2725 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_MICHAEL_MYSTERY_GIFT, MichaelMysteryGift_Text_Intro, MichaelMysteryGift_Text_Defeat
# 2726 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox MichaelMysteryGift_Text_PostBattle, MSGBOX_AUTOCLOSE
	end


MegaAlakazamIntro_Text_0:
# 79 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Greetings, trainer.$"

PlayerTalkingToMegaAlakazam_Text_0:
# 89 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER}$"

PlayerTalkingToMegaAlakazam_Text_1:
# 90 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you talking to me?$"

MegaAlakazamTalkingtoPlayer1_Text_0:
# 97 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Yes, I'm a talking Mega Alakazam.$"

MegaAlakazamTalkingtoPlayer1_Text_1:
# 98 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Pokémon Compendium!\nI will be able to aid you.\nFor a price...$"

MegaAlakazamTalkingtoPlayer1_Text_2:
# 99 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You can call me Wisdom.$"

MegaAlakazamTalkingtoPlayer1_Text_3:
# 101 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I'm a member of the famous Team\n"
	.string "Blaziken.$"

MegaAlakazamTalkingtoPlayer1_Text_4:
# 103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "How are you still talking to me?$"

MegaAlakazamTalkingtoPlayer1_Text_5:
# 105 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER}, I can talk to humans.$"

MegaAlakazamTalkingtoPlayer1_Text_6:
# 106 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Here at the Pokémon Compendium you can\n"
	.string "unlock features that will help you in\l"
	.string "your journey.$"

MegaAlakazamTalkingtoPlayer1_Text_7:
# 107 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Take this item.$"

PokemonCompendium_Text_0:
# 126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Pokémon Compendium.\n"
	.string "What services would you like to use?$"

PokemonCompendium_Text_1:
# 136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Move Tutor$"

PokemonCompendium_Text_2:
# 137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Item Shop$"

PokemonCompendium_Text_3:
# 138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Wonder Trade$"

PokemonCompendium_Text_4:
# 139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Perform Ritual$"

PokemonCompendium_Text_5:
# 140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Change Tera Type$"

PokemonCompendium_Text_6:
# 141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Leave$"

MoveTutorMenu_Text_0:
# 164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Since this is your first time using my\n"
	.string "move tutor system let me explain.\p"
	.string "I can teach your Pokémon moves.\n"
	.string "You can unlock moves by obtaining gym\l"
	.string "badges.\p"
	.string "The more gym badges you obtain\n"
	.string "increases the list of moves you can\l"
	.string "access.$"

OtherServices_Text_0:
# 178 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to use another service?$"

MoveTutorQuestion_Text_0:
# 189 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Do you want to teach a Pokémon\nthe move {STR_VAR_1}?$"

WisdomExitScript_Text_0:
# 203 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "If you wish to use my services again\n"
	.string "return to any Poke Center.$"

ItemShopMenuList_Text_0:
# 301 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "No Badges$"

ItemShopMenuList_Text_1:
# 302 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stone Badge$"

ItemShopMenuList_Text_2:
# 303 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Knuckle Badge$"

ItemShopMenuList_Text_3:
# 304 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dynamo Badge$"

ItemShopMenuList_Text_4:
# 305 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Heat Badge$"

ItemShopMenuList_Text_5:
# 306 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Balance Badge$"

ItemShopMenuList_Text_6:
# 307 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Feather Badge$"

ItemShopMenuList_Text_7:
# 308 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mind Badge$"

ItemShopMenuList_Text_8:
# 309 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rain Badge$"

ItemShopMenuList_Text_9:
# 310 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Evolution Stones$"

ItemShopMenuList_Text_10:
# 311 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Go Back$"

NoBadgeItemShop_Text_0:
# 345 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the no badge shop.$"

StoneBadgeItemShopMenu_Text_0:
# 366 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Stone Badge.$"

StoneBadgeItemShop_Text_0:
# 375 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Stone badge shop.$"

KnuckleBadgeItemShopMenu_Text_0:
# 400 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Knuckle Badge.$"

KnuckleBadgeItemShop_Text_0:
# 409 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Knuckle badge shop.$"

DynamoBadgeItemShopMenu_Text_0:
# 433 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Dynamo Badge.$"

DynamoBadgeItemShop_Text_0:
# 442 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Dynamo badge shop.$"

HeatBadgeItemShopMenu_Text_0:
# 469 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Heat Badge.$"

HeatBadgeItemShop_Text_0:
# 478 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Heat badge shop.$"

BalanceBadgeItemShopMenu_Text_0:
# 508 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Balance Badge.$"

BalanceBadgeItemShop_Text_0:
# 517 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Balance badge shop.$"

FeatherBadgeItemShopMenu_Text_0:
# 549 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Feather Badge.$"

FeatherBadgeItemShop_Text_0:
# 558 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Feather badge shop.$"

MindBadgeItemShopMenu_Text_0:
# 591 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Mind Badge.$"

MindBadgeItemShop_Text_0:
# 600 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Mind badge shop.$"

RainBadgeItemShopMenu_Text_0:
# 632 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Unfortunately, it seems you don't have\n"
	.string "the Rain Badge.$"

RainBadgeItemShop_Text_0:
# 641 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Welcome to the Rain badge shop.$"

EvolutionStoneShopMenu_Text_0:
# 664 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fire Stone$"

EvolutionStoneShopMenu_Text_1:
# 665 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Water Stone$"

EvolutionStoneShopMenu_Text_2:
# 666 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thunder Stone$"

EvolutionStoneShopMenu_Text_3:
# 667 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Leaf Stone$"

EvolutionStoneShopMenu_Text_4:
# 668 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ice Stone$"

EvolutionStoneShopMenu_Text_5:
# 669 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Moon Stone$"

EvolutionStoneShopMenu_Text_6:
# 670 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sun Stone$"

EvolutionStoneShopMenu_Text_7:
# 671 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shiny Stone$"

EvolutionStoneShopMenu_Text_8:
# 672 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dusk Stone$"

EvolutionStoneShopMenu_Text_9:
# 673 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dawn Stone$"

EvolutionStoneShopMenu_Text_10:
# 700 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Fire Stone? It\n"
	.string "will cost a Red Shard.$"

EvolutionStoneShopMenu_Text_11:
# 704 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have a Red Shard.$"

EvolutionStoneShopMenu_Text_12:
# 707 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Fire Stone.$"

EvolutionStoneShopMenu_Text_13:
# 718 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Water Stone? It\n"
	.string "will cost a Blue Shard.$"

EvolutionStoneShopMenu_Text_14:
# 722 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have a Blue Shard.$"

EvolutionStoneShopMenu_Text_15:
# 725 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Water Stone.$"

EvolutionStoneShopMenu_Text_16:
# 736 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Thunder Stone?\n"
	.string "It will cost a Yellow Shard.$"

EvolutionStoneShopMenu_Text_17:
# 740 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have a Yellow Shard.$"

EvolutionStoneShopMenu_Text_18:
# 743 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Thunder Stone.$"

EvolutionStoneShopMenu_Text_19:
# 754 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Leaf Stone?\n"
	.string "It will cost a Green Shard.$"

EvolutionStoneShopMenu_Text_20:
# 758 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have a Green Shard.$"

EvolutionStoneShopMenu_Text_21:
# 761 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Leaf Stone.$"

EvolutionStoneShopMenu_Text_22:
# 772 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want an Ice Stone?\n"
	.string "It will cost a Blue Shard.$"

EvolutionStoneShopMenu_Text_23:
# 779 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Ice Stone.$"

EvolutionStoneShopMenu_Text_24:
# 790 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Moon Stone?\n"
	.string "It will cost a Blue Shard.$"

EvolutionStoneShopMenu_Text_25:
# 797 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Moon Stone.$"

EvolutionStoneShopMenu_Text_26:
# 808 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Sun Stone?\n"
	.string "It will cost a Red Shard.$"

EvolutionStoneShopMenu_Text_27:
# 815 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Sun Stone.$"

EvolutionStoneShopMenu_Text_28:
# 826 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Shiny Stone?\n"
	.string "It will cost a Yellow Shard.$"

EvolutionStoneShopMenu_Text_29:
# 833 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Shiny Stone.$"

EvolutionStoneShopMenu_Text_30:
# 844 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Dusk Stone?\n"
	.string "It will cost a Green Shard.$"

EvolutionStoneShopMenu_Text_31:
# 851 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Dusk Stone.$"

EvolutionStoneShopMenu_Text_32:
# 862 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want a Dawn Stone?\n"
	.string "It will cost a Yellow Shard.$"

EvolutionStoneShopMenu_Text_33:
# 869 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Take this Dawn Stone.$"

StoneVerifyMenu_Text_0:
# 883 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to get another evolution\n"
	.string "stone?$"

NoBadgesMoveTutor_Text_0:
# 944 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Swords Dance$"

NoBadgesMoveTutor_Text_1:
# 945 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Nasty Plot$"

NoBadgesMoveTutor_Text_2:
# 946 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock Polish$"

NoBadgesMoveTutor_Text_3:
# 947 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dragon Dance$"

NoBadgesMoveTutor_Text_4:
# 948 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Acupressure$"

NoBadgesMoveTutor_Text_5:
# 949 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Coaching$"

NoBadgesMoveTutor_Text_6:
# 950 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Gear Up$"

NoBadgesMoveTutor_Text_7:
# 951 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Decorate$"

NoBadgesMoveTutor_Text_8:
# 952 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rototiller$"

NoBadgesMoveTutor_Text_9:
# 953 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Spicy Extract$"

NoBadgesMoveTutor_Text_10:
# 954 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Swagger$"

NoBadgesMoveTutor_Text_11:
# 955 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flower Shield$"

NoBadgesMoveTutor_Text_12:
# 956 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Magnetic Flux$"

NoBadgesMoveTutor_Text_13:
# 957 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flatter$"

NoBadgesMoveTutor_Text_14:
# 958 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Aromatic Mist$"

NoBadgesMoveTutor_Text_15:
# 959 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Coil$"

NoBadgesMoveTutor_Text_16:
# 960 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Meditate$"

NoBadgesMoveTutor_Text_17:
# 961 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Belly Drum$"

NoBadgesMoveTutor_Text_18:
# 962 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "No Retreat$"

NoBadgesMoveTutor_Text_19:
# 963 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Clangorous Soul$"

NoBadgesMoveTutor_Text_20:
# 964 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fillet Away$"

NoBadgesMoveTutor_Text_21:
# 965 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Growth$"

NoBadgesMoveTutor_Text_22:
# 966 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hone Claws$"

NoBadgesMoveTutor_Text_23:
# 967 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Howl$"

NoBadgesMoveTutor_Text_24:
# 968 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sharpen$"

NoBadgesMoveTutor_Text_25:
# 969 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shell Smash$"

NoBadgesMoveTutor_Text_26:
# 970 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shift Gear$"

NoBadgesMoveTutor_Text_27:
# 971 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tidy Up$"

NoBadgesMoveTutor_Text_28:
# 972 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Victory Dance$"

NoBadgesMoveTutor_Text_29:
# 973 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Acid Armor$"

NoBadgesMoveTutor_Text_30:
# 974 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Barrier$"

NoBadgesMoveTutor_Text_31:
# 975 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bulk Up$"

NoBadgesMoveTutor_Text_32:
# 976 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Cosmic Power$"

NoBadgesMoveTutor_Text_33:
# 977 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Cotton Guard$"

NoBadgesMoveTutor_Text_34:
# 978 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Defend Order$"

NoBadgesMoveTutor_Text_35:
# 979 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Defense Curl$"

NoBadgesMoveTutor_Text_36:
# 980 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Harden$"

NoBadgesMoveTutor_Text_37:
# 981 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Iron Defense$"

NoBadgesMoveTutor_Text_38:
# 982 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shelter$"

NoBadgesMoveTutor_Text_39:
# 983 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stockpile$"

NoBadgesMoveTutor_Text_40:
# 984 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Withdraw$"

NoBadgesMoveTutor_Text_41:
# 985 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stuff Cheeks$"

NoBadgesMoveTutor_Text_42:
# 986 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Amnesia$"

NoBadgesMoveTutor_Text_43:
# 987 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Calm Mind$"

NoBadgesMoveTutor_Text_44:
# 988 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Geomancy$"

NoBadgesMoveTutor_Text_45:
# 989 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Quiver Dance$"

NoBadgesMoveTutor_Text_46:
# 990 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tail Glow$"

NoBadgesMoveTutor_Text_47:
# 991 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Take Heart$"

NoBadgesMoveTutor_Text_48:
# 992 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Work Up$"

NoBadgesMoveTutor_Text_49:
# 993 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Charge$"

NoBadgesMoveTutor_Text_50:
# 994 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Double Team$"

NoBadgesMoveTutor_Text_51:
# 995 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Minimize$"

NoBadgesMoveTutor_Text_52:
# 996 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Agility$"

NoBadgesMoveTutor_Text_53:
# 997 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Autotomize$"

NoBadgesMoveTutor_Text_54:
# 998 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flash$"

NoBadgesMoveTutor_Text_55:
# 999 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Kinesis$"

NoBadgesMoveTutor_Text_56:
# 1000 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sand Attack$"

NoBadgesMoveTutor_Text_57:
# 1001 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Smokescreen$"

NoBadgesMoveTutor_Text_58:
# 1002 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Growl$"

NoBadgesMoveTutor_Text_59:
# 1003 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Charm$"

NoBadgesMoveTutor_Text_60:
# 1004 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Baby-Doll Eyes$"

NoBadgesMoveTutor_Text_61:
# 1005 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Feather Dance$"

NoBadgesMoveTutor_Text_62:
# 1006 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Memento$"

NoBadgesMoveTutor_Text_63:
# 1007 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Noble Roar$"

NoBadgesMoveTutor_Text_64:
# 1008 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Strength Sap$"

NoBadgesMoveTutor_Text_65:
# 1009 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tearful Look$"

NoBadgesMoveTutor_Text_66:
# 1010 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tickle$"

NoBadgesMoveTutor_Text_67:
# 1011 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Venom Drench$"

NoBadgesMoveTutor_Text_68:
# 1012 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Leer$"

NoBadgesMoveTutor_Text_69:
# 1013 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Octolock$"

NoBadgesMoveTutor_Text_70:
# 1014 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Screech$"

NoBadgesMoveTutor_Text_71:
# 1015 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tail Whip$"

NoBadgesMoveTutor_Text_72:
# 1016 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sweet Scent$"

NoBadgesMoveTutor_Text_73:
# 1017 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Captivate$"

NoBadgesMoveTutor_Text_74:
# 1018 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Confide$"

NoBadgesMoveTutor_Text_75:
# 1019 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Eerie Impulse$"

NoBadgesMoveTutor_Text_76:
# 1020 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Parting Shot$"

NoBadgesMoveTutor_Text_77:
# 1021 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fake Tears$"

NoBadgesMoveTutor_Text_78:
# 1022 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Metal Sound$"

NoBadgesMoveTutor_Text_79:
# 1023 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Cotton Spore$"

NoBadgesMoveTutor_Text_80:
# 1024 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Scary Face$"

NoBadgesMoveTutor_Text_81:
# 1025 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sticky Web$"

NoBadgesMoveTutor_Text_82:
# 1026 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stealth Rock$"

NoBadgesMoveTutor_Text_83:
# 1027 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Spikes$"

NoBadgesMoveTutor_Text_84:
# 1028 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Toxic Spikes$"

NoBadgesMoveTutor_Text_85:
# 1029 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Substitute$"

NoBadgesMoveTutor_Text_86:
# 1030 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Endure$"

NoBadgesMoveTutor_Text_87:
# 1031 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Follow Me$"

NoBadgesMoveTutor_Text_88:
# 1032 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Safeguard$"

NoBadgesMoveTutor_Text_89:
# 1033 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Defog$"

NoBadgesMoveTutor_Text_90:
# 1034 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "King's Shield$"

NoBadgesMoveTutor_Text_91:
# 1035 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Protect$"

NoBadgesMoveTutor_Text_92:
# 1036 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Detect$"

NoBadgesMoveTutor_Text_93:
# 1037 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Baneful Bunker$"

NoBadgesMoveTutor_Text_94:
# 1038 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Burning Bulwark$"

NoBadgesMoveTutor_Text_95:
# 1039 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Obstruct$"

NoBadgesMoveTutor_Text_96:
# 1040 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Crafty Shield$"

NoBadgesMoveTutor_Text_97:
# 1041 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mat Block$"

NoBadgesMoveTutor_Text_98:
# 1042 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Silk Trap$"

NoBadgesMoveTutor_Text_99:
# 1043 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Quick Guard$"

NoBadgesMoveTutor_Text_100:
# 1044 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Wide Guard$"

NoBadgesMoveTutor_Text_101:
# 1045 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Spiky Shield$"

NoBadgesMoveTutor_Text_102:
# 1046 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thunder Wave$"

NoBadgesMoveTutor_Text_103:
# 1047 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Glare$"

NoBadgesMoveTutor_Text_104:
# 1048 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stun Spore$"

NoBadgesMoveTutor_Text_105:
# 1049 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Will-O-Wisp$"

NoBadgesMoveTutor_Text_106:
# 1050 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Poison Gas$"

NoBadgesMoveTutor_Text_107:
# 1051 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Toxic$"

NoBadgesMoveTutor_Text_108:
# 1052 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Toxic Thread$"

NoBadgesMoveTutor_Text_109:
# 1053 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hypnosis$"

NoBadgesMoveTutor_Text_110:
# 1054 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Grass Whistle$"

NoBadgesMoveTutor_Text_111:
# 1055 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Lovely Kiss$"

NoBadgesMoveTutor_Text_112:
# 1056 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sing$"

NoBadgesMoveTutor_Text_113:
# 1057 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sleep Powder$"

NoBadgesMoveTutor_Text_114:
# 1058 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Spore$"

NoBadgesMoveTutor_Text_115:
# 1059 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Teeter Dance$"

NoBadgesMoveTutor_Text_116:
# 1060 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Confuse Ray$"

NoBadgesMoveTutor_Text_117:
# 1061 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Supersonic$"

NoBadgesMoveTutor_Text_118:
# 1062 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Attract$"

NoBadgesMoveTutor_Text_119:
# 1063 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Metronome$"

NoBadgesMoveTutor_Text_120:
# 1064 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Trick Room$"

NoBadgesMoveTutor_Text_121:
# 1065 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tailwind$"

NoBadgesMoveTutor_Text_122:
# 1066 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Recycle$"

NoBadgesMoveTutor_Text_123:
# 1067 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Heal Bell$"

NoBadgesMoveTutor_Text_124:
# 1068 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Light Screen$"

NoBadgesMoveTutor_Text_125:
# 1069 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Reflect$"

StoneBadgeMoveTutor_Text_0:
# 1222 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mach Punch$"

StoneBadgeMoveTutor_Text_1:
# 1223 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bullet Punch$"

StoneBadgeMoveTutor_Text_2:
# 1224 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ice Shard$"

StoneBadgeMoveTutor_Text_3:
# 1225 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shadow Sneak$"

StoneBadgeMoveTutor_Text_4:
# 1226 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock Smash$"

StoneBadgeMoveTutor_Text_5:
# 1227 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Cut$"

StoneBadgeMoveTutor_Text_6:
# 1228 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "False Swipe$"

StoneBadgeMoveTutor_Text_7:
# 1229 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tackle$"

StoneBadgeMoveTutor_Text_8:
# 1230 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Pound$"

StoneBadgeMoveTutor_Text_9:
# 1231 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Scratch$"

StoneBadgeMoveTutor_Text_10:
# 1232 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Double Slap$"

StoneBadgeMoveTutor_Text_11:
# 1233 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Comet Punch$"

StoneBadgeMoveTutor_Text_12:
# 1234 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fury Cutter$"

StoneBadgeMoveTutor_Text_13:
# 1235 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rollout$"

StoneBadgeMoveTutor_Text_14:
# 1236 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Echoed Voice$"

StoneBadgeMoveTutor_Text_15:
# 1237 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ember$"

StoneBadgeMoveTutor_Text_16:
# 1238 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Water Gun$"

StoneBadgeMoveTutor_Text_17:
# 1239 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thundershock$"

StoneBadgeMoveTutor_Text_18:
# 1240 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Gust$"

StoneBadgeMoveTutor_Text_19:
# 1241 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Confusion$"

StoneBadgeMoveTutor_Text_20:
# 1242 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mega Drain$"

StoneBadgeMoveTutor_Text_21:
# 1243 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Smog$"

KnuckleBadgeMoveTutor_Text_0:
# 1287 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fake Out$"

KnuckleBadgeMoveTutor_Text_1:
# 1289 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flame Charge$"

KnuckleBadgeMoveTutor_Text_2:
# 1290 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Incinerate$"

KnuckleBadgeMoveTutor_Text_3:
# 1291 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Aqua Jet$"

KnuckleBadgeMoveTutor_Text_4:
# 1292 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Chilling Water$"

KnuckleBadgeMoveTutor_Text_5:
# 1293 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Spark$"

KnuckleBadgeMoveTutor_Text_6:
# 1294 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Charge Beam$"

KnuckleBadgeMoveTutor_Text_7:
# 1295 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Razor Leaf$"

KnuckleBadgeMoveTutor_Text_8:
# 1296 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Magical Leaf$"

KnuckleBadgeMoveTutor_Text_9:
# 1297 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Avalanche$"

KnuckleBadgeMoveTutor_Text_10:
# 1298 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Icy Wind$"

KnuckleBadgeMoveTutor_Text_11:
# 1299 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Karate Chop$"

KnuckleBadgeMoveTutor_Text_12:
# 1300 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Vacuum Wave$"

KnuckleBadgeMoveTutor_Text_13:
# 1301 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Poison Fang$"

KnuckleBadgeMoveTutor_Text_14:
# 1303 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sand Tomb$"

KnuckleBadgeMoveTutor_Text_15:
# 1304 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mud-Slap$"

KnuckleBadgeMoveTutor_Text_16:
# 1305 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dual Wingbeat$"

KnuckleBadgeMoveTutor_Text_17:
# 1306 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Air Cutter$"

KnuckleBadgeMoveTutor_Text_18:
# 1307 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Psycho Cut$"

KnuckleBadgeMoveTutor_Text_19:
# 1309 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Pounce$"

KnuckleBadgeMoveTutor_Text_20:
# 1310 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Struggle Bug$"

KnuckleBadgeMoveTutor_Text_21:
# 1311 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Smack Down$"

KnuckleBadgeMoveTutor_Text_22:
# 1312 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ancient Power$"

KnuckleBadgeMoveTutor_Text_23:
# 1313 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Lick$"

KnuckleBadgeMoveTutor_Text_24:
# 1314 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Night Shade$"

KnuckleBadgeMoveTutor_Text_25:
# 1315 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dual Chop$"

KnuckleBadgeMoveTutor_Text_26:
# 1316 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Twister$"

KnuckleBadgeMoveTutor_Text_27:
# 1317 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Payback$"

KnuckleBadgeMoveTutor_Text_28:
# 1318 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Snarl$"

KnuckleBadgeMoveTutor_Text_29:
# 1320 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mirror Shot$"

KnuckleBadgeMoveTutor_Text_30:
# 1321 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Disarming Voice$"

KnuckleBadgeMoveTutor_Text_31:
# 1322 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fairy Wind$"

DynamoBadgeMoveTutor_Text_0:
# 1385 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flame Wheel$"

DynamoBadgeMoveTutor_Text_1:
# 1386 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Water Pulse$"

DynamoBadgeMoveTutor_Text_2:
# 1387 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bite$"

DynamoBadgeMoveTutor_Text_3:
# 1389 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Force Palm$"

DynamoBadgeMoveTutor_Text_4:
# 1390 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Aerial Ace$"

DynamoBadgeMoveTutor_Text_5:
# 1391 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shadow Claw$"

DynamoBadgeMoveTutor_Text_6:
# 1392 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bulldoze$"

DynamoBadgeMoveTutor_Text_7:
# 1393 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock Tomb$"

DynamoBadgeMoveTutor_Text_8:
# 1394 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bug Bite$"

DynamoBadgeMoveTutor_Text_9:
# 1395 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Pluck$"

DynamoBadgeMoveTutor_Text_10:
# 1396 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Smart Strike$"

DynamoBadgeMoveTutor_Text_11:
# 1397 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Metal Claw$"

DynamoBadgeMoveTutor_Text_12:
# 1398 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stomp$"

DynamoBadgeMoveTutor_Text_13:
# 1399 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Covet$"

DynamoBadgeMoveTutor_Text_14:
# 1400 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shock Wave$"

DynamoBadgeMoveTutor_Text_15:
# 1401 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Swift$"

DynamoBadgeMoveTutor_Text_16:
# 1403 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mud-Shot$"

DynamoBadgeMoveTutor_Text_17:
# 1405 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Acid Spray$"

DynamoBadgeMoveTutor_Text_18:
# 1407 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Psybeam$"

DynamoBadgeMoveTutor_Text_19:
# 1409 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ominous Wind$"

DynamoBadgeMoveTutor_Text_20:
# 1411 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Silver Wind$"

DynamoBadgeMoveTutor_Text_21:
# 1412 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Clear Smog$"

DynamoBadgeMoveTutor_Text_22:
# 1413 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hex$"

DynamoBadgeMoveTutor_Text_23:
# 1414 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bullet Seed$"

DynamoBadgeMoveTutor_Text_24:
# 1415 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Icicle Spear$"

DynamoBadgeMoveTutor_Text_25:
# 1416 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock Blast$"

DynamoBadgeMoveTutor_Text_26:
# 1417 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Arm Thrust$"

DynamoBadgeMoveTutor_Text_27:
# 1418 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fury Swipes$"

HeatBadgeMoveTutor_Text_0:
# 1475 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fire Punch$"

HeatBadgeMoveTutor_Text_1:
# 1476 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ice Punch$"

HeatBadgeMoveTutor_Text_2:
# 1477 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thunder Punch$"

HeatBadgeMoveTutor_Text_3:
# 1483 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Heart Stamp$"

HeatBadgeMoveTutor_Text_4:
# 1487 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flame Burst$"

HeatBadgeMoveTutor_Text_5:
# 1488 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bubble Beam$"

HeatBadgeMoveTutor_Text_6:
# 1489 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Aurora Beam$"

HeatBadgeMoveTutor_Text_7:
# 1497 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Knock Off$"

HeatBadgeMoveTutor_Text_8:
# 1498 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thief$"

HeatBadgeMoveTutor_Text_9:
# 1499 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rapid Spin$"

HeatBadgeMoveTutor_Text_10:
# 1500 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Nuzzle$"

BalanceBadgeMoveTutor_Text_0:
# 1544 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "U-turn$"

BalanceBadgeMoveTutor_Text_1:
# 1545 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Volt Switch$"

BalanceBadgeMoveTutor_Text_2:
# 1546 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Night Slash$"

BalanceBadgeMoveTutor_Text_3:
# 1548 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Slash$"

BalanceBadgeMoveTutor_Text_4:
# 1552 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Drain Punch$"

BalanceBadgeMoveTutor_Text_5:
# 1553 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Brick Break$"

BalanceBadgeMoveTutor_Text_6:
# 1554 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock Slide$"

BalanceBadgeMoveTutor_Text_7:
# 1555 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Crunch$"

BalanceBadgeMoveTutor_Text_8:
# 1556 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Poison Jab$"

BalanceBadgeMoveTutor_Text_9:
# 1557 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Seed Bomb$"

BalanceBadgeMoveTutor_Text_10:
# 1558 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Zen Headbutt$"

BalanceBadgeMoveTutor_Text_11:
# 1559 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Iron Head$"

BalanceBadgeMoveTutor_Text_12:
# 1560 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Lash Out$"

BalanceBadgeMoveTutor_Text_13:
# 1561 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Stomping Tantrum$"

BalanceBadgeMoveTutor_Text_14:
# 1562 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Extreme Speed$"

FeatherBadgeMoveTutor_Text_0:
# 1603 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Air Slash$"

FeatherBadgeMoveTutor_Text_1:
# 1604 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hyper Voice$"

FeatherBadgeMoveTutor_Text_2:
# 1605 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bug Buzz$"

FeatherBadgeMoveTutor_Text_3:
# 1606 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Aura Sphere$"

FeatherBadgeMoveTutor_Text_4:
# 1608 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fly$"

FeatherBadgeMoveTutor_Text_5:
# 1609 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bounce$"

FeatherBadgeMoveTutor_Text_6:
# 1612 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Scorching Sands$"

FeatherBadgeMoveTutor_Text_7:
# 1613 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Terrain Pulse$"

FeatherBadgeMoveTutor_Text_8:
# 1614 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Weather Ball$"

FeatherBadgeMoveTutor_Text_9:
# 1616 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Electroweb$"

FeatherBadgeMoveTutor_Text_10:
# 1618 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mystical Fire$"

MindBadgeMoveTutor_Text_0:
# 1655 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Psychic$"

MindBadgeMoveTutor_Text_1:
# 1656 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Shadow Ball$"

MindBadgeMoveTutor_Text_2:
# 1657 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dark Pulse$"

MindBadgeMoveTutor_Text_3:
# 1658 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Energy Ball$"

MindBadgeMoveTutor_Text_4:
# 1659 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Earth Power$"

MindBadgeMoveTutor_Text_5:
# 1660 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flash Cannon$"

MindBadgeMoveTutor_Text_6:
# 1661 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sludge Bomb$"

MindBadgeMoveTutor_Text_7:
# 1662 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dragon Pulse$"

MindBadgeMoveTutor_Text_8:
# 1663 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dazzling Gleam$"

MindBadgeMoveTutor_Text_9:
# 1666 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Psychic Fangs$"

MindBadgeMoveTutor_Text_10:
# 1667 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Play Rough$"

MindBadgeMoveTutor_Text_11:
# 1668 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Liquidation$"

MindBadgeMoveTutor_Text_12:
# 1669 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "High Horsepower$"

MindBadgeMoveTutor_Text_13:
# 1670 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Throat Chop$"

RainBadgeMoveTutor_Text_0:
# 1706 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flamethrower$"

RainBadgeMoveTutor_Text_1:
# 1707 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ice Beam$"

RainBadgeMoveTutor_Text_2:
# 1708 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thunderbolt$"

RainBadgeMoveTutor_Text_3:
# 1709 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Surf$"

RainBadgeMoveTutor_Text_4:
# 1710 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Moonblast$"

RainBadgeMoveTutor_Text_5:
# 1714 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Close Combat$"

RainBadgeMoveTutor_Text_6:
# 1715 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Superpower$"

RainBadgeMoveTutor_Text_7:
# 1716 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Earthquake$"

RainBadgeMoveTutor_Text_8:
# 1717 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flare Blitz$"

RainBadgeMoveTutor_Text_9:
# 1718 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Wave Crash$"

RainBadgeMoveTutor_Text_10:
# 1719 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Wood Hammer$"

RainBadgeMoveTutor_Text_11:
# 1720 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Brave Bird$"

RainBadgeMoveTutor_Text_12:
# 1721 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Double-Edge$"

RainBadgeMoveTutor_Text_13:
# 1722 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Outrage$"

RainBadgeMoveTutor_Text_14:
# 1723 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Megahorn$"

RainBadgeMoveTutor_Text_15:
# 1724 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Gunk Shot$"

RainBadgeMoveTutor_Text_16:
# 1725 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hurricane$"

RainBadgeMoveTutor_Text_17:
# 1728 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hydro Pump$"

Wonder_Trade_Text_0:
# 1788 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Searching for a Wonder Trade partner...\n"
	.string "Press the {A_BUTTON} to continue.$"

Wonder_Trade_Text_1:
# 1796 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Success! A trade partner was found.\n"
	.string "Trading with {STR_VAR_1}! Press {A_BUTTON} to\l"
	.string "trade.$"

WonderTradeAgain_Text_0:
# 1812 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Want to Wonder Trade again?$"

TeraTypeChangerMenu_Text_0:
# 1826 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Which Pokémon's Tera Type would you\n"
	.string "like to change?$"

TeraTypeChangerMenu_Text_1:
# 1835 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I cannot change the Tera Type of an\n"
	.string "Egg!$"

TeraTypeChangerMenu_Text_2:
# 1840 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Normal$"

TeraTypeChangerMenu_Text_3:
# 1841 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fighting$"

TeraTypeChangerMenu_Text_4:
# 1842 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Flying$"

TeraTypeChangerMenu_Text_5:
# 1843 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Poison$"

TeraTypeChangerMenu_Text_6:
# 1844 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ground$"

TeraTypeChangerMenu_Text_7:
# 1845 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rock$"

TeraTypeChangerMenu_Text_8:
# 1846 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bug$"

TeraTypeChangerMenu_Text_9:
# 1847 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ghost$"

TeraTypeChangerMenu_Text_10:
# 1848 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Steel$"

TeraTypeChangerMenu_Text_11:
# 1849 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fire$"

TeraTypeChangerMenu_Text_12:
# 1850 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Water$"

TeraTypeChangerMenu_Text_13:
# 1851 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Grass$"

TeraTypeChangerMenu_Text_14:
# 1852 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Electric$"

TeraTypeChangerMenu_Text_15:
# 1854 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ice$"

TeraTypeChangerMenu_Text_16:
# 1855 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dragon$"

TeraTypeChangerMenu_Text_17:
# 1856 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Dark$"

TeraTypeChangerMenu_Text_18:
# 1857 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fairy$"

TeraTypeChangerMenu_Text_19:
# 1894 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want to change to this\n"
	.string "Tera Type?\n"
	.string "It will cost 100 {STR_VAR_1}s.$"

TeraTypeChangerMenu_Text_20:
# 1899 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You don't have 100 {STR_VAR_1}s.$"

TeraTypeChangerMenu_Text_21:
# 1903 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you! Your Pokémon's Tera Type\n"
	.string "was changed.$"

TeraVerifyMenu_Text_0:
# 1937 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to change another\n"
	.string "Pokémon's Tera Type?$"

Cacoon_Ritual_Text_0:
# 1949 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Select the Pokémon to be cleansed.$"

Cacoon_Ritual_Text_1:
# 1959 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Select a Cascoon or Silcoon to\n"
	.string "sacrifice.$"

Cacoon_Ritual_Text_2:
# 1975 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The ritual is complete. The cocoon\n"
	.string "has been consumed.$"

RitualAgain_Text_0:
# 1982 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to perform another\n"
	.string "ritual?$"

Ritual_Failed_Text_0:
# 1993 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "The ritual failed. You must sacrifice\n"
	.string "a Cascoon or Silcoon.$"

MysteryManGreeting_Text_0:
# 2033 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mystery Man$"

MysteryManGreeting_Text_1:
# 2034 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Hello, would you like to use the Mystery\n"
	.string "Gift?$"

MysteryManGreeting_Text_2:
# 2036 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Enter a code.$"

MysteryManGreeting_Text_3:
# 2047 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Please come back when you discover a\n"
	.string "code.$"

IncorrectCode_Text_0:
# 2056 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sorry, that code is incorrect.$"

Demo2Code_Text_0:
# 2070 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I am sorry but you have already\n"
	.string "redeemed this code.$"

Demo2Code_Text_1:
# 2076 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you for entering in the Demo 2\n"
	.string "code. Here's your item pack.$"

Demo2Code_Text_2:
# 2083 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Oh no! You don't have enough room in\n"
	.string "your Bag for all of these items.$"

ShinyStarterWithZigzagoon_Text_0:
# 2100 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Thank you for entering in the Shiny\n"
	.string "Starter code.$"

ShinyStarterWithZigzagoon_Text_1:
# 2103 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Here is your Shiny Zigzagoon.$"

ShinyStarterMenu_Text_0:
# 2114 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Choose your shiny starter.$"

ShinyStarters_Text_0:
# 2121 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Bulbasaur$"

ShinyStarters_Text_1:
# 2122 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Charmander$"

ShinyStarters_Text_2:
# 2123 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Squirtle$"

ShinyStarters_Text_3:
# 2124 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Chikorita$"

ShinyStarters_Text_4:
# 2125 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Cyndaquil$"

ShinyStarters_Text_5:
# 2126 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Totodile$"

ShinyStarters_Text_6:
# 2127 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Treecko$"

ShinyStarters_Text_7:
# 2128 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Torchic$"

ShinyStarters_Text_8:
# 2129 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Mudkip$"

ShinyStarters_Text_9:
# 2130 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Turtwig$"

ShinyStarters_Text_10:
# 2131 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Chimchar$"

ShinyStarters_Text_11:
# 2132 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Piplup$"

ShinyStarters_Text_12:
# 2133 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Snivy$"

ShinyStarters_Text_13:
# 2134 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Tepig$"

ShinyStarters_Text_14:
# 2135 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Oshawott$"

ShinyStarters_Text_15:
# 2136 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Chespin$"

ShinyStarters_Text_16:
# 2137 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fennekin$"

ShinyStarters_Text_17:
# 2138 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Froakie$"

ShinyStarters_Text_18:
# 2139 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Rowlet$"

ShinyStarters_Text_19:
# 2140 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Litten$"

ShinyStarters_Text_20:
# 2141 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Popplio$"

ShinyStarters_Text_21:
# 2142 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Grookey$"

ShinyStarters_Text_22:
# 2143 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Scorbunny$"

ShinyStarters_Text_23:
# 2144 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sobble$"

ShinyStarters_Text_24:
# 2145 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sprigatito$"

ShinyStarters_Text_25:
# 2146 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Fuecoco$"

ShinyStarters_Text_26:
# 2147 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Quaxly$"

ShinyStarters_Text_27:
# 2153 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Bulbasaur?$"

ShinyStarters_Text_28:
# 2164 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Bulbasaur!$"

ShinyStarters_Text_29:
# 2173 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Charmander?$"

ShinyStarters_Text_30:
# 2184 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Charmander!$"

ShinyStarters_Text_31:
# 2193 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Squirtle?$"

ShinyStarters_Text_32:
# 2204 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Squirtle!$"

ShinyStarters_Text_33:
# 2213 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Chikorita?$"

ShinyStarters_Text_34:
# 2223 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Chikorita!$"

ShinyStarters_Text_35:
# 2232 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Cyndaquil?$"

ShinyStarters_Text_36:
# 2242 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Cyndaquil!$"

ShinyStarters_Text_37:
# 2251 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Totodile?$"

ShinyStarters_Text_38:
# 2262 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Totodile!$"

ShinyStarters_Text_39:
# 2272 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Treecko?$"

ShinyStarters_Text_40:
# 2282 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Treecko!$"

ShinyStarters_Text_41:
# 2291 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Torchic?$"

ShinyStarters_Text_42:
# 2302 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Torchic!$"

ShinyStarters_Text_43:
# 2311 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Mudkip?$"

ShinyStarters_Text_44:
# 2322 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Mudkip!$"

ShinyStarters_Text_45:
# 2331 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Turtwig?$"

ShinyStarters_Text_46:
# 2341 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Turtwig!$"

ShinyStarters_Text_47:
# 2350 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Chimchar?$"

ShinyStarters_Text_48:
# 2362 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Chimchar!$"

ShinyStarters_Text_49:
# 2371 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Piplup?$"

ShinyStarters_Text_50:
# 2383 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Piplup!$"

ShinyStarters_Text_51:
# 2392 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Snivy?$"

ShinyStarters_Text_52:
# 2403 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Snivy!$"

ShinyStarters_Text_53:
# 2412 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Tepig?$"

ShinyStarters_Text_54:
# 2423 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Tepig!$"

ShinyStarters_Text_55:
# 2432 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Oshawott?$"

ShinyStarters_Text_56:
# 2444 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Oshawott!$"

ShinyStarters_Text_57:
# 2453 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Chespin?$"

ShinyStarters_Text_58:
# 2464 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Chespin!$"

ShinyStarters_Text_59:
# 2473 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Fennekin?$"

ShinyStarters_Text_60:
# 2484 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Fennekin!$"

ShinyStarters_Text_61:
# 2493 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Froakie?$"

ShinyStarters_Text_62:
# 2504 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Froakie!$"

ShinyStarters_Text_63:
# 2513 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Rowlet?$"

ShinyStarters_Text_64:
# 2524 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Rowlet!$"

ShinyStarters_Text_65:
# 2533 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Litten?$"

ShinyStarters_Text_66:
# 2544 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Litten!$"

ShinyStarters_Text_67:
# 2553 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Popplio?$"

ShinyStarters_Text_68:
# 2564 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Popplio!$"

ShinyStarters_Text_69:
# 2573 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Grookey?$"

ShinyStarters_Text_70:
# 2584 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Grookey!$"

ShinyStarters_Text_71:
# 2593 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Scorbunny?$"

ShinyStarters_Text_72:
# 2604 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Scorbunny!$"

ShinyStarters_Text_73:
# 2613 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Sobble?$"

ShinyStarters_Text_74:
# 2624 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Sobble!$"

ShinyStarters_Text_75:
# 2633 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Sprigatito?$"

ShinyStarters_Text_76:
# 2644 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Sprigatito!$"

ShinyStarters_Text_77:
# 2653 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Fuecoco?$"

ShinyStarters_Text_78:
# 2662 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Fuecoco!$"

ShinyStarters_Text_79:
# 2671 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want Quaxly?$"

ShinyStarters_Text_80:
# 2682 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received Quaxly!$"

NicknameBoxMon2_Text_0:
# 2691 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to give your starter a\nNickname?$"

NicknameBoxMon2_Text_1:
# 2699 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Transferred to PC$"

NicknamePartyMon2_Text_0:
# 2703 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to give your starter\na nickname?$"

FirstTimeItemShop::
# 1758 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Since this is your first time using my\n"
	.string "item shop system let me explain.\p"
	.string "I can sell you items just like the\n"
	.string "PokeMart. You can unlock more shops\p"
	.string "by obtaining gym badges. The more gym\n"
	.string "badges you obtain increases the list\p"
	.string "of shops you can access.$"

MichaelMysteryGift_Text_Intro::
# 2730 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Let's battle!$"

MichaelMysteryGift_Text_Defeat::
# 2734 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I lost...$"

MichaelMysteryGift_Text_PostBattle::
# 2738 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Good battle.$"
