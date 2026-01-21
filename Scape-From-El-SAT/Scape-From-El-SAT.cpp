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

Hitbox CharacterHitboxUpdate(Hitbox box, int x, int y, int jump) {
	int height = 5;
	int width = 3;

	box.x1 = x;
	box.x2 = x + width;

	box.y2 = y - jump;
	box.y1 = box.y2 - height;
	return box;
}

Hitbox attackHitboxUpdate(Hitbox box, int x, int y) {
	box.x1 = x;
	box.y1 = y;

	box.x2 = box.x1 +1;
	box.y2 = y;

	return box;
}

void verifyinput(bool& jumping, bool& falling) {
	if (_kbhit()) {
		if (_getch() == ' ') {
			jumping = true;
			falling = false;
		}
	}
}

void gameupdate(bool &attacking, int &attackTimer, int &attackX, int& score) {
	srand(time(nullptr));
	if (attackX >= 100) {
		attacking = false;
		attackX = 0;
		score += 100;
	}
	attackTimer >= 100 ? attacking = true, attackTimer = 0 : attackTimer += rand() % 50;
	score++;
	gotoXY(100, 0);
	std::cout << score;
}

void renderGame(Character& you, Hitbox& player, Hitbox& attack, int& animation, int x, int y, int cX, int cY, int& attackX, int& attackY, bool attacking, bool& jumping, bool& falling, int& jump) {
	printMap(x, y);
	jumping ? animation = you.printJumpingCharacter(animation, jump, cX, cY, jumping, falling) : animation = you.printCharacter(animation, cX, cY);
	player = CharacterHitboxUpdate(player, cX, cY, jump);

	gotoXY(0, 0);
	std::cout << player.x1 << ", " << player.x2 << "  " << player.y1 << ", " << player.y2 << std::endl;
	if (attacking) {
		attackYUpdate(cY, attackY);
		attack = attackHitboxUpdate(attack, x - attackX, attackY);
		erase(x - attackX, attackY, 2, 2, 0);
		satAttack(x - attackX, attackY);
		attackX += 2;
	}
	gotoXY(0, 1);
	std::cout << attack.x1 << ", " << attack.x2 << "  " << attack.y1 << ", " << attack.y2 << "  " << std::endl;
	
}

int hitboxVerification(Hitbox player, Hitbox attack) {
	if (attack.x2 < player.x1 || attack.x1 > player.x2 || attack.y2 < player.y1 || attack.y1 > player.y2) {
		return 0;
	}
	return 100;
}

void gameStart(int x, int y) {
	system("cls");
	paintTerminal(x, y, 162, 184, 183);
	setBackColorRGB(162, 184, 183);
	printSAT((x / 2)- 11, (y / 2) -12);

	setBackColorRGB(162, 184, 183);
	setColorRGB(58, 64, 63);

	gotoXY((x / 2) - 9, (y / 2) + 2);
	std::cout << "Scape From El SAT";
	gotoXY((x / 2) - 16, (y / 2) + 5);
	system("pause");
	resetColor();
	system("cls");
}

void gameEnd(int x, int y, int score) {
	Sleep(100);
	system("cls");
	Sleep(100);
	printMap(x, y);
	system("cls");


	paintTerminal(x, y, 162, 184, 183);
	setBackColorRGB(162, 184, 183);
	printTHE((x / 2) - 11, (y / 2) - 12);
	printEND((x / 2) - 11, (y / 2) - 6);
	setBackColorRGB(162, 184, 183);
	setColorRGB(58, 64, 63);

	gotoXY((x / 2) - 9, (y / 2) + 2);
	std::cout << "Your score is : " << score;
	gotoXY((x / 2) - 16, (y / 2) + 5);
	system("pause");
	resetColor();
	system("cls");
}

int main() {
	Character you;
	you.calculateFisics(1, 6, 5);

	Hitbox player{
		0,0,0,0
	};

	Hitbox attack{
		120,26,121,26
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
	int jump = 0;

	bool attacking = false;
	bool jumping = false;
	bool falling = false;

	//start
	gameStart(terminal.x, terminal.y);

	while (you.health >= 0) {//game loop
		verifyinput(jumping, falling);
		gameupdate(attacking, attackTimer, attackXY.x, score);
		renderGame(you, player, attack, animation, terminal.x, terminal.y, character.x, character.y, attackXY.x, attackXY.y, attacking, jumping, falling, jump);
		you.takeDamage(hitboxVerification(player, attack));
		Sleep(100);
	}

	gameEnd(terminal.x, terminal.y, score);
	//highscore and end
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
