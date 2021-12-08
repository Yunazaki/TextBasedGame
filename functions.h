#pragma once


#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>


using namespace std;

extern string playerName;
extern string playerOccupation;
extern string playerClass;
extern string inventory[10];
extern string weapon;
extern string armor;
extern string quest[5];
extern bool questTrue[5];


extern int level;
extern int levelBar;
extern int levelCounter;

extern int kol; //currency
extern int slimeSecretion;
extern int skeletonsKilled;

extern int area;
extern int lives;
extern int health;
extern int mana;
extern int turns;
extern bool respawn;

extern char maps[8][16];

void masadoraGameWindow();

void forestGameWindow();

void slimeGameWindow();

void seaGameWindow();

void portalGameWindow();

void commands(string);

void checkInventory();

void checkQuest();

void help();

void map();

void monsterGenerator(int);

void battle(int, string);

void npcGenerator(int);

void itemDropper(string);

void adventurersGuild();

void tombOfNazarik(int);

void castle();

void underworld();

void townShops(int);