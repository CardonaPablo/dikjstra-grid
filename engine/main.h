#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include<bits/stdc++.h>

#include "Graph.h"
#include "utils.h"

using namespace std;

vector<int> dijkstra(Graph, int, int);
void updateMinimumLength(Graph, vector<int>&, vector<int>, vector<int>&, int);
vector<int> simplifyPath(vector<pair<int, int>>, int, int);
pair<int,int> addPath(Graph, vector<int>, int);
string createPath(int, vector<int>, int, int);

// vector<int> createPath(int dimension, int barriers_[], int initial, int final) {
string createPath(int dimension, vector<int> barriers, int initial, int final) {

	std::cout << "Barriers" << endl;
	printVector(barriers);

	Graph graph(dimension, barriers); 
	// graph.drawGraph();

	vector<int> result = dijkstra(graph, initial, final);
	string path = "";
	// Recorrer vector y concatenar
	for (auto i = result.begin(); i != result.end(); ++i) 
		path += to_string(*i) + "," ;

	path.pop_back();
	return path;
}

vector<int> dijkstra(Graph graph, int initial, int final) {

	const int dim = graph.getDimension();
	vector<int> visited{initial};
	vector<pair<int, int>> paths;
	vector<int> potentialJumps;
	vector<int> minLengths(dim, dim*dim);
	int currentNode = initial;

	// visited.reserve(dim);
	// potentialJumps.reserve(dim); 
	// paths.reserve(dim*2);

	minLengths.at(initial -1) = 0;
	while(currentNode != final) {
		updateMinimumLength(graph, minLengths, visited, potentialJumps, currentNode);
		if(potentialJumps.empty()) {
			cout << "No path" << endl;
			break;
		}

		int index = findIndexOfLowest(minLengths, potentialJumps, final);
		currentNode = index + 1;

		pair<int, int> path = addPath(graph, visited, currentNode);
		paths.push_back(path);
		visited.push_back(currentNode);

		// Remove the visited node from the potential jumps	
		remove(potentialJumps.begin(), potentialJumps.end(), currentNode);
	}
	return simplifyPath(paths, initial, final);
}

pair<int,int> addPath(Graph graph, vector<int> visited, int target) {
	for (auto i = visited.rbegin(); i != visited.rend(); ++i) {
		vector<int> directJumps = graph.getDirectJumps(*i);
		if(existsInVector(directJumps,target))
			return pair<int,int>(*i, target);
	}
	return pair<int,int>(NULL, target);
}

void updateMinimumLength(
	Graph graph,
	vector<int>& minLengths,
	vector<int> visited,
	vector<int>& potentialJumps,
	int node 
) {
	int currentNodeLength = minLengths.at(node - 1); 
	vector<int> directJumps = graph.getDirectJumps(node);
	for (auto i = directJumps.begin(); i != directJumps.end(); ++i) {
		if(existsInVector(visited, *i)) continue;
		int jumpIndex = *i - 1;
		int newMinLength = currentNodeLength + 1;
		if(!existsInVector(potentialJumps, *i)) {
			// If not exists in the potential jumps
			minLengths.at(jumpIndex) = newMinLength;
			potentialJumps.push_back(*i);
			continue;
		};
		// If exists, only replace if its lower
		int jumpMinLength = minLengths.at(jumpIndex);
		if(newMinLength < jumpMinLength)
			minLengths.at(jumpIndex) = newMinLength;
	}
}

vector<int> simplifyPath(vector<pair<int, int>> paths, int initial, int final) {
	vector<int> finalPath;
	// finalPath.reserve(paths.size());
	if(paths.empty())
		return vector<int>{initial};
	pair<int, int> currentPath = paths.at(paths.size()-1);
	while(currentPath.first != initial) {
		finalPath.push_back(currentPath.second);
		// Find next path
		for (auto i = paths.begin(); i != paths.end(); i++) {
			pair<int, int> p = *i;
			if(p.second == currentPath.first) {
				currentPath = p;
				break;
			}
		}
	}

	finalPath.push_back(currentPath.second);
	finalPath.push_back(currentPath.first);

	reverse(finalPath.begin(), finalPath.end());

	cout << "Final path:" << endl;
	printVector(finalPath);
	return finalPath;
}

#endif