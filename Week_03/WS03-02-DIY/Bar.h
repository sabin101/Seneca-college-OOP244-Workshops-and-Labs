/*
*****************************************************************************
                              Bar.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 31 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

#define MAX_TITLE_LENGTH 20

namespace sdds {
    class Bar {
    private:
        char title[MAX_TITLE_LENGTH];
        char fillChar;
        int value;

    public:
        // Initializes the Bar object to a safe empty state
        void setEmpty();

        // Set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable
        void set(const char arg_title[], char arg_fillChar, int arg_value);

        // Returns if the Bar is valid or not
        bool isBarValid() const;

        // Draws a bar
        void draw() const;
    };
}

#endif //SDDS_BAR_H
