/*
*****************************************************************************
                              BarChart.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 31 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "BarChart.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
    // Global index to assign values to class array
    int index = 0;

    // Returns if the array of Bars is valid or not
    bool BarChart::areBarsValid() const {
        bool result = true;
        int i, flag = 1;

        // Checking if each individual bar is valid or not
        for (i = 0; i < barsSize && flag == 1; i++) {
            if (!bars[i].isBarValid()) {
                result = false;
                flag = 0;
            }
        }

        return result;
    }

    // Initializes the Chart as explained before.
    void BarChart::init(const char* title, int noOfSamples, char fill) {

        // Checking if arguments are valid
        if (strcmp(title, "") != 0 && noOfSamples > 0) {

            // Dynamically allocating memory for the title
            chartTitle = new char[strlen(title) + 1];
            strcpy(chartTitle, title);

            // Assigning other values
            samples = noOfSamples;
            fillChar = fill;

            // Dynamically allocating memory for array of Bars
            bars = new Bar[noOfSamples];
            barsSize = 0; // Keeps track of the number of bars added
        }
    }

    // Sets the next available Bar (in the dynamic Bar array), or does nothing if they are all already set.
    void BarChart::add(const char* bar_title, int value) {

        // Checking if bars are valid
        if (BarChart::areBarsValid()) {
            bars[index].set(bar_title, '=', value);
            barsSize++; // Incrementing the number of bars added
            index++; // Incrementing the index
        }
    }

    // If The BarChar is valid and if all the Bars in the Chart are valid it draws the bar
    void BarChart::draw() const{
        // Checking if bars are valid and number of bars matches the number of samples provided
        if (BarChart::areBarsValid() && samples == barsSize) {

            // Printing all details
            cout << chartTitle << endl;
            printHyphens(71);

            int i;
            for (i = 0; i < barsSize; i++) {
                bars[i].draw();
            }

            printHyphens(71);
        }
        else {
            cout << "Invalid Chart!" << endl;
        }
    }

    // Deallocates all the dynamically allocated memory.
    void BarChart::deallocate() {
        delete[] chartTitle;
        delete[] bars;
    }

    // Print hyphens
    void printHyphens(int num) {
        int i;
        for (i = 0; i < num; i++) {
            cout << "-";
        }
        cout << "\n";
    }
}