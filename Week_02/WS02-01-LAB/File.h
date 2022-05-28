/*
*****************************************************************************
                              File.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
    // Predefined functions
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // Reads the name from a record
   bool read(char studentName[]);

   // Reads the student number from a record
   bool read(int& studentNumber);

   // Reads the student grade from a record
   bool read(char& studentGrade);
}
#endif // !SDDS_FILE_H_
