#include <conio.h>
#include "petugasRole.h"
#include "mahasiswaRole.h"
#include <iostream>
#include "fungsiumum.h"
using namespace std;


MahasiswaRole::MahasiswaRole(PetugasRole* petugasRole) : petugas(petugasRole) {}

void MahasiswaRole::pesanTempat(){
    string plat,pemilik,jenis,waktu;
    cout << "Masukkan plat nomor : ";
    cin >> plat;
    cout << "Masukkan nama pemilik : ";
    cin >> pemilik;
    cout << "Masukkan jenis kendaraan : ";
    cin >> jenis;
    cout << "Masukkan waktu masuk : ";
    cin >> waktu;
    Kendaraan kendaraan(plat,pemilik,jenis,waktu,"p");
    petugas->tambahKendaraan(kendaraan);
}

void MahasiswaRole::lihatHistoriMahasiswa(){
    petugas->liatHistoriPesan();
}

void MahasiswaRole::displayMenuMahasiswa(){
    fungsiUmum.hideCursor();
    int pilihanTerkini = 0;
    int key;
    const int PILIHAN_MENU = 3;
    const string menu[PILIHAN_MENU] = {
        "1. Pesan Tempat Parkir",
        "2. Lihat Histori Parkir",
        "3. Kembali"
    };

    while (true) {
        fungsiUmum.clearscreen();
        cout << "==========================" << endl;
        cout << "----- SELAMAT DATANG -----" << endl;
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
                case 0: // Pesan Tempat Parkir
                    {
                        pesanTempat();
                    }
                    break;
                case 1: // Lihat Histori
                    lihatHistoriMahasiswa();
                    break;
                case 2: // Kembali
                    return;
            }
            if(pilihanTerkini == 2){
                cout << "Apakah anda yakin mau kembali?";
                getch();
            }else{
                cout << "Tekan apa saja untuk kembali";
                getch();
            }
            
        }
    }
    
}