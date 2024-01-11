#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for sqrt()

#include <vector>
#include <fstream>

#include "List.h"
#include "Edge.h"

using namespace std;

void depthFirstTraversal (int visited_node, vector<bool>& vis, const vector<List<Edge>>& g) {
	// visited_node => visited node
	// vis => visited vector
	// g => graph in adjacency list form

	vis[visited_node] = true;
	
	//cout << "Visited vertex : " << v << endl;
	cout << "   " << visited_node;								// "visit" function

	for (auto& w : g[visited_node]) {
		if (!vis[w.tv])
			depthFirstTraversal(w.tv, vis, g);
	}
}

void breadthFirstTraversal(int visited_node, vector<bool>& vis, const vector<List<Edge>>& g) {
	// visited_node => visited node
	// vis => visited vector
	// g => graph in adjacency list form

	Queue<int> q;

	int frontOfQueue; 

//	visited_node--;

	cout << "    " << visited_node;

	for (int i = 0; i < vis.size(); i++) {				// Clearing visited vector (making them all false initially)
		vis[i] = false;
	}

	for (auto& v: g[visited_node]) {
		if (!vis[v.tv]) {
			q.enqueue(v.tv);

			while (!q.queueEmpty()) {
				frontOfQueue = q.dequeue();

				if (!vis[frontOfQueue]) {
					vis[frontOfQueue] = true;
					cout << "   " << frontOfQueue;
//					q.dequeue();

					for (auto& x : g[frontOfQueue]) {
						if (!vis[x.tv]) {
//							vis[x.tv] = true;
							q.enqueue(x.tv);
						}
					}
				}

			}
		}
	}


}

//void distanceSettingDFT(int source, vector<int> distance, vector<bool>& vis, vector<List<Edge>>& g) {
//	vis[source] = false;
//	
//
//	for (auto& v : g[source]) {
//		if (!vis[v.tv])
//			depthFirstTraversal(v.tv, vis, g);
//	}
//}

void elementErase(vector<int>& tempVect, int element) {
	for (int i = 0; i < tempVect.size(); i++) {
		if (tempVect.at(i) == element) {
			tempVect.erase(tempVect.begin() + i);
		}
	}
}

void shortestPaths(int source, vector<int>& distance, vector<bool>& vis, const vector<List<Edge>>& g) {
	// distance vector => weight aspect of an edge 
//	Edge v, w;
	int count;

	count = vis.size();						// count => number of vertices in a graph

	for (int i = 0; i < vis.size(); i++) {				// Clearing visited vector (making them all false initially)
		vis[i] = false;
	}

//	List<Edge> tempList;
//	Edge temp;
//	for (v = 0; v < count; v++) {
//		vis[v] = false;
////		distance[v] = g.at(source).
////		tempList 
//			
//		distance[v] = g.at(source).iterateUpTo(v)->data.weight;
//
////		iterateUpTo(tempList, v);
////			iterateUpTo(v)->data.weight;
//	}

	for (auto& v : g[source]) {				// v represents a node in a list<edge>
		vis[v.tv] = false;					// edges from the source
		distance[v.tv] = v.weight;
	}

	vector<int> L;
	for (int i = 0; i < count; i++) {
		L.push_back(i);
	}


	vis[source] = true;
//	foundVector.push_back(source);			// found vector pushed back
	elementErase(L, source);	// erase vertex from notFoundVector if the element is found/visited
	distance[source] = 0;

	int min;

	int v, w;

	vector<int> parent;
	for (int i = 0; i < count; i++) {
		parent.push_back(-1);
	}

	for (int i = 0; i < count; i++) {
		min = INT_MAX;
//		for (auto& w : g[source]) {
//		for (w = 0; w < count; w++) {
		for (w = 0; w < L.size(); w++) {
//			if (!vis[w]) {								// vertices not visited
				if (distance[L.at(w)] < min) {				// if distance from non-visited vertex is smaller than min
					v = L.at(w);								// if yes, then v = w
					min = distance[L.at(w)];					// and min = distance[w]
//					cout << "Shortest path from vertex " << i << " to " << w << ": " << min << endl;
				}
//			}
		}

		cout << "\nShortest path from each vertex: " << endl;
		for (int j = 0; j < count; j++) {
			if (distance[j] == INT_MAX) {
				cout << j << ": d = infinity (No path from vertex " << j << " to another vertex exists!)" << endl;
			}
			else {
				cout << j << ": d = " << distance[j] << endl;
			}
		}

		vis[v] = true;
//		foundVector.push_back(v);
		elementErase(L, v);

		if (vis[v] == true && distance[v] == min) {
			cout << "Shortest path selected: d = " << distance[v] << " with path from vertex " << source << " to vertex " << v << endl;
		}



//		for (auto& w : g[v.tv]) {
//		for (w = 0; w < count; w++) {
		for (w = 0; w < L.size(); w++) {
//			if (!vis[w]) {
				Edge w_edge;

				for (auto& temp : g[v]) {
					if (temp.tv == L.at(w)) {
						w_edge = temp;
					}
				}

				if (min + w_edge.weight < distance[L.at(w)]) {
					distance[L.at(w)] = min + w_edge.weight;
					parent[w] = v;
				}
			}
//		}
	}

	int k;
	for (int x = 0; x < count; x++) {
		cout << distance[x] << endl;
		cout << x << " ";
		k = x;
		while ((k != source) && (k != -1)) {
			cout << parent[k] << " ";
			k = parent[k];
		};
		if (k == -1) {
			cout << "There is no path from" << v << " to " << source << endl;
			cout << endl;
		}
	}

//	int minimum = INT_MAX;
	//cout << "\nShortest path from each vertex: " << endl;
	//for (int i = 0; i < count; i++) {
	//	int minimum = INT_MAX;
	//	for (auto& temp_2 : g[i]) {
	//		if (temp_2.weight < minimum) {
	//			minimum = temp_2.weight;
	//		}
	//	}
	//	if (minimum == INT_MAX) {
	//		cout << i << ": d = infinity (No path from vertex " << i << " to another vertex exists!)" << endl;
	//	}
	//	else {
	//		cout << i << ": d = " << minimum << endl;
	//	}
	//	
	//}
	//for (int i = 0; i < count; i++) {
	//	min = INT_MAX;
	//	for (w = 0; w < count; w++) {
	//		if (!vis[w]) {
	//			if (distance[w] < min) {
	//				v = w;
	//				min = distance[w];
	//			}
	//		}
	//	}
	//	vis[v] = true;
	//	for (w = 0; w < count; w++) {
	//		if (!vis[w]) {
	//			//if (min + g.at(v).iterateUpTo(w)->data.weight < distance[w]) {
	//			//	distance[w] = min + min + g.at(v).iterateUpTo(w)->data.weight;
	//			//}
	//		}
	//	}
	//}
}

