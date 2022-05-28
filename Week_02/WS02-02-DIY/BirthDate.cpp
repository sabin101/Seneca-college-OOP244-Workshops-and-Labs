/*
*****************************************************************************
                              BirthDate.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 26 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "BirthDate.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    // Declaring a file pointer
    FILE* fp;

    // Declaring a dynamically allocated struct array
    Employee* employees;
    int noOfEmployees;
    int monthMatches = 0;

    // Determines the number of records in a file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fp);
        return noOfRecs;
    }

    // Opens the datafile and prints the search data
    bool beginSearch(const char* filename) {
        bool result;
        fp = fopen(filename, "r");

        // Checking if file was successfully opened
        if (fp != nullptr) {
            cout << "Birthdate search program" << endl;
            result = true;
        }
        else {
            cout << "Data file \"" << filename << "\" not found!" << endl;
            result = false;
        }

        return result;
    }

    // Reads the file and assigns the matches to struct
    void valueAssigner(Employee* employee, int month, int matches) {
        // declaring variables to read from file
        char temp[TEMP_ARRAY_LENGTH];
        int day, mth, year;

        // Dynamically allocated array of structs
        employees = new Employee[matches];

        // Reading the file again to assign values to struct
        rewind(fp);
        int i, matchedRecs = 0;
        for (i = 0; i < noOfEmployees; i++) {
            if ((fscanf(fp, "%[^,],%d/%d/%d\n", temp, &mth, &day, &year) == 4) && (mth == month)) {
                // Assigning the values read to struct
                employees[matchedRecs].employeeDOB.day = day;
                employees[matchedRecs].employeeDOB.month = mth;
                employees[matchedRecs].employeeDOB.year = year;
                employees[matchedRecs].employeeName = new char[strlen(temp) + 1];
                strcpy(employees[matchedRecs].employeeName, temp);

                // Incrementing the number of records matched
                matchedRecs++;
            }
        }
    }

    // Reads the birth records and matches the month
    bool readBirthDate(int month) {
        bool result;
        noOfEmployees = noOfRecords();

        // declaring variables to read from file
        char temp[TEMP_ARRAY_LENGTH];
        int day, mth, year;

        // Reading file to determine the number of records that match a month
        int i;
        for (i = 0; i < noOfEmployees; i++) {
            if (fscanf(fp, "%[^,],%d/%d/%d\n", temp, &mth, &day, &year) == 4) {
                if (mth == month) {
                    // Incrementing variable if a match was found
                    monthMatches++;
                }
            }
        }

        // Assigning values to struct
        valueAssigner(employees, month, monthMatches);

        // Checking if a match was found
        if (monthMatches > 0) {
            result = true;
        }
        else {
            result = false;
        }

        return result;
    }

    // Sorts the records based on the year of birth in ascending order
    void sort() {
        int i, j;
        Employee temp;

        for (i = monthMatches - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                // Swapping if the next element is smaller than the current one
                if (employees[j].employeeDOB.year > employees[j + 1].employeeDOB.year) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // Displays the found records
    void displayBirthdays() {
        cout << monthMatches << " birthdates found:" << endl;
        int i;
        for (i = 0; i < monthMatches; i++) {
            cout << i + 1 << ") " << employees[i].employeeName << ":" << endl;
            cout << employees[i].employeeDOB.year << "-" << employees[i].employeeDOB.month << "-"
                 << employees[i].employeeDOB.day << endl;
            cout << "===================================" << endl;
        }
    }

    // Releases all dynamically allocated memory
    void deallocate() {
        int i;
        for (i = 0; i < monthMatches; i++) {
            delete[] employees[i].employeeName;
        }
        delete[] employees;
    }

    // Finalizes the program by making sure all resources are released and closed
    void endSearch() {
        // Closing the file
        if (fp) fclose(fp);

        cout << "Birthdate Search Program Closed." << endl;
    }

}