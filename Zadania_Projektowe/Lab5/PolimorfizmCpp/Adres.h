#ifndef ADRES_H
#define ADRES_H

#include <string>

using namespace std;

class Adres{
    private:
        string ulica;
        string miasto;
        string numer;

public:
        Adres();
        Adres(string ul, string mi, string n);
        string pokaz_adres();
};

#endif