#include "RekeningTabungan.h"

RekeningTabungan ::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo)
{
    if (biayaTransaksi < 0)
    {
        this->biayaTransaksi = 0;
    }
    else
    {
        this->biayaTransaksi = biayaTransaksi;
    }
}

void RekeningTabungan ::setBiayaTransaksi(double biayaTransaksi)
{
    this->biayaTransaksi = biayaTransaksi;
}

double RekeningTabungan ::getBiayaTransaksi() const
{
    return biayaTransaksi;
}

void RekeningTabungan ::simpanUang(double uang)
{
    Rekening::simpanUang(uang);
    int newSaldo = getSaldo() - biayaTransaksi;
    setSaldo(newSaldo);
}

bool RekeningTabungan ::tarikUang(double uang)
{
    if (Rekening::tarikUang(uang))
    {
        int newSaldo = getSaldo() - biayaTransaksi;
        setSaldo(newSaldo);
        return true;
    }
    return false;
}