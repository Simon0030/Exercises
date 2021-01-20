#ifndef FABRYKAPRACOWNIKOW_H
#define FABRYKAPRACOWNIKOW_H

#include "FabrykaOsob.h"
#include "Pracownik.h"

using namespace std;


class FabrykaPracownikow : public FabrykaOsob{
    public:
        Pracownik* utworz();
};

#endif