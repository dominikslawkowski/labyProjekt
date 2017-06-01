// stdafx.cpp : source file that includes just the standard includes
// labyProjekt.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int Menu::showMenu()
{
	int exit = 1;
	char pointer[4] = { '<',' ',' ',' ' };
	char pointer2[4] = { '>',' ',' ',' ' };
	int i = 0;

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (exit)
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << setw(60) << "Dungeon Adventure v1.0"; cout << setw(60) << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << setw(45) << pointer2[0] << " Start " << pointer[0] << endl << endl;
		cout << setw(42) << pointer2[1] << " Score Board " << pointer[1] << endl << endl;
		cout << setw(45) << pointer2[2] << " About " << pointer[2] << endl << endl;
		cout << setw(44) << pointer2[3] << " Exit :( " << pointer[3] << endl << endl;

		switch (_getch())
		{
		case 72:
			if (i == 0)
			{
				pointer[3] = pointer[i];
				pointer[i] = ' ';
				pointer2[3] = pointer2[i];
				pointer2[i] = ' ';

				i = 3;
			}
			else
			{
				pointer[i - 1] = pointer[i];
				pointer[i] = ' ';
				pointer2[i - 1] = pointer2[i];
				pointer2[i] = ' ';
				i--;
			} break;

		case 80:
			if (i == 3)
			{
				pointer[0] = pointer[i];
				pointer[i] = ' ';
				pointer2[0] = pointer2[i];
				pointer2[i] = ' ';
				i = 0;
			}
			else
			{
				pointer[i + 1] = pointer[i];
				pointer[i] = ' ';
				pointer2[i + 1] = pointer2[i];
				pointer2[i] = ' ';
				i++;
			} break;

		case 13:
			if (i == 0)
			{ system("cls"); return 0; }
			else if (i == 3) { return 1; }
			break;


		}
		
	}
}

void CharacterInterface::showCharacterInterface(Knight k1)
{
	Weapon longSword("Long Sword", 10, 35);

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "______________________" << endl;
	cout << "|"; 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	cout << setw(13) <<"Knight"<<setw(8); 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << "|Name: " << k1.name << setw(15 - k1.name.length()) << "|" << endl;
	cout << "|HP: " << k1.health << setw(14) << "|" << endl;
	cout << "|Fear: " << k1.fear <<setw(14) <<"|"<< endl;
	cout << "|____________________|" << endl;
	cout << "|";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "     Attributes     ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << "|Level: " << k1.level << "            |" << endl;
	cout << "|Strenght: " << k1.strenght << "        |" << endl;
	cout << "|Fencing: " << k1.fencing << "         |" << endl;
	cout << "|_____Equipment______|" << endl;
	cout << "|" << longSword.name<<"          |" << endl;
	cout << "|+"<<longSword.boost<<" damage          |" << endl;
	cout << "|____________________|" << endl;
}

void Option::showOption(Knight k1)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char pointer[4] = { '<',' ',' ',' ' };
	char pointer2[4] = { '>',' ',' ',' ' };
	int i = 0;
	int exit = 1;
	
	while (exit)
	{
		system("cls");
		CharacterInterface test;
		test.showCharacterInterface(k1);
		cout << endl;

		cout << setw(6) << pointer2[0] << " opcja1 " << pointer[0] << endl << endl;
		cout << setw(6) << pointer2[1] << " opcja2 " << pointer[1] << endl << endl;
		cout << setw(6) << pointer2[2] << " opcja3 " << pointer[2] << endl << endl;
		cout << setw(6) << pointer2[3] << " opcja4 " << pointer[3] << endl << endl;

		switch (_getch())
		{
		case 72:
			if (i == 0)
			{
				pointer[3] = pointer[i];
				pointer[i] = ' ';
				pointer2[3] = pointer2[i];
				pointer2[i] = ' ';
				i = 3;
			}
			else
			{
				pointer[i - 1] = pointer[i];
				pointer[i] = ' ';
				pointer2[i - 1] = pointer2[i];
				pointer2[i] = ' ';
				i--;
			} break;

		case 80:
			if (i == 3)
			{
				pointer[0] = pointer[i];
				pointer[i] = ' ';
				pointer2[0] = pointer2[i];
				pointer2[i] = ' ';
				i = 0;
			}
			else
			{
				pointer[i + 1] = pointer[i];
				pointer[i] = ' ';
				pointer2[i + 1] = pointer2[i];
				pointer2[i] = ' ';
				i++;
			} break;

		case 13:
		{
			

		} break;

		}

	}
}



