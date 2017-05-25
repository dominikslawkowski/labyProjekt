// labyProjekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>

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
	ShowConsoleCursor(false);
	system("MODE CON COLS=100 LINES=35");
	Menu menu1;
	menu1.showMenu();
	////////////////////////////////////
	string name;
	cout << "Enter your Knight name: "; cin >> name;
	Knight knight1(name);
	
	system("cls");

	CharacterInterface test;
	test.showCharacterInterface(knight1);

	system("pause");
	return 0;
}

