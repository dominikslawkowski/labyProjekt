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
	void showAbout();
};

class CharacterInterface
{
public:
	void showCharacterInterface(Knight *knight1, Weapon knightWeapon);
	void showEnemyInterface(Enemy enemy1, Weapon enemyWeapon);
};

class Character
{
public:
	string name;
	int health = 100;
	int fearCounter = 0;
	int fear[5] = { 0, 1, 2, 5, 10 };
	int level = 1;
	//void death(int health);
	
};

class Knight : public Character
{
public:
	int strenght = 35; // max 99 
	int fencing = 30; // max 99
	int potions = 3;
	int scrolls = 3;
	Knight(string knight_name, int knight_HP)
	{
		name = knight_name;
		health = knight_HP;
	}
	void Attack(Knight *knight, Weapon knightWeapon, Enemy *enemy);
	void Defence(Knight *knight, bool *turn, bool *lastKnightAction);
	void drinkPotion(Knight *knight);
	void useScroll(Knight *knight);
	friend void CharacterInterface::showCharacterInterface(Knight *knight1, Weapon knightWeapon);
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
	void showOption(Knight *knight1, Enemy enemy1, Weapon knightWeapon, Weapon enemyWeapon);
	void showText(Knight *knight);
	void levelUp(Knight *knight);
	void congratulations();
	void gameOver();
};

class Enemy: public Character
{
public:
	int strenght = 40;
	int terror = 10;
	Enemy(string enemy_name, int enemy_health, int enemy_strenght, int enemy_terror)
	{
		name = enemy_name;
		health = enemy_health;
		strenght = enemy_strenght;
		terror = enemy_terror;
	}
	void Action(Enemy enemy, Knight *knight, Weapon enemyWeapon, bool lastKnightAction);
	friend void CharacterInterface::showEnemyInterface(Enemy enemy1, Weapon enemyWeapon);
};