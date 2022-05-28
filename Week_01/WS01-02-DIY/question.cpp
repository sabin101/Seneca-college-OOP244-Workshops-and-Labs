/*
*****************************************************************************
                              question.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 23 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <cstdio>
#include "question.h"

namespace quizzer {
    // Handles question formatting
    void printQuestion(char* question) {
        printf("%s\n", question);
    }

    // Handles answer formatting
    void printAnswer(char* answer, int iteration) {
        printf("%d. %s\n", iteration, answer);
    }
}