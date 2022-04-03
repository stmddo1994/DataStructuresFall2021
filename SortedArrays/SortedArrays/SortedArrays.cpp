//File: SortedArrays.cpp
//Project: CSIS 3400 Assignment 4
//Author: Mathew Doty
//Version: 2.1 Sep 24, 2021

#include "SortedArrays.h" 

int SortedArrayBufferNoDups::locationOf(int tar)
{
	//loop through array so far
	for (int i = 0; i < numberOfElements; i++)
	{
		if (tar == intArray[i])
			return i;
		//Should stop as soon as target reaches higher number
		else if (tar < intArray[i])
			return -1;
	}
	return -1;
}

bool SortedArrayBufferNoDups::find(int t)
{
	if (locationOf(t) == -1)
		return false;
	else
		return true;
}

SortedArrayBufferNoDups::SortedArrayBufferNoDups()
{
	BUFFER_SIZE = 8;
	intArray = new int[BUFFER_SIZE];
}

SortedArrayBufferNoDups::SortedArrayBufferNoDups(int s)
{
	BUFFER_SIZE = s;
	intArray = new int[BUFFER_SIZE];
}

bool SortedArrayBufferNoDups::insert(int val)
{
	//Temporary number for storage
	int tempnum;

	//Display message for duplicated number
	if (locationOf(val) != -1)
	{
		cout << "Cannot insert duplicated number" << endl;
		return false;
	}

	if (numberOfElements < BUFFER_SIZE)
	{
		//Insert value at the top of the array
		intArray[numberOfElements] = val;
		numberOfElements++;

		//Compare numbers backwards
		for (int i = numberOfElements - 1; i > 0; i--)
		{
			//If number on left is greater than the inserted value
			//Swap the two numbers
			if (val < intArray[i - 1])
			{
				tempnum = intArray[i - 1];
				intArray[i - 1] = val;
				intArray[i] = tempnum;
			}
			//break from the loop if number on the left is smaller
			else
				break;
		}
		return true;
	}
	return false;
}

void SortedArrayBufferNoDups::display()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << intArray[i];
		if (i + 1 < numberOfElements)
			cout << ", ";
	}
	cout << endl;
}

bool SortedArrayBufferNoDups::stableRemove(int t)
{
	if (locationOf(t) == -1)
		return false;
	//If target found, replace current number with number to the right
	//Do the same for every number to the right
	//And deincriment number of elements
	else
		for (int i = locationOf(t); i < numberOfElements - 1; i++)
			intArray[i] = intArray[i + 1];
	numberOfElements--;
	return true;
}

int SortedArrayBufferWithDups::locationOf(int tar)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if (tar == intArray[i])
			return i;
		//Should stop once target reaches higher number
		else if (tar < intArray[i])
			return -1;
	}
	return -1;
}

bool SortedArrayBufferWithDups::find(int t)
{
	if (locationOf(t) == -1)
		return false;
	else
		return true;
}

SortedArrayBufferWithDups::SortedArrayBufferWithDups()
{
	BUFFER_SIZE = 8;
	intArray = new int[BUFFER_SIZE];
}

SortedArrayBufferWithDups::SortedArrayBufferWithDups(int s)
{
	BUFFER_SIZE = s;
	intArray = new int[BUFFER_SIZE];
}

bool SortedArrayBufferWithDups::insert(int val)
{
	int tempnum;

	//Same method as no dups but without blocking same number
	if (numberOfElements < BUFFER_SIZE)
	{
		intArray[numberOfElements] = val;
		numberOfElements++;

		for (int i = numberOfElements - 1; i > 0; i--)
		{
			if (val < intArray[i - 1])
			{
				tempnum = intArray[i - 1];
				intArray[i - 1] = val;
				intArray[i] = tempnum;
			}
			else
				break;
		}
		return true;
	}
	return false;
}

void SortedArrayBufferWithDups::display()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << intArray[i];
		if (i + 1 < numberOfElements)
			cout << ", ";
	}
	cout << endl;
}

bool SortedArrayBufferWithDups::stableRemove(int t)
{
	if (locationOf(t) == -1)
		return false;
	else
		for (int i = locationOf(t); i < numberOfElements - 1; i++)
			intArray[i] = intArray[i + 1];
	numberOfElements--;
	return true;
}

int SortedArrayBufferWithDups::findAll(int tar)
{
	int numFinds = 0;

	if (locationOf(tar) != -1)
	{
		//If number is in the array, start with location of the target
		//And incriment number of finds until it reaches the end
		//Or a number higher than the target
		for (int i = locationOf(tar); i < numberOfElements; i++)
		{
			if (tar < intArray[i])
				break;
			numFinds++;
		}
	}
	return numFinds;
}

int SortedArrayBufferWithDups::stableRemoveAll(int val)
{
	int numRemoved = findAll(val);

	if (locationOf(val) != -1)
	{
		//Continue to remove numbers from the array
		//Until the number in the array is no longer equal to the value
		while(val == intArray[locationOf(val)])
			stableRemove(val);
	}

	return numRemoved;
}