//File: md2689_Assignment1.cpp
//Project: CSIS 3400 Assignment 1
//Author: Mathew Doty
//Version: 1.2 Aug 29, 2021

#include <iostream>

using namespace std;

void printPersonalData()
{
	//  1) Name 
	cout << "Name: Mathew Doty" << endl;
	//  2) Email address 
	cout << "Email address: md2689@mynsu.nova.edu" << endl;
	//  3) Major
	cout << "Major: Computer Science" << endl;
	//  4) Status at Nova (full-time, part-time, non-degree seeking)
	cout << "Status at Nova: full-time" << endl;
	//  5) Employment status (full-time, part-time, intern, student)
	cout << "Employment status: student" << endl;
	//  6) Campus dorm or town where you now live
	cout << "Current home: Coral Springs, FL" << endl;
	//  7) Hometown where you grew up 
	cout << "Hometown where I grew up: Coral Springs, FL" << endl;
	//  8) Previous programming course(s) taken, where, and instructor’s name
	cout << "Previous programming courses: Basic Programming and Advanced Programming, both taught by Professor Ajoy Kumar at NSU" << endl;
	//  9) Other CS or Tech course(s) taken (and where if not Nova) 
	cout << "Other CS or Tech courses: Intro to Computer Science" << endl;
	// 10) Programming languages with which you have even a little experience
	cout << "Programming languages with which I have some experience: Python, Java" << endl;
}

void printSmallest(int x, int y, int z)
{
	int sm;

	if (x <= y && x <= z)
		sm = x;
	else if (y <= z)
		sm = y;
	else
		sm = z;

	cout << "The smallest value among " << x << ", " << y << ", and " << z << " is " << sm << "." << endl;
}

void printAsterisk(int r)
{
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= r - i; j++)
			cout << "-";
		for (j > r - i; j <= r; j++)
			cout << "*";
		cout << endl;
	}
}

int main()
{
	
	printPersonalData();
	cout << endl;

	int a, b, c;
	cout << "You will be asked to input three integers and the program will determine the smallest among them." << endl;
	cout << "Enter the first integer: " << endl;
	cin >> a;
	cout << "Enter the second integer: " << endl;
	cin >> b;
	cout << "Enter the third integer: " << endl;
	cin >> c;
	printSmallest(a, b, c);
	cout << endl;

	int n;
	cout << "Input a number of rows: " << endl;
	cin >> n;
	printAsterisk(n);

	return 0;

}


