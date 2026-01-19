#include "Character.h"
#include "iostream"
#include "Print.h"

void printSimpleFigure(int x, int y, int z) {
	printSpace(x);
	print();
	printSpace(y);
	print();
	printSpace(z);
}

int Character::takeDamage(int damage) {
	return health -= damage;
}

void Character::displayInfo() {
	std::cout << "your health: " << health << std::endl;
}

void Character::printLegs1(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(0, 1, 1);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(0, 1, 1);
}

void Character::printLegs2(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(0, 2, 0);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(1, 1, 0);
}

void Character::printLegs3(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(1, 0, 1);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(1, 0, 1);
}

void Character::printLegs4(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(1, 1, 0);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(0, 1, 1);
}

void Character::printTopCharacter(int x, int y) {
	gotoXY(x, y);
	setColorRGB(247, 208, 153);
	print();
	setColorRGB(34, 171, 186);
	printLine(2);
	setColorRGB(247, 208, 153);
	print();
	gotoXY(x, y - 1);
	setColorRGB(247, 208, 153);
	print();
	setColorRGB(34, 171, 186);
	printLine(2);
	setColorRGB(247, 208, 153);
	print();
	gotoXY(x, y - 2);
	printSpace(1);
	printLine(3);
	gotoXY(x, y - 3);
	printSpace(1);
	printLine(3);
}

// ███ 247, 208, 153
// ███
//████
//████
// █ █
// ██

Character::Character() {
	std::cout << "Character created" << std::endl;
}

Character::~Character() {
	std::cout << "Character is dead" << std::endl;
}