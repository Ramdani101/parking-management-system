#include "kendaraan.h"
#include <iostream>


Kendaraan::Kendaraan(string plat, string pemilik, string jenis, string waktu):
    platNomor(plat), pemilik(pemilik), jenisKendaraan(jenis), waktuMasuk(waktu), statusKendaraan("") {}

Kendaraan::Kendaraan(string plat, string pemilik, string jenis, string waktu, string status):
platNomor(plat), pemilik(pemilik), jenisKendaraan(jenis), waktuMasuk(waktu), statusKendaraan(status) {}

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

string Kendaraan::getStatus() const {
    return statusKendaraan;
}

void Kendaraan::setStatus(string ubah){
    statusKendaraan = ubah;
}

