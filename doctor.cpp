#include <iostream>
#include <fstream>
#include <string>
#include "doctor.h"

void Doctor::identification() {
    Person::personDetails();
    std::cout << "Please enter your Doctor Id number: ";
    std::cin >> doctorID;
}

void Doctor::addDoctor() {
    std::ofstream file("doctor.txt", std::ios::app);
    file << "Doctor Id: " << doctorID << "\n";
    file << "First Name: " << firstName << "\n";
    file << "Last Name: " << lastName << "\n";
    file << "Birthday: " << birthday << "\n";
    file << "Address: " << address << "\n";
    file << "Phone number: " << phoneNumber << "\n";
    file << "Gender: " << gender << "\n";
    file.close();
    std::cout << "Doctor details saved\n";
}

void Doctor::viewDoctor() {
    viewPerson("doctor.txt");
}

void Doctor::searchDoctor() {
    std::string line;
    std::string doctorID;
    bool found = false;

    std::cout << "Please enter the Doctor's Id: ";
    std::cin >> doctorID;

    std::ifstream file("doctor.txt");

    if (!file.is_open()) {
        std::cout << "File not found\n";
    }
    while(getline(file,line)) {
        if (line == "Doctor Id: " + doctorID) {
            getline(file, line);
            found = true;
            std::cout << "Doctor ID: " << doctorID;
            for (int i = 0; i < 5; i++) {
                getline(file, line);
                std::cout << line << "\n";
            }
            break;
        }
    }
    if (!found) {
        std::cout << "Doctor not found";
    }
}
