// Author: Cornel
#include <iostream>
#include "quiz.h"
#include "quiz.h"

using namespace std;

int main()
{
	// USAGE CASE #1: load a test from a file that doesn't exist
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #1: bad input file\n";
	cout << "------------------------------------------------------------\n";

    if (quizzer::LoadQuiz("quiz1.txt") == 0)
	{
		cout << "ERROR: There is no file; the function 'LoadTest()' should return non-zero value.\n";
		cout << "       Keep working on your code.\n";
	}
	else
	{
		cout << "SUCCESS\n";
	}
	cout << "------------------------------------------------------------\n\n";


//	// USAGE CASE #2: load a valid quiz from the file and display it to the user
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #2: good quiz\n";
	cout << "------------------------------------------------------------\n";
	if (quizzer::LoadQuiz("quiz2.txt") == 0)
	{
		if (quizzer::IsQuizValid() == 1)
		{
			// This function should produce no output since the user didn't take the quiz yet
			quizzer::ShowQuizResults();
			cout << "****** Answer [2] to every question. *****\n";

			int i = 0;
			do
			{
				cout << "\nQUESTION [" << ++i << "]\n";
				cout << "^^^^^^^^^^^^\n";
				quizzer::ShowNextQuestion();
			}
			while (quizzer::HasMoreQuestions());

			// The quiz has finished; show the user's score (each question is worth 1 point)
			quizzer::ShowQuizResults();
		}
		else
		{
			cout << "ERROR: The quiz should be valid, but the program is not detecting it as valid.\n";
			cout << "       Keep working on your code.\n";
		}
	}
	cout << "------------------------------------------------------------\n\n";


	// USAGE CASE #3: load an invalid quiz from the file
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #3: bad quiz (not enough questions)\n";
	cout << "------------------------------------------------------------\n";
	if (quizzer::LoadQuiz("quiz3.txt") == 0)
	{
		if (quizzer::IsQuizValid() == 1)
		{
			cout << "ERROR: The file contains an invalid quiz, yet the program doesn't detect it as invalid.\n";
			cout << "       Keep working on your code.\n";
		}
		else
		{
			cout << "SUCCESS\n";
		}
		// This function should produce no output since the quiz is not valid
		quizzer::ShowQuizResults();
	}
	cout << "------------------------------------------------------------\n\n";


	// USAGE CASE #4: load another valid quiz from the file and display it to the user
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #4: another good quiz\n";
	cout << "------------------------------------------------------------\n";
	if (quizzer::LoadQuiz("quiz4.txt") == 0)
	{
		if (quizzer::IsQuizValid() == 1)
		{
			// This function should produce no output since the user didn't take the quiz yet
			quizzer::ShowQuizResults();
			cout << "****** Answer [3] to every question. *****\n";

			int i = 1;
			do
			{
				cout << "\nQUESTION [" << i++ << "]\n";
				cout << "^^^^^^^^^^^^\n";
				quizzer::ShowNextQuestion();
			} while (quizzer::HasMoreQuestions());

			// The quiz has finished; show the user's score (each question is worth 1 point)
			quizzer::ShowQuizResults();
		}
		else
		{
			cout << "ERROR: The quiz should be valid, but the program is not detecting it as valid.\n";
			cout << "       Keep working on your code.\n";
		}
	}
	cout << "------------------------------------------------------------\n\n";



	// USAGE CASE #5: load an invalid quiz from the file
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #5: another bad quiz (bad questions)\n";
	cout << "------------------------------------------------------------\n";
	if (quizzer::LoadQuiz("quiz5.txt") == 0)
	{
		if (quizzer::IsQuizValid() == 1)
		{
			cout << "ERROR: The file contains an invalid quiz, yet the program doesn't detect it as invalid.\n";
			cout << "       Keep working on your code.\n";
		}
		else
		{
			cout << "SUCCESS\n";
		}
		// This function should produce no output since the quiz is not valid
		quizzer::ShowQuizResults();
	}
	cout << "------------------------------------------------------------\n\n";

	return 0;
}