#include "iostream"
#pragma once
class Character {
public:
	int health = 100;

	Character();

	~Character();

	int takeDamage(int damage);

	void displayInfo();

	void printLegs1(int x , int y);
	void printLegs2(int x, int y);
	void printLegs3(int x, int y);
	void printLegs4(int x, int y);

	void printTopCharacter(int x, int y);
};

