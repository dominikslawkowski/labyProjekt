// labyProjekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; //set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}



int main()
{
	
	//zmienna potrzebna do zmiany koloru czcionki
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	//ustawienie rozmiarow konsoli
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("MODE CON COLS=100 LINES=40");
	
	//funkcja usuwajaca kursor
	ShowConsoleCursor(false);

	////////////////////////////////////
	Menu menu1;
	if (menu1.showMenu() == 1) { system("cls");  return 0; }
	
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << endl;
	cout << setw(55) << "Enter your Knight name: "; 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	ShowConsoleCursor(true);
	string name;
	cin >> name;
	ShowConsoleCursor(false);

	system("cls");

	Knight k1(name);
	Enemy e1("Skeleton");
	Option option;

	while (1)
	{
		option.showOption(k1, e1);
		system("cls");
	}

	system("pause");
	return 0;
}