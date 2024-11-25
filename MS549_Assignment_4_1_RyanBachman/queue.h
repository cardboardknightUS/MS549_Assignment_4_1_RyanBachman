/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	queue.h
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

#ifndef QUEUE_H
#define QUEUE_H

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Create a queue class using a Node struct for doubly linked lists.
class Queue
{
private:
	struct Node
	{
		int data;
		Node* prev;
		Node* next;

		Node(int value) : data(value), prev(nullptr), next(nullptr) {}
	};

	Node* front;
	Node* back;
	vector<int> temp;

public:
	Queue();
	~Queue();
	void push(int value);
	int pop();
	int isEmpty();
	int peek();
	void printQueue();
	void moveToFrontAndPop(int value);
};
#endif