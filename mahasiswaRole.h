#ifndef MAHASISWA_ROLE_H
#define MAHASISWA_ROLE_H
#include "nodeParkir.h"
#include "petugasRole.h"
#include <iostream>
using namespace std;

class MahasiswaRole{
    private:
    NodeParkir* historiParkirHead;
    NodeParkir* historiParkirTail;
    PetugasRole* petugas;

    public:
    MahasiswaRole(PetugasRole* petugasRole);
    void displayMenuMahasiswa();
    void pesanTempat();
    void lihatHistoriMahasiswa();
};

#endif