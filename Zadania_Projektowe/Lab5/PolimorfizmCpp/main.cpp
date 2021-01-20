#include "Adres.h"
#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"
#include <iostream>
#include <ctime>
#include <map>
#include <vector>

using namespace std;

void foo(Osoba &os){
    os.przedstaw();
}

void bar(Osoba *os){
    os->przedstaw();
}


int main(){
    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    vector<Osoba*> tablicaOsob;
    string opt;

    while(true){
        cout << "Wpisz student, aby stworzyć obiekt student lub pracownik aby stworzyć obiekt pracownik: ";
        cin >> opt;
        if (opt == "student" || opt == "pracownik"){
            tablicaOsob.push_back(m[opt]->utworz());
        }
    }
    return 0;
}
