/*
*****************************************************************************
                              Army.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 02 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Army.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {

    // Initializes the Army object to a safe empty state
    void Army::setEmpty() {
        strcpy(nationality, "");
        noOfUnits = 0;
    }

    // Initializes an Army object
    void Army::createArmy(const char* country, double pow, int troops) {
        // Checking if arguments are valid
        if (country != nullptr && country[0] != '\0' && troops > 0 && pow > 0) {
            strncpy(nationality, country, MAX_NAME_LEN);
            noOfUnits = troops;
            power = pow;
        }
        else {
            nationality[0] = '\0';
            noOfUnits = 0;
            power = 0;
        }
    }

    // Updates the Army
    void Army::updateUnits(int troops) {
        noOfUnits += troops;
        power += 0.25 * troops;
    }

    // This query returns the nationality of an Army
    const char* Army::checkNationality() const {
        return nationality;
    }

    // This query returns the number of units in an Army
    int Army::checkCapacity() const {
        return noOfUnits;
    }

    // This query returns the power of an Army.
    double Army::checkPower() const {
        return power;
    }

    // This query returns true if the Army object is in a safe empty state
    bool Army::isEmpty() const {
        return (strcmp(nationality, "") == 0 && noOfUnits == 0);
    }

    // This function returns true if the Army has more power than the incoming Army
    bool Army::isStrongerThan(const Army& army) const {
        return (power > army.power);
    }

    // This function will force both armies to fight
    void battle( Army& arm1, Army& arm2) {
        // Checking whether both armies are valid
        if ((strcmp(arm1.checkNationality(), "") != 0 && arm1.checkCapacity() != 0) && (strcmp(arm2.checkNationality(), "") != 0 && arm2.checkCapacity() != 0)) {
            Army winner;

            if (arm1.isStrongerThan(arm2)) {
                arm2.updateUnits((int) (0.5 * (0 - arm2.checkCapacity()))); // Passing 50 % of army in negative
                winner = arm1; // Army 1 wins as it is stronger
            }

            else {
                arm1.updateUnits((int) (0.5 * (0 - arm1.checkCapacity()))); // Passing 50 % of army in negative
                winner = arm2; // Army 2 wins as it is stronger
            }

            // Printing the result
            cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", "
                 << winner.checkNationality() << " is victorious!" << endl;
        }
    }

    // This function sends the information about an Army array to standard output if the object holds valid data values
    void displayDetails(const Army* armies, int size) {
        int i;
        cout << "Armies reporting to battle: " << endl;

        for (i = 0; i < size; i++) {
            if (strcmp(armies[i].checkNationality(), "") != 0 && armies[i].checkCapacity() != 0) {

                // Setting the output formatting
                cout.setf(ios::fixed);
                cout.precision(1);

                // Printing the details line by line
                cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << armies[i].checkPower() << endl;
            }
        }
    }
}