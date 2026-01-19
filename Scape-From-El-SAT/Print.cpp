#include "windows.h"
#include "iostream"
#include "Print.h"

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColorRGB(int r, int g, int b) {
	std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void resetColor() {
	std::cout << "\033[0m";
}

void print() {
	char rectangle = 219;
	std::cout << rectangle;
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
