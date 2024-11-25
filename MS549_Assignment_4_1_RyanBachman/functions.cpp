/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	functions.cpp
*/

#include "functions.h"
#include "stack.h"
#include "queue.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Outputs the main menu options to the user using only cout.
int mainMenu()
{
	cout << "\n\nRyan Bachman's Assignment 4.1 Project" << endl;
	cout << "1: Stack" << endl;
	cout << "2: Queue" << endl;
	cout << "3: Testing" << endl;
	cout << "4: Exit Program" << endl;

	return 0;
}

// Outputs the stack menu options to the user using only cout.
int stackMenu()
{
	cout << "\n\nStack Menu:" << endl;
	cout << "1: Add a Number to the Stack" << endl;
	cout << "2: Remove Number at Top of Stack" << endl;
	cout << "3: Remove Specific Number from Stack" << endl;
	cout << "4: Print Stack" << endl;
	cout << "5: Main Menu" << endl;

	return 0;
}

// Outputs the queue menu options to the user using only cout.
int queueMenu()
{
	cout << "\n\nQueue Menu:" << endl;
	cout << "1: Add a Number to the Queue" << endl;
	cout << "2: Remove Number from Front of Queue" << endl;
	cout << "3: Remove Specific Number from Queue" << endl;
	cout << "4: Print Queue" << endl;
	cout << "5: Main Menu" << endl;

	return 0;
}

// Get the time when the function is called for start time.
chrono::high_resolution_clock::time_point getStartTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto startHigh = chrono::high_resolution_clock::now();

	return startHigh;
}

// Get the time when the function is called for end time.
chrono::high_resolution_clock::time_point getEndTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto endHigh = chrono::high_resolution_clock::now();

	return endHigh;
}

// Calculate the time elapsed between getStartTime() and getEndTime() so this can be reused anywhere.
chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh)
{
	chrono::duration<double> elapsedHighRes = endHigh - startHigh;

	cout << fixed << setprecision(5) << "The operation took " << elapsedHighRes.count() << " seconds.\n" << endl;

	return elapsedHighRes;
}

void getResults(chrono::duration<double> stackInsertTime100, chrono::duration<double> stackInsertTime1000, chrono::duration<double> stackInsertTime10000, chrono::duration<double> stackDeleteTime100, chrono::duration<double> stackDeleteTime1000, 
	chrono::duration<double> stackDeleteTime10000, chrono::duration<double> queueInsertTime100, chrono::duration<double> queueInsertTime1000, chrono::duration<double> queueInsertTime10000, chrono::duration<double> queueDeleteTime100, chrono::duration<double> queueDeleteTime1000, chrono::duration<double> queueDeleteTime10000)
{
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                                               R   E   S   U   L   T   S                                                                              |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                      |                     I   N   S   E   R   T                    |                           D   E   L   E   T   E                                |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Object / Code        | 100                 | 1,000             | 10,000             | 100                    | 1,000                   | 10,000                      |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Stack                | " << stackInsertTime100.count() << "             | " << stackInsertTime1000.count() << "           | " << stackInsertTime10000.count() << "            | " << stackDeleteTime100.count() << "                | " << stackDeleteTime1000.count() << "                 | " << stackDeleteTime10000.count() << "                     |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Queue                | " << queueInsertTime100.count() << "             | " << queueInsertTime1000.count() << "           | " << queueInsertTime10000.count() << "            | " << queueDeleteTime100.count() << "                | " << queueDeleteTime1000.count() << "                 | " << queueDeleteTime10000.count() << "                     |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}