#include <iostream>
#include <windows.h>
#include "fungsiumum.h"

using namespace std;

FungsiUmum fungsiUmum;

FungsiUmum::FungsiUmum() {}

void FungsiUmum::clearscreen() {
    cout << "\033[2J\033[H"; // untuk membersihkan layar
}

void FungsiUmum::setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void FungsiUmum::hideCursor() {
    cout << "\033[?25l";
}

void FungsiUmum::showCursor() {
    cout << "\033[?25h";
}
