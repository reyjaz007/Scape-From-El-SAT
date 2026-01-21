#pragma once

void gotoXY(int x, int y);

void terminalSize(int& ancho, int& alto);

void setColorRGB(int r, int g, int b);

void setBackColorRGB(int r, int g, int b);

void resetColor();

void print();

void printSpace(int x);

void printLine(int x);

void paintTerminal(int x, int y, int r, int g, int b);

void printFigure(int a, int b, int c, int d, int e, int f, int g, int h, int x, int& y);

void topSAT();

void printSAT(int x, int y);

void printTHE(int x, int y);

void printEND(int x, int y);

void printMap(int x, int y);

void satAttack(int x, int y);

void attackYUpdate(int y, int &aY);

void erase(int x, int y, int length, int offsetX, int offsetY);