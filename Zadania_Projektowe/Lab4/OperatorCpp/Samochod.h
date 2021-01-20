#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

using namespace std;

class Samochod{
    private:
        float pojemnosc_baku;
        float poziom_paliwa;
        unsigned int liczba_kilometrow;
        string model;
    public:
        Samochod();
        Samochod(float p, string m);
        float odczytaj_pojemnosc_baku()const;
        void tankowanie(float ilosc_paliwa);
        void jezdzenie(unsigned int droga);
        operator bool() const{
            if( this->model == "" || this->pojemnosc_baku <= 0){
                return false;
            }else{
                return true;
            }
        }
        bool operator !() const{
            if( this->model == "" || this->pojemnosc_baku <= 0){
                return false;
            }else{
                return true;
            }
        }
        friend ostream & operator << (ostream &os, const Samochod & samochod){
            string space = " ";
            string end = "\n";
            os << samochod.model << space << to_string(samochod.poziom_paliwa) << end;
            return os;
        }

        bool operator < (const Samochod &samochod) const{
            return this->model < samochod.model;
        }

        void operator ++(){
            this->poziom_paliwa += 1.0;
        }

       void operator ,(){
            this->pojemnosc_baku += 1.0;
        }

        void operator |=(){
            this->liczba_kilometrow += 1.0;
        }

};

#endif
