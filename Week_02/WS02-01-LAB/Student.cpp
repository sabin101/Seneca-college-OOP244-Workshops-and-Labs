/*
*****************************************************************************
                              Student.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Student.h"
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    // Global Variables
    int noOfStudents;
    Student* students;

    // Sorts the dynamic array of students based on the Grade of the students.
    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    // Loads each records into a struct
    bool load(Student& student) {
        bool result;
        char localArray[TEMP_ARRAY_LENGTH];

        // Reading a record
        if (read(localArray) && read(student.m_studentNumber) && read(student.m_grade)) {
            student.m_name = new char[strlen(localArray) + 1];
            strcpy(student.m_name, localArray);
            result = true;
        }
        else {
            result = false;
        }

        return result;
    }

    // Uses a file and loads all the records in a struct array
    bool load(const char* filename) {
        int result;
        openFile(filename);
        noOfStudents = noOfRecords();
        students = new Student[noOfStudents];

        // Loading all the records
        int i;
        for (i = 0; i < noOfStudents; i++) {
            if (!load(students[i])) {
                result = false;
            }
            else {
                result = true;
            }
        }

        // Closing the file
        closeFile();

        return result;
    }

    // Displays a single records
    void display(Student& studentDetails) {
        printf("%s, %d: %c\n", studentDetails.m_name, studentDetails.m_studentNumber, studentDetails.m_grade);
    }

    // Displays all records
    void display() {
        // Sorting the array
        sort();

        int i;
        for (i = 0; i < noOfStudents; i++) {
            printf("%d: ", i + 1);
            display(students[i]);
        }
    }

    // Deallocates the dynamically allocated memory
    void deallocateMemory() {
        int i;

        // Deallocating
        for (i = 0; i < noOfStudents; i++) {
            delete[] students[i].m_name;
        }
        delete[] students;
    }
}