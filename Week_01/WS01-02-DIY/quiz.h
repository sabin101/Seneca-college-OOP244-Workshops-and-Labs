/*
*****************************************************************************
                              quiz.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 23 May 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef QUIZZER_QUIZ_H
#define QUIZZER_QUIZ_H

#define MAX_QUESTIONS 60

namespace quizzer {

    // Creating a Quiz datatype
    struct QuizDetails {
        int totalQuestions;
    };

    /// <summary>
    /// Loads a quiz from a file.  If a quiz is already loaded, that quiz is discarded
    ///   (together with any information regarding that previously loaded quiz).
    /// </summary>
    /// <param name="filename">The name of the file containing the quiz.</param>
    /// <returns>0 if the quiz was loaded, any other value if some error appeared
    ///   (null parameter, empty parameter, missing file).</returns>
    int LoadQuiz(const char *filename);

    /// <summary>
    /// Checks if a quiz is currently loaded and is valid.
    ///   A quiz is considered valid if it has at least 5 questions
    ///   and each question is correct (multiple-choice questions have
    ///   exactly one correct answer, and multiple-answer questions
    ///   have at least one correct answer.
    ///
    ///   For each question in the quiz, print to screen "Question X -> OK" or
    ///   "Question X -> ERROR" if the question is valid or it contains some error.
    ///
    ///   If the quiz has an insufficient number of questions, this function prints nothing.
    /// </summary>
    /// <returns>1 if the quiz is loaded and correct, 0 otherwise</returns>
    int IsQuizValid();

    /// <summary>
    /// Checks if there are still questions in the quiz that haven't been shown to the user.
    /// </summary>
    /// <returns>1 if the quiz has more questions to show to the user; 0 otherwise.</returns>
    int HasMoreQuestions();

    /// <summary>
    /// Prints to the screen the next question from the quiz and records
    ///   user's answer. Once this function is called at least once,
    ///   it is considered that the user took the quiz.
    ///
    /// After the question is shown, this function will print "Your answer? "
    ///   and read the user's choice.
    /// </summary>
    void ShowNextQuestion();

    /// <summary>
    /// Prints to the screen the results in the format
    ///   "QUIZ RESULTS: your score is X/Y.".
    ///
    /// If the user didn't took the quiz, this function does nothing.
    /// </summary>
    void ShowQuizResults();

}

#endif //QUIZZER_QUIZ_H
