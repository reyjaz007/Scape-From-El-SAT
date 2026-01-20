#include "windows.h"
#include "iostream"
#include "Print.h"

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void terminalSize(int& ancho, int& alto) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void setColorRGB(int r, int g, int b) {
	std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void setBackColorRGB(int r, int g, int b) {
	std::cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";
}

void resetColor() {
	std::cout << "\033[0m";
}

void print() {
	char rectangle = 219;
	std::cout << rectangle;
}

void print18() {
	std::cout << "18";
}

void printSpace(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << " ";
	}
}

void printLine(int x) {
	for (int i = 0; i < x; i++) {
		print();
	}
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

void topSAT() {
	for (int i = 0; i < 3; i++) {
		printFigure(4, 6, 3, 6, 0, 0, 0, 0);
	}
	std::cout << std::endl;
}

void printSAT() {
	setColorRGB(40, 50, 137);

	topSAT();
	topSAT();
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
	print18();
	resetColor();
}

void attackYUpdate( int y, int &aY) {
	aY = y - 2;
}

void erase(int x, int y, int length, int offsetX, int offsetY) {
	gotoXY(x + offsetX, y + offsetY);
	printSpace(length);
}