/*
*****************************************************************************
                              BirthDate.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 30 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BIRTHDATE_H_
#define SDDS_BIRTHDATE_H_

#define TEMP_ARRAY_LENGTH 30

namespace sdds {
    // Defining a Date datatype
    struct Date {
        int month;
        int day;
        int year;
    };

    // Defining an Employee datatype
    struct Employee {
        char* employeeName;
        Date employeeDOB;
    };

    // Opens the datafile and prints the search data
    bool beginSearch(const char* filename);

    // Reads the file and assigns the matches to struct
    void valueAssigner(Employee* employee, int month, int matches);

    // Reads the birth records and matches the month
    bool readBirthDate(int month);

    // Sorts the records based on the year of birth in descending order
    void sort();

    // Displays the found records
    void displayBirthdays();

    // Releases all dynamically allocated memory
    void deallocate();

    // Finalizes the program by making sure all resources are released and closed
    void endSearch();
}

#endif