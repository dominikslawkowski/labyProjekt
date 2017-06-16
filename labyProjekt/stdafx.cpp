// stdafx.cpp : source file that includes just the standard includes
// labyProjekt.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>


using namespace std;
///////////////////////////////////////////////////////////////////////////////////////

void Knight::Attack(Knight *knight, Weapon knightWeapon, Enemy *enemy)
{
	int sleepTime = 1500;
	
	srand(time(NULL));
	int damage = (rand() % (knight->fencing) / 10) + (knight->strenght/10) + knightWeapon.boost - knight->fear[fearCounter];
	enemy->health -= damage;
	cout << "You attacked your opponent! Your damage: " << damage << endl << endl;
	
	Sleep(sleepTime);
}

void Enemy::Action(Enemy enemy, Knight *knight, Weapon enemyWeapon, bool lastKnightAction)
{
	int chooseAction = rand() % 21 - 10;

	if (chooseAction > 0 && lastKnightAction == FALSE && knight->fearCounter <= 4)
	{
		knight->fearCounter++;
		cout << "Your opponent scared you. + 1 to level of Fear" << endl;
	}

	else
	{
		if (lastKnightAction == TRUE)
		{
			int attackNerf = 15;
			int damage = ((rand() % (enemy.strenght) / 10) + enemyWeapon.boost) - attackNerf;
			knight->health -= damage;
			cout << "Your opponent attacked. His damage: " << damage << endl << endl;
		}
		else if (lastKnightAction == FALSE)
		{
			int damage = (rand() % (enemy.strenght) / 10) + enemyWeapon.boost;
			knight->health -= damage;
			cout << "Your opponent attacked. His damage: " << damage << endl << endl;
		}
	}
}

void Knight::Defence(Knight *knight)
{
	int sleepTime = 1500;

	if (knight->fearCounter <= 0)
	{
		cout << "Your knight does not feel fear." << endl << endl;
	}
	else
	{
	knight->fearCounter -= 1;
	cout << "You defend yourself. Your fear: " << knight->fear[fearCounter] << endl << endl;
	}
	Sleep(sleepTime);
}

void Knight::drinkPotion(Knight *knight)
{
	int sleepTime = 1500;

	if (knight->potions <= 0) { cout << "You have no potions." << endl << endl; }

	else if (knight->health >= 100) { cout << "You have full health points." << endl << endl; }

	else
	{
		knight->health += 10;
		knight->potions--;
		cout << "You drank a potion. + 10 HP" << endl << endl;
	}
	Sleep(sleepTime);
}

void Knight::useScroll(Knight *knight)
{
	int sleepTime = 1500;

	if (knight->scrolls <= 0) cout << "You have no scrolls." << endl;
	else
	{
		knight->scrolls--;
		knight->strenght += 10;
		knight->fearCounter = 0;
		cout << "You used the scroll of blessing! You dont feel Fear now and + 10 to Strength." << endl;
	}
	Sleep(sleepTime);
}

///////////////////////////////////////////////////////////////////////////////////////

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
		cout << setw(95) << "Dungeon Adventure v3.0"; cout << setw(60) << endl << endl;
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

///////////////////////////////////////////////////////////////////////////////////////

void CharacterInterface::showCharacterInterface(Knight *knight1, Weapon knightWeapon)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int margin = 70;

	cout << setw(margin) << ' ' << "______________________" << endl;
	cout << setw(margin) << ' ' << "|";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); 
							 cout <<"       Knight       ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << setw(margin) << ' ' << "|Name: " << knight1->name << setw(15 - knight1->name.length()) << "|" << endl;
	cout << setw(margin) << ' ' << "|HP: " << knight1->health; if (knight1->health == 100)cout << setw(14); else if (knight1->health < 10)cout << setw(16); else  cout << setw(15); cout << "|" << endl;
	cout << setw(margin) << ' ' << "|Fear: " << knight1->fear[knight1->fearCounter] <<setw(14) << "|" << endl;
	cout << setw(margin) << ' ' << "|____________________|" << endl;
	cout << setw(margin) << ' ' << "|";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
							 cout <<"     Attributes     ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); cout << "|" << endl;
	cout << setw(margin) << ' ' << "|Level: " << knight1->level << setw(13)<< "|" << endl;
	cout << setw(margin) << ' ' << "|Strenght: " << knight1->strenght <<setw(9) << "|" << endl;
	cout << setw(margin) << ' ' << "|Fencing: " << knight1->fencing <<setw(10) << "|" << endl;
	cout << setw(margin) << ' ' << "|_____Equipment______|" << endl;
	cout << setw(margin) << ' ' << "|" << knightWeapon.name<<" +" << knightWeapon.boost << " dmg  |" << endl;
	cout << setw(margin) << ' ' << "|Potions: " << knight1->potions << setw(11) << "|" << endl;
	cout << setw(margin) << ' ' << "|Scrolls: " <<knight1->scrolls << setw(11) << "|"<< endl;
	cout << setw(margin) << ' ' << "|____________________|" << endl;
}

