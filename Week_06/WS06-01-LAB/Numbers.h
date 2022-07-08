/*
*****************************************************************************
                              Numbers.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 8 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
   class Numbers {
   private:
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
       // Copy constructor
       Numbers(const Numbers& nums);

      // Returns the number of lines in the data file
      int numberCount() const;

      // Returns true if all the double values are read from the data file and stored in a dynamically allocated memory, otherwise returns false.
      bool load();

      // Write all the elements from the m_numbers Array
      void save();

      // += Operator Overloading
      Numbers& operator+=(double value);

       // copy assignment operator
       Numbers& operator=(const Numbers& src);

      // Function to display a Numbers object
      std::ostream& display(std::ostream& os=std::cout) const;

      // Previously implemented functions
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
   };

   // Input and output operator overloading
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

