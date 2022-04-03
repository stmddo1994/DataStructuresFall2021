#include <iostream>
#include <string>

using namespace std;

static const int numValues = 10;

static int values[numValues] = { 9, 22, 3, 41, 18, 7, 24, 1, 8, 11 };
//static double values[numValues] = { 9.2, 22.2, 3.2, 41.7, 7.2, 24.3, 1.2, 8.2, 99.0 };
//static string values[numValues] = { "hat", "bat", "cat", "rat", "eat", "sat", "mat", "pat", "fat", "oat" };

void display();

void swap(int& item1, int& item2);



//Insertion sort
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
void bubbleUp(int startIndex, int lastIndex)
{
	//Switches adjacent pair out of order
	for (int index = lastIndex; index > startIndex; index--)
	{
		if (values[index] < values[index - 1])
			swap(values[index], values[index - 1]);
	}
}

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
//Selection Sort two functions minIndex and selectionSort
int minIndex(int startIndex, int endIndex)
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

void swap(int& item1, int& item2)
{
	int temp = item1;
	item1 = item2;
	item2 = temp;
}

void selectionSort()
{
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
	{
		swap(values[current], values[minIndex(current, endIndex)]);
		//display();
	}
}

//Merge Sort (O(NlogN))
void merge(int leftFirst, int leftLast, int rightFirst, int rightLast)
//Pre-condition values[leftFirst]...values[leftLast] are sorted
//And values[rightFirst]...values[rightLast] are also sorted
{
	cout << "LeftFIRST: " << leftFirst << " rightLAST: " << rightLast << endl;
	int* temp = new int[numValues];
	int index = leftFirst;
	int saveFirst = leftFirst;
	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (values[leftFirst] < values[rightFirst])
		{
			temp[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			temp[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	while (leftFirst <= leftLast)
		//copy remaining items from left half
	{
		temp[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast)
		//copy remaining items from right half
	{
		temp[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = saveFirst; index <= rightLast; index++)
		values[index] = temp[index];
	display();
}

void mergeSort(int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(first, middle);
		mergeSort(middle + 1, last);

		merge(first, middle, middle + 1, last);
	}
}

//Quick Sort (O(NlogN)...maybe)
int split(int first, int last)
{
	int splitVal = values[first];
	int saveF = first;
	bool onCorrectSide;
	first++;

	do
	{
		onCorrectSide = true;
		while (onCorrectSide)
		{
			if (values[first] > splitVal)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		}
		onCorrectSide = (first <= last);
		while (onCorrectSide)
		{
			if (values[last] < splitVal)
				onCorrectSide = false;
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}
		}
		if (first < last)
		{
			swap(values[first], values[last]);
			display();
			first++;
			last--;
		}
	} while (first <= last);

	swap(values[saveF], values[last]);
	display();
	cout << "saveF phase" << endl;
	return last;
}

void quickSort(int first, int last)
{
	if (first < last)
	{
		int splitPoint;
		splitPoint = split(first, last);
		//values[splitPoint] = splitValue
		quickSort(first, splitPoint - 1);
		quickSort(splitPoint + 1, last);
	}
}

//Heap Sort O(logN)
void reheapDown(int root, int lastIndex)
{
	int maxChild;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;
	
	maxChild = leftChild;
	if (leftChild <= lastIndex)
	{
		if (leftChild == lastIndex)
			maxChild = leftChild;
		else
		{
			if (values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
	}
	else
		return;
	if (values[root] < values[maxChild])
	{
		swap(values[root], values[maxChild]);
		reheapDown(maxChild, lastIndex);
	}
}

void heapSort()
{
	int index;
	for (index = numValues / 2 - 1; index >= 0; index--)
	{
		reheapDown(index, numValues - 1);
	}
	for (index = numValues - 1; index >= 1; index--)
	{
		swap(values[0], values[index]);
		reheapDown(0, index - 1);
	}
}

void display()
{
	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Array Before Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	//selectionSort();
	//bubbleSort();
	//shortBubble();
	//insertionSort();
	//mergeSort(0, 9);
	quickSort(0, 9);
	//heapSort();
	cout << endl;

	cout << "Array After Sorting" << endl;
	cout << "-------------------------" << endl;
	display();

	return 0;
}