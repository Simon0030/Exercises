#include "Samochod.h"

using namespace std;

Samochod::Samochod(){
    this->pojemnosc_baku = 100.0;
    this->poziom_paliwa = 50.0;
    this->liczba_kilometrow = 10.0;
    this->model = "Ferrari";
}

Samochod::Samochod(float ilosc, string marka){
    this->model = marka;
    this->pojemnosc_baku = ilosc;
    this->poziom_paliwa = 0;
    this->liczba_kilometrow = 0;
}

void Samochod::tankowanie(float ilosc){
    this->poziom_paliwa += ilosc;
    if( this->poziom_paliwa > this->pojemnosc_baku) this->poziom_paliwa = this->pojemnosc_baku;
}

void Samochod::jezdzenie(unsigned int km){
    while(this->poziom_paliwa > 0 || km > 0){
        this->poziom_paliwa -= 0.5;
        this->liczba_kilometrow += 1.0;
        km--;
    }
}

