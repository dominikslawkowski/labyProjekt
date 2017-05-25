// stdafx.cpp : source file that includes just the standard includes
// labyProjekt.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int Menu::showMenu()
{
	int exit = 1;
	char pointer[4] = { '<',' ',' ',' ' };
	char pointer2[4] = { '>',' ',' ',' ' };
	int i = 0;
	string dash = "-";
	while (exit)
	{
		system("cls");
		for (int i = 0; i < 39; i++) { cout << "-"; } cout << "Dungeon Adventure v1.0";						for (int i = 0; i < 39; i++) { cout << "-"; } cout << endl << endl;
		for (int i = 0; i < 45; i++) { cout << " "; } cout << pointer2[0] << " Start " << pointer[0];		for (int i = 0; i < 47; i++) { cout << " "; } cout << endl;
		for (int i = 0; i < 42; i++) { cout << " "; } cout << pointer2[1] << " Score Board " << pointer[1];	for (int i = 0; i < 46; i++) { cout << " "; } cout << endl;
		for (int i = 0; i < 45; i++) { cout << " "; } cout << pointer2[2] << " About " << pointer[2];		for (int i = 0; i < 47; i++) { cout << " "; } cout << endl;
		for (int i = 0; i < 44; i++) { cout << " "; } cout << pointer2[3] << " Exit :( " << pointer[3];		for (int i = 0; i < 45; i++) { cout << " "; } cout << endl;

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
			else if (i == 3) { }
			break;


		}
		// TODO: reference any additional headers you need in STDAFX.H
		// and not in this file
	}
}

void CharacterInterface::showCharacterInterface(Knight k1)
{
	int name_lenght = size(k1.name);
	Weapon longSword("Long Sword", 10, 35);

	cout << "______________________" << endl;
	cout << "|      Knight        |" << endl;
	cout << "|" << k1.name; for (int i = 0; i < (20 - name_lenght); i++) { cout << " "; } cout << "|" << endl;
	cout << "|HP: " << k1.health; if (k1.health == 100) { cout << "             "; } else { cout << "            "; } cout << "|" << endl;
	cout << "|Fear: " << k1.fear; cout<<"             | " << endl;
	cout << "|____________________|" << endl;
	cout << "|     Attributes     |" << endl;
	cout << "|Level: "<<k1.level<<"            |" << endl;
	cout << "|Strenght: "<<k1.strenght<<"        |" << endl;
	cout << "|Fencing: "<<k1.fencing<<"         |" << endl;
	cout << "|     Equipment      |" << endl;
	cout << "|" << longSword.name<<"          |" << endl;
	cout << "|+"<<longSword.boost<<" damage          |" << endl;
	cout << "|____________________|" << endl;
}

