#include "functions.h"

void adventurersGuild()
{
	string input;
	int room = 1;
	do
	{
		cout << "-----------------------------------------------" << endl;

		cout << "Turns: " << turns << "     "
			<< "Level: " << level << "     "
			<< "Class: " << playerOccupation
			<< "     " << "Lives: " << lives;
		cout << endl << endl;

		turns++;

		switch (room)
		{
		case 1:
			if (inventory[0].compare("Adventurers Card") != 0)
			{

				npcGenerator(2);

				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("go to front desk") == 0)
				{
					room = 2;
				}

				if (input.compare("leave") == 0)
				{
					cout << "Thanks! See you again!" << endl
						<< endl;
				}
			}
			if (inventory[0].compare("Adventurers Card") == 0)
			{

				npcGenerator(2);

				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("go to quest board") == 0)
				{
					room = 3;
				}

				if (input.compare("leave") == 0)
				{
					cout << "Thanks! See you again!" << endl
						<< endl;
				}
			}

			break;

		case 2:
			if (inventory[0].compare("Adventurers Card") != 0)
			{

				npcGenerator(3);

			}
			if (inventory[0].compare("Adventurers Card") == 0)
			{

				npcGenerator(3);

				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("go to quest board") == 0)
				{
					room = 3;
				}
				else if (input.compare("leave") == 0)
				{
					cout << "Thanks! See you again!" << endl
						<< endl;
				}
				else
				{
					cout << "Sorry, that doesn't seem to be an option." << endl;
				}
			}

			break;

		case 3:
			cout << "Welcome to the Quest Board!\n";
			cout << "Choose one of the following quests.\n\n";

			if (questTrue[0] != TRUE && questTrue[1] != TRUE && questTrue[2] != TRUE && questTrue[3] != TRUE && questTrue[4] != TRUE) {
				if (inventory[5].compare("Slime King Crown") != 0)
				{
					cout << quest[0] << endl;
				}
				if (inventory[6].compare("Kraken Ink") != 0)
				{
					cout << quest[1] << endl;
				}
				if (inventory[7].compare("Staff of Ainz Ooal Gown") != 0)
				{
					cout << quest[2] << endl;
				}
				if (inventory[8].compare("Dragon Head") != 0 && inventory[7].compare("Staff of Ainz Ooal Gown") == 0 && inventory[6].compare("Kraken Ink") == 0 && inventory[5].compare("Slime King Crown") == 0)
				{
					cout << quest[3] << endl;
				}
				if (inventory[9].compare("Demon King Core") != 0 && inventory[8].compare("Dragon Head") == 0)
				{
					cout << quest[4] << endl;
				}
			}
			else
			{
				cout << "Seems like you currently have an active quest!" << endl;
			}

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("defeat kraken") == 0 && inventory[6].compare("Kraken Ink") != 0)
			{
				cout << "You picked up the quest 'Defeat the Kraken'." << endl;
				cout << "The paper tells you to head SOUTH in order to find the Kraken." << endl;
				questTrue[1] = TRUE;

				cout << endl;
				system("pause");
				cout << endl;
			}
			if (input.compare("defeat slime king") == 0 && inventory[5].compare("Slime King Crown") != 0)
			{
				cout << "You picked up the quest 'Defeat the Slime King'." << endl;
				cout << "The paper tells you to head WEST in order to find the Slime King." << endl;
				questTrue[0] = TRUE;

				cout << endl;
				system("pause");
				cout << endl;
			}
			if (input.compare("defeat ainz ooal gown") == 0 && inventory[7].compare("Staff of Ainz Ooal Gown") != 0)
			{
				cout << "You picked up the quest 'Defeat Ainz Ooal Gown'." << endl;
				cout << "The paper tells you to head EAST in order to find the Ainz Ooal Gown." << endl;
				questTrue[2] = TRUE;
				
				cout << endl;
				system("pause");
				cout << endl;
			}
			if (inventory[8].compare("Dragon Head") != 0 && inventory[7].compare("Staff of Ainz Ooal Gown") == 0 && inventory[6].compare("Kraken Ink") == 0 && inventory[5].compare("Slime King Crown") == 0)
			{
				cout << "You picked up the quest 'Slay the Dragon'." << endl;
				cout << "The paper tells you to head South of the Slime Sector and find the gate to the underworld." << endl;
				questTrue[3] = TRUE;

				cout << endl;
				system("pause");
				cout << endl;
			}
			if (inventory[9].compare("Demon King Core") != 0 && inventory[8].compare("Dragon Head") == 0)
			{
				cout << "You picked up the quest 'Slay the Demon King'." << endl;
				cout << "The paper tells you to find the Demon King Castle in the underworld." << endl;
				questTrue[4] = TRUE;

				cout << endl;
				system("pause");
				cout << endl;
			}

			break;
		}
	} while (input.compare("leave") != 0 && lives > 0);
}

