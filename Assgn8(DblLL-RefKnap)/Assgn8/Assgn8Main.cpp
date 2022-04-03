//File: Assgn8Main.cpp
//Project: CSIS 3400 Assignment 8
//Author: Mathew Doty
//Version: 2.1 Oct 30, 2021

#include "SortDblLnkLst.h"

//Recursion variables
//Currently works with one function per run in main
//Will need to touch up on function
static const int arrlength = 5;

static int weights[arrlength] = { 11, 8, 7, 6, 5 };

void knapsack(int tar, int ind);

bool combo = false;

int main()
{
	SortDblLnkLst<int> usl = SortDblLnkLst<int>();

	usl.printList();
	usl.putItem(3);
	usl.putItem(1);
	usl.putItem(9);
	usl.putItem(5);
	usl.printList();

	cout << "Enter a value to find" << endl;
	int findVal;
	cin >> findVal;

	if (usl.findItem(findVal) == true)
		cout << findVal << " is found in the list" << endl;
	else
		cout << findVal << " is not found in the list" << endl;

	usl.deleteItem(99);
	usl.printList();
	usl.printListReverse();

	SortDblLnkLst<string> uslStr = SortDblLnkLst<string>();
	uslStr.printList();
	uslStr.putItem("Honda");
	uslStr.putItem("Lexus");
	uslStr.putItem("Toyota");
	uslStr.putItem("Ford");
	uslStr.printList();

	cout << "Enter a value to find" << endl;
	string findStr;
	cin >> findStr;

	if (uslStr.findItem(findStr) == true)
		cout << findStr << " is found in the list" << endl;
	else
		cout << findStr << " is not found in the list" << endl;

	uslStr.deleteItem("Ford");
	uslStr.printList();
	uslStr.printListReverse();

	knapsack(20, 0);

	return 0;
}

void knapsack(int tar, int ind)
{

	if (tar == 0)
	{
		combo = true;
		return;
	}
	else if (ind >= arrlength)
	{
		return;
	}
	else if (tar < weights[ind])
	{
		knapsack(tar, ind + 1);
		return;
	}
	else if (tar >= weights[ind])
	{
		knapsack(tar - weights[ind], ind + 1);
		if (combo == true)
		{
			cout << weights[ind] << " ";
			return;
		}
		else
		{
			knapsack(tar, ind + 1);
			return;
		}
	}

	if (combo == false)
		cout << "No possible combination found";
	cout << endl;

}
