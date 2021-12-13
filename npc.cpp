#include "functions.h"

// Controls all of the different types of NPCs in the game

void npcGenerator(int npc)
{

	string input;
	int chance = rand() % 100 + 1;
	string npcName;

	switch (npc)
	{

	case 1: // Slime NPC

		npcName = "Rimuru";

		if (chance < 50)
		{
			PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
			if (playerOccupation == "Knight" || playerOccupation == "Mage" || playerOccupation == "Assassin")
			{
				cout << "| NPC: " << npcName << endl;
				cout << "| Hey there Adventurer!" << endl;

				if (questTrue[0] != TRUE && questTrue[1] != TRUE && questTrue[2] != TRUE)
				{
					cout << "| Did you go pick up your quest yet?" << endl << endl;
				}
				else if (respawn != TRUE)
				{
					cout << "| You should go receive the blessing of the Masadora statue." << endl;
					cout << "| It should help you in your endeavors!" << endl << endl;
				}
				else if (questTrue[0] == TRUE)
				{
					cout << "| You have to go defeat the Slime King?" << endl;
					cout << "| I heard you have to defeat some smaller little slimes first before you can summon the Slime King." << endl;
					cout << "| Good luck trying to defeat him!" << endl << endl;
				}
				else if (questTrue[1] == TRUE)
				{
					cout << "| That slimey Kraken?!" << endl;
					cout << "| Good luck trying to battle the Kraken in rough waters." << endl;
					if (inventory[4].compare("Boat") != 0)
					{
						cout << "| I heard you need a boat to get onto rough waters though so make sure you got some Kol on you to buy one." << endl;
						if (kol <= 25)
						{
							cout << "| If you don't have enough Kol," << endl;
							cout << "| There are some wolves southeast of Masadora." << endl;
							cout << "| Look for the area with some visible claw marks and you'll probably run into one." << endl;
						}
					}
					cout << endl;
				}
				else if (questTrue[2] == TRUE)
				{
					cout << "| Ainz Ooal Gown?" << endl;
					cout << "| That's a pretty long name." << endl;
					cout << "| I think that you have to defeat at least 5 regular skeletons in order to summon him." << endl;
					cout << "| Good luck trying to defeat him and his skeleton army!" << endl << endl;
				}
				else if (questTrue[3] == TRUE)
				{
					cout << "| SLAYING A DRAGON!?!?" << endl;
					cout << "| That sounds like it's going to be rough but I'm pretty sure the Dragon rest in the underworld." << endl;
					cout << "| The gate to the underworld is South of the Slime Sector." << endl;
					if (level < 5)
					{
						cout << "| Just make sure you reach level 5 before you go through the gate." << endl;
						cout << "| Otherwise your body might not be able to handle the transition." << endl;
					}
					cout << "| Good luck trying to collect it's head." << endl << endl;
				}
				else if (questTrue[4] == TRUE)
				{
					cout << "| Great job on surviving the Underworld." << endl;
					cout << "| I hear you're ready to take on the Demon King now." << endl;
					cout << "| He's probably resting in his castle in the underworld." << endl;
					cout << "| You'll most likely find him there." << endl << endl;
				}

			}
			else if (playerOccupation != "Knight" || playerOccupation != "Mage" || playerOccupation != "Assassin")
			{
				cout << "| NPC: " << npcName << endl;
				cout << "| Hey there!" << endl;
				cout << "| You look new here!" << endl;
				cout << "| If you want an easy job. You may want to go to the Adventurers Guild!" << endl
					<< endl;
			}
			else
			{
				cout << "| NPC: " << npcName << endl;
				cout << "| Hey there!" << endl;
			}
		}

		break;

	case 2: // Adventurers Guild NPC

		npcName = "Shion";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		if (inventory[0].compare("Adventurers Card") != 0)
		{
			cout << "| NPC: " << npcName << endl;
			cout << "| Welcome to the Adventurers Guild!\n";
			cout << "| Please go to the Front Desk in order to register yourself.\n\n";
		}
		if (inventory[0].compare("Adventurers Card") == 0)
		{
			cout << "| NPC: " << npcName << endl;
			cout << "| Welcome to the Adventurers Guild!\n";
			cout << "| You can go get a quest at the Quest Board!\n\n";
		}

		break;

	case 3: // Adventurers Front Desk NPC

		npcName = "Shuna";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		if (inventory[0].compare("Adventurers Card") != 0)
		{
			cout << "| NPC: " << npcName << endl;
			cout << "| Hi there!\n";
			cout << "| In order to register, please type in your desired name.\n\n";
			cout << "Name: ";

			getline(cin, playerName);

			cout << endl;

			cout << "| Great! Welcome to the Adventurers life " << playerName << "!\n\n";
			cout << "| What is your class?\n";
			cout << "| 1.) Knight\n";
			cout << "| 2.) Mage\n";
			cout << "| 3.) Assassin\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("knight") == 0)
			{
				playerOccupation = "Knight";
				cout << "| You've chosen the role of " << playerOccupation << " and obtained an Adventurers Card!" << endl
					<< endl;
			}
			else if (input.compare("mage") == 0)
			{
				playerOccupation = "Mage";
				cout << "| You've chosen the role of " << playerOccupation << " and obtained an Adventurers Card!" << endl
					<< endl;
			}
			else if (input.compare("assassin") == 0)
			{
				playerOccupation = "Assassin";
				cout << "| You've chosen the role of " << playerOccupation << " and obtained an Adventurers Card!" << endl
					<< endl;
			}
			else
			{
				cout << "| Doesn't seem like that's a valid class." << endl;
			}

			if (playerOccupation == "Knight" || playerOccupation == "Mage" || playerOccupation == "Assassin")
			{
				inventory[0] = "Adventurers Card";
				cout << "| Please proceed to the Quest Board or come back later!\n\n";
			}
		}

		break;

	case 4: // Potion Shop NPC

		npcName = "Wiz";

		cout << "| NPC: " << npcName << endl;
		cout << "| Choose from the following potions to buy!" << endl << endl;
		if (inventory[1].compare("Health Potion") != 0)
		{
			cout << "1.) Health Potion [10 Kol] [HEALS 50 HP]" << endl;
		}
		if (inventory[2].compare("Damage Potion") != 0)
		{
			cout << "2.) Damage Potion [15 Kol] [+5 DAMAGE]" << endl;
		}
		if (inventory[3].compare("Agility Potion") != 0 && playerOccupation.compare("Mage") != 0)
		{
			cout << "3.) Agility Potion [15 Kol] [25% MONSTER MISS CHANCE] [-25% MISS CHANCE]" << endl;
		}
		if (inventory[3].compare("Mana Potion") != 0 && playerOccupation.compare("Mage") == 0)
		{
			cout << "3.) Mana Potion [10 Kol] [+50 Mana]" << endl;
		}

		cout << endl;
		cout << "Input leave to leave" << endl;

		break;

	case 5:

		npcName = "Kaijin";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| NPC: " << npcName << endl;

		if (level == 1)
		{

			if (playerOccupation.compare("Civilian") == 0)
			{
				cout << "| This isn't the place for someone like you." << endl;
				cout << "| I'll consider letting you buy stuff when you become an Adventurer." << endl;
			}

			cout << "| Sorry but it doesn't seem like your level is high enough to buy any of my products." << endl;

			cout << endl;
			cout << "Input leave to leave" << endl;
		}

		if (level >= 2)
		{
			if (playerOccupation.compare("Knight") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following weapons to buy!" << endl << endl;
				if (weapon.compare("Copper Sword") != 0)
				{
					cout << "| Copper Sword [20 Kol] [8-18 DAMAGE]" << endl;
				}
				if (weapon.compare("Iron Sword") != 0 && level > 3)
				{
					cout << "| Iron Sword [50 Kol] [12-24 DAMAGE]" << endl;
				}
				if (weapon.compare("War") != 0 && level > 5)
				{
					cout << "| War [75 Kol] [18-32 DAMAGE]" << endl;
				}

			}
			if (playerOccupation.compare("Mage") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following weapons to buy!" << endl << endl;
				if (weapon.compare("Ruby Gem Staff") != 0)
				{
					cout << "| Ruby Gem Staff [20 Kol] [8-20 DAMAGE]" << endl;
				}
				if (weapon.compare("Tome of Stars") != 0 && level > 3)
				{
					cout << "| Tome of Stars [50 Kol] [12-28 DAMAGE]" << endl;
				}
				if (weapon.compare("War") != 0 && level > 5)
				{
					cout << "| Tome of Eternity [75 Kol] [18-36 DAMAGE]" << endl;
				}
			}
			if (playerOccupation.compare("Assassin") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following weapons to buy!" << endl << endl;
				if (weapon.compare("Copper Daggers") != 0)
				{
					cout << "| Copper Daggers [20 Kol] [8-16 DAMAGE]" << endl;
				}
				if (weapon.compare("Iron Daggers") != 0 && level > 3)
				{
					cout << "| Iron Daggers [50 Kol] [12-20 DAMAGE]" << endl;
				}
				if (weapon.compare("Demon Daggers") != 0 && level > 5)
				{
					cout << "| Demon Daggers [75 Kol] [18-28 DAMAGE]" << endl;
				}

			}

			cout << endl;
			cout << "Input leave to leave" << endl;
		}

		break;

	case 6:

		npcName = "Yamato";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| NPC: " << npcName << endl;

		if (level == 1)
		{
			if (playerOccupation.compare("Civilian") == 0)
			{
				cout << "| Awww what's a cutie like you doing here." << endl;
				cout << "| Maybe come back when you're able to call yourself an Adventurer." << endl;
			}
			cout << "| Sorry but it doesn't seem like your level is high enough to buy any of my products." << endl;

			cout << endl;
			cout << "Input leave to leave" << endl;
		}

		if (level >= 2)
		{
			if (playerOccupation.compare("Knight") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following armor sets to buy!" << endl << endl;
				if (armor.compare("Copper Armor") != 0)
				{
					cout << "| Copper Armor [20 Kol] [20% DMG REDUCTION]" << endl;
				}
				if (armor.compare("Iron Armor") != 0 && level >= 3)
				{
					cout << "| Iron Armor [45 Kol] [30% DMG REDUCTION]" << endl;
				}
				if (armor.compare("Samurai Armor") != 0 && level >= 5)
				{
					cout << "| Samurai Armor [60 Kol] [35% DMG REDUCTION] [20% MONSTER MISS CHANCE]" << endl;
				}
			}
			if (playerOccupation.compare("Mage") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following armor sets to buy!" << endl << endl;
				if (armor.compare("Leather Robe") != 0)
				{
					cout << "| Leather Robe [20 Kol] [15% PLAYER DAMAGE] [+10 MANA]" << endl;
				}
				if (armor.compare("Silk Woven Robe") != 0 && level >= 3)
				{
					cout << "| Silk Woven Robe [45 Kol] [20% PLAYER DAMAGE] [+30 MANA]" << endl;
				}
				if (armor.compare("Gown of Ainz Ooal Gown") != 0 && level >= 5)
				{
					cout << "| Gown of Ainz Ooal Gown [60 Kol] [25% PLAYER DAMAGE] [10% DMG REDUCTION] [+50 MANA]" << endl;
				}
			}
			if (playerOccupation.compare("Assassin") == 0)
			{
				cout << "| I see that you're a " << playerOccupation << "!" << endl;
				cout << "| You can choose from the following weapons to buy!" << endl << endl;
				if (armor.compare("Wolf Hide"))
				{
					cout << "| Wolf Hide [20 Kol] [50% MONSTER MISS CHANCE]" << endl;
				}
				if (armor.compare("Skeleton Bone Armor") != 0 && level >= 3)
				{
					cout << "| Skeleton Bone Armor [45 Kol] [60% MONSTER MISS CHANCE]" << endl;
				}
				if (armor.compare("Ninja Outfit") != 0 && level >= 5)
				{
					cout << "| Ninja Outfit [60 Kol] [70% MONSTER MISS CHANCE] [5% DMG REDUCTION]" << endl;
				}
			}

			cout << endl;
			cout << "Input leave to leave" << endl;
		}

		break;

	case 7:

		npcName = "Shizue";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| NPC: " << npcName << endl;
		cout << "| Welcome to the Masadora Docks!" << endl;

		if (inventory[4].compare("Boat") != 0)
		{
			cout << "| If you want to go out onto rough waters, you're going to need a boat" << endl;
			cout << "| I can get you a boat if you need but you're going to have to pay me 25 Kol." << endl;
			if (kol <= 25)
			{
				cout << "| If you need some Kol, you can slay some wolves northeast of here in order to get some." << endl;
				cout << "| Good luck!" << endl << endl;
			}
			if (kol >= 25)
			{
				cout << "| Would you like to buy a boat right now?" << endl << endl;

				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("yes") == 0)
				{
					cout << "| You bought a boat!" << endl;
					cout << "| You can now travel on rough waters!" << endl << endl;
					inventory[4] = "Boat";
				}
				else if (input.compare("no") == 0)
				{
					cout << "| Aww man." << endl;
					cout << "| That's unfortunate." << endl;
					cout << "| Well come back to me when you need a boat!" << endl << endl;
				}
				else
				{
					cout << "| Sorry doesn't seem like that's an option." << endl << endl;
				}
			}
		}

		break;

	case 8:

		npcName = "Rigurd";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| NPC: " << npcName << endl;

		if (inventory[9].compare("Demon King Core") != 0)
		{
			cout << "| HALT!\n";
			cout << "| You stand in front of the Castle of Masadora.\n";
			cout << "| You may not enter.\n";
			cout << "| You must go back South!\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go south") == 0)
			{
				area = 10;
			}
		}
		else if (inventory[9].compare("Demon King Core") == 0)
		{
			cout << "| You stand in front of the Castle of Masadora.\n";
			cout << "You may enter the Castle\n";
			cout << "OR\n";
			cout << "You can go back South\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into castle") == 0)
			{
				castle();
			}
			if (input.compare("go south") == 0)
			{
				area = 10;
			}

		}

		break;

	case 9:

		npcName = "King Rimuru";

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| NPC: " << npcName << endl << endl;

		cout << "| Hello there " << playerName << endl;
		cout << "| Do you remember me?" << endl;
		cout << "| I'm the one that has been guiding you everywhere you needed to go!" << endl;
		
		cout << endl;
		system("pause");
		cout << endl;

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);

		cout << "| You've done a splendid job at completing the task the city has asked of you." << endl;
		cout << "| And not only that. You ended the oppression of the Demon King, 'Anos Voldigoad'" << endl;
		cout << "| We could never ask anything more of you hero." << endl;
		cout << "| Please come and claim your reward." << endl;

		cout << endl;
		system("pause");
		cout << endl;

		cout << "You go towards King Rimuru as he carefully extracts a crown from one of his chest." << endl;
		cout << "You bow down to the King and you puts the crown on top of your head." << endl;

		cout << endl;
		system("pause");
		cout << endl;

		cout << "Suddenly, as the crown has just been placed upon your head." << endl;
		cout << "Time stops. And only you can move." << endl;
		cout << "You hear a feminine voice coming closer and closer to you." << endl;

		cout << endl;
		system("pause");
		cout << endl;

		npcName = "Emilia";

		cout << "| NPC: " << npcName << endl << endl;

		PlaySoundA((LPCSTR)"./Sounds/voice_sans.WAV", NULL, SND_FILENAME | SND_ASYNC);
		cout << "| My hero." << endl;
		cout << "| You've done so well my hero." << endl;
		cout << "| You can rest now." << endl;

		cout << endl;
		system("pause");
		cout << endl;

		cout << "Suddenly, you fall into a deep slumber." << endl;
		cout << "Never to be woken up ever again." << endl;
		cout << "But you don't feel pain, you feel relieved." << endl;
		cout << "For some reason, the woman's voice, was the thing that you wanted the most." << endl;

		cout << endl;
		system("pause");
		cout << endl;
	}
}