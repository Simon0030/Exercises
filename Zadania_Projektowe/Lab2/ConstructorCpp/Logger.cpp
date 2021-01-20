#include <iostream>
#include "Logger.h"

using namespace std;


Logger::Logger(bool debug){
    this -> debug = debug;
};

void Logger::log(string s){
    if (!debug)
        return;
    auto end = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << ctime(&end_time) << s << endl;
}