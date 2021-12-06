#include "functions.h"

void checkInventory()
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

void checkQuest()
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

void help()
{

	cout << "| The commands available to you are:" << endl;
	cout << "| go (direction)" << endl;
	cout << "| go through (something)" << endl;
	cout << "| go into (place)" << endl;
	cout << "| inventory" << endl;
	cout << "| quest" << endl;
	cout << "| pick up (item)" << endl;

}