void CharacterInterface::showEnemyInterface(Enemy enemy1, Weapon enemyWeapon)
{
	int margin = 70;

	cout << setw(margin) << ' ' << "______________________" << endl;
	cout << setw(margin) << ' ' << "|       Enemy        |" << endl;
	cout << setw(margin) << ' ' << "|Name: " << enemy1.name << setw(15 - enemy1.name.length()) << "|" << endl;
	cout << setw(margin) << ' ' << "|HP: " << enemy1.health; if (enemy1.health == 100)cout << setw(14); else if (enemy1.health < 10)cout << setw(16); else  cout << setw(15); cout << "|" << endl;
	cout << setw(margin) << ' ' << "|____________________|" << endl;
	cout << setw(margin) << ' ' << "|     Attributes     |" << endl;
	cout << setw(margin) << ' ' << "|Level: " << enemy1.level << "            |" << endl;
	cout << setw(margin) << ' ' << "|Strenght: " << enemy1.strenght << "        |" << endl;
	cout << setw(margin) << ' ' << "|Terror: " << enemy1.terror << "          |" << endl;
	cout << setw(margin) << ' ' << "|_____Equipment______|" << endl;
	cout << setw(margin) << ' ' << "|" << enemyWeapon.name << setw(21-size(enemyWeapon.name)) <<"|" << endl;
	cout << setw(margin) << ' ' << "|+" << enemyWeapon.boost << " damage          |" << endl;
	cout << setw(margin) << ' ' << "|____________________|" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////

void Option::showText(Enemy enemy)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int margin = 70;

	system("cls");
	cout << endl << endl << endl <<endl << endl << endl << endl;

	if (enemy.health <= 0)
	{
		cout << setw(margin-7);
		int n = 0;
		string text = "You won the fight! Enter to begin next stage.";
		while (text[n])
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << text[n++];
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			Sleep(100);
		}
	}
	else
	{
		cout << setw(margin-7);
		int n = 0;
		string text = "You lost the fight! Enter to begin next stage.";
		while (text[n])
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << text[n++];
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			Sleep(100);
		}
	}
	Sleep(2000);
	while (_getch() != 13) {};
}

void Option::showOption(Knight *knight1, Enemy enemy1, Weapon knightWeapon, Weapon enemyWeapon)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CharacterInterface test;

	char pointer[4] = { '<',' ',' ',' ' };
	char pointer2[4] = { '>',' ',' ',' ' };
	int i = 0;
	bool turn;
	int sleepTime = 2000;
	int margin = 70;

	string info;
	string turnInfo = "--- YOUR TURN ---";

	bool lastKnightAction ; //Accepts value true when knight defended himself
	
	while (enemy1.health > 0 && knight1->health > 0)
	{

		lastKnightAction = FALSE;
		turn =TRUE;

		while (turn == TRUE)
		{
			system("cls");
			
			test.showCharacterInterface(knight1, knightWeapon);
			
			cout << endl;

			test.showEnemyInterface(enemy1, enemyWeapon);

			cout << endl;

			cout << setw(margin + 6) << ' ' << pointer2[0] << " Attack " << pointer[0] << endl << endl;
			cout << setw(margin + 6) << ' ' << pointer2[1] << " Defense " << pointer[1] << endl << endl;
			cout << setw(margin + 2) << ' ' << pointer2[2] << " Drink the Potion " << pointer[2] << endl << endl;
			cout << setw(margin + 3) << ' ' << pointer2[3] << " Use the Scroll" << pointer[3] << endl << endl;

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
					knight1->Attack(knight1, knightWeapon, &enemy1);
					turn = FALSE;
				}
				else if (i == 1)
				{
					knight1->Defence(knight1);

					lastKnightAction = TRUE;
					turn = FALSE;
				}
				
				else if (i == 2)
				{
					knight1->drinkPotion(knight1);
				}
				else if (i == 3)
				{
					knight1->useScroll(knight1);
					turn = FALSE;
				}

			} break;

			}

		}
		
		//Turn of the opponent now
		enemy1.Action(enemy1, knight1, enemyWeapon, lastKnightAction);

		Sleep(sleepTime);

		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Enter to continue. ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		Sleep(sleepTime-500);
		
		//Waiting for user reactions
		while (_getch() != 13) {};
	}
	

	Option text;
	text.showText(enemy1);
	
}

void Option::gameOver()
{
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << setw(70) << "GAME OVER";
}



