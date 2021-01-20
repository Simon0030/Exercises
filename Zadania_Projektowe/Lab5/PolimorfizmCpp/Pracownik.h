#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Osoba.h"
#include <vector>
#include <string>

using namespace std;

class Pracownik: public Osoba{
    private:
        vector<string> *przedmioty;
    public:
        Pracownik();
        ~Pracownik();
        Pracownik(string i, string naz, tm d, Adres a, vector<string> st);
        Pracownik(const Pracownik &);
        Pracownik(Pracownik &&);
        void dodaj_przedmiot(string st);
        void usun_przedmiot(string st);
        bool czy_prowadzi(string st);
        void pokaz_przedmioty();
        void przedstaw();
};

#endif