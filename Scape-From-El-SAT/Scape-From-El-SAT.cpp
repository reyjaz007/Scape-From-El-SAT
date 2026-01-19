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

void terminalSize(int& ancho, int& alto) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}//funciones terminalSize y gotoXY son funciones ya creadas 

void topSAT() {
	printSpace(4);
	printLine(6);
	printSpace(3);
	printLine(6);
	std::cout << std::endl;
}

void printFigure(int a, int b, int c, int d, int e, int f, int g, int h) {
	printSpace(a);
	printLine(b);
	printSpace(c);
	printLine(d);
	printSpace(e);
	printLine(f);
	printSpace(g);
	printLine(h);
	std::cout << std::endl;
}

void printSAT() {
	setColorRGB(40, 50, 137);
	
	for (int i = 0; i < 3; i++) {
		topSAT();
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		topSAT();
	}
	std::cout << std::endl;

	printFigure(0, 6, 3, 6, 2, 6, 0, 0);
	printFigure(0, 1, 8, 1, 4, 1, 4, 2);
	printFigure(1, 4, 4, 6, 4, 2, 0, 0);
	printFigure(5, 1, 3, 1, 4, 1, 4, 2);
	printFigure(0, 6, 3, 1, 4, 1, 4, 2);

	resetColor();
}

void printMap(int x, int y) {
	gotoXY(0, y / 2);
	printSAT();
	setColorRGB(96, 97, 102);
	printLine(x);
	resetColor();
}

void satAttack(int x, int y) {
	gotoXY(x, y); // x-3  y-5
	setColorRGB(230, 2, 2);
	std::cout << "18";
	resetColor();
}

int main() {
	Character you;

	Hitbox player{
		0,0,0,0
	};

	Hitbox attack{
		0,0,0,0
	};

	int x = 0, y = 0;
	terminalSize(x, y);

	int cX = x / 3;
	int cY = y - 3;
	int attackTimer = 0;
	int attackX = 0;
	int score = 0;

	char input = ' ';

	bool attacking = false;
	bool jumping = false;

	srand(time(nullptr));

	while (you.health > 0) {

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
