#include <iostream>
#include "amunisi.h"
#include "petugas.h"
#include "mahasiswa.h"
using namespace std;


//VARIABLE COLLECTION
int pilihan; //untuk menyimpan pilihan user

//FUNGSI COLLECTION
void mainMenu(); //untuk tampilan menu utama
void petugasMenu(); //untuk tampilan menu petugas
void mahasiswaMenu(); //untuk tampilan menu mahasiswa

//INSTANCE DARI CLASS PETUGAS DAN MAHASISWA
Petugas petugas;
Mahasiswa mahasiswa;

int main(){
    mainMenu();
    return 0;
}

void mainMenu(){
    cout << 
    "========================\n" <<
    "--SISTEM PARKIR KAMPUS--\n" <<
    "========================\n";

    cout << 
    "1. Masuk sebagai Petugas\n"<<
    "2. Masuk sebagai Mahasiswa\n"<<
    "3. Keluar\n"<<
    "Pilihan: ";
    cin >> pilihan;
    switch(pilihan){
        case 1:
            petugasMenu();
            break;
        case 2:
            mahasiswaMenu();
            break;
        case 3:
            exit(0);
            break;
    }

}

void petugasMenu(){
    cout << 
    "=======================\n" <<
    "-- DASHBOARD PETUGAS --\n" <<
    "=======================\n";

    cout << 
    "1. Tambah Kendaraan\n"<<
    "2. Lihat Kendaraan di Parkiran\n"<<
    "3. Hapus Kendaraan\n"<<
    "4. Kelola Antrean Kendaraan\n"<<
    "5. Lihat histori kendaraan keluar\n"
    "6. Keluar\n"<<
    "Pilihan: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        petugas.tambahKendaraan();
        break;
    case 2:
        petugas.lihatKendaraan();
        break;
    case 3:
        petugas.hapusKendaraan();
        break;
    case 4:
        petugas.kelolaAntreanKendaraan();
        break;
    case 5:
        petugas.lihatHistoriKendaraan();
        break;
    case 6:
        exit(0);
        break;
    default:
    cout << "Pilihan tidak tersedia";
    }
}

void mahasiswaMenu(){
    cout << 
    "========================\n" <<
    "-- DASHBOARD MAHASISWA --\n" <<
    "========================\n";

    cout << 
    "1. Booking Parkiran\n"<<
    "2. Histori Parkir\n"<<
    "3. Keluar\n"<<
    "Pilihan: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        mahasiswa.pilihanRandom();
        break;
    case 2:
        mahasiswa.pilihanRandom();
        break;
    case 3:
        exit(0);
        break;
    default:
    cout << "Pilihan tidak tersedia";
    }
}