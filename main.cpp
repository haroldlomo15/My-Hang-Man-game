#include <iostream>	//library for input/output 
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw
using namespace std;

bool is_hung(int no_error);
int main()
{
	string question, answerA, answerB, answerC, answerD, answer, user_answer;
	int no_error = 0;
	ifstream myfile;	//file into code
	myfile.open("infile.txt");
	
	while (myfile)
	{
		// Read and display question
		getline(myfile, question);
		//Read and display each answer
		getline(myfile, answerA);
		getline(myfile, answerB);
		getline(myfile, answerC);
		getline(myfile, answerD);
		myfile.ignore(16);
		// Read correct letter for answer
		getline(myfile, answer);
		cout << "********************** MY HANG MAN GAME *************************" << endl;
		cout << question << "\n" << answerA << "\n" << answerB << "\n" << answerC << "\n" << answerD << "\n" << endl;
		cout << "Enter the capital letter of your answer: ";
		
		cin >> user_answer;
		// Determine if user answer is correct
		if (answer == user_answer)
		{
			cout << "CORRECT" << endl; // If user answered correctly display "CORRECT"
		}
		// If user answered incorrectly
		else
		{
			
			no_error += 1; //add 1 to no_errors
			cout << "INCORRECT" << endl; //display "INCORRECT"
			if (is_hung(no_error))
			{
				system("pause");
				return 0;
				
			}
			system("pause");
			system("cls");
		}
		
	}
	
}
//Determine(using returned boolean value from is_hung) whether to continue
bool is_hung(int no_error)
{
	if (no_error == 1)
	{
		cout << "\t \t \t" << " O " << endl;
		return false;
	}
	else if (no_error == 2)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << " |" << endl;
		return false;
	}
	else if (no_error == 3)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|" << endl;
		return false;
	}
	else if (no_error == 4)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		return false;
	}
	else if (no_error == 5)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;

		return false;
	}
	else if (no_error == 6)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "\t \t \t" << "/ \\" << endl;
		return false;
	}
	else if (no_error = 7)
	{
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "\t \t \t" << "/ \\" << endl;
		cout << " YOU ARE HUNG" << endl;
		return true;
	}
	
	else
		return false;
}

/*
********************** MY HANG MAN GAME *************************
Question: Which two pairs of expressions are equivalent ?
		  A Answer : !(a == b) and a != b
		  B Answer : !(a == b) and a = !B
		  C Answer : (a == b)!and a != b
		  D Answer : (a == b)!and a = !B

		  Enter the capital letter of your answer : E
		  INCORRECT
		  O
		  / | \
		  |
		  / \
		  YOU ARE HUNG
 
 */
