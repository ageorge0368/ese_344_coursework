#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class Record>
class Sortable_list {
private:

	vector<Record> entry;			// Vector storing the elements of the list
	int numOfComp;				// Number of comparisons 


public:
	// Constructor
	Sortable_list () {
		numOfComp = 0;
	}

	// Getter
	vector<Record>& getEntry() {
		return entry;
	}

	// Quick sort methods
	void swap(int low, int high) {
		Record temp;
		temp = entry[low];
		entry[low] = entry[high];
		entry[high] = temp;
	}

	int partition(int low, int high) {
		Record pivot;
		int i, // used to scan through the list
			last_small; // position of the last key less than pivot
		swap(low, (low + high) / 2);
		pivot = entry[low]; // First entry is now pivot.
		last_small = low;
		for (i = low + 1; i <= high; i++) {
			/* At the beginning of each iteration of this loop, we have the following conditions:
			If low < j <= last_small then entry[j].key < pivot.
			If last_small < j < i then entry[j].key >= pivot. */
			numOfComp++;			// increment the counter after each comparison

			if (entry[i] < pivot) {
				last_small = last_small + 1;
				swap(last_small, i); // Move large entry to right and small to left.
			}

		}
		swap(low, last_small); // Put the pivot into its proper position.
		return last_small;
	}

	void recursive_quick_sort(int low, int high) {
		int pivot_position;
		if (low < high) { // Otherwise, no sorting is needed.
			pivot_position = partition(low, high);
			recursive_quick_sort(low, pivot_position - 1);
			recursive_quick_sort(pivot_position + 1, high);
		}
	}

	void quick_sort() {
		recursive_quick_sort(0, entry.size() - 1);
	}


	// Heap Sort Methods
	void heapify(int n, int i) {
		int biggestVal = i;
		int leftChild = (2 * i) + 1;
		int rightChild = (2 * i) + 2;

		// Checking if the left child is larger than the root
		if ((leftChild < n) && (entry[leftChild] > entry[biggestVal])) {
			biggestVal = leftChild;
		}

		// Checking if the right child is larger than the root
		if ((rightChild < n) && (entry[rightChild] > entry[biggestVal])) {
			biggestVal = rightChild;
		}

		numOfComp += 2;

		// Checking if biggestVal is not the root
		if (biggestVal != i) {
			std::swap(entry[i], entry[biggestVal]);

			// Now heapify the smaller subtree
			heapify(n, biggestVal);
		}
	}

	void build_heap() {
		// n => size of the array / vector
		int n = entry.size();

		// Building the heap for the first time!
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(n, i);
		}
	}

	void heap_sort()
	{
		// n => size of the array / vector
		int n = entry.size();

		// Building the heap for the first time
		build_heap();
		
		// One by one extract an element from heap
		for (int i = n - 1; i >= 0; i--) {
			// Move current root to end
			std::swap(entry[0], entry[i]);

			// call max heapify on the reduced heap
			heapify(i, 0);
		}
	}


	// Other Methods
	int numOfComparisons() {
		return numOfComp;
	}

	double mean() {
		int sum = 0; 
		double mean = 0.0;
		for (int i = 0; i < entry.size(); i++) {
			sum = sum + entry.at(i);
		}

		mean = sum / entry.size();
		
		return mean;
	}

	int median() {
		if (entry.size() % 2 != 0) {
			return entry[entry.size() / 2];
		}
		else {
			int evenMedian = (entry[(entry.size() - 1) / 2] + entry[entry.size() / 2]) / 2;
			return evenMedian;
		}
	}

	double standardDev(double inputMean) {
		double stanDevSum = 0;

		for (int i = 0; i < entry.size(); i++) {
			stanDevSum = stanDevSum + pow((entry[i] - inputMean), 2);
		}
		double stanDev = sqrt((stanDevSum / entry.size()));

		return stanDev;
	}
};