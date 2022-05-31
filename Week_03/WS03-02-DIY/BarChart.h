/*
*****************************************************************************
                              BarChart.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 31 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

#include "Bar.h"

namespace sdds {
    class BarChart {
    private:
        char* chartTitle;
        Bar* bars;
        char fillChar;
        int barsSize;
        int samples;

    public:
        // Returns if the array of Bars is valid or not
        bool areBarsValid() const;

        // Initializes the Chart as explained before.
        void init(const char* title, int noOfSamples, char fill);

        // Sets the next available Bar (in the dynamic Bar array), or does nothing if they are all already set.
        void add(const char* bar_title, int value);

        // If The BarChar is valid and if all the Bars in the Chart are valid it draws the bar exactly as follows:
        void draw() const;

        // Deallocates all the dynamically allocated memory.
        void deallocate();
    };

    // Print hyphens
    void printHyphens(int num);
}

#endif //SDDS_BARCHART_H
