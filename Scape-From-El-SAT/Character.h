#include "iostream"
#pragma once
class Character {
public:
	int health = 100;

	Character();

	~Character();

	int takeDamage(int damage);

	void displayInfo();

	int printCharacter(int animation, int x, int y);
};

