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

void printLegs1(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(0, 1, 1);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(0, 1, 1);
}

void printLegs2(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(0, 2, 0);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(1, 1, 0);
}

void printLegs3(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(1, 0, 1);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(1, 0, 1);
}

void printLegs4(int x, int y) {
	gotoXY(x, y);
	setColorRGB(205, 206, 212);
	printSimpleFigure(1, 1, 0);
	gotoXY(x, y - 1);
	setColorRGB(19, 24, 54);
	printSimpleFigure(0, 1, 1);
}

void printTopCharacter(int x, int y) {
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

int Character::printCharacter(int animation, int x, int y) {
	int yTop = y - 2;
	switch (animation)
	{
	case 1:
		printLegs1(x, y);
		printTopCharacter(x, yTop);
		return 2;
	case 2:
		printLegs2(x, y);
		printTopCharacter(x, yTop);
		return 3;
	case 3:
		printLegs3(x, y);
		printTopCharacter(x, yTop);
		return 4;
	case 4:
		printLegs4(x, y);
		printTopCharacter(x, yTop);
		return 1;
	default:
		break;
	}
}

bool Character::fallingAction(int& animation, int& jump, int x, int y, bool& jumping) {
	if (jump != 0) {
		jump -= gravity;
		erase(x, y, 4, 0, -(jump + 6));
		animation = printCharacter(animation, x, y - jump);
		return true;
	}
	return false;
}

int Character::printJumpingCharacter(int animation,int& jump, int x, int y, bool& jumping, bool& falling){

	if (jump >= velocity ) {
		falling = true;
	}

	if (falling) {
		jumping = fallingAction(animation, jump, x, y, jumping);
		return animation;
	}

	if (jumping) {
		erase(x, y - jump, 4, 0, 0);
		jump += (velocity / 4);

		animation = printCharacter(animation, x, y - jump);
		return animation;
	}

}

int Character::calculateFisics(int gravity, int strength, int time) {
	this->gravity = gravity;
	this->strength = strength;
	this->time = time;

	Character::velocity = strength - gravity;
	return Character::velocity;
}


// ███ 247, 208, 153
// ███ 
//████  4 x 6 
//████  (0,0) -> (3,5)
// █ █  
// ██

Character::Character() {
	std::cout << "Character created" << std::endl;
}

Character::~Character() {
	std::cout << "Character is dead" << std::endl;
}