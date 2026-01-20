#include "iostream"
#pragma once
class Character {
private:
	int velocity = 0;
	int gravity = 0;
	int strength = 0;
	int time = 0;

public:
	int health = 100;

	int calculateFisics(int gravity, int strength, int time);

	Character();

	~Character();


	int takeDamage(int damage);

	void displayInfo();

	int printCharacter(int animation, int x, int y);

	int printJumpingCharacter(int animation, int& jump, int x, int y, bool& jumping, bool& falling);

	bool fallingAction(int& animation, int& jump, int x, int y, bool& jumping);
};

