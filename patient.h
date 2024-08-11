#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <person.h>

class Patient : public Person {
public:
    std::string healthCard;

    void identification();
    void addPatient();
    void viewPatient();
    void searchPatient();
};

#endif // PATIENT_H
