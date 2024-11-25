/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	main.cpp
*/

#include "functions.h"
#include "stack.h"
#include "queue.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

// This assignment will be using doubly linked lists to create a stack and queue, allow inserts, deletions of top of stack or front of queue, deletion of searched items and printing.
// There will also be a troubleshooting section for timing insertions and deletions for stacks and queues.
int main()
{
	bool programLoop = true; // Set a variable for looping the program.

	// Begin FULL program loop...
	while (programLoop == true)
	{
		int menuChoice;

		mainMenu(); // Output main menu to the user.
		
		cout << "Please select a menu item (1 through 4): ";
		cin >> menuChoice; // Get input from the user for going through the main menu.
		cout << endl;

		if (menuChoice == 1) // Stack Menu Option...
		{
			bool stackLoop = true;
			int stackMenuChoice;
			int userInput;
			Stack stack;

			while (stackLoop == true) // Begin STACK MENU loop...
			{
				stackMenu();

				cout << "Please select a menu item (1 through 5): ";
				cin >> stackMenuChoice; // Get input from the user for going through the stack menu.
				cout << endl;

				if (stackMenuChoice == 1) // Push an item onto the stack.
				{
					cout << "Please enter a number to add to the stack: ";
					cin >> userInput;
					cout << endl;

					stack.push(userInput);
				}
				else if (stackMenuChoice == 2) // Remove the item from the top of the stack.
				{
					stack.pop();
				}
				else if (stackMenuChoice == 3) // Remove specific item from the stack at any location.
				{
					cout << "Please enter the element you want to remove as an integer: ";
					cin >> userInput;
					cout << endl;

					stack.moveToTopAndPop(userInput);
				}
				else if (stackMenuChoice == 4) // Print the stack.
				{
					stack.printStack();
				}
				else if (stackMenuChoice == 5) // Go back to the main menu.
				{
					stackLoop = false; // ... End the STACK MENU loop.
				}
				else // Basic error checking.
				{
					cout << "Please enter a valid number from 1 to 5.\n" << endl;
				}
			}
		}
		else if (menuChoice == 2) // Queue Menu Option
		{
			bool queueLoop = true;
			int queueMenuChoice;
			int userInput;
			Queue queue;

			while (queueLoop == true) // Begin QUEUE MENU loop...
			{
				queueMenu();

				cout << "Please select a menu item (1 through 5): ";
				cin >> queueMenuChoice; // Get input from the user for going through the queue menu.
				cout << endl;

				if (queueMenuChoice == 1) // Push an item into the queue.
				{
					cout << "Please enter a number to add to the queue: ";
					cin >> userInput;
					cout << endl;

					queue.push(userInput);
				}
				else if (queueMenuChoice == 2) // Remove the item from the front of the queue.
				{
					queue.pop();
				}
				else if (queueMenuChoice == 3) // Remove specific item from the queue at any location.
				{
					cout << "Please enter the element you want to remove as an integer: ";
					cin >> userInput;
					cout << endl;

					queue.moveToFrontAndPop(userInput);
				}
				else if (queueMenuChoice == 4)  // Print the queue.
				{
					queue.printQueue();
				}
				else if (queueMenuChoice == 5) // Go back to the main menu.
				{
					queueLoop = false; // ... End the QUEUE MENU loop.
				}
				else // Basic error checking.
				{
					cout << "Please enter a valid number from 1 to 5.\n" << endl;
				}
			}
		}
		else if (menuChoice == 3)
		{
			// BEGIN TESTING PROTOCOLS FOR ADDING N ELEMENTS TO THE STACKS AND QUEUES AND RETURN TIMING DETAILS.
			// STACK INSERTS
			// STACK TIMING FOR 100 ELEMENTS
			Stack stack100;

			cout << "Inserting 100 elements into the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 100; i++)
			{
				stack100.push(rand() % 100);
			}

			// Get the end time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point endTime = getEndTime();

			cout << "100 elements inserted into the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackInsertTime100 = elapsedTime(startTime, endTime);

			// STACK TIMING FOR 1000 ELEMENTS
			Stack stack1000;

			cout << "\nInserting 1,000 elements into the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 1000; i++)
			{
				stack1000.push(rand() % 1000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements inserted into the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackInsertTime1000 = elapsedTime(startTime, endTime);

			// STACK TIMING FOR 10000 ELEMENTS
			Stack stack10000;

			cout << "\nInserting 10,000 elements into the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 10000; i++)
			{
				stack10000.push(rand() % 1000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements inserted into the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackInsertTime10000 = elapsedTime(startTime, endTime);
			// END OF STACK INSERTS

			// STACK DELETES
			// STACK TIMING FOR 100 ELEMENTS
			cout << "\nDeleting 100 elements from the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 100; i++)
			{
				stack100.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "100 elements deleted from the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackDeleteTime100 = elapsedTime(startTime, endTime);

			// STACK TIMING FOR 1000 ELEMENTS
			cout << "\nDeleting 1,000 elements from the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 1000; i++)
			{
				stack1000.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements deleted from the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackDeleteTime1000 = elapsedTime(startTime, endTime);

			// STACK TIMING FOR 10000 ELEMENTS
			cout << "\nDeleting 10,000 elements from the stack..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the stack 100 times.
			for (int i = 0; i < 10000; i++)
			{
				stack10000.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements deleted from the stack..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> stackDeleteTime10000 = elapsedTime(startTime, endTime);
			// END OF STACK DELETES

			// QUEUE INSERTS
			// QUEUE TIMING FOR 100 ELEMENTS
			Queue queue100;

			cout << "\nInserting 100 elements into the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 100 times.
			for (int i = 0; i < 100; i++)
			{
				queue100.push(rand() % 100);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "100 elements inserted into the queue..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> queueInsertTime100 = elapsedTime(startTime, endTime);

			// QUEUE TIMING FOR 1000 ELEMENTS
			Queue queue1000;

			cout << "\nInserting 1,000 elements into the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 1,000 times.
			for (int i = 0; i < 1000; i++)
			{
				queue1000.push(rand() % 1000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements inserted into the queue..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> queueInsertTime1000 = elapsedTime(startTime, endTime);

			// QUEUE TIMING FOR 10000 ELEMENTS
			Queue queue10000;

			cout << "\nInserting 10,000 elements into the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 10,000 times.
			for (int i = 0; i < 10000; i++)
			{
				queue10000.push(rand() % 1000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements inserted into the queue..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> queueInsertTime10000 = elapsedTime(startTime, endTime);
			// END OF QUEUE INSERTS

			// QUEUE DELETES
			// QUEUE TIMING FOR 100 ELEMENTS
			cout << "\nDeleting 100 elements from the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 100 times.
			for (int i = 0; i < 100; i++)
			{
				queue100.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			// Print out elapsed time to the user.
			chrono::duration<double> queueDeleteTime100 = elapsedTime(startTime, endTime);

			// QUEUE TIMING FOR 1000 ELEMENTS
			cout << "\nDeleting 1,000 elements from the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 1,000 times.
			for (int i = 0; i < 1000; i++)
			{
				queue1000.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements deleted from the queue..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> queueDeleteTime1000 = elapsedTime(startTime, endTime);

			// QUEUE TIMING FOR 10000 ELEMENTS
			cout << "\nDeleting 10,000 elements from the queue..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the queue 10,000 times.
			for (int i = 0; i < 10000; i++)
			{
				queue10000.pop();
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements deleted from the queue..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> queueDeleteTime10000 = elapsedTime(startTime, endTime);
			// END OF QUEUE DELETES

			getResults(stackInsertTime100, stackInsertTime1000, stackInsertTime10000, stackDeleteTime100, stackDeleteTime1000, stackDeleteTime10000, queueInsertTime100, queueInsertTime1000, queueInsertTime10000, queueDeleteTime100, queueDeleteTime1000, queueDeleteTime10000);
		}
		else if (menuChoice == 4)
		{
			return 0;
		}
		else
		{
			cout << "Please enter a valid number from 1 to 4.\n" << endl;
		}
	} // ... End FULL program loop.


	cout << "\n" << endl;
	system("pause");
	return 0;
}