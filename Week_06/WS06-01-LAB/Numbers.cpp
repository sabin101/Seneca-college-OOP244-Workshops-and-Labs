/*
*****************************************************************************
                              Numbers.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 8 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;

namespace sdds {
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }

    // Copy constructor
    Numbers::Numbers(const Numbers& nums) {
        setEmpty();
        m_isOriginal = false;
        *this = nums; //calling copy assignment operator
   }

   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

    // Returns the number of lines in the data file
    int Numbers::numberCount() const {
       int size = 0;
       string line;
       ifstream myfile;
       myfile.open(m_filename);
       if (myfile.is_open()) {
           // Read line by line and increment the number of lines read
            while (getline(myfile, line, '\n')) {
                size++;
            }
           myfile.close();
       }

       return size;
   }

    // Returns true if all the double values are read from the data file and stored in a dynamically allocated memory, otherwise returns false.
    bool Numbers::load() {
        int numbersRead = 0; // Variable to track whether all the numbers were read
        if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream file;
           file.open(m_filename);

           if (file.is_open()) {
               int i;
               // Reading from the file
               for (i = 0; i < m_numCount; i++) {
                   file >> m_numbers[i];
                   numbersRead++;
               }
           }
       }

       return numbersRead == m_numCount;
   }

    // Write all the elements from the m_numbers Array
    void Numbers::save() {
       if (m_isOriginal && !isEmpty()) {
           ofstream file;
           file.open(m_filename);
           int i;
           for (i = 0; i < m_numCount; i++) {
               file << m_numbers[i] << endl;
           }
       }
   }

    // += Operator Overloading
    Numbers& Numbers::operator+=(double value) {
       double* temp = new double[m_numCount + 1];
       int i;
       for (i = 0; i < m_numCount; i++) {
           temp[i] = m_numbers[i];
       }
       m_numCount++;
       temp[m_numCount - 1] = value;

       delete[] m_numbers;
       m_numbers = temp;
       sort();
       return *this;
   }

    // copy assignment operator
    Numbers& Numbers::operator=(const Numbers& src) {
        delete[] m_numbers;
        m_numbers = new double[src.m_numCount];
        m_numCount = src.m_numCount;
        for (int i = 0; i < src.m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
        }
        sort();
        return *this;
    }

    // Function to display a Numbers object
    std::ostream& Numbers::display(std::ostream& os) const {
       if (isEmpty()) {
           os << "Empty list";
       }
       else {
           os << "=========================" << endl;
           if (m_isOriginal) {
               os << m_filename << endl;
           }
           else {
               os << "*** COPY ***" << endl;
           }

           for (int i = 0; i < m_numCount; i++) {
               if (i != m_numCount - 1) {
                   os << m_numbers[i] << ", ";
               }
               else os << m_numbers[i];
           }

           os << endl;
           os << "-------------------------"<<endl;
           os << "Total of " << m_numCount << " number(s)"<<endl;
           os << "Largest number:  " << max() << endl;
           os << "Smallest number: " << min() << endl;
           os << "Average :        " << average() << endl;
           os << "=========================";
       }

       return os;
   }

    // Already Implemented Functions
   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }

   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

    // Input and output operator overloading
    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       return N.display(os);
   }

    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double num;
        istr >> num;
        N += num;
        return istr;
   }
}
