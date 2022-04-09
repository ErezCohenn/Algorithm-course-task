#pragma once
#include <iostream>
#include<vector>
#include <iterator>
#include "AdjacentList.h"

using namespace std;
// Data structure to store adjacency list nodes


class WeightedGraph
{

	int numberOfVertex;
	vector<AdjacentList*> adjListArray;
	void MakeEmptyGraph(int n);
public:
	WeightedGraph(int n) :numberOfVertex(n)
	{
		MakeEmptyGraph(numberOfVertex);
	}
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int c);
	AdjacentList* GetAdjList(int u);
	void RemoveEdge(int u, int v);
	void printGraph();
	// Destructor
	~WeightedGraph() {
		for (int i = 0; i < numberOfVertex; i++) {
			delete[] adjListArray[i];
		}
	}
};

