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
public:
	int boost;
	string name;
		Weapon(string n, int b)
	{
		name = n;
		boost = b;
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
	void showCharacterInterface(Knight knight1, Weapon knightWeapon);
	void showEnemyInterface(Enemy enemy1, Weapon enemyWeapon);
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
public:
	int strenght = 35; // max 99 
	int fencing = 30; // max 99
	int potions = 3;
	Knight(string knight_name)
	{
		name = knight_name;
	}

	friend void CharacterInterface::showCharacterInterface(Knight knight1, Weapon knightWeapon);
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
	void showOption(Knight knight1, Enemy enemy1, Weapon knightWeapon, Weapon enemyWeapon);
};

class Enemy: public Character
{
public:
	int strenght = 40;
	int terror = 10;
	Enemy(string enemy_name, int enemy_health)
	{
		name = enemy_name;
		health = enemy_health;
	}
	friend void CharacterInterface::showEnemyInterface(Enemy enemy1, Weapon enemyWeapon);
};


// TODO: reference additional headers your program requires here
