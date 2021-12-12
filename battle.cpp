#include "functions.h"

void battle(int monsterhealth, string monster)
{

	int playerDamage = rand() % 2 + 1;
	int manaCost;
	int monsterDamage;
	string input;
	int battleStart = rand() % 2 + 1;
	int monsterMissChance;

	while (monsterhealth > 0 && health > 0)
	{

		int chance = rand() % 101;
		int missChance = rand() % 101;

		cout << "-----------------------------------------------" << endl;
		if (playerName == "Player") {
			cout << "| Player: " << health << " HP" << "     " << "| " << monster << ": " << monsterhealth << " HP" << endl << endl;
		}
		else if (playerName != "Player") {
			if (playerOccupation.compare("Mage") == 0)
			{
				cout << playerName << ": " << health << " HP" << "     " << "| Mana:" << mana << "     " << "| " << monster << ": " << monsterhealth << " HP" << endl << endl;
			}
			else
			{
				cout << playerName << ": " << health << " HP" << "     " << "| " << monster << ": " << monsterhealth << " HP" << endl << endl;
			}
		}

		if (weapon != "Fist")
		{

			if (weapon.compare("Wooden Sword") == 0)
			{
				playerDamage = rand() % 7 + 4;
			}
			if (weapon.compare("Copper Sword") == 0)
			{
				playerDamage = rand() % 11 + 8;
			}
			if (weapon.compare("Ruby Gem Staff") == 0)
			{
				playerDamage = rand() % 13 + 8;
				manaCost = 10;
			}
			if (weapon.compare("Copper Daggers") == 0)
			{
				playerDamage = rand() & 9 + 8;
				missChance *= 1.4;
			}

		}

		if (monster.compare("Slime") == 0)
		{
			monsterDamage = rand() % 5 + 1;
			monsterMissChance = rand() % 101;
		}

		if (monster.compare("Slime King") == 0)
		{
			monsterDamage = rand() % 7 + 4;
			monsterMissChance = rand() % 151;
		}

		if (monster.compare("Kraken") == 0)
		{
			monsterDamage = rand() % 7 + 4;
			monsterMissChance = rand() % 151;
		}

		if (monster.compare("Ainz Ooal Gown") == 0)
		{
			monsterDamage = rand() % 8 + 5;
			monsterMissChance = rand() % 101;
		}

		if (monster.compare("Wolf") == 0)
		{
			monsterDamage = rand() % 5 + 1;
			monsterMissChance = rand() % 126;
		}

		if (monster.compare("Skeleton") == 0)
		{
			monsterDamage = rand() % 5 + 1;
			monsterMissChance = rand() % 101;
		}


		if (armor != " ")
		{
			if (armor.compare("Copper Armor") == 0)
			{
				monsterDamage *= .8;
			}
			if (armor.compare("Leather Robe") == 0)
			{
				playerDamage *= 1.15;
				mana = 110;
			}
			if (armor.compare("Wolf Hide") == 0)
			{
				monsterMissChance *= 1.5;
			}
		}

		if (barrier == TRUE)
		{
			monsterDamage *= .8;
			monsterMissChance * 1.1;
		}

		if (battleStart == 1)
		{

			cout << "> ";
			getline(cin, input);

			cout << endl;

			if (input.compare("attack") == 0)
			{
				if (missChance <= 20)
				{
					cout << "You missed your attack!" << endl << endl;
				}
				else if (weapon.compare("Fist") == 0)
				{
					cout << "You hit the " << monster << " for " << playerDamage << endl << endl;
					monsterhealth -= playerDamage;
				}
				else if (weapon.compare("Wooden Sword") == 0)
				{
					cout << "You slash the " << monster << " for " << playerDamage << " with your " << weapon << "." << endl << endl;
					monsterhealth -= playerDamage;
				}
				else if (playerOccupation.compare("Knight") == 0 || playerOccupation.compare("Civilian") == 0)
				{
					if (weapon.compare("Copper Sword") == 0)
					{
						cout << "You slash the " << monster << " for " << playerDamage << " with your " << weapon << "." << endl << endl;
						monsterhealth -= playerDamage;
					}
				}
				else if (playerOccupation.compare("Mage") == 0)
				{
					if (mana <= 0)
					{
						cout << "You have no mana to cast anything!" << endl << endl;
					}
					else if (weapon.compare("Ruby Gem Staff") == 0)
					{
						cout << "You used a fireball on the " << monster << " using up " << manaCost << " mana doing " << playerDamage << " damage." << endl << endl;
						monsterhealth -= playerDamage;
						mana -= manaCost;
					}
				}
				else if (playerOccupation.compare("Assassin") == 0)
				{
					if (weapon.compare("Copper Daggers") == 0)
					{
						cout << "You throw your " << weapon << " at the " << monster << " dealing " << playerDamage << "." << endl << endl;
						monsterhealth -= playerDamage;
					}
				}
			}
			if (input.compare("run") == 0)
			{
				if (chance <= 40)
				{
					monsterhealth = 0;
					cout << "You ran away" << endl << endl;;
				}
				else
				{
					cout << "You couldn't run away!" << endl;
					if (monsterMissChance <= 20)
					{
						cout << "The " << monster << " missed their attack!" << endl << endl;
					}
					else
					{
						cout << "The " << monster << " hit you for " << monsterDamage << endl << endl;
						health -= monsterDamage;
					}
				}
			}
			if (input.compare("potion") == 0) {
				cout << "Here is your list of potions." << endl;
				for (int i = 1; i <= 3; i++)
				{
					cout << i << ".) " << inventory[i] << endl;
				}
				cout << endl;
				cout << "Choose one of the following potions to use." << endl << endl;

				cout << "> ";
				getline(cin, input);

				if (input.compare("health potion") == 0)
				{
					if (inventory[1].compare("Health Potion") == 0)
					{
						health += 50;
						cout << "You've used up your health potion and healed 50 HP!" << endl;
						inventory[1] = " ";
					}
					else
					{
						cout << "You don't have anything to heal with!" << endl;
					}
				}
				if (input.compare("damage potion") == 0)
				{
					if (inventory[2].compare("Damage Potion") == 0)
					{
						playerDamage += 5;
						cout << "You drank you damage potion to gain an extra 5 damage!" << endl;
						inventory[2] = " ";
					}
					else
					{
						cout << "You don't have a damage potion!" << endl;
					}
				}
				if (input.compare("agility potion") == 0)
				{
					if (inventory[3].compare("Agility Potion") == 0)
					{
						monsterMissChance *= 1.25;
						missChance *= 1.25;
						inventory[3] = " ";
					}
					else
					{
						cout << "You don't have an agility potion!" << endl;
					}
				}
				if (input.compare("mana potion") == 0)
				{

					if (inventory[3].compare("Mana Potion") == 0)
					{
						mana += 50;
						inventory[3] = " ";
					}
					else
					{

						cout << "You don't have a mana potion!" << endl;

					}
				}

			}
			if (input.compare("run") != 0)
			{
				if (monsterMissChance <= 20)
				{
					cout << "The " << monster << " missed their attack!" << endl << endl;
				}
				else
				{
					cout << "The " << monster << " hit you for " << monsterDamage << endl << endl;
					health -= monsterDamage;
				}
			}
			system("pause");
		}
		if (battleStart == 2)
		{

			if (monsterMissChance <= 20)
			{
				cout << "The " << monster << " missed their attack!" << endl << endl;
			}
			else
			{
				cout << "The " << monster << " hit you for " << monsterDamage << endl << endl;
				health -= monsterDamage;
			}


			cout << "> ";
			getline(cin, input);

			cout << endl;

			if (input.compare("attack") == 0)
			{
				if (missChance <= 20)
				{
					cout << "You missed your attack!" << endl << endl;
				}
				else if (weapon.compare("Fist") == 0)
				{
					cout << "You hit the " << monster << " for " << playerDamage << endl << endl;
					monsterhealth -= playerDamage;
				}
				else if (weapon.compare("Wooden Sword") == 0)
				{
					cout << "You slash the " << monster << " for " << playerDamage << " with your " << weapon << "." << endl << endl;
					monsterhealth -= playerDamage;
				}
				else if (playerOccupation.compare("Knight") == 0 || playerOccupation.compare("Civilian") == 0)
				{
					if (weapon.compare("Copper Sword") == 0)
					{
						cout << "You slash the " << monster << " for " << playerDamage << " with your " << weapon << "." << endl << endl;
						monsterhealth -= playerDamage;
					}
				}
				else if (playerOccupation.compare("Mage") == 0)
				{
					if (mana <= 0)
					{
						cout << "You have no mana to cast anything!" << endl << endl;
					}
					else if (weapon.compare("Ruby Gem Staff") == 0)
					{
						cout << "You used a fireball on the " << monster << " using up " << manaCost << " mana doing " << playerDamage << " damage." << endl << endl;
						monsterhealth -= playerDamage;
						mana -= manaCost;
					}
				}
				else if (playerOccupation.compare("Assassin") == 0)
				{
					if (weapon.compare("Copper Daggers") == 0)
					{
						cout << "You throw your " << weapon << " at the " << monster << " dealing " << playerDamage << "." << endl << endl;
						monsterhealth -= playerDamage;
					}
				}
			}
			if (input.compare("run") == 0)
			{
				if (chance <= 40)
				{
					monsterhealth = 0;
					cout << "You ran away" << endl << endl;;
				}
				else
				{
					cout << "You couldn't run away!" << endl;
					if (monsterMissChance <= 20)
					{
						cout << "The " << monster << " missed their attack!" << endl << endl;
					}
					else
					{
						cout << "The " << monster << " hit you for " << monsterDamage << endl << endl;
						health -= monsterDamage;
					}
				}
			}
			if (input.compare("potion") == 0) {
				cout << "Here is your list of potions." << endl;
				for (int i = 1; i <= 3; i++)
				{
					cout << i << ".) " << inventory[i] << endl;
				}
				cout << endl;
				cout << "Choose one of the following potions to use." << endl << endl;

				cout << "> ";
				getline(cin, input);

				if (input.compare("health potion") == 0)
				{
					if (inventory[1].compare("Health Potion") == 0)
					{
						health += 50;
						cout << "You've used up your health potion and healed 50 HP!" << endl;
						inventory[1] = " ";
					}
					else
					{
						cout << "You don't have anything to heal with!" << endl;
					}
				}
				if (input.compare("damage potion") == 0)
				{
					if (inventory[2].compare("Damage Potion") == 0)
					{
						playerDamage += 5;
						cout << "You drank you damage potion to gain an extra 5 damage!" << endl;
						inventory[2] = " ";
					}
					else
					{
						cout << "You don't have a damage potion!" << endl;
					}
				}
				if (input.compare("agility potion") == 0)
				{
					if (inventory[3].compare("Agility Potion") == 0)
					{
						monsterMissChance *= 1.25;
						missChance *= 1.25;
						inventory[3] = " ";
					}
					else
					{
						cout << "You don't have an agility potion!" << endl;
					}
				}
				if (input.compare("mana potion") == 0)
				{

					if (inventory[3].compare("Mana Potion") == 0)
					{
						mana += 50;
						inventory[3] = " ";
					}
					else
					{

						cout << "You don't have a mana potion!" << endl;

					}
				}

			}
			cout << endl;
			system("pause");
		}
	}

	if (health <= 0) {
		cout << "-----------------------------------------------" << endl;
		cout << "You died!" << endl;
		if (respawn == TRUE) {
			cout << "You've have received the blessing of the statue." << endl;
			lives -= 1;
			cout << "You have " << lives << " remaining lives left." << endl;
			area = 10;
			cout << "You soul is being taken back to the statue." << endl;
			cout << "You will shortly respawn at the statue of 'Masadora'" << endl << endl;
			health = 100;
		}
		if (respawn == FALSE) {
			lives = 0;
			if (lives == 0)
			{
				MessageBox(nullptr, TEXT("You have no more lives!"), TEXT("GAME OVER"), MB_OK);
				exit(0);
			}
		}
	}

	if (monsterhealth <= 0 && input.compare("run") != 0)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "You defeated the " << monster << "!" << endl;
		itemDropper(monster);
		system("pause");
		cout << endl;
	}

}

