#include "Stack.h"

Stack::Stack(){
    this->maxStackSize = 50;
}


Stack::Stack(int max_ilosc){
    this->maxStackSize = max_ilosc;
}


void Stack::push(int nowy){
    if(this->dfs.size() == this->maxStackSize){
        throw StackFullException("Pełny stos", nowy, maxStackSize);
    }else{
        dfs.push_back(nowy);
    }
}


int Stack::pop(){
    if(this->dfs.size() == 0){
        throw StackEmptyException("Pusty stos");
    }else{
        int last = this->dfs.back();
        this->dfs.pop_back();
        return last;
    }
}
