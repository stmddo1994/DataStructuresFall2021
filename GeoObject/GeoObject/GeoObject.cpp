#include "GeoObject.h"
GeoObject::GeoObject()
{
	createDateTime = "1970/01/01 12:00 am";
}
GeoObject::GeoObject(string date, string clr, bool fill)
{
	this->createDateTime = date;
	this->color = clr;
	this->filled = fill;
}
string GeoObject::getCreateDttm()
{
	return createDateTime;
}
string GeoObject::getColor()
{
	return color;
}
bool GeoObject::isFilled()
{
	return filled;
}
void GeoObject::setColor(string clr)
{
	color = clr;
}
void GeoObject::setFilled(bool fill)
{
	filled = fill;
}
string GeoObject::display()
{
	string op = "GeoObject with color " + color + " was created at " + createDateTime;
	string fld;
	fld = isFilled() ? "  and Is Filled " : "  and Is not filled ";
	op += fld + "\n";
	return op;
}
Rectangle::Rectangle()
{
	length = 0.0;width = 0.0;
}
Rectangle::Rectangle(string date, string clr, bool fill, double len, double wid):GeoObject( date, clr, fill)
{
	length = len;
	width = wid;
}
void Rectangle::setLength(double len) 
{ 
	length = len; 
}
void Rectangle::setWidth(double wid) 
{
	width = wid; 
}
string Rectangle::display() 
{
	string op = GeoObject::display();
	op += "Length = " + to_string(length) + "\n"; 
	op += "Width = " + to_string(width) + "\n"; 
	return op; 
}
double Rectangle::calcArea() 
{ 
	return length * width; 
}
double Rectangle::calcPeri() 
{ 
	return 2.0 * (length + width); 
}