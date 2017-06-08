// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <string>

using namespace std;

class Knight;
class Enemy;
class CharacterInterface;

class Weapon
{
	int boost;
	int requirement;
public:
	string name;
		Weapon(string n, int b, int r)
	{
		name = n;
		boost = b;
		requirement = r;
	}
		friend CharacterInterface;
};


class Menu
{
	
public:
	int showMenu();
};

class CharacterInterface
{
public:
	void showCharacterInterface(Knight k1);
	void showEnemyInterface(Enemy e1);
};

class Character
{
public:
	string name;
	int health = 100;
	int fear = 0;
	int level = 1;
	void death(int health);
	
};

class Knight : public Character
{
	int strenght = 35; // max 99 
	int fencing = 30; // max 99
public:
	Knight(string knight_name)
	{
		name = knight_name;
	}

	friend void CharacterInterface::showCharacterInterface(Knight k1);
};

class Alchemist : public Character
{
	int mana = 35;
	int magic = 30;
};

class Archer : public Character
{
	int agility = 35;
	int archery = 30;
};

class Option
{
public: 
	void showOption(Knight k1, Enemy e1);
};

class Enemy: public Character
{
	int strenght = 40;
	int terror = 10;
public:
	Enemy(string enemy_name)
	{
		name = enemy_name;
	}
	friend void CharacterInterface::showEnemyInterface(Enemy e1);
};


// TODO: reference additional headers your program requires here
