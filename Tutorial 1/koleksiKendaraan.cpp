#include "koleksiKendaraan.hpp"

KoleksiKendaraan::KoleksiKendaraan() : size(100), Neff(0)
{
}

KoleksiKendaraan ::KoleksiKendaraan(int size) : size(size), Neff(0)
{
    kendaraanArray = new Kendaraan[size];
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan &other) : size(other.size), Neff(other.Neff)
{
    Kendaraan *kendaraanArray = new Kendaraan[size];
    for (int i = 0; i < Neff; ++i)
    {
        kendaraanArray[i] = other.kendaraanArray[i];
    }
}

KoleksiKendaraan ::~KoleksiKendaraan()
{
    delete[] kendaraanArray;
}

void KoleksiKendaraan::printAll()
{
    for (int i = 0; i < Neff; ++i)
    {
        kendaraanArray[i].printInfo();
    }
}

KoleksiKendaraan &KoleksiKendaraan ::operator=(const KoleksiKendaraan &other)
{
    if (this != &other)
    {
        delete[] kendaraanArray;
        size = other.size;
        Neff = other.Neff;
        kendaraanArray = new Kendaraan[size];
        for (int i = 0; i < Neff; ++i)
        {
            kendaraanArray[i] = other.kendaraanArray[i];
        }
    }
    return *this;
}

KoleksiKendaraan &KoleksiKendaraan ::operator<<(const Kendaraan &k)
{
    kendaraanArray[Neff] = k;
    Neff++;
    return *this;
}

KoleksiKendaraan &KoleksiKendaraan ::operator<<(const KoleksiKendaraan &other)
{
    int space = size- Neff;
    int NumToAdd;
    if (space < other.Neff)
    {
        NumToAdd = space;
    }
    else
    {
        NumToAdd = other.Neff;
    }

    for (int i = 0; i < NumToAdd; ++i)
    {
        kendaraanArray[Neff + i] = other.kendaraanArray[i];
        Neff++;
    }
    return *this;
}