#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string address;
    std::string phoneNumber;
    std::string gender;

    void personDetails();
    void printDetails();
    void viewPerson(std::string fileName);
};

#endif // PERSON_H
