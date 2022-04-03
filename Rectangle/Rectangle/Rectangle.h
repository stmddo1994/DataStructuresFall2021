#include <iostream>

using namespace std;

//Header defines the functions
class Rectangle
{
private:
	//private attributes
	double length;
	double width;
	
public:
	//constructors: create instace or object of a class
	//define constructors first
	Rectangle(); //no-argument constructor
	Rectangle(double x, double y); //argument constructor

	//Accessors/Getters
	double getLength();
	double getWidth();

	//Mutators/Setters
	void setLength(double x);
	void setWidth(double y);

	//Operators
	double calcArea();
	double calcPerimeter();

	void printRect();

};
