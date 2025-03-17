#ifndef FUNGSIUMUM_H
#define FUNGSIUMUM_H
#include "nodeParkir.h"
#include <iostream>
using namespace std;

class FungsiUmum{
    public:
    FungsiUmum();
    void clearscreen();
    void setColor(int color);
    void hideCursor();
    void showCursor();
};

extern FungsiUmum fungsiUmum;

#endif