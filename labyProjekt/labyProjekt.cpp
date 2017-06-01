// labyProjekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>



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
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	ShowConsoleCursor(false);
	system("MODE CON COLS=100 LINES=35");

	Menu menu1;
	if (menu1.showMenu() == 1) { system("cls");  return 0; }
	////////////////////////////////////
	
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
	Option option;
	option.showOption(k1);

	system("pause");
	return 0;
}