#include <iostream>

using namespace std;

int main()
{
	int a = 3, b = -17;
	int* fp;

	fp = &b;
	cout << "I1: " << " a = " << a << " b = " << b << " fp = " << fp << " * fp = " << *fp << endl;
	b++;
	cout << "I2: " << " a = " << a << " b = " << b << " fp = " << fp << " * fp = " << *fp << endl;
	*fp = *fp - 2;
	cout << "I3: " << " a = " << a << " b = " << b << " fp = " << fp << " * fp = " << *fp << endl;
	a = *fp;
	a++;
	cout << "I4: " << " a = " << a << " b = " << b << " fp = " << fp << " * fp = " << *fp << endl;
}