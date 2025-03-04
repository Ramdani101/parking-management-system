#include <iostream>
#include "amunisi.h"
#include "petugasRole.h"
#include "nodeParkir.h"
#include "kendaraan.h"
#include "fungsiumum.h"
using namespace std;

void displayMainMenu(){
    cout << "============================" << endl;
    cout << "--- SISTEM PARKIR KAMPUS ---" << endl;
    cout << "============================" << endl;
    cout << "1. Masuk sebagai petugas" << endl;
    cout << "2. Masuk sebagai mahasiswa" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih : ";
}

int main(){
    PetugasRole pr;
    FungsiUmum fungsiUmum;
    int pilihan;
    string plat,pemilik,jenis,waktu;

    do{
        displayMainMenu();
        cin >> pilihan;
        if(pilihan == 1){
            fungsiUmum.clearscreen();
            pr.displayMenuPetugas();
        }else if(pilihan == 2){
            fungsiUmum.clearscreen();
            cout << "Masih dalam tahap pengembangan" << endl;
            displayMainMenu();
        }else if(pilihan != 3){
            fungsiUmum.clearscreen();
            cout << "Input tidak valid" << endl;
            displayMainMenu();
        }
    }while(pilihan != 3);
    return 0;
}