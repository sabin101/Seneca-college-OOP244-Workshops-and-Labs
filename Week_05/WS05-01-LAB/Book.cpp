/*
*****************************************************************************
                              Book.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 17 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"
#include "Chapter.h"
using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

    // A private member function called add_chapter which receives a pointer to a chapter and adds the chapter to the array of chapters for the book. It returns an integer which is the number of chapters after the new chapter is been added. Make sure you use the postfix ++ operator you implemented above.
    int Book::add_chapter(Chapter* chapter) {
        m_chapters[m_num_chapters] = *chapter;
        this->operator++(0);
        m_num_pages += chapter->num_pages();
        return 1;
    }

    // A postfix ++ operator overload to increase the number of chapters by one.
    Book Book::operator++(int) {
        Book bk = *this;
        m_num_chapters++;
        return bk;
    }

    // This function is going to print a book object according to the provided sample output.
    std::ostream& Book::displayBook(std::ostream& os) const {
        os << "Title:'" << m_title << "'" << endl;
        os << "Author: '" << m_author << "'" << endl;
        int i;
        for (i = 0; i < MAX_NUM_CHAPTERS; i++) {
            if (m_chapters[i].num_pages() > 0) {
                m_chapters[i].display(os);
            }
        }
        return os;
    }

    // An int type cast operator: It will return the number of chapters of a book object.
    Book::operator int() const {
        return m_num_chapters;
    }

    // A bool type cast operator: It will return true if title and author, and num_chapters are non-empty and there is at least one chapter with number of pages greater than zero.
    Book::operator bool() const {
        bool result = false;
        int i, flag = 1;
        if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters > 0) {
            for (i = 0; i < m_num_chapters && flag == 1; i++) {
                if (m_chapters[i].num_pages() > 0) {
                    result = true;
                    flag = 0;
                }
            }
        }

        return result;
    }

    // A double type cast operator: It will return the book price.
    Book::operator double() const {
        return m_price;
    }

    // A const char* type cast operator: It will return title of the book
    Book::operator const char*() const {
        return m_title;
    }

    // A logical not operator overload: return true if any of the conditions mentioned for the bool operator overload are not true.
    bool Book::operator!() const {
        bool result = true;
        int i, flag = 1;
        if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters > 0) {
            for (i = 0; i < m_num_chapters && flag == 1; i++) {
                if (m_chapters[i].num_pages() > 0) {
                    result = false;
                    flag = 0;
                }
            }
        }

        return result;
    }

    // A += operator overload: to allow adding a chapter to a book. Make sure you reuse code through the add_chapter member function you implemented above.
    Book& Book::operator+=(Chapter chapter) {
        add_chapter(&chapter);
        return *this;
    }

    // A -= operator overload to apply a dollar value discount to the book price.
    Book& Book::operator-=(double discount) {
        m_price -= discount;
        return *this;
    }

    // An insertion operator overload: to allow printing of a book object to the output console. Make sure you properly reuse the display member function you implemented above.
    std::ostream& operator<<(std::ostream& out, const Book& b) {
        return b.displayBook(out);
    }

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITLE);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

}
