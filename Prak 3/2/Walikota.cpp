#include "Walikota.hpp"
#include "Bangunan.hpp"
#include <iostream>
#include <vector>

using namespace std;

Walikota::Walikota()
{
    this->kayu = DEFAULT_KAYU;
    this->gulden = DEFAULT_GULDEN;
    this->pekerja = DEFAULT_PEKERJA;
    vector<Bangunan> bangunan;
    this->bangunan = bangunan;
}

Walikota::Walikota(int kayu, int gulden, int pekerja)
{
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
    vector<Bangunan> bangunan;
    this->bangunan = bangunan;
}

Walikota::~Walikota() {}


void Walikota::tambahKayu(int num)
{
    this->kayu += num;
}

void Walikota::tambahGulden(int num)
{
    this->gulden += num;
}

void Walikota::tambahPekerja(int num)
{
    this->pekerja += num;
}

void Walikota::pakaiKayu(int num)
{
    if (this->kayu < num)
    {
        throw KayuTidakCukupException();
    }

    this->kayu -= num;
}

void Walikota::pakaiGulden(int num)
{
    if (this->gulden < num)
    {
        throw GuldenTidakCukupException();
    }

    this->gulden -= num;
}

void Walikota::pekerjakanPekerja()
{
    if (this->pekerja < 1)
    {
        throw PekerjaTidakCukupException();
    }

    this->pekerja--;
}

void Walikota::batalPakaiKayu(int num)
{
    this->kayu += num;
}

void Walikota::batalPakaiGulden(int num)
{
    this->gulden ++;
}

void Walikota::batalkanPekerja()
{
    this->pekerja ++;
}

void Walikota::sebutBangunan(int idx)
{
    try
    {
        cout << bangunan.at(idx).getNamaBangunan() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}


void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden)
{
    try
    {
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();
        Bangunan b(namaBangunan);
        bangunan.push_back(b);
        cout << "Bangunan [" << bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << endl;
    }
    catch (KayuTidakCukupException &e)
    {
        cout << e.what() << ", beli kayu dulu." << endl;

    }
    catch (GuldenTidakCukupException &e)
    {
        batalPakaiKayu(kayu);
        cout << e.what() << ", tagih pajak dulu." << endl;
    }
    catch (PekerjaTidakCukupException &e)
    {
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden);
        cout << e.what() << ", rekrut pekerja dulu." << endl;
    }
}

void Walikota::statusKota()
{
    cout << "Status" << endl;
    cout << "  Kayu: " << this->kayu << endl;
        cout << "  Gulden: " << this->gulden << endl;
        cout << "  Pekerja: " << this->pekerja << endl;
    cout << "  Bangunan:" << endl;
    for (int i = 0; i < bangunan.size(); i++)
    {
        cout << "    Bangunan[" << i + 1 << "]: " << bangunan[i].getNamaBangunan() << endl;
    }
}