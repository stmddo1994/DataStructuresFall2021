#include <iostream>

using namespace std;
//This is a comment
/*
This is a multiline comment
*/

int add(int, int); //definition of a function

//write function prior to main

int main()
{
	int x;
	//integer variable declared

	cout << "Please enter an integer" << endl;
	//Prompt for user

	cin >> x;
	//Input read into variable x

	cout << x + 3 << endl;

	cout << "Welcome to the world of C++" << endl;

	int y = add(x, 3);

	void swap(x, y);

	cout << "y = " << y << endl;

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "x = " << a << " y = " << b;
}