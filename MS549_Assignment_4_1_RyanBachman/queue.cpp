/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Queue and a Queue
	queue.cpp
*/

#include "queue.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

Queue::Queue() : front(nullptr), back(nullptr) {}

Queue::~Queue()
{
	while (!isEmpty())
	{
		pop();
	}
}

// Push function for adding a new value to the front of the queue.
void Queue::push(int value)
{
	Node* newNode = new Node{ value };

	if (isEmpty())
	{
		front = back = newNode;
	}
	else
	{
		back->next = newNode;
		newNode->prev = back;
		back = newNode;
	}
}

// Pop function for removing the element at the front of the queue.
int Queue::pop()
{
	if (isEmpty())
	{
		cerr << "Queue is Empty!!!" << endl;
		return -1;
	}

	int value = front->data;
	Node* temp = front;

	if (front == back)
	{
		front = back = nullptr;
	}
	else
	{
		front = front->next;
		front->prev = nullptr;
	}

	delete temp;

	return value;
}

// Function to check if the queue is empty.
int Queue::isEmpty()
{
	return front == nullptr;
}

// Function to return the value at the front of the queue.
int Queue::peek()
{
	if (isEmpty())
	{
		cerr << "Queue is Empty!!!" << endl;
		return -1;
	}

	Node* temp = front;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

// Function to print the entire queue to the user.
void Queue::printQueue()
{
	Node* current = front;

	cout << "Queue: [";

	while (current != nullptr)
	{
		cout << current->data << ", ";
		current = current->next;
	}

	cout << "]" << endl;
}

// Function to move the user's inputted value to the front of the queue and calls pop() to remove the new item in front.
void Queue::moveToFrontAndPop(int value)
{
	Node* current = front;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			if (current == front)
			{
				pop();
				return; // Already at the front
			}

			if (current == back)
			{
				back = current->prev;
				back->next = nullptr;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			current->next = front;
			current->prev = nullptr;
			front->prev = current;
			front = current;

			pop();
			return;
		}
		current = current->next;
	}

	std::cerr << "Value not found in queue." << std::endl;
}