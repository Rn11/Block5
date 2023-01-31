#include <iostream>
#include <ctime>

using namespace std;

/*
This is a program that sorts an array of 10 random numbers using heap sort. The time complexity of heap sort is O(n log n).
It creates a max-heap and  rearranges the numbers in the array so that the largest number is at the end.
This procedure is then repeated until the whole array is sorted. This makes use of a recursive call of heapify().
*/

// prototypes of functions
void printArray(int values[], int n);
void heapSort(int values[], int n);
void heapify(int values[], int n, int i);

int main() {
	int values[10], elements;
	srand((unsigned)time(NULL));

	cout << "########################\n";
	cout << "# HEAP SORT TO MINHEAP #\n";
	cout << "########################\n\n";

	// generate random values, print them out and write them into array called values
	cout << "Random number array content:\n";
	for (int i = 0; i < 10; i++) {
		values[i] = rand() % 100;
		cout << values[i] << "\t";
	}

	// programatically set amount of elements in values array
	elements = sizeof(values) / sizeof(values[0]);
	heapSort(values, elements);

	cout << "\n\nSorted array content:\n";
	printArray(values, elements);
	return 0;
}

// prints out all elements of values with formatting
void printArray(int values[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << values[i] << "\t";
	}
	cout << endl;
}

// sorts an array with heap sort
void heapSort(int values[], int n) {
	// start building min heap from reading max heap backwards
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(values, n, i);
	// sort by swapping first element with last element and heapifying remaining elements in values
	for (int i = n - 1; i >= 0; i--) {
		swap(values[0], values[i]);
		heapify(values, i, 0);
	}
}

// rearranges elements in array to so we get a max-heap
void heapify(int values[], int n, int i) {
	// initialize largest to be root node
	int largest = i;
	// left child node
	int left = 2 * i + 1;
	// right child node
	int right = 2 * i + 2;
	// if the left child node exists and the value is greater than the current largest value
	// update largest with value of left child node
	if (left < n && values[left] > values[largest])
		largest = left;
	// if the right child node exists and its value is greater than the current largest value
	// update largest with value of right child node
	if (right < n && values[right] > values[largest])
		largest = right;
	// if the largest is not the root node, swap the largest and the root node
	// and recursively call the heapify function again with the the new largest (root) node set
	if (largest != i) {
		swap(values[i], values[largest]);
		heapify(values, n, largest);
	}
}