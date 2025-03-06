#ifndef PETUGAS_ROLE_H
#define PETUGAS_ROLE_H
#include "nodeParkir.h"
#include <iostream>
using namespace std;

class PetugasRole{
    private :
    NodeParkir* head;
    NodeParkir* tail;
    NodeParkir* historyHead;
    NodeParkir* historyTail;

    NodeParkir* cariBerdasarkanPlat(string plat);

    public:
    PetugasRole();
    ~PetugasRole();

    void tambahKendaraan(Kendaraan kendaraan);
    void hapusKendaraan(string plat);
    void lihatKendaraan() const;
    void kelolaAntrean();
    void liatHistori();
    void displayMenuPetugas();
};



#endif