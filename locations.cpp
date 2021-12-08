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
				system("pause");
			}
			if (input.compare("defeat slime king") == 0 && inventory[5].compare("Slime King Crown") != 0)
			{
				cout << "You picked up the quest 'Defeat the Slime King'." << endl;
				cout << "The paper tells you to head WEST in order to find the Slime King." << endl;
				questTrue[0] = TRUE;
				system("pause");
			}
			if (input.compare("defeat ainz ooal gown") == 0 && inventory[7].compare("Staff of Ainz Ooal Gown") != 0)
			{
				cout << "You picked up the quest 'Defeat Ainz Ooal Gown'." << endl;
				cout << "The paper tells you to head EAST in order to find the Ainz Ooal Gown." << endl;
				questTrue[2] = TRUE;
				system("pause");
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
			if (killed >= 5)
			{

				cout << "There is an eerie feeling deeper inside the tomb.\n";
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
			}
			if (killed >= 5)
			{
				cout << "The throne seems to have a glow to it of some sort.\n";
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
			cout << "You can touch the light\n";
			cout << "OR\n";
			cout << "You can Leave or go back West\n";

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("touch light") == 0 && killed >= 5)
			{
				monsterGenerator(5);
			}

		}

	} while (input.compare("leave") != 0 && lives > 0);

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

	} while (lives > 0);

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
			SetConsoleTitle(b);

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
			SetConsoleTitle(b);

			npcGenerator(5);

			cout << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (playerOccupation == "Knight")
			{
				if (input.compare("buy copper sword") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Copper Sword";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}
			if (playerOccupation == "Mage")
			{
				if (input.compare("buy ruby gem staff") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Ruby Gem Staff";
						cout << "You bought a " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
					}
					else if (kol < 20)
					{
						cout << "| Sorry, seems like you don't have enough Kol for that." << endl << endl;
					}
				}
			}
			if (playerOccupation == "Assassin")
			{
				if (input.compare("buy copper daggers") == 0)
				{
					if (kol >= 20)
					{
						weapon = "Copper Daggers";
						cout << "You bought " << weapon << "!" << endl;
						kol -= 20;
						cout << "You have " << kol << " Kol left." << endl << endl;
						system("pause");
					}
					else if (kol < 20)
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
			SetConsoleTitle(b);

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
					}
					else if (kol < 20)
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
					}
					else if (kol < 20)
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
					}
					else if (kol < 20)
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