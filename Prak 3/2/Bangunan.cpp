#include "Bangunan.hpp"
#include <iostream>

using namespace std;

Bangunan::Bangunan() : namaBangunan("Bangunan Kosong") {}

Bangunan::Bangunan(string namaBangunan) : namaBangunan(namaBangunan){};

string Bangunan::getNamaBangunan()
{
    return this->namaBangunan;
}
