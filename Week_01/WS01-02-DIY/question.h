/*
*****************************************************************************
                              question.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 23 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef QUIZZER_QUESTION_H
#define QUIZZER_QUESTION_H

#define MAX_ANSWERS 10
#define MAX_TEXT 1024
#define QUESTION_TEXT 1024
#define ANSWER_TEXT 1024

namespace quizzer {
    // Struct to store the details of a question
    struct QuestionDetails {
        char questionType;
        char question[QUESTION_TEXT];
        int totalAnswers;
        int correctAnswers;
    };

    // Struct to store the answer details for a multiple choice question
    struct MCAnswerDetails {
        char answers[MAX_ANSWERS][ANSWER_TEXT];
        int rightAnswerIndex;
    };

    // Struct to store the answer details for a multiple answer question
    struct MAAnswerDetails {
        char answers[MAX_ANSWERS][ANSWER_TEXT];
        int rightAnswerIndexes[MAX_ANSWERS];
    };

    // Handles question formatting
    void printQuestion(char* question);

    // Handles answer formatting
    void printAnswer(char* answer, int iteration);

}

#endif //QUIZZER_QUESTION_H
