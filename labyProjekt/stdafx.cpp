// stdafx.cpp : source file that includes just the standard includes
// labyProjekt.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>


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
		cout << endl <<endl <<endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << setw(95) << "Dungeon Adventure v1.0"; cout << setw(60) << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << endl << endl;
		cout << setw(80) << pointer2[0] << " Start " << pointer[0] << endl << endl;
		cout << setw(77) << pointer2[1] << " Score Board " << pointer[1] << endl << endl;
		cout << setw(80) << pointer2[2] << " About " << pointer[2] << endl << endl;
		cout << setw(80) << pointer2[3] << " Exit ? " << pointer[3] << endl << endl;

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

void CharacterInterface::showCharacterInterface(Knight knight1, Weapon knightWeapon)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "______________________" << endl;
	cout << "|"; 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); 
	cout << setw(13) <<"Knight"<<setw(8); 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << "|Name: " << knight1.name << setw(15 - knight1.name.length()) << "|" << endl;
	cout << "|HP: " << knight1.health << setw(14) << "|" << endl;
	cout << "|Fear: " << knight1.fear <<setw(14) <<"|"<< endl;
	cout << "|____________________|" << endl;
	cout << "|";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "     Attributes     ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << "|Level: " << knight1.level << setw(13)<<"|" << endl;
	cout << "|Strenght: " << knight1.strenght <<setw(9) <<"|" << endl;
	cout << "|Fencing: " << knight1.fencing <<setw(10) <<"|" << endl;
	cout << "|_____Equipment______|" << endl;
	cout << "|" << knightWeapon.name<<setw(11)<<"|" << endl;
	cout << "|+"<<knightWeapon.boost<<" damage"<<setw(11)<<"|" << endl;
	cout << "|Potions: " << knight1.potions << setw(11)<<"|" << endl;
	cout << "|____________________|" << endl;
}

void CharacterInterface::showEnemyInterface(Enemy enemy1, Weapon enemyWeapon)
{

	cout << "______________________" << endl;
	cout << "|";
	
	cout << setw(13) << "Enemy" << setw(8); cout << "|" << endl;
	cout << "|Name: " << enemy1.name << setw(15 - enemy1.name.length()) << "|" << endl;
	cout << "|HP: " << enemy1.health; if (enemy1.health == 100)cout << setw(14); else if (enemy1.health < 10)cout << setw(16); else  cout << setw(15); cout << "|" << endl;
	cout << "|____________________|" << endl;
	cout << "|     Attributes     |" << endl;
	cout << "|Level: " << enemy1.level << "            |" << endl;
	cout << "|Strenght: " << enemy1.strenght << "        |" << endl;
	cout << "|Terror: " << enemy1.terror << "          |" << endl;
	cout << "|_____Equipment______|" << endl;
	cout << "|" << enemyWeapon.name << "         |" << endl;
	cout << "|+" << enemyWeapon.boost << " damage          |" << endl;
	cout << "|____________________|" << endl;
}

void Option::showOption(Knight knight1, Enemy enemy1, Weapon knightWeapon, Weapon enemyWeapon)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char pointer[4] = { '<',' ',' ',' ' };
	char pointer2[4] = { '>',' ',' ',' ' };
	int i = 0;
	int exit = 1;
	CharacterInterface test;
	string info;

	while (exit)
	{
		system("cls");
		test.showCharacterInterface(knight1, knightWeapon);
		
		cout << endl;

		cout << info;

		cout << endl;

		if (enemy1.health > 0) { test.showEnemyInterface(enemy1, enemyWeapon); }
		else {  }

		cout << endl;

		cout << setw(6) << pointer2[0] << " Attack " << pointer[0] << endl << endl;
		cout << setw(6) << pointer2[1] << " Defense " << pointer[1] << endl << endl;
		cout << setw(4) << pointer2[2] << " Drink Potion " << pointer[2] << endl << endl;
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
			if (i == 0)
			{
				srand(time(NULL));
				info = "You attacked your opponent!";
				enemy1.health -= (rand() % (knight1.fencing)/10) + knightWeapon.boost - knight1.fear;
			}
			else if (i == 1)
			{
				info = "You defend yourself.";
			}
			else if (i == 2)
			{
				if (knight1.potions <= 0) info = "You have no potions.";
				else if (knight1.health >= 100) info = "You have full health points.";
				else
				{
					knight1.health += 10;
					knight1.potions--;
					info = "You drank a potion.";
				}
			}

		} break;

		}

	}
}



