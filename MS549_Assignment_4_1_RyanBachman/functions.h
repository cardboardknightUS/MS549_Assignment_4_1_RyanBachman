/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 4.1 - Project - Linked List implemented as a Stack and a Queue
	functions.h
*/

#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

// Allows you to use iostream statements without the use of std::.
using namespace std;

int mainMenu();

int stackMenu();

int queueMenu();

chrono::high_resolution_clock::time_point getStartTime();

chrono::high_resolution_clock::time_point getEndTime();

chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh);

void getResults(chrono::duration<double> stackInsertTime100, chrono::duration<double> stackInsertTime1000, chrono::duration<double> stackInsertTime10000, chrono::duration<double> stackDeleteTime100, chrono::duration<double> stackDeleteTime1000, 
	chrono::duration<double> stackDeleteTime10000, chrono::duration<double> queueInsertTime100, chrono::duration<double> queueInsertTime1000, chrono::duration<double> queueInsertTime10000, chrono::duration<double> queueDeleteTime100, chrono::duration<double> queueDeleteTime1000, chrono::duration<double> queueDeleteTime10000);