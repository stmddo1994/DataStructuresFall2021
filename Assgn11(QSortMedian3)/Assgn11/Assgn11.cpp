//File: Assgn11.cpp
//Project: CSIS 3400 Assignment 11
//Author: Mathew Doty
//Version: 3.2 Nov 19, 2021
#include <iostream>

using namespace std;

static const int numValues = 11;

static int values[numValues] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};

void display()
{
	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;
}

void swap(int& item1, int& item2)
{
	int temp = item1;
	item1 = item2;
	item2 = temp;
}

int split(int first, int last)
{
	int splitVal = values[first];
	int saveF = first;
	bool onCorrectSide;
	first++;

	do
	{
		onCorrectSide = true;
		while (onCorrectSide)
		{
			if (values[first] > splitVal)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		}
		onCorrectSide = (first <= last);
		while (onCorrectSide)
		{
			if (values[last] < splitVal)
				onCorrectSide = false;
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}
		}
		if (first < last)
		{
			swap(values[first], values[last]);
			display();
			first++;
			last--;
		}
	} while (first <= last);

	swap(values[saveF], values[last]);
	display();
	cout << "saveF phase" << endl;
	return last;
}

int median(int first, int last)
{
	int middle = (first + last) / 2;
	if (values[first] > values[middle])
		swap(values[first], values[middle]);
	if (values[middle] > values[last])
		swap(values[middle], values[last]);
	if (values[first] > values[middle])
		swap(values[first], values[middle]);
	cout << values[first] << " " << values[middle] << " " << values[last] << endl;

	swap(values[middle], values[first]);
	display();
	cout << "Bring median front" << endl;

	return split(first, last);
}

void quickSort(int first, int last)
{
	if (first < last)
	{
		int splitPoint;
		splitPoint = median(first, last);
		quickSort(first, splitPoint - 1);
		quickSort(splitPoint + 1, last);
	}
}

void quickSort2(int first, int last)
{
	int sortStack[numValues];
	int top = -1;
	top++;
	sortStack[top] = first;
	top++;
	sortStack[top] = last;

	while (top >= 0)
	{
		last = sortStack[top];
		top--;
		first = sortStack[top];
		top--;

		int splitPoint = median(first, last);
		cout << "Pivot: " << splitPoint << endl;

		if (splitPoint - 1 > first)
		{
			top++;
			sortStack[top] = first;
			top++;
			sortStack[top] = splitPoint - 1;
		}

		if (splitPoint + 1 < last)
		{
			top++;
			sortStack[top] = splitPoint + 1;
			top++;
			sortStack[top] = last;
		}
	}
}

int main()
{
	cout << "Array Before Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	//quickSort(0, 10);
	//cout << endl;

	quickSort2(0, 10);
	cout << endl;

	cout << "Array After Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	return 0;
}