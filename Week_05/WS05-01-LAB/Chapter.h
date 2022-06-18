/*
*****************************************************************************
                              Chapter.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 17 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>

namespace sdds {
   const int MAX_CHAPTER_TITLE = 20;

    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;

        // Initializes a chapter
        void init_chapter();

    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);

        // An int type cast operator: It will return the number of the pages in the Chapter object.
        operator int() const;

        // A double type cast operator: It will return the average number of words per page.
        operator double() const;

        // A const char* type cast operator: It will return the title of a chapter object.
        operator const char*() const;

        // An assignment operator overload: to allow setting a chapter to another chapter object. (i.e., right-hand operand is of type const Chapter&).
        Chapter& operator=(const Chapter& chapter);

        // A prefix ++ operator overload: It will increase the number of pages for a chapter object by one.
        Chapter& operator++();

        // A prefix -- operator overload: It will decrease the number of pages for a chapter object by one.
        Chapter& operator--();

        // Getter function that gets the number of pages for each chapter
        int num_pages() const;

        // Display function
        std::ostream& display(std::ostream&)const;
    };

    // An insertion helper operator overload: to allow printing of a chapter to the output console. You will need to use the provided display member function to accomplish this operator overload.
    std::ostream& operator<<(std::ostream& out, const Chapter& c);
}
#endif


