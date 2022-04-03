#include <iostream>

using namespace std;

int factorial(int);

int main()
{
	cout << "Please enter positive integer: " << endl;
	int num;

	cin >> num;

	int result = factorial(num);

	cout << "Factorial of " << num << " is " << result << endl;

	return 0;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}