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
	
	//The variable needed to change the color of the font
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	//Set the size of the console
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("MODE CON COLS=170 LINES=45");
	
	//Function to remove the cursor
	ShowConsoleCursor(false);


	while (true)
	{
		Menu menu1;
		if (menu1.showMenu() == 3) { system("cls");  return 0; }

		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << endl << endl << endl << endl << endl << endl;
		cout << setw(90) << "Enter your Knight name: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		ShowConsoleCursor(true);
		string name;
		cin >> name;
		ShowConsoleCursor(false);

		system("cls");

		//////////////////////////////////////////
		//Creating all characters
		Knight knight1(name, 100);
		Weapon longSword("Long Sword", 15);

		Enemy enemy1("Skeleton", 50, 40, 10);
		Weapon rustySword("Rusty Sword", 10);

		Enemy enemy2("Undead Mage", 60, 45, 15);
		Weapon blackMagicWand("Black Magic Wand", 20);

		Enemy enemy3("Black Knight", 70, 50, 20);
		Weapon ironWarAxe("Iron War Axe", 30);


		//////////////////////////////////////////

		Option option;
		
		//First stage
		option.showOption(&knight1, enemy1, longSword, rustySword);
		option.showText(&knight1);
		if (knight1.health > 0) option.levelUp(&knight1);
		
		if (knight1.health > 0)
		{	
			//Second stage
			option.showOption(&knight1, enemy2, longSword, blackMagicWand);
			option.showText(&knight1);
			if (knight1.health > 0) option.levelUp(&knight1);

			if (knight1.health > 0)
			{
				//Third stage
				option.showOption(&knight1, enemy3, longSword, ironWarAxe);
				if (knight1.health > 0) option.congratulations();
			}
		}

		//When the hero dies, the game ends

		if (knight1.health <= 0)
		{
			option.gameOver();
		}

		Sleep(200);
	}

	return 0;
}