void tombOfNazarik(int killed)
{

	string input;
	int room = 1;

	do
	{

		cout << "-----------------------------------------------" << endl;
		cout << "Turns: " << turns << "     "
			<< "Level: " << level << "     "
			<< "Class: " << playerOccupation
			<< "     " << "Lives: " << lives;
		cout << endl << endl;

		turns++;

		switch (room)
		{

		case 1:

			if (killed <= 0)
			{

				cout << "Doesn't seem like there is too much going on here.\n";

				cout << endl;
				cout << "You can go deeper in by going East\n";
				cout << "OR\n";
				cout << "Leave\n";

				cout << endl;
				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("go east") == 0)
				{
					room = 2;
				}
				if (input.compare("leave") == 0)
				{
					room = 999;
				}

			}
			if (killed >= 5)
			{

				cout << "There is an eerie feeling deeper inside the tomb.\n";

				cout << endl;
				cout << "You can go deeper in by going East\n";
				cout << "OR\n";
				cout << "Leave\n";

				cout << endl;
				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("go east") == 0)
				{
					room = 2;
				}

			}

			break;

		case 2:

			cout << "You've entered a huge room and you see a throne at the end of it.\n";
			if (killed <= 0)
			{
				cout << "Doesn't seem like there's much you can do in this tomb right now.\n";
				cout << "Maybe come back after defeating some skeletons.\n";
				cout << endl;
			}
			if (killed >= 5)
			{
				cout << "The throne seems to have a glow to it of some sort.\n";
				cout << endl;
				cout << "You can go to the throne\n";
				cout << "OR\n";
			}
			cout << "You can leave or go back West\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				room = 1;
			}
			if (input.compare("go to throne") == 0 && killed >= 5)
			{
				room = 3;
			}
			else if (input.compare("go to throne") == 0 && killed <= 5)
			{
				cout << "Going there wouldn't do you any good.\n";
			}

			break;

		case 3:

			cout << "There seems to be a light on the seat of the throne.\n";

			cout << endl;
			cout << "You can touch the light\n";
			cout << "OR\n";
			cout << "You can go back West\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("touch light") == 0 && killed >= 5)
			{
				for (int i = skeletonsKilled; i > 0; i--)
				{
					skeletonsKilled--;
				}
				monsterGenerator(6);
			}
			
			if (input.compare("go west") == 0)
			{
				room = 2;
			}
		}

		if (room == 999)
		{
			break;
		}

	} while (health > 0 && lives > 0);

}

void castle()
{

	string input;
	int room = 1;

	do
	{
		cout << "-----------------------------------------------" << endl;
		cout << "Turns: " << turns << "     "
			<< "Level: " << level << "     "
			<< "Class: " << playerOccupation
			<< "     " << "Lives: " << lives;
		cout << endl << endl;

		turns++;

		switch (room)
		{



		}

	} while (input.compare("leave") != 0 && lives > 0);

}

