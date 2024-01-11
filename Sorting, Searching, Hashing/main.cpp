#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for sqrt()

#include "Sortable_list.cpp"
#include "HashTable.cpp"

using namespace std;

int main() {
	srand((unsigned int)time(NULL));// seed rand() with system time

	Sortable_list<int> QSComparisons;
	Sortable_list<int> HSComparisons;

	/////////////////////////////////////////////////////////////////////////////// Part 1 ////////////////////////////////////////////////////////////////////////////////////
	for (int numOfTimes = 0; numOfTimes < 30; numOfTimes++) {
		// Generate 5000 random integers from 0 to 10^6, store them into a Sorted_List object
		// Sortable_list will be made from an array!
		Sortable_list<int> quickList, heapList;
		int randomNum = 0;

		for (int i = 0; i < 5000; i++) {
			randomNum = rand() % 1000001;			// generating a random number between 0 and 10^6
			quickList.getEntry().push_back(randomNum);
			heapList.getEntry().push_back(randomNum);
		}

		quickList.quick_sort();

		//		cout << "\nNum of Comparisons (Quick Sort): " << quickList.numOfComparisons() << endl;
		QSComparisons.getEntry().push_back(quickList.numOfComparisons());


		heapList.heap_sort();

		//		cout << "\nNum of Comparisons (Heap Sort): " << heapList.numOfComparisons() << endl;
		HSComparisons.getEntry().push_back(heapList.numOfComparisons());

	}

	QSComparisons.quick_sort();				// Sort quick sort comparisons
	HSComparisons.heap_sort();				// Sort heap sort comparisons

	cout << "Part I:" << endl;

	cout << "Quick Sort Algorithm: " << endl;
	cout << "Minimum # of Comparisons: " << QSComparisons.getEntry().at(0) << endl;
	cout << "Maximum # of Comparisons: " << QSComparisons.getEntry().at(QSComparisons.getEntry().size() - 1) << endl;

	double quickSortMean = QSComparisons.mean();
	cout << "Mean: " << quickSortMean << endl;

	cout << "Median: " << QSComparisons.median() << endl;
	cout << "Standard Deviation: " << QSComparisons.standardDev(quickSortMean) << endl;


	cout << "\nHeap Sort Algorithm: " << endl;
	cout << "Minimum # of Comparisons: " << HSComparisons.getEntry().at(0) << endl;
	cout << "Maximum # of Comparisons: " << HSComparisons.getEntry().at(HSComparisons.getEntry().size() - 1) << endl;

	double heapSortMean = HSComparisons.mean();
	cout << "Mean: " << heapSortMean << endl;

	cout << "Median: " << HSComparisons.median() << endl;
	cout << "Standard Deviation: " << HSComparisons.standardDev(heapSortMean) << endl;



	/////////////////////////////////////////////////////////////////////////////// Part 2 ////////////////////////////////////////////////////////////////////////////////////

	// Vectors for probes
	vector<int> linearProbes, quadraticProbes;

	// Random num for hash tables
	int randomHashNum = 0;

	for (int numOfTimes = 0; numOfTimes < 10; numOfTimes++) {

		// Hash Tables
		HashTable linearHash{};
		HashTable quadraticHash{};

		for (int i = 0; i < 4000; i++) {
			randomHashNum = rand() % 1000000;				// Random num from 0 to 10^6 - 1

			linearHash.linearProbing(randomHashNum);			// Inserting into linearHash with linear probing
			quadraticHash.quadraticProbing(randomHashNum);		// Inserting into quadraticHash with quadratic probing
		}

		linearProbes.push_back(linearHash.numOfProbes());
		quadraticProbes.push_back(quadraticHash.numOfProbes());
	}

	double linearSum = 0.0, quadraticSum = 0.0;

	for (int i = 0; i < 10; i++) {
		linearSum = linearSum + linearProbes.at(i);
		quadraticSum = quadraticSum + quadraticProbes.at(i);
	}

	double averageLinProbe = linearSum / 10;
	double averageQuadProbe = quadraticSum / 10;

	cout << "\nPart II: " << endl;

	cout << "Average # of Linear Probes: " << averageLinProbe << endl;
	cout << "Average # of Quadratic Probes: " << averageQuadProbe << endl;

}