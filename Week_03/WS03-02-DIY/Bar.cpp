/*
*****************************************************************************
                              Bar.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 31 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Bar.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
    // Initializes the Bar object to a safe empty state
    void Bar::setEmpty() {
        strcpy(title, "");
        fillChar = '\0';
        value = 0;
    }

    // Set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable
    void Bar::set(const char arg_title[MAX_TITLE_LENGTH], char arg_fillChar, int arg_value) {
        if (arg_value >= 0 && arg_value <= 100) {
            strcpy(title, arg_title);
            fillChar = arg_fillChar;
            value = arg_value;
        }
        else {
            // Set to empty state
            setEmpty();
        }
    }

    // Returns if the Bar is valid or not
    bool Bar::isBarValid() const{
        bool result = false;
        if (strcmp(title, "") != 0 && value > 0) {
            result = true;
        }

        return result;
    }

    // Draws a bar
    void Bar::draw() const {
        // Printing only if Bar is valid
        if (Bar::isBarValid()) {
            int i;

            // Formatting the output
            cout.width(MAX_TITLE_LENGTH);
            cout.fill('.');
            cout.setf(ios::left);
            cout << title << "|";

            // Printing the bar
            for (i = 0; i < (value / 2); i++) {
                cout << fillChar;
            }
            cout << "\n";
        }
    }
}
