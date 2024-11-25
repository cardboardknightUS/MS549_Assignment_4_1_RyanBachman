/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	stack.h
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

#ifndef STACK_H
#define STACK_H

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Create a stack class using a Node struct for doubly linked lists.
class Stack
{
private:
	struct Node
	{
		int data;
		Node* prev;
		Node* next;
	};

	Node* top;
	Node* bottom;

public:
	Stack();
	~Stack();
	void push(int value);
	int pop();
	int isEmpty();
	int peek();
	void printStack();
	void moveToTopAndPop(int value);
};
#endif