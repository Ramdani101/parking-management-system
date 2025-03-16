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
    NodeParkir* antrianHead;
    NodeParkir* antrianTail;
    NodeParkir* historyPesanHead;
    NodeParkir* historyPesanTail;
    int jumlahMotor,jumlahMobil,jumlahSepeda;

    NodeParkir* cariBerdasarkanPlat(string plat);

    public:
    PetugasRole();
    ~PetugasRole();

    void tambahKendaraan(Kendaraan kendaraan);
    void hapusKendaraan(string plat);
    void hapusKendaraanAntrian(string plat);
    void lihatKendaraan() const;
    void kelolaAntrean();
    void liatHistori();
    void displayMenuPetugas();
    void liatHistoriPesan();
    int getJumlahMotor() const;
    int getJumlahMobil() const;
    int getJumlahSepeda() const;
    void setJumlahMotor(int jumlah);
    void setJumlahMobil(int jumlah);
    void setJumlahSepeda(int jumlah);
};



#endif