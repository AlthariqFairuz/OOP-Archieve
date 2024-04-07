#include "kendaraan.hpp"    

Kendaraan::Kendaraan () : nomor(0), kategori("mobil"), tahunKeluaran(0), merk("XXX") {}

Kendaraan::Kendaraan (int nomor,string merk,int tahunKelauran,string kategori) : nomor(nomor), kategori(kategori), tahunKeluaran(tahunKelauran), merk(merk) {}

Kendaraan::Kendaraan (const Kendaraan &k) : nomor(k.nomor), kategori(k.kategori), tahunKeluaran(k.tahunKeluaran), merk(k.merk) {}

Kendaraan& Kendaraan::operator=(const Kendaraan &k) {
    nomor = k.nomor;
    kategori = k.kategori;
    tahunKeluaran = k.tahunKeluaran;
    merk = k.merk;
    return *this;
}

Kendaraan::~Kendaraan () {}


void Kendaraan :: printInfo()
{
    cout << "Nomor Kendaraan : " << nomor << endl;
    cout << "Merk Kendaraan : " << merk << endl;
    cout << "Tahun Keluaran : " << tahunKeluaran << endl;
    cout << "Kategori Kendaraan : " << kategori << endl;
}

int Kendaraan:: biayaSewa(int lamaSewa) {
    if (kategori == "bus") {
        return lamaSewa * 1000000;
    } else if (kategori == "minibus") {
        if (lamaSewa <= 5) {
            return 5000000;
        } else {
            return 5000000 + 500000*(lamaSewa - 5);
        }
    } else if (kategori == "mobil") {
        return 500000 * lamaSewa;
    }
}

class bus : public Kendaraan {
    public:
        int kapasitas;
        bus (int nomor, string merk, int tahunKeluaran, string kategori, int kapasitas) : Kendaraan(nomor, merk, tahunKeluaran, kategori), kapasitas(kapasitas) {}
};