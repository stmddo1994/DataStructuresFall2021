//File: SortedArrays.h
//Project: CSIS 3400 Assignment 4
//Author: Mathew Doty
//Version: 1.4 Sep 23, 2021

#include <iostream>

using namespace std;

class SortedArrayBufferNoDups
{
protected:
	int BUFFER_SIZE; 
	int* intArray;
	int numberOfElements = 0; 
	int locationOf(int target);

public:
	SortedArrayBufferNoDups(); //NoArg Constructor

	SortedArrayBufferNoDups(int size); //Arg Constructor

	bool insert(int value);

	bool find(int target);

	void display();

	bool stableRemove(int target);
};

class SortedArrayBufferWithDups
{
protected:
	int BUFFER_SIZE;
	int* intArray;
	int numberOfElements = 0;
	int locationOf(int target);

public:
	SortedArrayBufferWithDups(); //NoArg Constructor

	SortedArrayBufferWithDups(int size); //Arg Constructor

	bool insert(int value);

	bool find(int target);

	void display();

	bool stableRemove(int target);

	int findAll(int target);

	int stableRemoveAll(int target);
};