#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>

using namespace std;

class Stack
{
    private:
        int maxStackSize;
        vector<int> dfs;
        int top;
    public:
        Stack();
        Stack(int max);
        void push(int newItem);
        int pop();
};

class StackException : public exception{
    public:
        StackException() {}
        virtual const char* what() const noexcept override{
            return "Bledna operacja na stosie!";
        }
};

class StackFullException : public StackException{
    int element = 0 ;
    int maxStackSize = 0;
    string message;
    public:
        StackFullException(){}
        StackFullException(string p, int e, int s){
            this->message = p;
            this->element = e;
            this->maxStackSize = s;
        }
        virtual const char* what() const noexcept override{
            return "Pełny stos";
        }
};

class StackEmptyException : public StackException{
    string message;
    public:
        StackEmptyException();
        StackEmptyException(string p){
            this->message = p;
        }
        virtual const char* what() const noexcept override{
            return "Pusty stos";
        }
};

#endif

