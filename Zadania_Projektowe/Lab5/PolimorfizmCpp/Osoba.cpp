#include "Osoba.h"
#include "Adres.h"
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

Osoba::Osoba(){
    this->imie = nullptr;
    this->nazwisko = nullptr;
    this->data = nullptr;
    this->adres = nullptr;
}


Osoba::Osoba(string i, string naz, tm d, Adres a){
    this->imie = new string(i);
    this->nazwisko = new string(naz);
    this->data = new tm(d);
    this->adres = new Adres(a);
}


Osoba::~Osoba(){
    if(this->imie != nullptr)delete this->imie;
    if(this->nazwisko != nullptr)delete this->nazwisko;
    if(this->data != nullptr)delete this->data;
    if(this->adres != nullptr)delete this->adres;
}


Osoba::Osoba(const Osoba &o){
    this->imie = new string(*o.imie);
    this->nazwisko = new string(*o.nazwisko);
    this->data = new tm(*o.data);
    this->adres = new Adres(*o.adres);
}

Osoba::Osoba(Osoba &&o){
    this->imie = move(o.imie);
    this->nazwisko = move(o.nazwisko);
    this->data = move(o.data);
    this->adres = move(o.adres);
}

void Osoba::ustaw_imie(string i, string naz){
    this->imie = new string(i);
    this->nazwisko = new string(naz);
}

void Osoba::pokaz_imie(){
    cout << *this->imie << " " << *this->nazwisko << endl;
}


void Osoba::ustaw_date(int d, int m, int y){
    this->data = new tm();
    if( d > 31 && d < 1){
        cout << "Nie ma takiej daty\n";
    }else{
        (*this->data).tm_mday = d;
        if( m > 12 && m < 1){
            cout << "Nie ma takiej daty\n";
        }else{
            (*this->data).tm_mon = m;
            (*this->data).tm_year = y;
        }
    }
}

void Osoba::pokaz_date(){
    cout << (*this->data).tm_mday << "." << (*this->data).tm_mon << "." << (*this->data).tm_year << endl;
}


void Osoba::ustaw_adres(string ul, string mi, string n){
    this->adres = new Adres();
    this->adres = new Adres(ul, mi, n);
}

void Osoba::pokaz_adres(){
    cout << (*this->adres).pokaz_adres() << endl;
};

void Osoba::przedstaw(){
    this->pokaz_imie();
    this->pokaz_date();
    this->pokaz_adres();
};