//File: doubleStackInt.h
//Project: CSIS 3400 Assignment 6
//Author: Mathew Doty
//Version: 1.0 Oct 16, 2021

/*I would implement an array with a regular top and one top for the whole array and one top for low.
Numbers higher than 500 will be added in front while lower numbers will be added in the array before the high ones*/

#include <iostream>

using namespace std;

class doubleStackComp
{
private:
	int maxStack;
	int* items;
	int topLow;
	int top;

public:
	doubleStackComp();

	bool isEmpty();

	bool isFull();

	void push(int item);

	void pop1();
	void pop2();

	int lowTopView() const;
	int highTopView() const;
	void printStacks();
};

doubleStackComp::doubleStackComp()
{
	maxStack = 20;
	items = new int[maxStack];
	topLow = -1;
	top = -1;
}

bool doubleStackComp::isEmpty()
{
	return (top == -1);
}

bool doubleStackComp::isFull()
{
	return (top == maxStack - 1);
}

void doubleStackComp::push(int item)
{
	if (isFull())
		cout << "There are too many numbers to push into a stack" << endl;
	else
	{
		top++;

		if (item <= 500)
		{
			topLow++;
			if (topLow < top)
			{
				for (int i = top; i > topLow; i--)
					items[i] = items[i - 1];
			}
			items[topLow] = item;
		}
		else
		{
			items[top] = item;
		}
	}
	//It seems the performance of push() is O(N) if the number is lower than 500 since the array needs to move each item up before insertion
	//Push for a higher number is O(1)
}

void doubleStackComp::pop1()
{
	if (isEmpty() || topLow == -1)
		cout << "Stack is empty; cannot pop anything" << endl;
	else
	{
		if (topLow < top)
		{
			for (int i = topLow; i < top; i++)
				items[i] = items[i + 1];
		}
		topLow--;
		top--;
	}
}

void doubleStackComp::pop2()
{
	if (isEmpty() || top == topLow)
		cout << "Stack is empty; cannot pop anything" << endl;
	else
		top--;
}

int doubleStackComp::lowTopView() const
{
	if (topLow == -1)
		cout << "Stack is empty" << endl;
	else
		return items[topLow];
}

int doubleStackComp::highTopView() const
{
	if (top == topLow)
		cout << "Stack is empty" << endl;
	else
		return items[top];
}

void doubleStackComp::printStacks()
{
	if (isEmpty())
		cout << "Both stacks are empty" << endl;
	else
	{
		if (topLow == -1)
			cout << "Low stack is empty" << endl;
		else
		{
			for (int i = 0; i <= topLow; i++)
			{
				cout << items[i] << " ";
			}
			cout << endl;
		}

		if (top == topLow)
			cout << "High stack is empty" << endl;
		else
		{
			for (int i = topLow + 1; i <= top; i++)
			{
				cout << items[i] << " ";
			}
			cout << endl;
		}
	}
}