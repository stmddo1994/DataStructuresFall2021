#include "GeoObject.h"
int main()
{
	GeoObject go1 = GeoObject("9/3/2020 4:18 pm", "Red", true);
	Rectangle R1 = Rectangle("9/3/2020 4:35 pm", "Yellow", false, 1.5, 2.3);
	cout << go1.display() << endl;
	cout << R1.display() << endl;
	cout << R1.calcArea() << endl;
	cout << R1.calcPeri() << endl;
	return 0;
}