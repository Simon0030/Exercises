#include "Adres.h"
#include <string>

using namespace std;

Adres::Adres(){
    this->ulica = "Długa";
    this->miasto = "Poznan";
    this->numer = "15";
}


Adres::Adres(string ul, string mi, string n){
    this->ulica = ul;
    this->miasto = mi;
    this->numer = n;
}


string Adres::pokaz_adres(){
    return this->ulica + ", " + this->miasto + ", " + this->numer;
}