#ifndef STUDENT_H
#define STUDENT_H
#include "Osoba.h"
#include <map>

using namespace std;

class Student: public Osoba{
    private:
        map<string,int> *oceny;

    public:
        Student();
        ~Student();
        Student(string i, string naz, tm d, Adres a, map<string, int> oc);
        Student(const Student&);
        Student(Student&&);

        void dodaj_ocene(string st, int oc);

        void pokaz_ocene(string st);

        void pokaz_oceny();

        void przedstaw();
};

#endif