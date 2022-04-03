#include <iostream>
#include <string>

using namespace std;

static const int numValues = 10;

//static int values[numValues] = { 9, 22, 3, 41, 18, 7, 24, 1, 8, 11 };
//static double values[numValues] = { 9.2, 22.2, 3.2, 41.7, 7.2, 24.3, 1.2, 8.2, 99.0 };
//static string values[numValues] = { "hat", "bat", "cat", "rat", "eat", "sat", "mat", "pat", "fat", "oat" };

template<class Itemtype>
void swap(Itemtype values[], int& item1, int& item2)
{
	int temp = item1;
	item1 = item2;
	item2 = temp;
}

template<class Itemtype>
void display(Itemtype values[])
{
	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;
}

void display();

void swap(int& item1, int& item2);

template<class Itemtype>
void insertItem(int startIndex, int endIndex)
{
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = true;
	while (moreToSearch && !finished)
	{
		if (values[current] < values[current - 1])
		{
			swap(values[current], values[current - 1]);
			current--;
			moreToSearch = (current != startIndex);
		}
		else
			finished = true;
	}
}

template<class Itemtype>
void insertionSort()
{
	//Sorts values in array using inserion sort
	for (int count = 1; count < numValues; count++)
	{
		insertItem(0, count);
		display();
	}
}

//------------------------------------------------
//Bubble Sort: efficient and inefficient
template<class Itemtype>
void bubbleUp(int startIndex, int lastIndex)
{
	//Switches adjacent pair out of order
	for (int index = lastIndex; index > startIndex; index--)
	{
		if (values[index] < values[index - 1])
			swap(values[index], values[index - 1]);
	}
}

template<class Itemtype>
void bubbleSort()
{
	int current = 0;

	while (current < (numValues - 1))
	{
		bubbleUp(current, numValues - 1);
		current++;
		display();
	}
}
//More efficient way of doing bubble sort

template<class Itemtype>
bool bubbleUp2(int startIndex, int lastIndex)
{
	//Switches adjacent pair out of order
	bool sorted = true;
	for (int index = lastIndex; index > startIndex; index--)
	{
		if (values[index] < values[index - 1])
		{
			swap(values[index], values[index - 1]);
			sorted = false;
		}
	}
	return sorted;
}

template<class Itemtype>
void shortBubble()
{
	int current = 0;
	bool sorted = false;
	while ((current < (numValues - 1)) && !sorted)
	{
		sorted = bubbleUp2(current, numValues - 1);
		current++;
		display();
	}
}

//---------------------------------------------------------
template<class Itemtype>
//Selection Sort two functions minIndex and selectionSort
int minIndex(Itemtype values[], int startIndex, int endIndex)
{
	//Returns index of smallest value in
	//values[startIndex] ..... values[endIndex]

	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{
		if (values[index] < values[indexOfMin])
			indexOfMin = index;
	}
	//cout << indexOfMin << endl;
	return indexOfMin;
}



template<class Itemtype>
void selectionSort(Itemtype values[])
{
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
	{
		swap(values[current], values[minIndex(current, endIndex)]);
		//display();
	}
}


int main()
{
	cout << "Array Before Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	int values1[numValues] = { 9, 22, 3, 41, 18, 7, 24, 1, 8, 11 };
	//double values2[numValues] = { 9.2, 22.2, 3.2, 41.7, 7.2, 24.3, 1.2, 8.2, 99.0 };
	//string values3[numValues] = { "hat", "bat", "cat", "rat", "eat", "sat", "mat", "pat", "fat", "oat" };

	selectionSort(values1);
	//bubbleSort();
	//shortBubble();
	//insertionSort();
	cout << endl;

	cout << "Array After Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	return 0;
}