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

void paintTerminal(int x, int y, int r, int g, int b) {
	gotoXY(0, 0);
	setColorRGB(r, g, b);
	for (int i = 0; i < y; i++) {
		printLine(x);
	}
	resetColor();
}

void printFigure(int a, int b, int c, int d, int e, int f, int g, int h, int x, int& y) {
	gotoXY(x, y);
	printSpace(a);
	printLine(b);
	printSpace(c);
	printLine(d);
	printSpace(e);
	printLine(f);
	printSpace(g);
	printLine(h);
	printSpace(3);
	y++;
}

void topSAT(int x, int& y) {
	for (int i = 0; i < 3; i++) {
		printFigure(4, 6, 3, 6, 0, 0, 0, 0, x, y);
	}
	y++;
}

void printSAT(int x, int y) {
	setColorRGB(40, 50, 137);

	topSAT(x, y);
	topSAT(x, y);
	printFigure(0, 6, 3, 6, 2, 6, 0, 0, x, y);
	printFigure(0, 1, 8, 1, 4, 1, 4, 2, x, y);
	printFigure(1, 4, 4, 6, 4, 2, 0, 0, x, y);
	printFigure(5, 1, 3, 1, 4, 1, 4, 2, x, y);
	printFigure(0, 6, 3, 1, 4, 1, 4, 2, x, y);

	resetColor();
}

void printMap(int x, int y) {
	gotoXY(0, y / 2);
	printSAT(x, y);
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