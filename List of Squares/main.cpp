#include <iostream>
#include <vector>
#include <string>

#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for math functions like sqrt() etc

#include "List.h"			// importing list class
#include "Square.h"		// importing square class

using namespace std;

int main() {
	// Creating L1, L2, L3, L4
	List<Square> L1, L2, L3, L4, L5;
	vector<int> squareSides;

	while (L1.size() <= 20) {
		//////////////////////////////////////// Generating random number k /////////////////////////////
		int k = ((rand() % 100) + 1);
		squareSides.push_back(k);
		
		//////////////////////////////////// Creating a new square x with side k //////////////////////////
		Square x{ k };

		//////////////////////// Pushing x to L1 and L2 (L1 => push_front, L2 => push_back) ///////////////
		L1.push_front(x);
		L2.push_back(x);

		/////////////////////////////////////////////// Pushing to L3 ///////////////////////////////////

			// If L3 is empty (first time)
		if (L3.empty() == false) {

				// Checks if x already exists in L3 
//			if (L3.checkSquareExists(x) == true) {
//				continue;
//			}

			int p = rand() % (L3.size() + 1);

			L3.insert_between(p, x);

			////////////////////////////////////////////////// Populating L4 ////////////////////////////////
			if (L3.size() == 5) {
				L4 = L3;						// assignment operator													// need to fix this!

				L4.pop_front();
				L4.pop_back();
			}

			//////////////////////////////////////////// Creating and Populating L5 ///////////////////////////
			if (L1.size() == 5) {
				L5 = L1;						// copy constructor

				cout << "Previous Nodes from L5: " << endl;
				L5.deleteOdds();				// deleting all of the Odd nodes

				cout << "\nL5: " << endl;		// print L5
				L5.printList();

				L5.clear();						// clear L5
			}

			///////////////////////////////////////////// Printing L1, L2, L3, L4 ////////////////////////// 
			cout << "\nL1: " << endl;
			L1.printList();

			cout << "\nL2: " << endl;
			L2.printList();

			cout << "\nL3: " << endl;
			L3.printList(); 

			cout << "\nL4: " << endl;
			L4.printList();


		}
		else {
			L3.push_back(x);					// first case where L3 is empty

			continue;
		}

	}

	///////////////////////////////////// Clearing L1, L2, L3, L4 ////////////////////////////////////

	L1.clear();
	L2.clear();
	L3.clear();
	L4.clear();

	//////////////////////////////////// Printing Empty L1, L2, L3, L4 ///////////////////////////////

	cout << "\nL1: " << endl;
	L1.printList();

	cout << "\nL2: " << endl;
	L2.printList();

	cout << "\nL3: " << endl;
	L3.printList();

	cout << "\nL4: " << endl;
	L4.printList();

	return 0;
}