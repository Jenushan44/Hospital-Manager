#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include "person.h"

class Doctor : public Person {
public:
    std::string doctorID;


    void identification();
    void addDoctor();
    void viewDoctor();
    void searchDoctor();
};


#endif // DOCTOR_H
