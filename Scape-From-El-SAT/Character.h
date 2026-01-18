#include "iostream"
#pragma once
class Character {
public:
	int health = 100;
	int stamina = 5;

	Character();

	~Character();

	int takeDamage(int damage);

	int useDash();

	void displayInfo();

};

