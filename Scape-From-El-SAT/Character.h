#include "iostream"
#pragma once
class Character {
	int velocity;
	int gravity;
	int strength;
public:
	int health = 100;

	Character();

	~Character();

	int calculateFisics(int velocity, int gravity, int strength);

	int takeDamage(int damage);

	void displayInfo();

	int printCharacter(int animation, int x, int y);
};

