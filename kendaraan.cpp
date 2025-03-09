#include "kendaraan.h"
#include <iostream>


Kendaraan::Kendaraan(string plat, string pemilik, string jenis, string waktu):
    platNomor(plat), pemilik(pemilik), jenisKendaraan(jenis), waktuMasuk(waktu) {}

string Kendaraan::getPlatNomor() const {
    return platNomor;
}

string Kendaraan::getPemilik() const {
    return pemilik;
}

string Kendaraan::getJenisKendaraan() const {
    return jenisKendaraan;
}

string Kendaraan::getWaktuMasuk() const {
    return waktuMasuk;
}

