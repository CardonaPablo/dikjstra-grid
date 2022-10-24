#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int findIndex(vector<int>, int);
// void printVector(vector<int>);
// bool existsInVector(vector<int>, int);

bool existsInVector(vector<int> vector, int target) {
	for (auto i = vector.begin(); i != vector.end(); ++i) 
		if(*i == target)
			return true;
	return false;
}

void printVector(vector<int> vector) {
	for (auto i = vector.begin(); i != vector.end(); ++i) 
		cout << *i << " ";
	cout << endl;
}

int findIndex(vector<int> v, int target) {
    auto it = find(v.begin(), v.end(), target);
	return it != v.end() ? it - v.begin() : -1;
}

int findIndexOfLowest(vector<int> minLengths, vector<int> potentialJumps, int final) {
	int minIndex = minLengths.size()-1;
	// If final is in direct jumps, check first to see
	// int finalIndex = findIndex(potentialJumps, final);
	if(existsInVector(potentialJumps, final))
		return final-1;

	for (int j = 0; j < minLengths.size(); j++) {
		bool exists = existsInVector(potentialJumps, j+1);
		if(!exists) continue;
		if(minLengths.at(j) < minLengths.at(minIndex)) {
			minIndex = j;
		}
	}
	if(minIndex == minLengths.size() -1)
		return -1;
	return minIndex;
}

#endif