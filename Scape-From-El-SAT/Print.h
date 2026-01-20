#pragma once

void gotoXY(int x, int y);

void terminalSize(int& ancho, int& alto);

void setColorRGB(int r, int g, int b);

void setBackColorRGB(int r, int g, int b);

void resetColor();

void print();

void printSpace(int x);

void printLine(int x);

void printFigure(int a, int b, int c, int d, int e, int f, int g, int h);

void topSAT();

void printSAT();

void printMap(int x, int y);

void satAttack(int x, int y);

void attackYUpdate(int y, int &aY);

void erase(int x, int y, int length, int offsetX, int offsetY);