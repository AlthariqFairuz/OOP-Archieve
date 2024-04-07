#include "kendaraan.hpp"
#include "koleksiKendaraan.hpp"

int main()
{
    Kendaraan k1(1, "Toyota", 2010, "mobil");
    Kendaraan k2;
    Kendaraan k3(k1);
    k3.printInfo();
    k3 = k1;
    k3.printInfo();
    return 0;
}