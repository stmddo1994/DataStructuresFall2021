//File: Assgn6Main.cpp
//Project: CSIS 3400 Assignment 6
//Author: Mathew Doty
//Version: 1.4 Oct 15, 2021

#include "StackDoublePopArr.h"

int main()
{

	StackDoublePopArr<string> str = StackDoublePopArr<string>();

	str.push("Arc");
	str.push("Final");
	str.push("Peak");

	str.printStack();

	str.pop();

	str.printStack();

	str.pop();

	str.printStack();

	str.pop();

	StackDoublePopLLT<int> llint = StackDoublePopLLT<int>();

	llint.push(7);
	llint.push(12);
	llint.push(4);

	llint.printStack();

	llint.pop();

	llint.printStack();

	llint.push(2);
	llint.push(8);

	llint.printStack();

	llint.pop();

	llint.printStack();

	llint.pop();

	llint.printStack();

	return 0;
}