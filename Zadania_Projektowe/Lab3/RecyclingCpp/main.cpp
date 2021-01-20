#include <memory>
#include <iostream>
#include <stdlib.h>
#include "Wezel.h"

using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        shared_ptr<Wezel> w1 = make_shared<Wezel>();

        //zadanie 8
        //shared_ptr<Wezel> w2 = make_shared<Wezel>();
        //w1->next = w2;
        //w2->next = w1;

        //zad 10
        weak_ptr<Wezel> w2 = w1;
        (w2.expired());
    }
    return 0;
}