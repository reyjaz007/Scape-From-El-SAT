#include "Character.h"
#include "iostream"

int Character::takeDamage(int damage) {
	return health -= damage;
}

int Character::useDash() {
	return stamina--;
}

void Character::displayInfo() {
	std::cout << "your health: " << health << std::endl;
	std::cout << "your stamina: " << stamina << std::endl;
}

Character::Character() {
	std::cout << "Character created" << std::endl;
}

Character::~Character() {
	std::cout << "Character is dead" << std::endl;
}