void underworld()
{

	string input;
	int room = 1;
	bool first = TRUE;

	underworldGameWindow();

	do
	{
		cout << "-----------------------------------------------" << endl;
		cout << "Turns: " << turns << "     "
			<< "Level: " << level << "     "
			<< "Class: " << playerOccupation
			<< "     " << "Lives: " << lives;
		cout << endl << endl;

		turns++;

		commands(input);

		switch (room)
		{

		case 1:

			cout << "Surrounded by the heat of the flames, you've made it into the Underworld.\n";

			if (first == TRUE)
			{
				cout << "You're one step closer to your goal.\n";
				first = FALSE;
			}


			cout << endl;
			cout << "You can go back through the gate.\n";
			cout << "OR\n";
			cout << "You can go North or West\n";


			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go through gate") == 0)
			{
				room = 999;
			}
			if (input.compare("go north") == 0)
			{
				room = 2;
			}
			if (input.compare("go west") == 0)
			{
				room = 3;
			}


			break;

		case 2:

			monsterGenerator(7);

			cout << "You've made it into a seemingly empty space in the underworld.\n";
			cout << "There seems to be a mountain of ashes North of you.\n";
			cout << "Powerful monsters lurk here.\n";

			cout << endl;
			cout << "You can go North or West or East or South.\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				room = 7;
			}
			if (input.compare("go west") == 0)
			{
				room = 4;
			}
			if (input.compare("go east") == 0)
			{
				room = 3;
			}
			if (input.compare("go south") == 0)
			{
				room = 1;
			}

			break;

		case 3:

			monsterGenerator(7);
			cout << "You seem to be on the border of some barrier.\n";
			if (barrier == FALSE)
			{
				cout << "There seems to be some sort of glass clouded ball on the floor next to the barrier.\n";
				cout << endl;
				cout << "You can pick up the ball\n";
				cout << "OR";
			}

			cout << endl;
			cout << "You can go West\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				room = 2;
			}
			if (input.compare("pick up ball") == 0 && barrier == FALSE)
			{
				barrier = TRUE;
				cout << "You've picked up the glass clouded ball!\n";
				cout << "The glass breaks as soon as you pick it up and a slimey substance comes to shroud your entire body.\n";
				cout << "Seems like the slimey substance will protect you even more in battle!\n";

				cout << endl;
				system("pause");
				cout << endl;
			}

			break;

		case 4:

			cout << "You've made it to a building with the label 'Potion Shop' on it.\n";

			cout << endl;
			cout << "You can go into the Potion Shop\n";
			cout << "OR\n";
			cout << "You can go East or South\n";

			if (input.compare("go into potion shop") == 0)
			{
				townShops(1);
			}
			if (input.compare("go east") == 0)
			{
				room = 2;
			}
			if (input.compare("go south") == 0)
			{
				room = 5;
			}
			
			break;

		case 5:

			monsterGenerator(7);

			cout << "You've made it into a seemingly empty space in the underworld.\n";
			cout << "Powerful monsters lurk around here.\n";
			cout << "Be careful\n";

			cout << endl;
			cout << "You can go North or West or East or South.\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				room = 4;
			}
			if (input.compare("go west") == 0)
			{
				room = 8;
			}
			if (input.compare("go east") == 0)
			{
				room = 1;
			}
			if (input.compare("go south") == 0)
			{
				room = 6;
			}

			break;

		case 6:

			monsterGenerator(7);

			cout << "You seem to be on the border of some barrier.\n";
			if (barrier == FALSE)
			{
				cout << "There seems to be some sort of glass clouded ball on the floor next to the barrier.\n";
				cout << endl;
				cout << "You can pick up the ball\n";
				cout << "OR";
			}

			cout << endl;
			cout << "You can go North\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				room = 5;
			}
			if (input.compare("pick up ball") == 0 && barrier == FALSE)
			{
				barrier = TRUE;
				cout << "You've picked up the glass clouded ball!\n";
				cout << "The glass breaks as soon as you pick it up and a slimey substance comes to shroud your entire body.\n";
				cout << "Seems like the slimey substance will protect you even more in battle!\n";

				cout << endl;
				system("pause");
				cout << endl;
			}

			break;

		case 7:

			cout << "You climb up the mountain of ashes.\n";

			if (inventory[8].compare("Dragon Head") == 0)
			{
				cout << "You see a dragon resting on the other side of the mountain.\n";
				cout << "Will you dare contest the Dragon?\n";

				cout << endl;
				cout << "You can fight the Dragon\n";
				cout << "OR";
			}

			cout << endl;
			cout << "You can go back South\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("fight dragon") == 0)
			{
				monsterGenerator(8);
			}
			if (input.compare("go south") == 0)
			{
				room = 2;
			}

			break;

		case 8:

			cout << "You've made it to a bridge of some sort.\n";
			cout << "You see a black castle to your West and the Portal to your East.\n";

			cout << endl;
			cout << "You can go West or East\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				room = 9;
			}
			if (input.compare("go east") == 0)
			{
				room = 5;
			}

			break;

		case 9:

			cout << "You stand in front of a castle.\n";
			cout << "You can tell immediately that this is the castle of the Demon King.\n";

			cout << endl;
			cout << "Do you want to proceed into the castle\n";
			cout << "OR\n";
			cout << "Go East\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into castle") == 0)
			{

				cout << "IF YOU GO INTO THE DEMON KING'S CASTLE, YOU WILL NOT BE ABLE TO COME BACK.\n";

				cout << endl;
				cout << "Do you still wish to proceed?\n";
				cout << "yes or no\n";

				cout << endl;
				cout << "> ";
				getline(cin, input);
				cout << endl;

				if (input.compare("no") == 0)
				{
					room = 9;
				}
				if (input.compare("yes") == 0)
				{
					room = 10;
				}

			}
			if (input.compare("go east") == 0)
			{
				room = 8;
			}

			break;

		case 10:

			cout << "You open the doors to the Demon King's Castle.\n";
			cout << "He sits on his throne seemingly waiting for you to arrive.\n\n";

			monsterGenerator(9);

			if (inventory[9].compare("Demon King Core") == 0)
			{
				room = 9;
			}

		}

		if (room == 999)
		{
			break;
		}

	} while (health > 0 && lives > 0);

}

