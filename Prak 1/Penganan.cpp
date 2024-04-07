#include "Penganan.hpp"
#include <iostream>
using namespace std;
int Penganan :: n_rumah = 0;
int Penganan :: uang = 0;

Penganan :: Penganan () {
    this->keik = 0;
    this->panekuk =0;
}

Penganan :: Penganan (int keik, int panekuk){
    this->keik = keik;
    this->panekuk = panekuk;
}

int Penganan::GetKeik() const{
    return keik;
}

int Penganan::GetPanekuk() const{
    return panekuk;
}

void Penganan::SetKeik(int a) {
    this->keik = a;
}

void Penganan::SetPanekuk(int a) {
    this->panekuk = a;
}

int Penganan::JumlahUang(){
    return uang;
}

int Penganan::HitungNRumah(){
    return n_rumah;
}

Penganan operator+(const Penganan &other1, const Penganan &other2){
    Penganan c;
    c.keik = other1.keik + other2.keik;
    c.panekuk = other1.panekuk + other2.panekuk;
    Penganan::n_rumah++;
    return c;
}

Penganan operator-(const Penganan &other1, const Penganan &other2){
    Penganan c;
    Penganan d;
    if(other1.keik < other2.keik){
        c.keik += other1.keik;
        d.keik = 0;
    }
    else {
        c.keik += other1.keik - other2.keik;
        d.keik =  other1.keik - other2.keik;
    }
    if(other1.panekuk < other2.panekuk){
        c.panekuk += other1.panekuk;
        d.panekuk = 0;
    }
    else {
        c.panekuk += other1.panekuk - other2.panekuk;
        d.panekuk =  other1.panekuk - other2.panekuk;
    }

    Penganan::uang+=c.keik*51 + c.panekuk*37;
    return d;
}

Penganan operator^(const Penganan& other1, const int x){
    Penganan c;
    Penganan d;
    if (other1.keik < x) {
        c.keik += x;
        d.keik=0;
    }
    else {
        c.keik += other1.keik - x;
        d.keik +=other1.keik - x;
    }
    if (other1.panekuk < x) {
        c.panekuk += x;
        d.panekuk=0;
    }
    else {
        c.panekuk += other1.panekuk - x;
        d.panekuk +=other1.panekuk - x;
    }

    Penganan::uang = Penganan::uang - ( c.panekuk*37 + c.keik*51);
    return d;
}

Penganan operator^(const int x,const Penganan& other1){
    Penganan c;
    Penganan d;
    if (other1.keik < x) {
        c.keik += x;
        d.keik=0;
    }
    else {
        c.keik += other1.keik - x;
        d.keik +=other1.keik - x;
    }
    if (other1.panekuk < x) {
        c.panekuk += x;
        d.panekuk=0;
    }
    else {
        c.panekuk += other1.panekuk - x;
        d.panekuk +=other1.panekuk - x;
    }

    Penganan::uang = Penganan::uang - ( c.panekuk*37 + c.keik*51);
    return d;
}

void Penganan::Print(){
    cout<<this->keik<<"keik"<<"-"<<this->panekuk<<"panekuk"<<endl;
}

