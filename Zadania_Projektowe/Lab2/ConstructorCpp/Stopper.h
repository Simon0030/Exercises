#ifndef STOPPER_H
#define STOPPER_H
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime> 
#include <string>

using namespace std;
using namespace std::chrono;

class Stopper{
    private:
        time_point<high_resolution_clock> start_time;
        milliseconds duration;
    public:
        Stopper();
        void start();
        void stop();
        void reset();
        void showTotal();
    };


#endif