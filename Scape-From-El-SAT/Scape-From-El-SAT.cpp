#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "Windows.h"
#include "Character.h"
#include "Print.h"

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

int main() {
	Character you;
	int x = 0, y = 0;
	gotoXY(x, y);
	terminalSize(x, y);
	char input = ' ';

	while (you.health > 0) {
		gotoXY(0, y / 2);
		printSAT();
		setColorRGB(96, 97, 102);
		printLine(x);

		switch (input) {
		case 'q':
			
			break;

		case ' ':

			input = 's';
			break;

		case 's':

			input = 'z';
			break;

		case 'z':
		case 'Z':
			you.printTopCharacter(x / 3, y - 5);
			you.printLegs1(x / 3, y - 3);
			Sleep(150);
			you.printLegs2(x / 3, y - 3);

			Sleep(150);
			you.printLegs3(x / 3, y - 3);

			Sleep(150);
			you.printLegs4(x / 3, y - 3);

			Sleep(150);

			break;

		}
		
	}
}

//Discarted Code

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
