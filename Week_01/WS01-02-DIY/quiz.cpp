/*
*****************************************************************************
                              quiz.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 23 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <cstdio>
#include "quiz.h"
#include "question.h"

namespace quizzer
{
    // Global variables that are used throughout the program
    int questionsDisplayed = 0, score = 0;

    // Initializing structs
    QuizDetails quizDetails{};
    QuestionDetails questionDetails[MAX_QUESTIONS]{};
    MCAnswerDetails mcAnswerDetails[MAX_ANSWERS]{};
    MAAnswerDetails maAnswerDetails[MAX_ANSWERS]{};

    // Loads a quiz from a file.  If a quiz is already loaded, that quiz is discarded.
    int LoadQuiz(const char *filename)
    {
        // Resetting the amount of questions displayed
        questionsDisplayed = 0;

        // Opening the file
        FILE *fp = std::fopen(filename, "r");
        int result; // Storing the return value

        // Checking whether the file exists or not
        if (fp != nullptr)
        {
            char buf[MAX_TEXT + 1]; // Buffer to read lines
            int line = 0;           // Keeping track of the number of lines read

            int totalQuestions = 0; // Variable to keep track of the total questions
            int totalAnswers = 0; // Keeps track of the total answers for one question
            int rightAnswers = 0; // Keeps track of the number of correct answers

            char ans; // Checks whether answer is correct or not

            while (std::fgets(buf, sizeof(buf), fp) != nullptr)
            {
                // Normally, the program skips the first line of the text file because of reading it in the while statement
                // This line ensures that the pointer is back to its original state
                if (line == 0)
                {
                    rewind(fp);
                }

                line++; // incrementing the number of lines to keep track of lines

                // Reading a question
                if (fscanf(fp, "{m%c} %[^\n]", &questionDetails[totalQuestions].questionType, questionDetails[totalQuestions].question) == 2)
                {
                    // Initializing the total number of answers to zero
                    totalAnswers = 0;
                    rightAnswers = 0;

                    totalQuestions++;
                }

                // Reading answers for multiple choice questions
                if (questionDetails[totalQuestions - 1].questionType == 'c')
                {
                    if (fscanf(fp, "[%c] %[^\n]", &ans, mcAnswerDetails[totalQuestions - 1].answers[totalAnswers]) == 2)
                    {
                        // Storing the index number of the correct answer according to the order that they are printed in
                        if (ans == 'X')
                        {
                            mcAnswerDetails[totalQuestions - 1].rightAnswerIndex = totalAnswers;
                            rightAnswers++;
                        }

                        totalAnswers++;
                    }
                }

                // Reading answers for multiple answer questions
                if (questionDetails[totalQuestions - 1].questionType == 'a')
                {
                    if (fscanf(fp, "[%c] %[^\n]", &ans, maAnswerDetails[totalQuestions - 1].answers[totalAnswers]) == 2)
                    {
                        // Storing the index number of the correct answer according to the order that they are printed in
                        if (ans == 'X')
                        {
                            maAnswerDetails[totalQuestions - 1].rightAnswerIndexes[rightAnswers] = totalAnswers;
                            rightAnswers++;
                        }

                        totalAnswers++;
                    }
                }

                // Storing the total questions in the quiz details struct
                quizDetails.totalQuestions = totalQuestions;

                // Storing the total answers in the QuestionDetails struct
                questionDetails[totalQuestions - 1].totalAnswers = totalAnswers;

                // Storing the correct answers in the QuestionDetails struct
                questionDetails[totalQuestions - 1].correctAnswers = rightAnswers;
            }

            std::fclose(fp);
            result = 0;
        }
        else {
            result = 1;
        }

        return result;
    }

    // Checks if a quiz is currently loaded and is valid.
    int IsQuizValid() {
        int result; // Stores the return value

        // Checking whether the quiz has at least 5 questions
        if (quizDetails.totalQuestions >= 5) {
            int i, incorrect = 0;

            // Checking whether the questions are correct
            for (i = 1; i <= quizDetails.totalQuestions; i++) {
                if (questionDetails[i - 1].questionType == 'c') {
                    if (questionDetails[i - 1].correctAnswers != 1) {
                        printf("Question %d -> ERROR\n", i);
                        incorrect++;
                    }
                    else {
                        printf("Question %d -> OK\n", i);
                    }
                }
                else {
                    if (questionDetails[i - 1].correctAnswers < 1) {
                        printf("Question %d -> ERROR\n", i);
                        incorrect++;
                    }
                    else {
                        printf("Question %d -> OK\n", i);
                    }
                }
            }

            // Returning appropriate result
            if (incorrect == 0) {
                result = 1;
            }
            else {
                result = 0;
            }
        }

        // result = 0 if there are less than 5 questions in a quiz
        else {
            result = 0;
        }

        // Returning from function
        return result;
    }

    // Checks if there are still questions in the quiz that haven't been shown to the user.
    int HasMoreQuestions() {
        int result;

        // Checking for more questions
        if (questionsDisplayed < quizDetails.totalQuestions) {
            result = 1;
        }
        else {
            result = 0;
        }

        return result;
    }

    // Prints to the screen the next question from the quiz and records user's answer.
     void ShowNextQuestion() {
        int i, choice;

        // Displaying the Questions
        printQuestion(questionDetails[questionsDisplayed].question);

        // Displaying the answers
        for (i = 1; i <= questionDetails[questionsDisplayed].totalAnswers; i++){
            if (questionDetails[questionsDisplayed].questionType == 'c') {
                printAnswer(mcAnswerDetails[questionsDisplayed].answers[i - 1], i);
            }
            else {
                printAnswer(maAnswerDetails[questionsDisplayed].answers[i - 1], i);
            }
        }

        // Prompting the user for input
        printf("Your answer? ");
        scanf("%d", &choice);

        // Checking whether the answer inputted by the user is correct or not
        if (questionDetails[questionsDisplayed].questionType == 'c') {
            if ((choice - 1) == mcAnswerDetails[questionsDisplayed].rightAnswerIndex) {
                score++;
            }
        }
        else {
            int j;
            for (j = 0; j < MAX_ANSWERS; j++) {
                if (maAnswerDetails[questionsDisplayed].rightAnswerIndexes[j] == (choice - 1)) {
                    score++;
                }
            }
        }

        questionsDisplayed++;
    }

    // Prints to the screen the results in the format "QUIZ RESULTS: your score is X/Y.".
    void ShowQuizResults() {
        if (questionsDisplayed != 0) {
            printf("\n");
            printf("QUIZ RESULTS: your score is %d/%d.\n", score, quizDetails.totalQuestions);
            score = 0;
        }
    }
}