int main() {
	
	//////////////////////////////////////////// READING FILE ////////////////////////////////////////

	fstream inputFile;
	inputFile.open("input3-v2.txt");		// open file
	if (!inputFile) {
		cerr << "No file exists!" << endl;
	}


	int nv = 0;					// number of vertices
	int ne = 0;					// number of edges
	
	inputFile >> nv >> ne;		// inputs, sssuming that they have no errors
	
	cout  << "Input:  nv = " << nv << " , ne =  " << ne  << endl;

    if((nv < 0) || (nv > 10000) || (ne < 0) || (ne > 10000)) {
		cerr << "Input values out of range." << endl;
		exit(1);
	}

	vector<List<Edge>> g2(nv);		 //graph
	int cv1 = 0, cv2 = 0;			 // Edge from current vertex cv1 to cv2
	double wt = 0.0;				 // weight

	for(int ne1 = 0; ne1 < ne; ne1++)
	{
		inputFile >> cv1 >> cv2 >> wt;	// input; assume no error in input.
		if ((cv1 < 0) || (cv1 > nv) || (cv2 < 0) || (cv2 > nv) || (wt<0) || (wt >10000.0)) {
			cerr << "Input values out of range." << endl;
			exit(1);
		}
		Edge nsq(cv1, cv2, wt);
		g2[cv1].push_back(nsq);
	}

	cout << endl << "Graph " << endl;
	for (int i = 0; i < nv; i++) {
		cout << i << " : ";
		g2[i].printList();
	//	cout << endl;
	}


	vector<bool> visited(nv, false);
	cout <<endl<< "Depth First traversal " << endl<< "Order of vertices visited : " ;
	for (int v = 0; v < nv; v++) {
		if (!visited[v])
			depthFirstTraversal(v, visited, g2);
	}
	cout << endl;

	cout << endl << "Breadth First traversal " << endl << "Order of vertices visited : ";
	breadthFirstTraversal(0, visited, g2);

	//for (int i = 0; i < nv; i++) {
	////	cout << i << " : Cleared ";
	//	g2[i].clear();
	//	cout << endl;
	//}

	cout << "\n\n\nShortest Path Algorithm: " << endl;
	int source = 0;
	vector<int> distances;

	for (int i = 0; i < nv; i++) {
		distances.push_back(INT_MAX);
	}

	shortestPaths(0, distances, visited, g2);
	cout << "\nSource: 0" << endl;
	cout << "Shortest distances of source to each other vertex: " << endl;
	cout << endl;
	for (int i = 0; i < nv; i++) {
		if (i == source) {
			continue;
		}

		cout << i << ": d = " << distances[i] << endl;
	}

	return 0;
}
