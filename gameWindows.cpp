#include "functions.h"

void masadoraGameWindow()
{

	LPCWSTR a = L"The City of Masadora";
	LPCSTR b = "The City of Masadora";
	SetConsoleTitle(a);

	system("COLOR E8");
}

void forestGameWindow()
{

	LPCWSTR a = L"The Forest";
	LPCSTR b = "The Forest";
	SetConsoleTitle(a);

	system("COLOR 21");
}

void slimeGameWindow()
{

	LPCWSTR a = L"The Slime Sector";
	LPCSTR b = "The Slime Sector";
	SetConsoleTitle(a);

	system("COLOR A1");
}

void seaGameWindow()
{

	LPCWSTR a = L"Rough Waters";
	LPCSTR b = "Rough Waters";
	SetConsoleTitle(a);

	system("COLOR 17");

}

void portalGameWindow()
{

	LPCWSTR a = L"Portal";
	LPCSTR b = "Portal";
	SetConsoleTitle(a);

	system("COLOR 0D");

}