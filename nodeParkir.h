#ifndef NODEPARKIR_H
#define NODEPARKIR_H
#include "kendaraan.h"

#include <iostream>
#include "kendaraan.h"

using namespace std;

class NodeParkir {
    public:
    Kendaraan kendaraan;
    NodeParkir* next;
    NodeParkir* prev;

    NodeParkir(Kendaraan kendaraan);

};

#endif