#include "petugasRole.h"
#include <iostream>
#include "fungsiumum.h"
using namespace std;

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

int PetugasRole::getJumlahMobil() const {
    return jumlahMobil;
}

int PetugasRole::getJumlahMotor() const {
    return jumlahMotor;
}

int PetugasRole::getJumlahSepeda() const {
    return jumlahSepeda;
}

void PetugasRole::setJumlahMobil(int jumlah) {
    jumlahMobil = jumlah;
}

void PetugasRole::setJumlahMotor(int jumlah) {
    jumlahMotor = jumlah;
}

void PetugasRole::setJumlahSepeda(int jumlah) {
    jumlahSepeda = jumlah;
}

void PetugasRole::tambahKendaraan(Kendaraan kendaraan) {
    NodeParkir* nodeBaru = new NodeParkir(kendaraan);
    if(kendaraan.getJenisKendaraan() == "Mobil") {
        if (getJumlahMobil() <= 5)
        {
            if(head == nullptr) {
                head = nodeBaru;
                tail = nodeBaru;
            } else {
                tail->next = nodeBaru;
                nodeBaru->prev = tail;
                tail = nodeBaru;
                tail->next = head;
                head->prev = tail;
            }
            fungsiUmum.clearscreen();
            cout << "Data berhasil ditambahkan" << endl;
            setJumlahMobil(getJumlahMobil() + 1);
        }
    }else{
        cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
        "Antrian akan diproses ketika parkiran kosong" << endl;
        if(antrianHead == nullptr) {
            antrianHead= nodeBaru;
            antrianTail = nodeBaru;
        } else {
            antrianTail->next = nodeBaru;
            nodeBaru->prev = antrianTail;
            antrianTail = nodeBaru;
            antrianTail->next = antrianHead;
            antrianHead->prev = antrianTail;
        }
        fungsiUmum.clearscreen();
    }

    if(kendaraan.getJenisKendaraan() == "Motor") {
        if (getJumlahMotor() <= 30)
        {
            if(head == nullptr) {
                head = nodeBaru;
                tail = nodeBaru;
            } else {
                tail->next = nodeBaru;
                nodeBaru->prev = tail;
                tail = nodeBaru;
                tail->next = head;
                head->prev = tail;
            }
            fungsiUmum.clearscreen();
            cout << "Data berhasil ditambahkan" << endl;
            setJumlahMotor(getJumlahMotor() + 1);
        }
    }else{
        cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
        "Antrian akan diproses ketika parkiran kosong" << endl;
        if(antrianHead == nullptr) {
            antrianHead= nodeBaru;
            antrianTail = nodeBaru;
        } else {
            antrianTail->next = nodeBaru;
            nodeBaru->prev = antrianTail;
            antrianTail = nodeBaru;
            antrianTail->next = antrianHead;
            antrianHead->prev = antrianTail;
        }
        fungsiUmum.clearscreen();
    }

    if(kendaraan.getJenisKendaraan() == "Sepeda") {
        if (getJumlahSepeda() <= 10)
        {
            if(head == nullptr) {
                head = nodeBaru;
                tail = nodeBaru;
            } else {
                tail->next = nodeBaru;
                nodeBaru->prev = tail;
                tail = nodeBaru;
                tail->next = head;
                head->prev = tail;
            }
            fungsiUmum.clearscreen();
            cout << "Data berhasil ditambahkan" << endl;
            setJumlahSepeda(getJumlahSepeda() + 1);
        }
    }else{
        cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
        "Antrian akan diproses ketika parkiran kosng" << endl;
        if(antrianHead == nullptr) {
            antrianHead= nodeBaru;
            antrianTail = nodeBaru;
        } else {
            antrianTail->next = nodeBaru;
            nodeBaru->prev = antrianTail;
            antrianTail = nodeBaru;
            antrianTail->next = antrianHead;
            antrianHead->prev = antrianTail;
        }
        fungsiUmum.clearscreen();
    }    
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

void PetugasRole::hapusKendaraanAntrian(string plat) {
    NodeParkir* hapus = nullptr;
    
    if(antrianHead != nullptr){
        NodeParkir* bantu = antrianHead;
        while(bantu != nullptr){
            if(bantu->kendaraan.getPlatNomor() == plat){
                hapus = bantu;
                if(bantu->prev != nullptr){
                    bantu->prev->next = bantu->next;
                }else{
                    antrianHead = bantu->next;
                }
                if(bantu->next != nullptr){
                    bantu->next->prev = bantu->prev;
                }else{
                    antrianTail = bantu->prev;
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
    string input;
    do{
            cout <<"--------------------------" << endl;
            cout <<"| Plat                  : " << bantu->kendaraan.getPlatNomor()<< endl;
            cout <<"| Pemilik               : " << bantu->kendaraan.getPemilik() <<  endl;
            cout <<"| Jenis Kendaraan       : " << bantu->kendaraan.getJenisKendaraan() << endl;
            cout <<"| Waktu Masuk           : " << bantu->kendaraan.getWaktuMasuk() << endl;
            cout <<"--------------------------" << endl;
            cout << endl;
            cout << "1. Previous" << endl;
            cout << "2. Next" << endl;
            cout << "3. Kembali" << endl;
            cout << "Pilih : ";
            cin >> input;
            if(input == "1"){
                bantu = bantu->prev;
                fungsiUmum.clearscreen();
            }else if(input == "2"){
                bantu = bantu->next;
                fungsiUmum.clearscreen();
            }else if(input != "3"){
                fungsiUmum.clearscreen();
                cout << "Input tidak valid" << endl;
            }
        }while(input != "3");
}

void PetugasRole::kelolaAntrean(){
    string input;
    cout << "================================" << endl;
    cout << "--- DAFTAR ANTRIAN PEMESANAN ---" << endl;
    cout << "================================" << endl;
    NodeParkir* bantu = antrianHead;
    do{
        int i = 1;
        do{
            cout << i << "| Plat : " << bantu->kendaraan.getPlatNomor() << "| Pemilik : " << bantu->kendaraan.getPemilik() << "| Jenis : " << bantu->kendaraan.getJenisKendaraan() << endl;
            bantu = bantu->next;
            i++; 
        }while(bantu != antrianHead);
    cout << "================================" << endl;
    cout << "1. Masukkan kendaraan" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilih : ";
    cin >> input;
    if(input == "1"){
        tambahKendaraan(bantu->kendaraan);
        NodeParkir* hapus = bantu;
        bantu = bantu->next;
        hapus->prev->next = bantu;
        bantu->prev = hapus->prev;
        delete hapus;
        fungsiUmum.clearscreen();
    }else if(input == "2"){
        cout << "Masukkan plat nomor : ";
        string plat;
        cin >> plat;
        hapusKendaraanAntrian(plat);
    }else if(input != "3"){
        cout << "Input tidak valid" << endl;
    }
    }while(input != "3");
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