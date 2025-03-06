#include "petugasRole.h"
#include <iostream>
#include "fungsiumum.h"
using namespace std;

FungsiUmum fungsiUmum;

//Constructor
PetugasRole::PetugasRole() : head(nullptr), tail(nullptr) {}
//Destructor
PetugasRole::~PetugasRole() {
    while(head != nullptr) {
        NodeParkir* hapus = head;
        head = head->next;
        delete hapus;
    }
}

void PetugasRole::tambahKendaraan(Kendaraan kendaraan) {
    NodeParkir* nodeBaru = new NodeParkir(kendaraan);
    if(head == nullptr) {
        head = nodeBaru;
        tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    fungsiUmum.clearscreen();
    cout << "Data berhasil ditambahkan" << endl;
}

void PetugasRole::hapusKendaraan(string plat) {
    NodeParkir* hapus = nullptr;
    
    if(head != nullptr){
        NodeParkir* bantu = head;
        while(bantu != nullptr){
            if(bantu->kendaraan.getPlatNomor() == plat){
                hapus = bantu;
                if(bantu->prev != nullptr){
                    bantu->prev->next = bantu->next;
                }else{
                    head = bantu->next;
                }
                if(bantu->next != nullptr){
                    bantu->next->prev = bantu->prev;
                }else{
                    tail = bantu->prev;
                }
                break;
            }
            bantu = bantu->next;
        }
       delete hapus;
       fungsiUmum.clearscreen();
       cout<< "Data berhasil dihapus" << endl;
       displayMenuPetugas();
    }else{
        fungsiUmum.clearscreen();
        cout << "Data tidak ditemukan" << endl;
        displayMenuPetugas();
    }
}

void PetugasRole::lihatKendaraan() const {
    int totalKendaraan = 0;
    NodeParkir* bantu = head;
    //hitung total kendaraan
    while(bantu!=nullptr){
        bantu = bantu->next;
        totalKendaraan++;
    }

    if(totalKendaraan == 0){
        fungsiUmum.clearscreen();
        cout << "Tidak ada kendaraan yang parkir" << endl;
        return;
    }

    //buat array untuk navigasi
    NodeParkir** nodes = new NodeParkir*[totalKendaraan];
    bantu = head;
    for(int i = 0; i < totalKendaraan; i++){
        nodes[i] = bantu;
        bantu = bantu->next;
    }

    int index = 0;
    string input;
    fungsiUmum.clearscreen();
    do{
        cout <<"--------------------------" << endl;
        cout <<"| Plat                  : " << nodes[index]->kendaraan.getPlatNomor() << endl;
        cout <<"| Pemilik               : " << nodes[index]->kendaraan.getPemilik() <<  endl;
        cout <<"| Jenis Kendaraan       : " << nodes[index]->kendaraan.getJenisKendaraan() << endl;
        cout <<"| Waktu Masuk           : " << nodes[index]->kendaraan.getWaktuMasuk() << endl;
        cout <<"--------------------------" << endl;
        cout << endl;
        cout << "1. Previous" << endl;
        cout << "2. Next" << endl;
        cout << "3. Kembali" << endl;
        cout << "Pilih : ";
        cin >> input;
        if(input == "1" && index > 0){
            index--;
            fungsiUmum.clearscreen();
        }else if(input == "2" && index < totalKendaraan - 1){
            index++;
            fungsiUmum.clearscreen();
        }else if(input != "3"){
            fungsiUmum.clearscreen();
            cout << "Input tidak valid atau sudah mencapai batas" << endl;
        }
    }while(input != "3");
    delete[] nodes;
}

void PetugasRole::kelolaAntrean(){
    fungsiUmum.clearscreen();
    cout << "Masih dalam tahap pengembangan \n";
}

void PetugasRole::liatHistori(){
    fungsiUmum.clearscreen();
    cout << "Masih dalam tahap pengembangan \n";
}

void PetugasRole::displayMenuPetugas() {
    string input;
    do {
        //fungsiUmum.clearscreen();
        cout << "==========================" << endl;
        cout << "--- DASHBOARD  PETUGAS ---" << endl;
        cout << "==========================" << endl;
        cout << "1. Tambah Kendaraan" << endl;
        cout << "2. Lihat Kendaraan di Parkiran" << endl;
        cout << "3. Hapus Kendaraan" << endl;
        cout << "4. Kelola antrean kendaraan" << endl;
        cout << "5. Lihat histori kendaraan keluar" << endl;
        cout << "6. Kembali" << endl;
        cout << "Pilih : ";
        cin >> input;
        if(input == "1") {
            string plat, pemilik, jenis, waktu;
            cout << "Masukkan plat nomor : ";
            cin >> plat;
            cout << "Masukkan nama pemilik : ";
            cin >> pemilik;
            cout << "Masukkan jenis kendaraan : ";
            cin >> jenis;
            cout << "Masukkan waktu masuk : ";
            cin >> waktu;
            Kendaraan kendaraan(plat, pemilik, jenis, waktu);
            tambahKendaraan(kendaraan);
            displayMenuPetugas();
        } else if(input == "2") {
            lihatKendaraan();
            //fungsiUmum.clearscreen();
        } else if(input == "3") {
            string plat;
            cout << "Masukkan plat nomor : ";
            cin >> plat;
            hapusKendaraan(plat);
            fungsiUmum.clearscreen();
        } else if(input == "4") {
            kelolaAntrean();
            displayMenuPetugas();
        } else if(input == "5") {
            liatHistori();
            displayMenuPetugas();
        } else if(input != "6"){
            cout << "Input tidak valid" << endl;
            displayMenuPetugas();
        }
    } while(input != "6");
}