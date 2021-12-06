#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

#include "functions.h"
using namespace std;

string inventory[10];
string weapon = "Fist";
string armor = " ";
string quest[5] = { "Defeat the Slime King", "Defeat the Kraken", "Defeat Ainz Ooal Gown", "Slay the Dragon", "Slay the Demon King" };
bool questTrue[5] = { FALSE, FALSE, FALSE, FALSE, FALSE };

int level = 1;
int levelBar = 100;
int levelCounter = 0;

int kol = 0; //currency
int slimeSecretion = 0;
int skeletonsKilled = 0;

int area = 1;
int turns = 0;
bool respawn = FALSE;

int main()
{

	LPCWSTR a = L"The Typical Isekai";
	LPCSTR b = "The Typical Isekai";
	SetConsoleTitle(a);

	HWND console = GetConsoleWindow();
	RECT r;

	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
	system("COLOR A5");

	//MessageBox(nullptr, TEXT("Welcome to 'The Typical Isekai'!"), TEXT("Welcome!"), MB_OK);
	srand(time(NULL));

	string input;
	bool first = false;

	do
	{

		cout << "-----------------------------------------------" << endl;
		if (area >= 15 && area <= 23)
		{
			cout << "Turns: " << turns << "     " << "Level: " << level << "     " << "Class: " << playerOccupation << "     " << "Lives: " << lives << "     " << "Slime Secretion: " << slimeSecretion;
		}
		else
		{
			cout << "Turns: " << turns << "     "
				<< "Level: " << level << "     "
				<< "Class: " << playerOccupation
				<< "     " << "Lives: " << lives;
		}
		cout << endl << endl;
		turns++;

		if (input.compare("inventory") == 0)
		{
			checkInventory();
			cout << endl;
			system("pause");
			cout << "-----------------------------------------------" << endl;
		}
		if (input.compare("quest") == 0)
		{
			checkQuest();
			cout << endl;
			system("pause");
			cout << "-----------------------------------------------" << endl;
		}
		if (input.compare("help") == 0)
		{
			help();
			cout << endl;
			system("pause");
			cout << "-----------------------------------------------" << endl;
		}

		switch (area)
		{
		case 1:

			cout << "You open your eyes to a forest filled with the light of fireflies.\n";

			if (weapon.compare("Wooden Sword") != 0)
			{
				cout << "You find a Wooden Sword next to you.\n";
			}

			cout << "You can go North\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("pick up wooden sword") == 0)
			{
				weapon = "Wooden Sword";
				cout << "You picked up a " << weapon << "!" << endl
					<< endl;
			}
			else if (input.compare("go north") == 0)
			{
				area = 2;
			}

			break;

		case 2:

			cout << "You find yourself in front a gigantic stone wall.\n";
			cout << "You can follow the wall Left or Right\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go left") == 0)
			{
				area = 3;
			}
			else if (input.compare("go right") == 0)
			{
				area = 4;
			}

			break;

		case 3:

			masadoraGameWindow();
			cout << "You stand in front of a big gate labeled 'West Gate'.\n";
			cout << "You can go through the gate\n";
			cout << "OR\n";
			cout << "Proceed West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go through gate") == 0)
			{
				area = 5;
			}
			else if (input.compare("go west") == 0)
			{
				area = 13;
			}
			else if (input.compare("go south") == 0)
			{
				area = 2;
			}

			break;

		case 4:

			masadoraGameWindow();
			cout << "You stand in front of a big gate labeled 'South Gate'\n";
			cout << "You can go through the gate\n";
			cout << "OR\n";
			cout << "Proceed East or West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go through gate") == 0)
			{
				area = 6;
			}
			if (input.compare("go south") == 0)
			{
				area = 29;
			}
			if (input.compare("go west") == 0)
			{
				area = 2;
			}
			if (input.compare("go east") == 0)
			{
				area = 48;
			}


			break;

		case 5:

			npcGenerator(1);

			cout << "You've made it into the west side of the city of Masadora.\n";
			cout << "You can go North or East or West.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 6;
			}
			if (input.compare("go west") == 0)
			{
				area = 3;
			}
			if (input.compare("go north") == 0)
			{
				area = 8;
			}

			break;

		case 6:

			npcGenerator(1);

			cout << "You've made it into the south side of the city of Masadora.\n";
			cout << "You can go North or East or West or South.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 9;
			}
			if (input.compare("go west") == 0)
			{
				area = 5;
			}
			if (input.compare("go north") == 0)
			{
				area = 10;
			}
			if (input.compare("go south") == 0)
			{
				area = 4;
			}

			break;

		case 7:

			npcGenerator(1);

			cout << "You've made it into the East side of the city of Masadora.\n";
			cout << "You can go East or West or South.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 12;
			}
			if (input.compare("go west") == 0)
			{
				area = 10;
			}
			if (input.compare("go south") == 0)
			{
				area = 9;
			}

			break;

		case 8:

			cout << "You see a shop labeled 'Potion Shop' in front of you.\n";
			cout << "You can go into the Potion Shop\n";
			cout << "OR\n";
			cout << "You can go North or East or South.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into potion shop") == 0)
			{
				townShops(1);
			}
			if (input.compare("go north") == 0)
			{
				area = 24;
			}
			if (input.compare("go east") == 0)
			{
				area = 10;
			}
			if (input.compare("go south") == 0)
			{
				area = 5;
			}

			break;

		case 9:

			cout << "You stand in front of a palace like building labeled 'Adventurers Guild'.\n";
			cout << "You can go into the Adventurers Guild\n";
			cout << "OR\n";
			cout << "You can go West or North.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into adventurers guild") == 0)
			{
				adventurersGuild();
			}
			if (input.compare("go west") == 0)
			{
				area = 6;
			}
			if (input.compare("go north") == 0)
			{
				area = 7;
			}

			break;

		case 10:

			masadoraGameWindow();
			cout << "There is a gigantic statue labeled 'Masadora' in the middle of town." << endl;
			cout << "You can go touch the Statue.\n";
			cout << "OR\n";
			cout << "Proceed North or East or South or West.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("touch statue") == 0)
			{
				if (respawn == TRUE)
				{
					cout << "You have healed to full health!" << endl
						<< endl;
					health = 100;
					system("pause");
				}
				if (respawn != TRUE)
				{
					cout << "You've touched the statue and gained it's wisdom" << endl;
					cout << "(You may now respawn a total of 3 times when you die)" << endl;
					cout << "(You can also come touch the statue again in order to heal)" << endl << endl;
					respawn = TRUE;
					system("pause");
				}
			}
			if (input.compare("go north") == 0)
			{
				area = 11;
			}
			if (input.compare("go east") == 0)
			{
				area = 7;
			}
			if (input.compare("go west") == 0)
			{
				area = 8;
			}
			if (input.compare("go south") == 0)
			{
				area = 6;
			}

			break;

		case 11:

			npcGenerator(8);

			break;

		case 12:

			masadoraGameWindow();
			cout << "You stand in front of a big gate labeled 'East Gate'.\n";
			cout << "You can go through the gate\n";
			cout << "OR\n";
			cout << "You can proceed East\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go through gate") == 0)
			{
				area = 7;
			}
			if (input.compare("go east") == 0)
			{
				area = 35;
			}

			break;

		case 13:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "You can go East or West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 3;
			}
			if (input.compare("go west") == 0)
			{
				area = 14;
			}
			if (input.compare("go south") == 0)
			{
				area = 26;
			}

			break;

		case 14:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "Theres a sign dangling from a tree saying,\n\n";
			cout << "West <--- Slime Sector\n\n";
			cout << "You can go East or West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 13;
			}
			if (input.compare("go west") == 0)
			{
				area = 15;
			}
			if (input.compare("go south") == 0)
			{
				area = 27;
			}


			break;

		case 15:

			slimeGameWindow();
			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go North or East or West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 14;
			}
			if (input.compare("go north") == 0)
			{
				area = 22;
			}
			if (input.compare("go west") == 0)
			{
				area = 23;
			}
			if (input.compare("go south") == 0)
			{
				area = 16;
			}

			break;

		case 16:

			slimeGameWindow();
			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go North or East or West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 25;
			}
			if (input.compare("go west") == 0)
			{
				area = 17;
			}
			if (input.compare("go north") == 0)
			{
				area = 15;
			}

			break;

		case 17:

			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go North or East or West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 16;
			}
			if (input.compare("go west") == 0)
			{
				area = 18;
			}
			if (input.compare("go north") == 0)
			{
				area = 23;
			}

			break;

		case 18:

			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go North or East\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 17;
			}
			else if (input.compare("go north") == 0)
			{
				area = 19;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 19:

			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go North or East\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 23;
			}
			else if (input.compare("go north") == 0)
			{
				area = 20;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 20:

			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go East or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 21;
			}
			else if (input.compare("go south") == 0)
			{
				area = 19;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 21:

			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go West or East or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 22;
			}
			else if (input.compare("go south") == 0)
			{
				area = 23;
			}
			else if (input.compare("go west") == 0)
			{
				area = 20;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 22:

			slimeGameWindow();
			monsterGenerator(1);

			cout << "You find yourself in a slimy musty looking area.\n";
			cout << "You can go West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 21;
			}
			else if (input.compare("go south") == 0)
			{
				area = 15;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 23:

			cout << "You see an altar covered in slime in front of you.\n";
			if (slimeSecretion >= 5)
			{
				cout << "You can pour the 5 Slime Secretion onto the Altar.\n";
				cout << "OR\n";
			}
			cout << "You can go North or East or South or West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go east") == 0)
			{
				area = 15;
			}
			else if (input.compare("go north") == 0)
			{
				area = 21;
			}
			else if (input.compare("go west") == 0)
			{
				area = 19;
			}
			else if (input.compare("go south") == 0)
			{
				area = 17;
			}
			else if (input.compare("altar") == 0)
			{
				if (slimeSecretion >= 5)
				{
					slimeSecretion -= 5;
					monsterGenerator(2);
				}
				else
				{
					cout << "The altar doesn't seem to currently do anything.\n\n";
				}
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 24:

			cout << "You see a shop labeled 'Weapon Shop' in front of you.\n";
			cout << "You can go into the Weapon Shop\n";
			cout << "OR\n";
			cout << "You can go West or South.\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into weapon shop") == 0)
			{
				townShops(2);
			}
			else if (input.compare("go west") == 0)
			{
				area = 25;
			}
			else if (input.compare("go south") == 0)
			{
				area = 8;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 25:

			cout << "You see a shop labeled 'Armor Shop' in front of you.\n";
			cout << "You can go into the Armor Shop\n";
			cout << "OR\n";
			cout << "You can go East\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go into armor shop") == 0)
			{
				townShops(3);
			}
			else if (input.compare("go east") == 0)
			{
				area = 24;
			}
			else if (input.compare("inventory") == 0)
			{
				checkInventory();
			}
			else
			{
				cout << "Sorry, doesn't seem like that's an option\n\n";
			}

			break;

		case 26:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "You can go North or West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 13;
			}
			if (input.compare("go west") == 0)
			{
				area = 27;
			}

			break;

		case 27:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "You see a sign North of you\n";
			cout << "You can go North or East or West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;


			if (input.compare("go north") == 0)
			{
				area = 14;
			}
			if (input.compare("go east") == 0)
			{
				area = 3;
			}
			if (input.compare("go west") == 0)
			{
				area = 16;
			}
			if (input.compare("go south") == 0)
			{
				area = 28;
			}

			break;

		case 28:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			if (level < 5)
			{
				cout << "You feel a creepy vibe coming from the southern direction.\n";
				cout << "Maybe it's best not to go that way.\n";
			}
			cout << "You can go North or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 27;
			}
			if (input.compare("go south") == 0)
			{
				area = 44;
			}

			break;

		case 29:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "You smell the salty sea south of you.\n";
			cout << "You can go North or East or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go south") == 0)
			{
				area = 30;
			}
			if (input.compare("go north") == 0)
			{
				area = 4;
			}
			if (input.compare("go east") == 0)
			{
				area = 46;
			}

			break;

		case 30:

			seaGameWindow();

			cout << "You've made it to the docks.\n\n";

			npcGenerator(7);

			if (inventory[4].compare("Boat") == 0)
			{
				cout << "You can go North\n";
				cout << "OR\n";
				cout << "You can travel South onto rough waters\n\n";
			}
			else
			{
				cout << "You can go North\n\n";
			}

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 29;
			}
			if (input.compare("go south") == 0 && inventory[4].compare("Boat") == 0)
			{
				area = 31;
			}
			if (input.compare("go south") == 0 && inventory[4].compare("Boat") != 0)
			{
				cout << "Sorry, doesn't seem like you can travel onto rough waters yet." << endl;
				cout << "Consider getting a boat." << endl << endl;
			}

			break;

		case 31:

			monsterGenerator(3);

			cout << "You're sailing on rough waters!" << endl;
			cout << "You can go back to the docks North" << endl;
			cout << "OR" << endl;
			cout << "Continue sailing East or South" << endl << endl;

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 30;
			}
			if (input.compare("go east") == 0)
			{
				area = 32;
			}
			if (input.compare("go south") == 0)
			{
				area = 33;
			}

			break;

		case 32:

			monsterGenerator(3);

			cout << "You're sailing on rough waters!" << endl;
			cout << "You can sail West or South" << endl << endl;

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 31;
			}
			if (input.compare("go south") == 0)
			{
				area = 34;
			}

		case 33:

			monsterGenerator(3);

			cout << "You're sailing on rough water!" << endl;
			cout << "You can sail North or East" << endl << endl;

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 31;
			}
			if (input.compare("go east") == 0)
			{
				area = 34;
			}

		case 34:

			monsterGenerator(3);

			cout << "You're sailing on rough waters!" << endl;
			cout << "You can sail North or West" << endl << endl;

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 32;
			}
			if (input.compare("go west") == 0)
			{
				area = 33;
			}

			break;

		case 35:

			forestGameWindow();
			cout << "You find yourself in a forest.\n";
			cout << "You can see a graveyard in the distance towards the East direction\n";
			cout << "You can go West or East\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 12;
			}
			if (input.compare("go east") == 0)
			{
				area = 36;
			}

			break;

		case 36:

			cout << "You've made it to the front gate of the graveyard.\n";
			cout << "There is a sign that says,\n\n";
			cout << "<--- DANGER! TOMB OF NAZARIK AHEAD!\n\n";
			cout << "You can proceed East\n";
			cout << "OR\n";
			cout << "Go back West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 35;
			}
			if (input.compare("go east") == 0)
			{
				area = 37;
			}

			break;

		case 37:

			cout << "You're on a pathway within the graveyard.\n";
			cout << "Tombstones are plenty within the graveyard and it is all you see to the North and South of you.\n";
			cout << "You can go North or West or East or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 38;
			}
			if (input.compare("go south") == 0)
			{
				area = 40;
			}
			if (input.compare("go east") == 0)
			{
				area = 42;
			}
			if (input.compare("go west") == 0)
			{
				area = 36;
			}

			break;

		case 38:

			monsterGenerator(5);

			cout << "You walk through a field of graveyards.\n";
			cout << "You can go East or South.\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go south") == 0)
			{
				area = 37;
			}
			if (input.compare("go east") == 0)
			{
				area = 39;
			}

			break;

		case 39:

			monsterGenerator(5);

			cout << "You walk through a field of graveyards.\n";
			cout << "You can go West or South.\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go south") == 0)
			{
				area = 42;
			}
			if (input.compare("go west") == 0)
			{
				area = 38;
			}

			break;

		case 40:

			monsterGenerator(5);

			cout << "You walk through a field of graveyards.\n";
			cout << "You can go North or east.\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 37;
			}
			if (input.compare("go east") == 0)
			{
				area = 41;
			}

			break;

		case 41:

			monsterGenerator(5);

			cout << "You walk through a field of graveyards.\n";
			cout << "You can go North or West.\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 42;
			}
			if (input.compare("go west") == 0)
			{
				area = 40;
			}

			break;

		case 42:

			cout << "You're on a pathway within the graveyard.\n";
			cout << "Fog starts to grow around this area.\n";
			cout << "You start to see a stone structure past the fog towards East.\n";
			cout << "You can go North or West or East or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 39;
			}
			if (input.compare("go south") == 0)
			{
				area = 41;
			}
			if (input.compare("go east") == 0)
			{
				area = 43;
			}
			if (input.compare("go west") == 0)
			{
				area = 37;
			}

			break;

		case 43:

			cout << "You stand in front of a monument named 'The Great Tomb of Nazarik'\n";
			cout << "You can go into the Tomb\n";
			cout << "OR\n";
			cout << "You can go West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 42;
			}
			if (input.compare("go into tomb") == 0)
			{
				tombOfNazarik(skeletonsKilled);
			}

			break;

		case 46:

			monsterGenerator(4);

			cout << "You find yourself in a forest.\n";
			cout << "There seem to be claw marks on the trees around you.\n";
			cout << "You can go North or East or West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go north") == 0)
			{
				area = 48;
			}
			if (input.compare("go west") == 0)
			{
				area = 29;
			}
			if (input.compare("go east") == 0)
			{
				area = 47;
			}

			break;

		case 47:

			monsterGenerator(4);

			cout << "You find yourself in a forest.\n";
			cout << "There seem to be claw marks on the trees around you.\n";
			cout << "You can go West\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 46;
			}

			break;

		case 48:

			monsterGenerator(4);

			cout << "You find yourself in a forest.\n";
			cout << "There seem to be claw marks on the trees around you.\n";
			cout << "You can go West or South\n\n";

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("go west") == 0)
			{
				area = 4;
			}
			if (input.compare("go south") == 0)
			{
				area = 46;
			}

			break;

		default:
			MessageBox(nullptr, TEXT("An error has occured"), TEXT("Exit"), MB_OK);
			return NULL;
			break;
		}

	} while (input.compare("quit") != 0 && lives != 0);

	if (input.compare("quit") == 0)
	{
		MessageBox(nullptr, TEXT("You quit! Thanks for playing"), TEXT("Quit"), MB_OK);
	}
}