void townShops(int shop)
{

	string input;
	do
	{
		turns++;
		cout << "-----------------------------------------------" << endl;

		cout << "Kol: " << kol << endl << endl;

		if (shop == 1)
		{

			LPCWSTR a = L"Potion Shop";
			LPCSTR b = "Potion Shop";
			SetConsoleTitle(a);

			npcGenerator(4);

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("buy health potion") == 0)
			{
				if (kol >= 10)
				{
					inventory[1] = "Health Potion";
					cout << "You bought a " << inventory[1] << "!" << endl;
					kol -= 10;
					cout << "You have " << kol << " kol left." << endl << endl;
					system("pause");
				}
				else if (kol < 10)
				{
					cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
				}
			}
			if (input.compare("buy damage potion") == 0)
			{
				if (kol >= 15)
				{
					inventory[2] = "Damage Potion";
					cout << "You bought a " << inventory[2] << "!" << endl;
					kol -= 15;
					cout << "You have " << kol << " kol left." << endl << endl;
					system("pause");
				}
				else if (kol < 15)
				{
					cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
				}
			}
			if (input.compare("buy agility potion") == 0 && playerOccupation.compare("Mage") != 0)
			{
				if (kol >= 15)
				{
					inventory[3] = "Agility Potion";
					cout << "You bought a " << inventory[3] << "!" << endl;
					kol -= 15;
					cout << "You have " << kol << " kol left." << endl << endl;
					system("pause");
				}
				else if (kol < 15)
				{
					cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
				}
			}
			if (input.compare("buy mana potion") == 0 && playerOccupation.compare("Mage") == 0)
			{
				if (kol >= 10)
				{
					inventory[3] = "Mana Potion";
					cout << "You bought a " << inventory[3] << "!" << endl;
					kol -= 10;
					cout << "You have " << kol << " kol left." << endl << endl;
					system("pause");
				}
				else if (kol < 10)
				{
					cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
				}
			}
		}

		if (shop == 2)
		{

			LPCWSTR a = L"Weapon Shop";
			LPCSTR b = "Weapon Shop";
			SetConsoleTitle(a);

			npcGenerator(5);

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (playerOccupation == "Knight") // All weapons for Knight Class
			{
				if (input.compare("buy copper sword") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Copper Sword";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy iron sword") == 0 && level >= 3)
				{
					if (kol >= 50)
					{
						weapon = "Iron Sword";
						cout << "You bought an " << weapon << "!" << endl;
						kol -= 50;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 50)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy war") == 0 && level >= 5)
				{
					if (kol >= 75)
					{
						weapon = "War";
						cout << "You bought " << weapon << "!" << endl;
						kol -= 75;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 75)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}
			if (playerOccupation == "Mage") // All weapons for Mage Class
			{
				if (input.compare("buy ruby gem staff") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Ruby Gem Staff";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy tome of stars") == 0 && level >= 3)
				{
					if (kol >= 50)
					{
						weapon = "Tome of Stars";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 50;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 50)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy tome of eternity") == 0 && level >= 5)
				{
					if (kol >= 75)
					{
						weapon = "Tome of Eternity";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 75;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 75)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}
			if (playerOccupation == "Assassin") // All weapons for Assassin Class
			{
				if (input.compare("buy copper daggers") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Copper Daggers";
						cout << "You bought " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy iron daggers") == 0 && level >= 3)
				{
					if (kol >= 50)
					{
						weapon = "Iron Daggers";
						cout << "You bought " << weapon << "!" << endl;
						kol -= 50;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 50)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy demon daggers") == 0 && level >= 5)
				{
					if (kol >= 75)
					{
						weapon = "Demon Daggers";
						cout << "You bought " << weapon << "!" << endl;
						kol -= 75;
						cout << "You have " << kol << " Kol left." << endl;

						cout << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 75)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}

		}

		if (shop == 3)
		{

			LPCWSTR a = L"Armor Shop";
			LPCSTR b = "Armor Shop";
			SetConsoleTitle(a);

			npcGenerator(6);

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (playerOccupation == "Knight" && level > 1)
			{
				if (input.compare("buy copper armor") == 0)
				{
					if (kol >= 20)
					{
						armor = "Copper Armor";
						cout << "You bought " << armor << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy iron armor") == 0 && level > 3)
				{
					if (kol >= 45)
					{
						armor = "Iron Armor";
						cout << "You bought " << armor << "!" << endl;
						kol -= 45;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 45)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy samurai armor") == 0 && level > 5)
				{
					if (kol >= 60)
					{
						armor = "Copper Armor";
						cout << "You bought " << armor << "!" << endl;
						kol -= 60;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 60)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}

			if (playerOccupation == "Mage" && level > 1)
			{
				if (input.compare("buy leather robe") == 0)
				{
					if (kol >= 20)
					{
						armor = "Leather Robe";
						cout << "You bought " << armor << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy silk woven robe") == 0 && level > 3)
				{
					if (kol >= 45)
					{
						armor = "Silk Woven Robe";
						cout << "You bought a " << armor << "!" << endl;
						kol -= 45;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 45)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy gown of ainz ooal gown") == 0 && level > 5)
				{
					if (kol >= 60)
					{
						armor = "Gown of Ainz Ooal Gown";
						cout << "You bought the " << armor << "!" << endl;
						kol -= 60;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 60)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}

			if (playerOccupation == "Assassin" && level > 1)
			{
				if (input.compare("buy wolf hide") == 0)
				{
					if (kol >= 20)
					{
						armor = "Wolf Hide";
						cout << "You bought " << armor << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy skeleton bone armor") == 0 && level > 3)
				{
					if (kol >= 45)
					{
						armor = "Skeleton Bone Armor";
						cout << "You bought " << armor << "!" << endl;
						kol -= 45;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 45)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
				if (input.compare("buy ninja outfit") == 0 && level > 5)
				{
					if (kol >= 60)
					{
						armor = "Ninja Outfit";
						cout << "You bought a " << armor << "!" << endl;
						kol -= 60;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
						cout << endl;
					}
					else if (kol < 60)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}

		}

		if (input.compare("leave") == 0)
		{
			cout << "| Thanks! See you again!" << endl << endl;
			masadoraGameWindow();
		}

	} while (input.compare("leave") != 0);
}