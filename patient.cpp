#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "patient.h"

void Patient::identification() {
    Person::personDetails();
    std::cout << "Please enter your health card number: ";
    std::cin >> healthCard;
}

void Patient::addPatient() {
    std::ofstream file("patient.txt", std::ios::app);
    file << "Health Card Number: " << healthCard << "\n";
    file << "First name: " << firstName << "\n";
    file << "Last name: " << lastName << "\n";
    file << "Birthday: " << birthday << "\n";
    file << "Address: " << address << "\n";
    file << "Phone Number: " << phoneNumber << "\n";
    file << "Gender: " << gender << "\n";
    file.close();
    std::cout << "Patient details saved\n";
}

void Patient::viewPatient() {
    viewPerson("patient.txt");
}

void Patient::searchPatient() {
    std::string healthCard;
    std::string line;
    bool found = false;

    std::cout << "Please enter the health card number: ";
    std::cin >> healthCard;

    std::ifstream file("patient.txt");
    if (!file.is_open()) {
        std::cout << "File not found";
    }
    while (getline(file, line)) {
        if (line == "Health Card Number: " + healthCard) {
            getline(file, line);
            found = true;
            std::cout << "Health Card Number: " << healthCard << "\n";
            std::cout << line << "\n";
            for (int i = 0; i < 5; i++) {
                getline(file, line);
                std::cout << line << "\n";
            }
            break;
        }
    }
    if (!found) {
        std::cout << "Patient not found\n";
    }
    file.close();
}


