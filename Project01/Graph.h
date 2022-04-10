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
	
public:
	WeightedGraph(int n = 0)
	{
		MakeEmptyGraph(numberOfVertex);
	}

	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int c);
	AdjacentList* GetAdjList(int u);
	void RemoveEdge(int u, int v);
	Edge* getEdge(int u, int v) const;
	int getGraphSize() const { return numberOfVertex; }
	AdjacentList getAdjList(int index) const { return *(adjListArray[index]); }
	void printGraph();
	// Destructor
	~Graph() {
		for (int i = 0; i < numberOfVertex; i++) {
			delete[] adjListArray[i];
		}
	}
};

