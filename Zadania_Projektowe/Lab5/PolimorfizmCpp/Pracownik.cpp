#include "Pracownik.h"
#include "Adres.h"
#include <algorithm>
#include <iostream>

using namespace std;

Pracownik::~Pracownik(){
    if(this->imie != nullptr)delete this->imie;
    if(this->nazwisko != nullptr)delete this->nazwisko;
    if(this->data != nullptr)delete this->data;
    if(this->adres != nullptr)delete this->adres;
    if(this->przedmioty != nullptr)delete this->przedmioty;
}


Pracownik::Pracownik(string i, string naz, tm d, Adres a, vector<string> st){
    this->imie = new string(i);
    this->nazwisko = new string(naz);
    this->data = new tm(d);
    this->adres = new Adres(a);
    this->przedmioty = new vector<string>(st);
}


Pracownik::Pracownik(const Pracownik & p){
    this->imie = new string(*p.imie);
    this->nazwisko = new string(*p.nazwisko);
    this->data = new tm(*p.data);
    this->adres = new Adres(*p.adres);
    this->przedmioty = new vector<string>(*p.przedmioty);
}


Pracownik::Pracownik(Pracownik && p){
    this->imie = move(p.imie);
    this->nazwisko = move(p.nazwisko);
    this->data = move(p.data);
    this->adres = move(p.adres);
    this->przedmioty = move(p.przedmioty);
}

void Pracownik::dodaj_przedmiot(string s){
    if(this->przedmioty == nullptr){
        this->przedmioty = new vector<string>({});
    }
    (*this->przedmioty).push_back(s);
}


void Pracownik::pokaz_przedmioty(){
    for(auto const& value: *this->przedmioty){
        cout << value << endl;
    }
}


void Pracownik::przedstaw(){
    Osoba::przedstaw();
    cout << "Prowadzone przedmioty:\n";
    this->pokaz_przedmioty();
}