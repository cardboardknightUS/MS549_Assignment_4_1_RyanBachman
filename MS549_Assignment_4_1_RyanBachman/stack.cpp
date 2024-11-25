/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	stack.cpp
*/

#include "stack.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

// Push function for adding a new value to the top of the stack.
void Stack::push(int value)
{
	Node* newNode = new Node{ value, nullptr, top };

	if (top)
	{
		top->prev = newNode;
	}

	top = newNode;
}

// Pop function for removing the element at the top of the stack.
int Stack::pop()
{
	// If statement to check for Stack Underflow if the user tries to pop while the stack is empty.
	if (isEmpty())
	{
		cerr << "Stack Underflow!!!" << endl;
		return -1;
	}

	int value = top->data;
	Node* temp = top;
	top = top->next;

	if (top)
	{
		top->prev = nullptr;
	}

	delete temp;

	return value;
}

// Function to check if the stack is empty.
int Stack::isEmpty()
{
	return top == nullptr;
}

// Function to return the value at the top of the stack.
int Stack::peek()
{
	if (isEmpty())
	{
		cerr << "Stack is Empty!!!" << endl;
		return -1;
	}

	return top->data;
}

// Function to print the entire stack to the user.
void Stack::printStack()
{
	Node* current = top;

	cout << "Stack: [";

	while (current != nullptr)
	{
		cout << current->data << ", ";
		current = current->next;
	}

	cout << "]" << endl;
}

// Function to move the user's inputted value to the front of the queue and calls pop() to remove the new item in front.
void Stack::moveToTopAndPop(int value)
{
	vector<int> temp;

	// While loop to fill the temporary vector with all of the values from the main stack the user is interacting with.
	while (!isEmpty())
	{
		int current = pop();

		cout << current << endl;

		if (current == value)
		{
			break;
		}

		temp.push_back(current);
	}

	if (!isEmpty())
	{
		while (!temp.empty())
		{
			push(temp.back());
			temp.pop_back();
		}

		push(value);
		pop();
	}
	else
	{
		cerr << "Value was not found in the stack!!!" << endl;

		// Restore the original stack so nothing is changed.
		while (!temp.empty())
		{
			push(temp.back());
			temp.pop_back();
		}
	}
}