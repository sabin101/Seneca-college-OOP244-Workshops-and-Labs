/*
*****************************************************************************
                              Chapter.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 17 June 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
    // Initializes a chapter
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}

	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}

	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}

    // An int type cast operator: It will return the number of the pages in the Chapter object.
    Chapter::operator int() const {
        return m_num_pages;
    }

    // A double type cast operator: It will return the average number of words per page.
    Chapter::operator double() const {
        return ((double) m_num_words / m_num_pages);
    }

    // A const char* type cast operator: It will return the title of a chapter object.
    Chapter::operator const char*() const {
        return m_title;
    }

    // An assignment operator overload: to allow setting a chapter to another chapter object. (i.e., right-hand operand is of type const Chapter&).
    Chapter& Chapter::operator=(const Chapter& chapter) {
        strcpy(m_title, chapter.m_title);
        m_num_pages = chapter.m_num_pages;
        m_num_words = chapter.m_num_words;
        m_chapter_number = chapter.m_chapter_number;

        return *this;
    }

    // A prefix ++ operator overload: It will increase the number of pages for a chapter object by one.
    Chapter& Chapter::operator++() {
        m_num_pages++;
        return *this;
    }

    // A prefix -- operator overload: It will decrease the number of pages for a chapter object by one.
    Chapter& Chapter::operator--() {
        m_num_pages--;
        return *this;
    }

    // An insertion helper operator overload: to allow printing of a chapter to the output console. You will need to use the provided display member function to accomplish this operator overload.
    ostream& operator<<(ostream& out, const Chapter& c) {
        c.display(out);
        return out;
    }

    // Getter function that gets the number of pages for each chapter
    int Chapter::num_pages() const{
        return m_num_pages;
    }

    // Display Chapter
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	
}

