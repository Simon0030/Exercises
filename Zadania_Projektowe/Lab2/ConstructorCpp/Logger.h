#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime> 
#include <string>

using namespace std;

class Logger{
    bool debug;
    public:
        Logger(bool debug);
        void log(string s);
    };


#endif