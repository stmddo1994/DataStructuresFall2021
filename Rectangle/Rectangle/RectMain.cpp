#include "Rectangle.h"

int main()
{
	double len, wid;

	cout << "Please enter length of rectangle: " << endl;
	cin >> len;

	cout << "Please enter width of rectangle: " << endl;
	cin >> wid;

	Rectangle R0 = Rectangle(len, wid);

	R0.printRect();

	Rectangle R1 = Rectangle();

	R1.printRect();

	Rectangle R2 = Rectangle(3.0, 1.5);

	R2.printRect();

	return 0;
}