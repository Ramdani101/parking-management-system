#include <iostream>
#include "fungsiumum.h"
using namespace std;

FungsiUmum::FungsiUmum() {}

void FungsiUmum::clearscreen() {
    cout << "\033[2J\033[H"; // untuk membersihkan layar
}