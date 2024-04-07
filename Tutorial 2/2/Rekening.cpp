#include <iostream>
#include "Rekening.h"

Rekening :: Rekening (double saldo) {
    if (saldo < 0) {
        this->saldo = 0;
    } else {
        this->saldo = saldo;
    }
}

void Rekening :: setSaldo (double saldo) {
    this->saldo = saldo;
}

double Rekening :: getSaldo () const {
    return saldo;
}

void Rekening :: simpanUang (double uang) {
    saldo += uang;
}

bool Rekening :: tarikUang (double uang) {
    if (saldo - uang >= 0) {
        saldo -= uang;
        return true;
    } else {
        return false;
    }
}