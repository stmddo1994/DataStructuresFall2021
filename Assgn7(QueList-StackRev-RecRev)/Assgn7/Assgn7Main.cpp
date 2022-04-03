//File: Assgn7Main.cpp
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 3.1 Oct 23, 2021
#include "sortedRevLLStr.h"
#include "queueList.h"

int doty_exp(int x, int y);

int main()
{
	sortedRevLLStr uslStr = sortedRevLLStr();
	uslStr.printList();
	uslStr.putItem("Honda");
	uslStr.putItem("Toyota");
	uslStr.putItem("Lexus");
	uslStr.putItem("Ford");
	uslStr.printList();

	uslStr.displayListBackwards();
	cout << "Enter a char to find the word in the list" << endl;
	char endChar;
	cin >> endChar;
	cout << uslStr.findWordEndIn(endChar) << endl;
	uslStr.deleteItem("Ford");
	uslStr.printList();

	uslStr.putItem("Chevy");
	uslStr.putItem("Volkswagon");
	cout << "Enter a char to find the word in the list" << endl;
	cin >> endChar;
	cout << uslStr.findWordEndIn(endChar) << endl;
	uslStr.displayListBackwards();
	uslStr.displayListBackwardsRecM();

	qList_mathew<int> iqll = qList_mathew<int>();
	iqll.printQue();

	iqll.addQue(7);
	iqll.addQue(32);
	iqll.addQue(14);
	iqll.addQue(27);
	iqll.addQue(14);
	iqll.addQue(39);
	iqll.addQue(10);

	iqll.printQue();

	cout << iqll.findItemQue(39) << endl;
	cout << iqll.findItemQue(30) << endl;

	int q = 0;

	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.printQue();

	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.addQue(55);
	iqll.printQue();

	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.removeQue(q);
	cout << q << " was removed." << endl;
	iqll.removeQue(q);
	cout << q << " was removed." << endl;

	iqll.removeQue(q);

	iqll.printQue();

	cout << "Please enter an integer followed by a positive exponent: " << endl;
	int a;
	int b;

	cin >> a;
	cin >> b;

	int result = doty_exp(a, b);

	cout << a << " to the power of " << b << " equals " << result << endl;

	return 0;
}

int doty_exp(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return x * doty_exp(x, y - 1);
}