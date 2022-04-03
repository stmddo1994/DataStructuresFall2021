#include <iostream>
using namespace std;

class CSIS3400Arrays
{
private:
	int size;
	int numberOfElements = 0;
	int* intArray;

	/*locating method for the array*/
	int locationOf(int target);

public:
	//default constructor and constructor 
	CSIS3400Arrays();
	CSIS3400Arrays(int BUFFER_SIZE);

	//destructor
	~CSIS3400Arrays();

	/*standard array methods*/
	bool insert(int value);
	bool stableRemove(int value);
	bool find(int target);
	void display();

};

