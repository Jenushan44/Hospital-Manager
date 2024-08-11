#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

void Person::personDetails() {
    std::cout << "Please enter first name: ";
    std::cin >> firstName;

    std::cout << "Please enter last name: ";
    std::cin >> lastName;

    std::cout << "Please enter date of birth (DD/MM/YYYY): ";
    std::cin >> birthday;
    std::cin.ignore();

    std::cout << "Please enter the address: ";
    std::getline(std::cin, address);

    std::cout << "Please enter the phone number: ";
    std::cin >> phoneNumber;

    std::cout << "Please enter the gender: ";
    std::cin >> gender;
}

void Person::printDetails() {
    std::cout << "First name: " << firstName << "\n";
    std::cout << "Last name: " << lastName << "\n";
    std::cout << "Birthday: " << birthday << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "Gender: " << gender << "\n";
}

void Person::viewPerson(std::string fileName) {
    std::string line;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "File not found";
    }
    while(getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}
