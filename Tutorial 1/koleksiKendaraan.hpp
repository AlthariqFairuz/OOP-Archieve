#ifndef KOLEKSIKENDARAAN_HPP
#define KOLEKSIKENDARAAN_HPP
#include "kendaraan.hpp"

class KoleksiKendaraan
{
private:
    Kendaraan *kendaraanArray;
    int size;
    int Neff;

public:
    KoleksiKendaraan();
    KoleksiKendaraan(int);
    KoleksiKendaraan(const KoleksiKendaraan &);
    KoleksiKendaraan &operator=(const KoleksiKendaraan &);
    ~KoleksiKendaraan();

    void printAll();

    KoleksiKendaraan &operator<<(const Kendaraan &);
    KoleksiKendaraan &operator<<(const KoleksiKendaraan &);
};

#endif