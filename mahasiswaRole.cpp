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
    Kendaraan kendaraan(plat,pemilik,jenis,waktu);
    petugas->tambahKendaraan(kendaraan);
}

void MahasiswaRole::lihatHistoriMahasiswa(){
    fungsiUmum.clearscreen();
    cout << "Sedang tahap Pengembangan" << endl;
}

void MahasiswaRole::displayMenuMahasiswa(){
    string input;
    do {
        cout << "======================" << endl;
        cout << "--- SELAMAT DATANG ---" << endl;
        cout << "======================" << endl;
        cout << "1. Pesan Tempat Parkir" << endl;
        cout << "2. Lihat Histori Parkir" << endl;
        cout << "3. Kembali" << endl;
        cout << "Pilih : ";
        cin >> input;
        if(input == "1") {
            pesanTempat();
            //displayMenuMahasiswa();
        } else if(input == "2") {
            lihatHistoriMahasiswa();
        } else if(input != "3"){
            cout << "Input tidak valid" << endl;
            //displayMenuMahasiswa();
        }
    } while(input != "3");
}