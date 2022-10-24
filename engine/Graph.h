#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

class Graph {
private:
	vector<vector<int>> data;
	int dimension;

public:
	Graph(int gridDimension, vector<int> barriers) {
		// Create a multidimensional array filled with the ids
		dimension = gridDimension*gridDimension;
		for (int i = 1; i <= dimension; i++) {
			vector<int> buffer;
			// Check for barriers
			bool foundI = existsInVector(barriers, i);
			if(foundI)
				buffer = vector<int>(dimension, 0);
			else
			for (int j = 1; j <= dimension; j++)
			{
				bool found = existsInVector(barriers, j);
				if(found)
					buffer.push_back(0);
				// We should put a 1 when j is one of:
				else if(
				// - j is i - 1: The left cell
				// 	Except when j is al multiple of dimension (j%dimension is 0) 
					(j == i-1 && j%gridDimension) ||
				// - j is i + 1: the right cell
				// 	Except when i is al multiple of dimension (i%dimension is 0) 
					(j == i+1 && i%gridDimension) ||
				// - j is i + dimension: Lower cell
					(j == i+gridDimension) ||
				// - j is i - dimension: Upper cell
					(j == i-gridDimension)
				)
					buffer.push_back(1);
				else 
					buffer.push_back(0);
			}
			data.push_back(buffer);
		}
	}
	
	int getDimension() { return dimension; }

	void drawGraph() {
		for (int i = 0; i < dimension; i++)
		{
			if(i == 0) {
				cout << " ";
				for (int k = 0; k < dimension; k++)
					cout << " " << k+1;
				cout << endl;
			}

			cout << i+1 << " ";
			vector<int> buffer = data.at(i);
			for (int j = 0; j < dimension; j++)
			{
				cout << buffer.at(j) << " ";
			}
			cout << endl;
		}
		
	}

	vector<int> getDirectJumps(int node) {
		vector<int> jumps = data.at(node -1);
		vector<int> onlyAvailable;
		for (int i = 0; i < jumps.size(); i++) 
			if(jumps.at(i) > 0) onlyAvailable.push_back(i + 1);
		return onlyAvailable;
	}

};

#endif