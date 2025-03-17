#include <iostream>
#include <conio.h>
#include "amunisi.h"
#include "petugasRole.h"
#include "nodeParkir.h"
#include "kendaraan.h"
#include "fungsiumum.h"
#include "mahasiswaRole.h"
using namespace std;


PetugasRole pr;
MahasiswaRole mr(&pr);

/*
void displayMainMenu(){
    cout << "============================" << endl;
    cout << "--- SISTEM PARKIR KAMPUS ---" << endl;
    cout << "============================" << endl;
    cout << "1. Masuk sebagai petugas" << endl;
    cout << "2. Masuk sebagai mahasiswa" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih : ";
}
*/

void displayMainMenu(){
    fungsiUmum.hideCursor();
    int pilihanTerkini = 0;
    int key;
    const int PILIHAN_MENU = 3;
    const string menu[PILIHAN_MENU] = {
        "1. Masuk sebagai petugas",
        "2. Masuk sebagai mahasiswa",
        "3. Keluar"
    };

    while (true) {
        fungsiUmum.clearscreen();
        cout << "==========================" << endl;
        cout << "-- SISTEM PARKIR KAMPUS --" << endl;
        cout << "==========================" << endl;

        // Tampilkan menu dengan highlight
        for (int i = 0; i < PILIHAN_MENU; i++) {
            if (i == pilihanTerkini) {
                fungsiUmum.setColor(0xEF); // Warna lain untuk pilihan yang aktif
            } else {
                fungsiUmum.setColor(7); // Warna default
            }
            cout << menu[i] << endl;
        }
        fungsiUmum.setColor(7); // Kembalikan ke warna default

        
        key = getch();
        if (key == 224 || key == 0) { // Handle arrow keys
            key = getch();
            switch (key) {
                case 72: // Panah atas
                    pilihanTerkini = (pilihanTerkini > 0) ? pilihanTerkini - 1 : PILIHAN_MENU - 1;
                    break;
                case 80: // Panah bawah
                    pilihanTerkini = (pilihanTerkini < PILIHAN_MENU - 1) ? pilihanTerkini + 1 : 0;
                    break;
            }
        } else if (key == 13) { // Tombol Enter
            switch (pilihanTerkini) {
                case 0: // Masuk sebagai petugas
                    {
                        fungsiUmum.clearscreen();
                        pr.displayMenuPetugas();
                        fungsiUmum.clearscreen();
                    }
                    break;
                case 1: // Masuk sebagai mahasiswa
                        fungsiUmum.clearscreen();
                        mr.displayMenuMahasiswa();
                        fungsiUmum.clearscreen();
                    break;
                case 2: // Kembali
                    return;
            }
            if(pilihanTerkini == 2){
                cout << "Apakah anda yakin mau Keluar?";
                getch();
            }else{
                cout << "Apakah yakin anda mau keluar?";
                getch();
            }
            
        }
    }
    
}

int main(){
    displayMainMenu();
}