#include <iostream>

#include <string>

using namespace std;

class GeoObject
{
protected:
	string createDateTime;
	string color = "White";
	bool filled = false;

public:
	GeoObject();
	  GeoObject(string date, string clr, bool fill);
	  string getCreateDttm();
	  string getColor();
	  bool isFilled();
	  void setColor(string clr);
	  void setFilled(bool fill);
	  virtual string display();
};

class Rectangle : 
public GeoObject
{
private:
	double length;
	double width;
public:
	Rectangle();
	Rectangle(string date, string clr, bool fill, double len, double wid);
	inline double getLength() 
	{ 
		return length; 
	}
	inline double getWidth() 
	{ 
		return width;  
	}
	void setLength( double len );
	void setWidth(double wid);
	string display();
	double calcArea();
	double calcPeri();
};
