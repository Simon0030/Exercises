#ifndef FABRYKASTUDENTOW_H
#define FABRYKASTUDENTOW_H

#include "FabrykaOsob.h"
#include "Student.h"



using namespace std;

class FabrykaStudentow : public FabrykaOsob{
    public:
        Student* utworz();
};

#endif