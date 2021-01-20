#include <iostream>
#include "Stopper.h"

Stopper::Stopper(){
    duration = milliseconds(0);
};
void Stopper::start(){
    start_time = high_resolution_clock::now();
}
void Stopper::stop(){
    duration += duration_cast<milliseconds>( high_resolution_clock::now() - start_time );
}
void Stopper::reset(){
    duration = milliseconds(0);
    start_time = high_resolution_clock::now();
}
void Stopper::showTotal(){
    cout << "Time measured: " << duration.count() << endl;
}
