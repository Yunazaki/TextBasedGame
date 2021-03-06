#include "functions.h"

void commands(string input) // Calling all of the command functions
{

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
	if (input.compare("map") == 0)
	{
		map();
		cout << endl;
		system("pause");
		cout << "-----------------------------------------------" << endl;
	}
	if (input.compare("health potion") == 0)
	{
		healthPotion();
		cout << endl;
		system("pause");
		cout << "-----------------------------------------------" << endl;
	}

}

void checkInventory() // Prints inventory
{

	cout << "Here is your Inventory: \n\n";
	cout << "Weapon: " << weapon << endl;
	if (armor != " ")
	{
		cout << "Armor: " << armor << endl;
	}
	cout << "Kol: " << kol << endl;
	for (int i = 0; i < 10; i++)
	{

		cout << i + 1 << ".) " << inventory[i] << endl;
	}

	cout << endl;
}

void checkQuest() // Check the current quest the player has
{

	string input;

	if (questTrue[0] != TRUE && questTrue[1] != TRUE && questTrue[2] != TRUE && questTrue[3] != TRUE && questTrue[4] != TRUE) {
		cout << "You currently don't have a quest." << endl << endl;
	}

	for (int i = 0; i < 5; i++) {
		if (questTrue[i] == TRUE) {
			cout << "Current Quest: " << quest[i] << endl << endl;
		}

		if (questTrue[i] == TRUE) {
			cout << "Would you like to give up on your quest?" << endl << endl;

			cout << "> ";
			getline(cin, input);
			cout << endl;

			if (input.compare("yes") == 0) {
				for (int i = 0; i < 5; i++) {
					questTrue[i] = FALSE;
				}
			}
		}
	}
}

void help() // Help function to assist player
{

	cout << endl;
	cout << "| The commands available for general exploration are:" << endl;
	cout << "| go (direction)" << endl;
	cout << "| go through (something)" << endl;
	cout << "| go into (place)" << endl;
	cout << "| go to (place)" << endl;
	cout << "| fight (something)" << endl;
	cout << "| leave" << endl;
	cout << "| inventory" << endl;
	cout << "| quest" << endl;
	cout << "| pick up (item)" << endl;
	cout << "| buy (item)" << endl;
	cout << endl;

	cout << "-----------------------------------------------" << endl << endl;

	cout << "| The commands available for combat are:" << endl;
	cout << "| attack" << endl;
	cout << "| run" << endl;
	cout << "| potion" << endl;
	cout << endl;

	cout << "-----------------------------------------------" << endl << endl;

	cout << "| If you get lost on a quest and don't know what you need to do" << endl;
	cout << "| Try to find the NPC 'Rimuru' who should be roaming around Masadora." << endl;
	cout << endl;

}

void map() 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 16; j++) {
			cout << maps[i][j];
		}
		cout << endl;
	}
}

void healthPotion() // Use health potion
{
	if (inventory[1].compare("Health Potion") == 0)
	{
		if (health > 50)
		{
			for (int i = health; i <= 100; i++) // Health Potion doesn't heal past 100
			{
				health++;
			}
			cout << "You've used up your health potion and healed back to 100 HP!" << endl;
			inventory[1] = " ";
		}
		else
		{
			health += 50;
			cout << "You've used up your health potion and healed 50 HP!" << endl;
			inventory[1] = " ";
		}
	}
	else
	{
		cout << "You don't have anything to heal with!" << endl;
	}
}