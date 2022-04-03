#include "Rectangle.h"
//What the functions do go in here

Rectangle::Rectangle()
{
	length = 1.0;
	width = 1.0;
}

Rectangle::Rectangle(double x, double y)
{
	length = x;
	width = y;
}

double Rectangle::getLength()
{
	return length;
}

double Rectangle::getWidth()
{
	return width;
}

void Rectangle::setLength(double l)
{

	length = l;

}

void Rectangle::setWidth(double w)
{

	width = w;

}

double Rectangle::calcArea()
{
	return (length * width);
}

double Rectangle::calcPerimeter()
{
	return 2.0 * (length + width);
}

void Rectangle::printRect()
{

	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Area: " << calcArea() << endl;
	cout << "Perimeter: " << calcPerimeter() << endl;
	cout << endl;
	cout << endl;
}
