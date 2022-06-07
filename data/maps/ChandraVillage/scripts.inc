.set LOCALID_TYLER, 10

ChandraVillage_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChandraVillage_OnFrame
	.byte 0

ChandraVillage_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 3, ChandraVillage_Intro
	.2byte 0

ChandraVillage_Intro::
	applymovement LOCALID_TYLER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox ChandraVillage_Text_TylerIntro_Player, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_TYLER, WalkL3
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox ChandraVillage_Text_TylerIntro_HeySnorlax, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TYLER, RunR3D5R3D
	waitmovement 0
	removeobject LOCALID_TYLER
	setflag FLAG_HIDE_CHANDRA_VILLAGE_TYLER_1
	setvar VAR_STORYLINE_STATE, 4
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

ChandraVillage_Tyler_Debug::
	lockall
	givemon SPECIES_TOTODILE, 77, ITEM_DRAGON_FANG
	givemon SPECIES_MACHOP, 77, ITEM_DRAGON_FANG
	givemon SPECIES_SABLEYE, 77, ITEM_DRAGON_FANG
	giveitem ITEM_MACH_BIKE, 1
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RECEIVED_RUNNING_SHOES
	addobject 16
	hideobjectat 16, MAP_CHANDRA_VILLAGE
	setfollower 16, 0x7E
	updatefollowerpokemongraphic
	showfollower
	releaseall
	end

ChandraVillage_Hoenn_Girl::
	msgbox ChandraVillage_Hoenn, MSGBOX_NPC
	end

ChandraVillage_Young_Girl::
	msgbox ChandraVillage_Flowers, MSGBOX_NPC
	end

ChandraVillage_Fat_Guy::
	msgbox ChandraVillage_Technology, MSGBOX_NPC
	end

ChandraVillage_Old_Man::
	lockall
	faceplayer
	msgbox ChandraVillage_Structure, MSGBOX_NPC
	applymovement 8, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement 8, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox ChandraVillage_Dusclops, MSGBOX_NPC
	applymovement 8, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

ChandraVillage_Truck_Boy::
	msgbox ChandraVillage_Slow, MSGBOX_NPC
	end

ChandraVillage_Idle_Truck::
	msgbox ChandraVillage_Truck, MSGBOX_NPC
	end

ChandraVillage_Jokers_Wife::
	msgbox ChandraVillage_Wife, MSGBOX_NPC
	end

ChandraVillage_Letterbox::
	msgbox ChandraVillage_Text_Mail, MSGBOX_SIGN
	end

ChandraVillage_Town_Sign::
	msgbox ChandraVillage_Text_Town_Sign, MSGBOX_SIGN
	end

ChandraVillage_Joker::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_BALL_CHANDRA, ChandraVillage_Joker_Received
	msgbox ChandraVillage_Joker_Question, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Joker_Yes
	msgbox ChandraVillage_Joker_No, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Joker_Yes::
	msgbox ChandraVillage_Joker_Joke, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_POKE_BALL_CHANDRA
	msgbox ChandraVillage_Joker_Gift, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Joker_Received::
	msgbox ChandraVillage_Joker_End, MSGBOX_DEFAULT
	release
	end

ChandraVillage_Facility_Sign::
	msgbox ChandraVillage_Text_Facility, MSGBOX_SIGN
	end

WalkL3:
	walk_left
	walk_left
	walk_left
	step_end

RunR3D5R3D:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end

ChandraVillage_Text_TylerIntro_Player:
	.string "{COLOR}{BLUE}{PLAYER}!$"

ChandraVillage_Text_TylerIntro_HeySnorlax:
	.string "{COLOR}{BLUE}Hey, Snorlax!\p"
	.string "I was beginning to think I would need\n"
	.string "a Poké Flute to wake you up!\p"
	.string "Anyway… Listen, {PLAYER}.\p"
	.string "There's an infestation of Pokémon in\n"
	.string "the Professor's Lab.\p"
	.string "We need to go and sort the problem!\p"
	.string "If we don't show the Professor what we\n"
	.string "are capable of, I fear he will never\l"
	.string "give us a Pokémon of our own…\p"
	.string "Let's go there and show him how real\n"
	.string "Pokémon Trainers fight!\p"
	.string "Haha!\n"
	.string "Meet me by the Professor's Lab!$"

ChandraVillage_Hoenn:
	.string "{COLOR}{RED}My family and I moved to Tenjo from\n"
	.string "the Hoenn region.\p"
	.string "The weather in Hoenn was too\n"
	.string "unpredictable at times…$"

ChandraVillage_Flowers:
	.string "{COLOR}{RED}Chandra Village is best known for its\n"
	.string "magical scent from the flowers.\p"
	.string "In the summertime, we often receive\n"
	.string "visits from Sunflora and Skiploom!$"

ChandraVillage_Technology:
	.string "{COLOR}{BLUE}Technology is incredible!\p"	
	.string "There are communities online who\n"
	.string "reverse-engineer old games and remake\l"
	.string "them as their own.\p"
	.string "I think it's called ROM hacking…$"

ChandraVillage_Slow:
	.string "{COLOR}{BLUE}Slow down there!\n"
	.string "This truck won't be moving for a while.\p"
	.string "The driver is dropping off a large\n"
	.string "box of Poké Balls to the Professor.$"

ChandraVillage_Structure:
	.string "This structure has stood for over\n"
	.string "200 years…$"

ChandraVillage_Dusclops:
	.string "Many people think its design was\n"
	.string "inspired by the Ghost-type Pokémon,\l"
	.string "known as Dusclops.\p"
	.string "Some people even say they have\n"
	.string "heard strange noises inside.$"

ChandraVillage_Truck:
	.string "A truck blocks the way…\n"
	.string "Maybe you should come back later.$"

ChandraVillage_Text_Mail:
	.string "There's mail in here!\n"
	.string "Better leave it alone…$"

ChandraVillage_Text_Town_Sign:
	.string "Chandra Village\n"
	.string "A place to call home.$"

ChandraVillage_Text_Facility:
	.string "Professor Hawthorne's Pokémon\n"
	.string "Research Facility$"

ChandraVillage_Wife:
	.string "{COLOR}{RED}I'm sorry for my husband's\n"
	.string "embarrassingly awful jokes!$"

ChandraVillage_Joker_Question:
	.string "{COLOR}{BLUE}Oh, hello there.\n"
	.string "I haven't seen you around here before…\p"
	.string "Wanna hear a joke?$"

ChandraVillage_Joker_No:
	.string "{COLOR}{BLUE}Suit yourself!$"

ChandraVillage_Joker_Joke:
	.string "{COLOR}{BLUE}What did one Geodude say to the\n"
	.string "other Geodude?\p"
	.string "…\n"
	.string "…\p"
	.string "Let's rock!\n"
	.string "HA.\p"
	.string "…\n"
	.string "…\p"
	.string "All right. I'm sorry.\n"
	.string "That was a bad one.\p"
	.string "Please take this as a token of my\n"
	.string "apology…$"

ChandraVillage_Joker_Gift:
	.string "{COLOR}{BLUE}Use this to catch a wild Pokémon!\n"
	.string "It doesn't always work, though.$"

ChandraVillage_Joker_End:
	.string "{COLOR}{BLUE}That's it!\n"
	.string "I'm all outta jokes!$"