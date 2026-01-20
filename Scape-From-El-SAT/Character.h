#include "iostream"
#pragma once
class Character {
private:
	int velocity;
	int gravity;
	int strength;
	int time;

public:
	int health = 100;

	int calculateFisics(int gravity, int strength, int time);

	Character();

	~Character();


	int takeDamage(int damage);

	void displayInfo();

	int printCharacter(int animation, int x, int y);

	int printJumpingCharacter(int animation, int& jump, int x, int y);

};