void itemDropper(string monster)
{

	int droprate = rand() % 101;
	int expdrop;
	int koldrop;

	if (droprate <= 90 && monster == "Slime")
	{
		koldrop = rand() % 6;
		expdrop = rand() % 11 + 15;
		cout << "You gained " << expdrop << " exp, Slime Secretion and " << koldrop << " Kol." << endl;
		slimeSecretion += 1;
		kol += koldrop;
		levelCounter += expdrop;
		cout << "-----------------------------------------------" << endl;
	}

	if (monster == "Slime King")
	{
		koldrop = rand() % 51 + 50;
		expdrop = rand() % 51 + 25;
		cout << "You gained " << expdrop << " exp, the Slime King Crown and " << koldrop << " Kol." << endl;
		inventory[5] = "Slime King Crown";
		kol += koldrop;
		levelCounter += expdrop;
		if (questTrue[0] != FALSE)
		{
			questTrue[0] = FALSE;
		}
		cout << "-----------------------------------------------" << endl;
	}

	if (monster == "Kraken")
	{
		koldrop = rand() % 26 + 25;
		expdrop = rand() % 51 + 25;
		cout << "You gained " << expdrop << " exp, Kraken Ink and " << koldrop << " Kol." << endl;
		inventory[5] = "Kraken Ink";
		kol += koldrop;
		levelCounter += expdrop;
		if (questTrue[1] != FALSE)
		{
			questTrue[1] = FALSE;
		}
		cout << "-----------------------------------------------" << endl;
	}

	if (droprate <= 85 && monster == "Skeleton")
	{
		koldrop = rand() % 6;
		expdrop = rand() % 11 + 15;
		cout << "You gained " << expdrop << " exp and " << koldrop << " Kol." << endl;
		skeletonsKilled += 1;
		kol += koldrop;
		levelCounter += expdrop;
		cout << "-----------------------------------------------" << endl;
	}

	if (monster == "Ainz Ooal Gown")
	{
		koldrop = rand() % 26 + 25;
		expdrop = rand() % 51 + 25;
		cout << "You gained " << expdrop << " exp, the Staff of Ainz Ooal Gown and " << koldrop << " Kol." << endl;
		inventory[5] = "Staff of Ainz Ooal Gown";
		kol += koldrop;
		levelCounter += expdrop;
		skeletonsKilled = 0;
		if (questTrue[2] != FALSE)
		{
			questTrue[2] = FALSE;
		}
		cout << "-----------------------------------------------" << endl;
	}

	if (droprate <= 40 && monster == "Hellhound")
	{
		koldrop = rand() % 15 + 1;
		expdrop = rand() % 31 + 15;
		cout << "You gained " << expdrop << " exp and " << koldrop << " Kol." << endl;
		kol += koldrop;
		levelCounter += expdrop;
		cout << "-----------------------------------------------" << endl;
	}

	if (levelCounter >= levelBar)
	{
		level += 1;
		levelBar *= 1.1;
		levelCounter = 0;
		cout << "You leveled up!" << endl;
		cout << "You now need " << levelBar << " EXP to level up again!" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

void monsterGenerator(int monster)
{

	int num = rand() % 100 + 1;

	if (monster == 1 && num <= 40)
	{
		cout << "You've encountered a slime!" << endl << endl;
		battle(30, "Slime");
	}

	if (monster == 2)
	{
		cout << "You pour the slime secretion onto the Altar and something unexpected happens." << endl;
		cout << "The slime secretion starts to expand." << endl;
		cout << "You've summoned the Slime King!" << endl << endl;
		battle(150, "Slime King");
	}

	if (monster == 3 && num <= 10)
	{
		cout << "A mythical deep sea creature comes from the depths and appears in front of you!" << endl;
		cout << "It's the Kraken!" << endl << endl;
		battle(150, "Kraken");
	}

	if (monster == 4 && num <= 40)
	{
		cout << "You've encountered a wolf!" << endl << endl;
		battle(40, "Wolf");
	}

	if (monster == 5 && num <= 40)
	{
		cout << "A skeleton has appeared from one of the graves!" << endl << endl;
		battle(25, "Skeleton");
	}

	if (monster == 6)
	{
		cout << "| Boss: Ainz Ooal Gown\n\n";
		cout << "| You stand before the great Ainz Ooal Gown.\n";
		cout << "| You've taken the souls of my comrades and now you will pay!\n\n";

		cout << "Ainz Ooal Gown summons skeletons on you.\n\n";
		battle(25, "Skeleton");

		cout << "Another Skeleton appears!\n\n";
		battle(25, "Skeleton");

		cout << "Ainz Ooal Gown finally appears!\n\n";
		battle(100, "Ainz Ooal Gown");

	}

	if (monster == 7)
	{
		cout << "You've encountered a hellhound!" << endl << endl;
		battle(80, "Hellhound");
	}

	
}