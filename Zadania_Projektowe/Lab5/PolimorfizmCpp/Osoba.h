#ifndef OSOBA_H
#define OSOBA_H

#include "Adres.h"
#include <string>
#include <ctime>

using namespace std;


class Osoba{
    protected:
        string *imie;
        string *nazwisko;
        tm *data;
        Adres *adres;
    public:
        Osoba();
        virtual ~Osoba();
        Osoba(string i, string naz, tm d, Adres a);
        Osoba(const Osoba &);
        Osoba(Osoba &&);

        void ustaw_imie(string i, string naz);

        void pokaz_imie();

        void ustaw_date(int d, int m, int y);

        void pokaz_date();

        void ustaw_adres(string ul, string mi, string n);

        void pokaz_adres();

        virtual void przedstaw() = 0;
};

#endif