#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP
#include <iostream>
#include <string>

using namespace std;

class Kendaraan
{
private:
    int nomor;
    string kategori;
    int tahunKeluaran;
    string merk;

public:
    Kendaraan();
    Kendaraan(int, string, int, string);
    Kendaraan(const Kendaraan &);
    Kendaraan &operator=(const Kendaraan &);
    ~Kendaraan();

    void printInfo();
    int biayaSewa(int);
};

#endif