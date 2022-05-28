/*
*****************************************************************************
                              Student.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define TEMP_ARRAY_LENGTH 128

namespace sdds {
    // Defining a Student datatype
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    // Sorts the dynamic array of students based on the Grade of the students
    void sort();

    // Loads each records into a struct
    bool load(Student& student);

    // Uses a file and loads all the records in a struct array
    bool load(const char* filename);

    // Displays a single records
    void display(const Student& student);

    // Displays all records
    void display();

    // Deallocates the dynamically allocated memory
    void deallocateMemory();
}

#endif // !SDDS_STUDENT_H_
