#include "Stack.h"
#include <iostream>

using namespace std;

void foo(Stack &s){
    try{
        for(int i = 0; i < 49; i++){
            s.push(i);
        }
    }
    catch(StackException e){
        cout << e.what() << endl;
    }
}

void bar(Stack &s){
    try{
        for(int i = 0; i < 49; i++){
            s.push(i);
        }
    }
    catch(StackException &e){
        cout << e.what() << endl;
    }
}


int main(){
    int nowy, choose;
    Stack stos;

    while(exit){
        cout << "Jeśli chcesz dodać element do stosu wciśnij 1, jeśli chcesz usunąć wciśnij 2: \n";
        cin >> choose;
        try{
            switch(choose){
                case 1:
                    cout << "Podaj liczbe, którą chcesz dodać: ";
                    cin >> nowy;
                    stos.push(nowy);
                    break;
                case 2:
                    cout << "\nUsunięto liczbe " << stos.pop() << " ze stosu\n";
                    break;
            }
        }
        catch(StackException &e){
            cout << e.what() << endl;
        }
    }

    return 0;
}
