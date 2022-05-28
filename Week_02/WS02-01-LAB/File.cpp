/*
*****************************************************************************
                              File.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {
   FILE* fptr;

   // Predefined functions
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // Reading the student name from a record
   bool read(char studentName[]) {
        return fscanf(fptr, "%[^,],", studentName) == 1;
   }

   // Reading the student number from a record
    bool read(int& studentNumber) {
        return fscanf(fptr, "%d,", &studentNumber) == 1;
   }

   // Reading the student grade from a record
    bool read(char& studentGrade) {
        return fscanf(fptr, "%c\n", &studentGrade) == 1;
   }

}