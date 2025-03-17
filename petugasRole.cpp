#include "petugasRole.h"
#include <iostream>
#include <conio.h>
#include "fungsiumum.h"
using namespace std;

//Constructor
PetugasRole::PetugasRole() : head(nullptr), tail(nullptr), antrianHead(nullptr), antrianTail(nullptr), historyHead(nullptr), historyTail(nullptr), historyPesanHead(nullptr), historyPesanTail(nullptr), jumlahMobil(0), jumlahMotor(0), jumlahSepeda(0) {}
//Destructor
PetugasRole::~PetugasRole() {
    while(head != nullptr) {
        NodeParkir* hapus = head;
        head = head->next;
        delete hapus;
    }

    while(antrianHead != nullptr) {
        NodeParkir* hapus = antrianHead;
        antrianHead = antrianHead->next;
        delete hapus;
    }

    while(historyHead != nullptr) {
        NodeParkir* hapus = historyHead;
        historyHead = historyHead->next;
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
    if(kendaraan.getJenisKendaraan() != "Mobil" && kendaraan.getJenisKendaraan() != "Motor" && kendaraan.getJenisKendaraan() != "Sepeda") {
        fungsiUmum.clearscreen();
        cout << "Jenis kendaraan tidak valid" << endl;
        cout << "Isikan Motor, Mobil atau Sepeda" <<endl;
        return;
    }else if (kendaraan.getJenisKendaraan() == "Mobil"){
        NodeParkir* nodeBaru = new NodeParkir(kendaraan);
        if(getJumlahMobil() < 5)
            {
                if(head == nullptr) {
                    head = nodeBaru;
                    tail = nodeBaru;
                    nodeBaru->next = head;
                    nodeBaru->prev = tail;
                } else {
                    tail->next = nodeBaru;
                    nodeBaru->prev = tail;
                    tail = nodeBaru;
                    tail->next = head;
                    head->prev = tail;
                }
                fungsiUmum.clearscreen();
                //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
                
                if(kendaraan.getStatus() == "p"){
                    if(historyPesanHead == nullptr) {
                        historyPesanHead = nodeBaru;
                        historyPesanTail = nodeBaru;
                        nodeBaru->nextPesan = historyPesanHead;
                        nodeBaru->prevPesan = historyPesanTail;
                    } else {
                        historyPesanTail->nextPesan = nodeBaru;
                        nodeBaru->prevPesan = historyPesanTail;
                        historyPesanTail = nodeBaru;
                        historyPesanTail->nextPesan = historyPesanHead;
                        historyPesanHead->prevPesan = historyPesanTail;
                    }
                    nodeBaru->kendaraan.setStatus("Berhasil");
                }else{} 

                
            
                cout << "Data berhasil ditambahkan" << endl;
                setJumlahMobil(getJumlahMobil() + 1);
            }else{
                if(antrianHead == nullptr) {
                antrianHead = nodeBaru;
                antrianTail = nodeBaru;
                antrianHead->next = nodeBaru;
                antrianHead->prev = nodeBaru;
                }else{
                antrianTail->next = nodeBaru;
                nodeBaru->prev = antrianTail;
                antrianTail = nodeBaru;
                antrianTail->next = antrianHead;
                antrianHead->prev = antrianTail;
                }
                fungsiUmum.clearscreen();
                //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
                
                if(kendaraan.getStatus() == "p"){
                    if(historyPesanHead == nullptr) {
                        historyPesanHead = nodeBaru;
                        historyPesanTail = nodeBaru;
                        nodeBaru->nextPesan = historyPesanHead;
                        nodeBaru->prevPesan = historyPesanTail;
                    } else {
                        historyPesanTail->nextPesan = nodeBaru;
                        nodeBaru->prevPesan = historyPesanTail;
                        historyPesanTail = nodeBaru;
                        historyPesanTail->nextPesan = historyPesanHead;
                        historyPesanHead->prevPesan = historyPesanTail;
                    }
                    nodeBaru->kendaraan.setStatus("Dalam Antrian");
                }else{}
                
               
                cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
                "Antrian akan diproses ketika parkiran kosong" << endl;
            }
    }else if(kendaraan.getJenisKendaraan() == "Motor"){
        NodeParkir* nodeBaru = new NodeParkir(kendaraan);
        if (getJumlahMotor() < 30)
        {
            if(head == nullptr) {
                head = nodeBaru;
                tail = nodeBaru;
                nodeBaru->next = head;
                nodeBaru->prev = tail;
            } else {
                tail->next = nodeBaru;
                nodeBaru->prev = tail;
                tail = nodeBaru;
                tail->next = head;
                head->prev = tail;
            }
            fungsiUmum.clearscreen();
            //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
            
            if(kendaraan.getStatus() == "p"){
                if(historyPesanHead == nullptr) {
                    historyPesanHead = nodeBaru;
                    historyPesanTail = nodeBaru;
                    nodeBaru->nextPesan = historyPesanHead;
                    nodeBaru->prevPesan = historyPesanTail;
                } else {
                    historyPesanTail->nextPesan = nodeBaru;
                    nodeBaru->prevPesan = historyPesanTail;
                    historyPesanTail = nodeBaru;
                    historyPesanTail->nextPesan = historyPesanHead;
                    historyPesanHead->prevPesan = historyPesanTail;
                }
                nodeBaru->kendaraan.setStatus("Berhasil");
            }else{} 

            
            
            cout << "Data berhasil ditambahkan" << endl;
            setJumlahMotor(getJumlahMotor() + 1);
        }else{
            cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
            "Antrian akan diproses ketika parkiran kosong" << endl;
            if(antrianHead == nullptr) {
            antrianHead = nodeBaru;
            antrianTail = nodeBaru;
            antrianHead->next = nodeBaru;
            antrianHead->prev = nodeBaru;
            }else{
            antrianTail->next = nodeBaru;
            nodeBaru->prev = antrianTail;
            antrianTail = nodeBaru;
            antrianTail->next = antrianHead;
            antrianHead->prev = antrianTail;
            }

            //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
            
            if(kendaraan.getStatus() == "p"){
                if(historyPesanHead == nullptr) {
                    historyPesanHead = nodeBaru;
                    historyPesanTail = nodeBaru;
                    nodeBaru->nextPesan = historyPesanHead;
                    nodeBaru->prevPesan = historyPesanTail;
                } else {
                    historyPesanTail->nextPesan = nodeBaru;
                    nodeBaru->prevPesan = historyPesanTail;
                    historyPesanTail = nodeBaru;
                    historyPesanTail->nextPesan = historyPesanHead;
                    historyPesanHead->prevPesan = historyPesanTail;
                }
                nodeBaru->kendaraan.setStatus("Dalam Antrian");
            }else{}
            
            
            fungsiUmum.clearscreen();
        }
    }else if(kendaraan.getJenisKendaraan() == "Sepeda"){
        NodeParkir* nodeBaru = new NodeParkir(kendaraan);
        if (getJumlahSepeda() < 10)
            {
                if(head == nullptr) {
                    head = nodeBaru;
                    tail = nodeBaru;
                    nodeBaru->next = head;
                    nodeBaru->prev = tail;
                } else {
                    tail->next = nodeBaru;
                    nodeBaru->prev = tail;
                    tail = nodeBaru;
                    tail->next = head;
                    head->prev = tail;
                }
                fungsiUmum.clearscreen();
                //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
                if(kendaraan.getStatus() == "p"){
                    if(historyPesanHead == nullptr) {
                        historyPesanHead = nodeBaru;
                        historyPesanTail = nodeBaru;
                        nodeBaru->nextPesan = historyPesanHead;
                        nodeBaru->prevPesan = historyPesanTail;
                    } else {
                        historyPesanTail->nextPesan = nodeBaru;
                        nodeBaru->prevPesan = historyPesanTail;
                        historyPesanTail = nodeBaru;
                        historyPesanTail->nextPesan = historyPesanHead;
                        historyPesanHead->prevPesan = historyPesanTail;
                    }
                    nodeBaru->kendaraan.setStatus("Berhasil");
                }else{}
                

                cout << "Data berhasil ditambahkan" << endl;
                setJumlahSepeda(getJumlahSepeda() + 1);
            }else{
                cout << "Parkiran sedang penuh, data kendaraan akan masuk kedalam daftar antrian \n" <<
                "Antrian akan diproses ketika parkiran kosng" << endl;
                if(antrianHead == nullptr) {
                antrianHead= nodeBaru;
                antrianTail = nodeBaru;
                antrianHead->next = nodeBaru;
                antrianHead->prev = nodeBaru;
                }else{
                antrianTail->next = nodeBaru;
                nodeBaru->prev = antrianTail;
                antrianTail = nodeBaru;
                antrianTail->next = antrianHead;
                antrianHead->prev = antrianTail;
            }
            //cek apakah kendaraan ditambahkan dari pesanan mahasiswa
            if(kendaraan.getStatus() == "p"){
                if(historyPesanHead == nullptr) {
                    historyPesanHead = nodeBaru;
                    historyPesanTail = nodeBaru;
                    nodeBaru->nextPesan = historyPesanHead;
                    nodeBaru->prevPesan = historyPesanTail;
                } else {
                    historyPesanTail->nextPesan = nodeBaru;
                    nodeBaru->prevPesan = historyPesanTail;
                    historyPesanTail = nodeBaru;
                    historyPesanTail->nextPesan = historyPesanHead;
                    historyPesanHead->prevPesan = historyPesanTail;
                }
                nodeBaru->kendaraan.setStatus("Dalam Antrian");
            }else{}
            
            
            fungsiUmum.clearscreen();
        }
    }
}

void PetugasRole::hapusKendaraan(string plat) {
    NodeParkir* hapus = nullptr;
    NodeParkir* bantu = head;
    bool ditemukan = false;

    do {
        if (bantu->kendaraan.getPlatNomor() == plat) {
            hapus = bantu;
            ditemukan = true;

            // Kalau node nya cuman 1
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                // kalau node nya itu di head
                if (hapus == head) {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                }
                // kalau node nya itu di tail
                else if (hapus == tail) {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                }
                // kalau node nya ditengah
                else {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
            }

            
            if (hapus->kendaraan.getJenisKendaraan() == "Mobil") {
                setJumlahMobil(getJumlahMobil() - 1);
            } else if (hapus->kendaraan.getJenisKendaraan() == "Motor") {
                setJumlahMotor(getJumlahMotor() - 1);
            } else if (hapus->kendaraan.getJenisKendaraan() == "Sepeda") {
                setJumlahSepeda(getJumlahSepeda() - 1);
            }

            //tambahkan ke history
            if(historyHead == nullptr) {
                historyHead = hapus;
                historyTail = hapus;
                hapus->next = historyHead;
                hapus->prev = historyTail;
            } else {
                historyTail->next = hapus;
                hapus->prev = historyTail;
                historyTail = hapus;
                historyTail->next = historyHead;
                historyHead->prev = historyTail;
            }

            //delete hapus;
            fungsiUmum.clearscreen();
            cout << "Data berhasil dihapus" << endl;
            displayMenuPetugas();
            return; 
        }
        bantu = bantu->next;
    } while (bantu != head);

    if (!ditemukan) {
        fungsiUmum.clearscreen();
        cout << "Data tidak ditemukan" << endl;
        displayMenuPetugas();
    }
}

void PetugasRole::hapusKendaraanAntrian(string plat) {
    if (antrianHead == nullptr) {
        fungsiUmum.clearscreen();
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    NodeParkir* bantu = antrianHead;
    NodeParkir* hapus = nullptr;

    do {
        if (bantu->kendaraan.getPlatNomor() == plat) {
            hapus = bantu;

            // Kalau node nya cuman 1
            if (antrianHead == antrianTail) {
                antrianHead = nullptr;
                antrianTail = nullptr;
            } else {
                // kalau node nya itu di head
                if (hapus == antrianHead) {
                    antrianHead = antrianHead->next;
                    antrianHead->prev = antrianTail;
                    antrianTail->next = antrianHead;
                }
                // kalau node nya itu di tail
                else if (hapus == antrianTail) {
                    antrianTail = antrianTail->prev;
                    antrianTail->next = antrianHead;
                    antrianHead->prev = antrianTail;
                }
                // kalau node nya ditengah
                else {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
            }

            delete hapus;
            fungsiUmum.clearscreen();
            cout << "Data berhasil dihapus" << endl;
            return;
        }
        bantu = bantu->next;
    } while (bantu != antrianHead);

    fungsiUmum.clearscreen();
    cout << "Data tidak ditemukan" << endl;
}

void PetugasRole::lihatKendaraan() const {
    fungsiUmum.clearscreen();
    if(head == nullptr) {
        fungsiUmum.clearscreen();   
        cout << "Parkiran kosong" << endl;
        return;
    }else{
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
    fungsiUmum.clearscreen();
}

void PetugasRole::kelolaAntrean() {
    fungsiUmum.clearscreen();
    string input;

    if (antrianHead == nullptr) {
        cout << "Antrian masih kosong" << endl;
        return;
    }

    cout << "================================" << endl;
    cout << "--- DAFTAR ANTRIAN PEMESANAN ---" << endl;
    cout << "================================" << endl;

    NodeParkir* bantu = antrianHead;
    int i = 1;

    do {
        cout << i << "| Plat : " << bantu->kendaraan.getPlatNomor() 
             << "| Pemilik : " << bantu->kendaraan.getPemilik() 
             << "| Jenis : " << bantu->kendaraan.getJenisKendaraan() << endl;
        bantu = bantu->next;
        i++;
    } while (bantu != antrianHead);

    cout << "================================" << endl;
    cout << "1. Masukkan kendaraan" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilih : ";
    cin >> input;

    if (input == "1") {
        string pilihan;
        cout << "Jenis Kendaraan : ";
        cin >> pilihan;
        bool ditemukan = false;

        if(pilihan != "Mobil" && pilihan != "Motor" && pilihan != "Sepeda"){
            fungsiUmum.clearscreen();
            cout << "Input tidak valid, masukkan Mobil, Motor atau Sepeda" << endl;
        }else if(pilihan == "Mobil"){
            NodeParkir* bantu = antrianHead;
            //cek apakah ada data mobil diantrean
            do
            {
                if(bantu->kendaraan.getJenisKendaraan() == "Mobil"){
                    ditemukan = true;
                }else{}
                bantu = bantu->next;
            } while (bantu != antrianHead);

            if (ditemukan == false)
            {
                fungsiUmum.clearscreen();
                cout << "Tidak ada Mobil di antrean" << endl;
            }else{
                //cek dulu apakah tersedia atau tidak slot nya di parkiran
                if(getJumlahMobil() >= 5){
                    fungsiUmum.clearscreen();
                    cout << "Maaf Parkiran untuk mobil masih penuh" << endl;
                    return;
                }else{
                    antrianHead->kendaraan.setStatus("Berhasil");
                    tambahKendaraan(antrianHead->kendaraan);
                    
                    NodeParkir* hapus = antrianHead;
                    if (antrianHead == antrianTail) {
                    antrianHead = nullptr;
                    antrianTail = nullptr;
                    } else {
                    antrianHead = antrianHead->next;
                    antrianHead->prev = antrianTail;
                    antrianTail->next = antrianHead;
                    }
                    //delete hapus;
    
                    fungsiUmum.clearscreen();
                    cout << "Data kendaraan berhasil dimasukkan" << endl;
                }
            }
            
            
        }else if(pilihan == "Motor"){
            NodeParkir* bantu = antrianHead;
            do
            {
                if(bantu->kendaraan.getJenisKendaraan() == "Motor"){
                    ditemukan = true;
                }else{}
                bantu = bantu->next;
            } while (bantu != antrianHead);

            if (ditemukan == false)
            {
                fungsiUmum.clearscreen();
                cout << "Tidak ada Motor di antrean" << endl;
            }else{
                //cek dulu apakah tersedia atau tidak slot nya di parkiran
                if(getJumlahMotor() >= 30){
                    fungsiUmum.clearscreen();
                    cout << "Maaf Parkiran untuk motor masih penuh" << endl;
                    return;
                }else{
                    tambahKendaraan(antrianHead->kendaraan);
    
                    NodeParkir* hapus = antrianHead;
                    if (antrianHead == antrianTail) {
                    antrianHead = nullptr;
                    antrianTail = nullptr;
                    } else {
                    antrianHead = antrianHead->next;
                    antrianHead->prev = antrianTail;
                    antrianTail->next = antrianHead;
                    }
                    //delete hapus;
    
                    fungsiUmum.clearscreen();
                    cout << "Data kendaraan berhasil dimasukkan" << endl;
                }
            }

        }else if(pilihan == "Sepeda"){
            NodeParkir* bantu = antrianHead;
            do
            {
                if(bantu->kendaraan.getJenisKendaraan() == "Sepeda"){
                    ditemukan = true;
                }else{}
                bantu = bantu->next;
            } while (bantu != antrianHead);

            if (ditemukan == false)
            {
                fungsiUmum.clearscreen();
                cout << "Tidak ada Sepeda di antrean" << endl;
            }else{
                //cek dulu apakah tersedia atau tidak slot nya di parkiran
                if(getJumlahSepeda() >= 10){
                    fungsiUmum.clearscreen();
                    cout << "Maaf Parkiran untuk Sepeda masih penuh" << endl;
                    return;
                }else{
                    tambahKendaraan(antrianHead->kendaraan);
    
                    NodeParkir* hapus = antrianHead;
                    if (antrianHead == antrianTail) {
                    antrianHead = nullptr;
                    antrianTail = nullptr;
                    } else {
                    antrianHead = antrianHead->next;
                    antrianHead->prev = antrianTail;
                    antrianTail->next = antrianHead;
                    }
                    //delete hapus;
    
                    fungsiUmum.clearscreen();
                    cout << "Data kendaraan berhasil dimasukkan" << endl;
                }
            }
        }
 
    } else if (input == "2") {
        cout << "Masukkan plat nomor : ";
        string plat;
        cin >> plat;
        hapusKendaraanAntrian(plat);
    } else if (input != "3") {
        cout << "Input tidak valid" << endl;
    }

    //fungsiUmum.clearscreen();
}


void PetugasRole::liatHistori(){
    fungsiUmum.clearscreen();
    char input;

    if (historyHead == nullptr) {
        cout << "History masih kosong" << endl;
        return;
    }

    cout << "===============================" << endl;
    cout << "------ HISTORY KENDARAAN ------" << endl;
    cout << "===============================" << endl;

    int i = 0;
    NodeParkir* bantuHitung = historyHead;
    //Hitung jumla node
    do{
        i++;
        bantuHitung = bantuHitung->next;
    }while(bantuHitung != historyHead);

    NodeParkir* bantu = historyTail;

    do {
        cout << i << "| Plat : " << bantu->kendaraan.getPlatNomor() 
             << "| Pemilik : " << bantu->kendaraan.getPemilik() 
             << "| Jenis : " << bantu->kendaraan.getJenisKendaraan() << endl;
        bantu = bantu->prev;
        i--;
    } while (bantu != historyTail);

    cout << "===============================" << endl;
    cout << "Tekan apa saja untuk kembali" << endl;
    input = getch();
    
    fungsiUmum.clearscreen();
}

void PetugasRole::liatHistoriPesan(){
    fungsiUmum.clearscreen();
    char input;

    if (historyPesanHead == nullptr) {
        cout << "Pesanan masih kosong" << endl;
        return;
    }

    cout << "===============================" << endl;
    cout << "----- HISTORI PARKIR ANDA -----" << endl;
    cout << "===============================" << endl;

    int i = 0;
    NodeParkir* bantuHitung = historyPesanHead;
    //Hitung jumla node
    do{
        i++;
        bantuHitung = bantuHitung->nextPesan;
    }while(bantuHitung != historyPesanHead);

    NodeParkir* bantu = historyPesanTail;

    do {
        cout << i << "| Plat : " << bantu->kendaraan.getPlatNomor() 
             << "| Pemilik : " << bantu->kendaraan.getPemilik() 
             << "| Status : " << bantu->kendaraan.getStatus() << endl;
        bantu = bantu->prevPesan;
        i--;
    } while (bantu != historyPesanTail);

    cout << "===============================" << endl;
    cout << "Tekan apa saja untuk kembali" << endl;
    input = getch();
    
    fungsiUmum.clearscreen();
}


void PetugasRole::displayMenuPetugas(){
    fungsiUmum.hideCursor();
    int pilihanTerkini = 0;
    int key;
    const int PILIHAN_MENU = 6;
    const string menu[PILIHAN_MENU] = {
        "1. Tambah Kendaraan",
        "2. Lihat Kendaraan di Parkiran",
        "3. Hapus Kendaraan",
        "4. Kelola antrean kendaraan",
        "5. Lihat histori kendaraan keluar",
        "6. Kembali"
    };

    while (true) {
        fungsiUmum.clearscreen();
        cout << "==========================" << endl;
        cout << "--- DASHBOARD  PETUGAS ---" << endl;
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
                case 0: // Tambah Kendaraan
                    {
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
                    }
                    break;
                case 1: // Lihat Kendaraan
                    lihatKendaraan();
                    break;
                case 2: // Hapus Kendaraan
                    if (head == nullptr) {
                        fungsiUmum.clearscreen();
                        cout << "Parkiran Masih Kosong" << endl;
                    } else {
                        string plat;
                        cout << "Masukkan plat nomor : ";
                        cin >> plat;
                        hapusKendaraan(plat);
                    }
                    break;
                case 3: // Kelola Antrean
                    kelolaAntrean();
                    break;
                case 4: // Lihat Histori
                    liatHistori();
                    break;
                case 5: // Kembali
                    return;
            }
            if(pilihanTerkini == 5){
                cout << "Apakah anda yakin mau kembali?";
                getch();
            }else{
                cout << "Tekan apa saja untuk kembali";
                getch();
            }
            
        }
    }
    
}
