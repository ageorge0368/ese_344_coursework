#include <iostream>

using namespace std;

class HashTable {
private:
	int hashTable[8191];
	int numberOfProbes;

public:
	// Constructor
	HashTable()  {
		for (int i = 0; i < 8191; i++) {
			hashTable[i] = -1;
		}

		numberOfProbes = 0;
	}

	// Getter
	int* getHashTable() {				// Getter for array (Hash Table)
		return hashTable;
	}

	// Other Functions
	void linearProbing(int inputVal) {
		int key = (inputVal * 17) % 8191;
		int i = 1;								// Collision number
		
		while (hashTable[key] != -1) {			// while hashTable[key] is used
			key = (key + i) % 8191;
			numberOfProbes++;
		}

		hashTable[key] = inputVal;
	}

	void quadraticProbing(int inputVal) {
		int key = (inputVal * 17) % 8191;
		int i = 1;								// Collision number

		while (hashTable[key] != -1) {			// while hashTable[key] is used
			key = (key + (i*i)) % 8191;
			i++;
			numberOfProbes++;
		}

		hashTable[key] = inputVal;
	}

	int numOfProbes() {
		return numberOfProbes;
	}

};