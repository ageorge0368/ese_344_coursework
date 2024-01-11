//#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////// Convert side from a double to an int! ///////////////////////////////////////////////////////////////

class Square
{
public:
	// Constructor //
	explicit Square(int s = 0) : side{ s }
	{ }
	
	// Getters //
	int getSide() const
		{ return side; }
	int getArea() const
		{ return side * side; }
	int getPerimeter() const
		{ return 4 * side; }
	
	// Setters //
	void setSide(int s) 
	{ side = s; }

	// Other functions //
	void print(ostream & out = cout) const
		{ out << "(square " << getSide() << ")"; }
	bool operator< (const Square & rhs) const
		{ return getSide() < rhs.getSide(); }

	// If needed!

	bool operator== (const Square& rhs) const {
//		bool exists = false;
		return (this->getSide() == rhs.getSide());
	}
	
private:
	// Data Fields //
	int side;
};

// Define an output operator for Square
ostream & operator<< (ostream & out, const Square & rhs)
{
	rhs.print(out);
	return out;
}

/**
* Return the maximum item in array a.
* Assumes a.size( ) > 0.
* Comparable objects must provide operator< and operator=
*/
template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a)
{
	int maxIndex = 0;

	for (int i = 1; i < a.size(); ++i)
		if (a[maxIndex] < a[i])
			maxIndex = i;

	return a[maxIndex];
}

//int main()
//{
//	vector<Square> v = { Square{ 3 }, Square{ 2 }, Square{ 5/2 } };
//	
//	cout << "Largest square: " << findMax(v) << endl;
//	
////	cout << v.at(2).getArea() << endl;
//
//	return 0;
//}

#endif