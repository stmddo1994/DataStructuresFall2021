#include "Midterm3400Arrays.h"


//default constructor
CSIS3400Arrays::CSIS3400Arrays()
{
	size = 10;
	intArray = new int[size];
}

// constructor
CSIS3400Arrays::CSIS3400Arrays(int bufSize)
{
	size = bufSize;
	intArray = new int[size];
}

//destructor
CSIS3400Arrays::~CSIS3400Arrays()
{
	if (intArray) 
	{
		delete[] intArray;
	}
}

/*locating target in the array*/
int CSIS3400Arrays::locationOf(int target)
{
	/* finds the target index if exists then returns that index*/
	for (int i = 0; i < numberOfElements; i++)
		if (intArray[i] == target) 
		{
			return i;
		}
	/*returns -1 if not located*/
	return -1;
}



/*inserts value into the array*/
bool CSIS3400Arrays::insert(int value)
{
	/*checks to see if array is full*/
	if (numberOfElements < size)
	{
		int posdup;
		bool dup == false;
		for (int i = 0; i < numberOfElements; i++)
		{
			posdup = intArray[i];
			for (int j = i + 1; j < numberOfElements; j++)
			{
				if (intArray[j] == posdup)
				{
					dup == true;
					break;
				}
			}
			if dup == true;
			stableRemove(posdup);
			break;
		}
		/* adds the value into the next empty slot*/
		intArray[numberOfElements++] = value;
		return true;
	}
	else 
	{
		if (locationOf(value) != -1)
			cout << "\nArray is Full and is also a duplicate" << endl;
		/*prints that array is full*/
		else
			cout << "\nArray is Full and insert failed\n" << "\n";
		return false;
	}
}








/*removes the value and then shifts up the values to fill in the empty spot(s)*/
bool CSIS3400Arrays::stableRemove(int value)
{
	int index = locationOf(value);
	if (index != -1)
	{
		cout << "\nInteger: " << intArray[locationOf(value)] << " removed\n\n";

		for (int i = index; i < numberOfElements - 1; i++) 
		{

			intArray[i] = intArray[i + 1];

		}
		numberOfElements--;
		return true;

	}
	else 
	{

		cout << "\nValue not found in array\n" << "\n";
		return false;
	}
}




/*returns whether a value is found or not found in the array*/
bool CSIS3400Arrays::find(int target)
{
	if (locationOf(target) != -1) 
	{
		cout << target << " Found\n\n";
		return true;
	}
	else 
	{
		cout << target << " Not Found\n\n";
		return false;
	}
}




/*prints out all the integers in the array*/
void CSIS3400Arrays::display()
{
	cout << "\nCSIS3400Arrays :  ";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (i == numberOfElements - 1) 
		{
			cout << intArray[i];
		}
		else 
		{
			cout << intArray[i] << ",";
		}
	}
	cout << endl;
}


