#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <iostream>
using namespace std;

class Kendaraan{
    private : 
    string platNomor,pemilik,jenisKendaraan,waktuMasuk,statusKendaraan;

    public :
    Kendaraan(string plat, string pemilik, string jenis, string waktu);
    Kendaraan(string plat, string pemilik, string jenis, string waktu, string status);

    string getPlatNomor() const;
    string getPemilik() const;
    string getJenisKendaraan() const;
    string getWaktuMasuk() const;
    string getStatus() const;
    void setStatus(string ubah);

};



#endif