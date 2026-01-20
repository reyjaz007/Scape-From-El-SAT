#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Character.h"
#include "Print.h"

struct Hitbox {
	int x1;
	int y1;

	int x2;
	int y2;
};

struct XY {
	int x;
	int y;
};

Hitbox CharacterHitboxUpdate(Hitbox box, int x, int y) {
	box.x1 = x;
	box.y1 = y;

	box.x2 = x + 3;
	box.y2 = y - 5;
	return box;
}

Hitbox attackHitboxUpdate(Hitbox box, int x, int y) {
	box.x1 = x;
	box.y1 = y;

	box.x2 = x + 1;
	box.y2 = y;

	return box;
}

void verifyinput(bool& jumping) {
	jumping = false;
	if (_kbhit()) {
		if (_getch() == ' ') {
			jumping = true;
		}
	}
}

void gameupdate(bool &attacking, int &attackTimer, int &attackX) {//add fisics for jump (maybe?)
	srand(time(nullptr));
	if (attackX >= 100) {
		attacking = false;
		attackX = 0;
	}
	attackTimer >= 100 ? attacking = true, attackTimer = 0 : attackTimer += rand() % 50;
}

void renderGame(Character& you, Hitbox &player, Hitbox &attack, int &animation, int x, int y, int cX, int cY, int &attackX, int &attackY, bool attacking) {
	printMap(x, y);
	animation = you.printCharacter(animation, cX, cY);
	player = CharacterHitboxUpdate(player, cX, cY);

	if (attacking) {
		attackXYUpdate(x,cY,attackX, attackY);
		attackHitboxUpdate(attack, attackX, attackY);
		erase(attackX + 2, attackY, 2);
		satAttack(attackX , attackY);
		attackX += 2;
	}
}

int main() {
	Character you;

	Hitbox player{
		0,0,0,0
	};

	Hitbox attack{
		0,0,0,0
	};

	XY terminal{
		0,0
	};

	terminalSize(terminal.x, terminal.y);

	XY character{
		terminal.x / 3,
		terminal.y - 3
	};

	XY attackXY{
		0,0
	};	
	
	int attackTimer = 0;
	int score = 0;
	int animation = 1;

	bool attacking = false;
	bool jumping = false;

	system("cls");

	while (you.health > 0) {
		verifyinput(jumping);
		gameupdate(attacking, attackTimer, attackXY.x);
		renderGame(you, player, attack, animation, terminal.x, terminal.y, character.x, character.y, attackXY.x, attackXY.y, attacking);
		//hitboxverify(); {if hitbox player == hitbox attack { takedamage(x);}}
		Sleep(100);
	}
}

//Discarted Code

//while (you.health > 0) {
//
//	if (i >= 100) {
//		attacking = !attacking;
//		i = 0;
//		score += 100;
//	}
//	system("cls");
//	printMap(x, y);
//
//	if (_kbhit()) {
//		if (_getch() == ' ') {
//			jumping = true;
//		}
//	}
//	jumping = false;
//
//	you.printTopCharacter(cX, cY - 2);
//	jumping ? you.printLegs1(cX, cY - 1) : you.printLegs1(cX, cY);
//
//	Sleep(150);
//	system("cls");
//	printMap(x, y);
//	jumping ? you.printLegs2(cX, cY - 2) : you.printLegs2(cX, cY);
//
//
//	Sleep(150);
//
//	if (attacking) {
//		satAttack(x - i - 3, y - 5);
//	}
//	else {
//		i += rand() % 50;
//	}
//
//	i++;
//	system("cls");
//	printMap(x, y);
//	jumping ? you.printLegs3(cX, cY - 4) : you.printLegs3(cX, cY);
//
//
//	Sleep(150);
//	system("cls");
//	printMap(x, y);
//	jumping ? you.printLegs4(cX, cY - 2) : you.printLegs4(cX, cY);
//
//
//	Sleep(150);
//	i++;
//	if (attacking) {
//		satAttack(x - i - 3, y - 5);
//		i += 2;
//	}
//}

//void gameStart(Character you, int x, int y ) {
//
//	int cX = x / 3;
//	int cY = y - 3;
//
//	switch (_getch()) {
//	case 'q':
//
//		break;
//
//	case ' ':
//		you.printTopCharacter(cX, cY - 5);
//		you.printLegs1(cX, cY - 3);
//
//		system("cls");
//		break;
//
//	case 'z':
//	case 'Z':
//		you.printTopCharacter(cX, cY - 2);
//		you.printLegs1(cX, cY);
//		Sleep(150);
//		you.printLegs2(cX, cY);
//
//		Sleep(150);
//		you.printLegs3(cX, cY);
//
//		Sleep(150);
//		you.printLegs4(cX, cY);
//
//		Sleep(150);
//		system("cls");
//		break;
//	}
//}
//struct Sprite {
//	int width;
//	int tall;
//
//	std::vector<std::string> image;
//};
//void printBackground(int x, int y) {
//	for (int i = 0; i < y; i++) {
//		printLine(x);
//	}
//}
//void drawingProtocol() {
//	FILE* protocol = fopen("Sprites.txt", "wb");
//
//	if (protocol == nullptr) {
//		std::cout << "Eror at file..." << std::endl;
//		std::cout << "Creating a new file :)" << std::endl;
//		return;
//	}
//
//	const int x = 19, y = 13;
//	std::vector<std::string> sat{
//		"    ██████   ██████",
//		"    ██████   ██████",
//		"    ██████   ██████",
//		" ",
//		"    ██████   ██████",
//		"    ██████   ██████",
//		"    ██████   ██████",
//		" ",
//		"██████   ██████  ██████",
//		"█        █    █    ██",
//		" ████    ██████    ██",
//		"     █   █    █    ██",
//		"██████   █    █    ██"
//	};
//
//
//	fwrite(&x, sizeof(int), 1, protocol);
//	fwrite(&y, sizeof(int), 1, protocol);
//
//	for (int i = 0; i < y; i++) {
//		fwrite(&sat[i], x, 1, protocol);
//	}
//	fclose(protocol);
//
//}
//
//void readingProtocol(Sprite& sprite) {
//	FILE* spriteFile = fopen("Sprites.txt", "rb");
//	std::string buffer;
//
//	if (spriteFile == nullptr) {
//		std::cout << "Reading eror, try again..." << std::endl;
//		return;
//	}
//
//	fread(&sprite.width, sizeof(int), 1, spriteFile);
//	fread(&sprite.tall, sizeof(int), 1, spriteFile);
//
//	std::cout << sprite.width << " || " << sprite.tall << std::endl;
//
//	for (int i = 0; i < sprite.tall; i++) {
//		fread(&buffer, sprite.width, 1, spriteFile);
//		sprite.image[i] = buffer;
//	}
//
//
//	fclose(spriteFile);
//}
//
//void printingProtocol(Sprite sprite) {
//	for (int i = 0; i < sprite.tall; i++) {
//		std::cout << sprite.image[i] << std::endl;
//	}
//}
//
//int main() {
//	int x = 0, y = 0;
//	gotoXY(x, y);
//	terminalSize(x, y);
//	print();
//	system("cls");
//
//	gotoXY(0, y - 1);
//	printLine(x);
//
//	gotoXY(0, y - 15);
//	
//
//
//	gotoXY(0, y - 1);
//	printLine(x);
//}
//
//int main() {
//	Sprite sat = {
//		0,0
//	};
//
//	readingProtocol(sat);
//	printingProtocol(sat);
//}
