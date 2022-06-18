/*
*****************************************************************************
                              Book.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 17 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITLE = 40;
   const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITLE+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        // Initializes a book object
        void init_book();

        // A private member function called add_chapter which receives a pointer to a chapter and adds the chapter to the array of chapters for the book. It returns an integer which is the number of chapters after the new chapter is been added. Make sure you use the postfix ++ operator you implemented above.
        int add_chapter(Chapter* chapter);

    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);

        // A postfix ++ operator overload to increase the number of chapters by one.
        Book operator++(int);

        // This function is going to print a book object according to the provided sample output.
        std::ostream& displayBook(std::ostream&)const;

        // An int type cast operator: It will return the number of chapters of a book object.
        operator int() const;

        // A bool type cast operator: It will return true if title and author, and num_chapters are non-empty and there is at least one chapter with number of pages greater than zero.
        operator bool() const;

        // A double type cast operator: It will return the book price.
        operator double() const;

        // A const char* type cast operator: It will return title of the book
        operator const char*() const;

        // A logical not operator overload: return true if any of the conditions mentioned for the bool operator overload are not true.
        bool operator!() const;

        // A += operator overload: to allow adding a chapter to a book. Make sure you reuse code through the add_chapter member function you implemented above.
        Book& operator+=(Chapter chapter);

        // A -= operator overload to apply a dollar value discount to the book price.
        Book& operator-=(double discount);

        // Print a book summary
        void summary();
    };

    // An insertion operator overload: to allow printing of a book object to the output console. Make sure you properly reuse the display member function you implemented above.
    std::ostream& operator<<(std::ostream& out, const Book& b);

}
#endif
