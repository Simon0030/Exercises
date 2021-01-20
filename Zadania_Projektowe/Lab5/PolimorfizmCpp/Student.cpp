#include "Student.h"
#include "Adres.h"
#include <iostream>

Student::Student(){
    this->oceny = nullptr;
}

Student::~Student(){
    if(this->imie != nullptr)delete this->imie;
    if(this->nazwisko != nullptr)delete this->nazwisko;
    if(this->data != nullptr)delete this->data;
    if(this->adres != nullptr)delete this->adres;
    if(this->oceny != nullptr)delete this->oceny;
}


Student::Student(string i, string naz, tm d, Adres a, map<string, int> oc){
    this->imie = new string(i);
    this->nazwisko = new string(naz);
    this->data = new tm(d);
    this->adres = new Adres(a);
    this->oceny = new map<string, int>(oc);
}



Student::Student(const Student& st){
    this->imie = new string(*st.imie);
    this->nazwisko = new string(*st.nazwisko);
    this->data = new tm(*st.data);
    this->adres = new Adres(*st.adres);
    this->oceny = new map<string, int>(*st.oceny);
}


Student::Student(Student&& st){
    this->imie = move(st.imie);
    this->nazwisko = move(st.nazwisko);
    this->data = move(st.data);
    this->adres = move(st.adres);
    this->oceny = move(st.oceny);
}


void Student::dodaj_ocene(string st, int oc){
    if(this->oceny == nullptr){
        this->oceny = new map<string, int>();
    }
    if(oc > 0 && oc < 6){
        (*this->oceny)[st] = oc;
    }else{
        cout << "Ocena musi być od 1 do 5\n";
    }
}


void Student::pokaz_ocene(string st){
    auto search = (*this->oceny).find(st);
    if(search != (*this->oceny).end()){
        cout << search->first << " : " << search->second << endl;
    }else{
        cout << "Błędny przedmiot\n";
    }
}


void Student::pokaz_oceny(){
    for(map<string,int>::iterator it=(*this->oceny).begin(); it!= (*this->oceny).end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
}


void Student::przedstaw(){
    Osoba::przedstaw();
    cout << "Oceny:\n";
    this->pokaz_oceny();
}