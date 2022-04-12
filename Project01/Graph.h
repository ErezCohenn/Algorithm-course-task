#pragma once
#include <iostream>
#include<vector>
#include <iterator>
#include "AdjacentList.h"
#include "Edge.h"

using namespace std;

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
	vector<Edge*> getEdgesArr();

	Edge* getEdge(int u, int v) const;
	int getGraphSize() const { return numberOfVertex; }
	AdjacentList getAdjList(int index) const { return *(adjListArray[index]); }
	void printGraph();
	// Destructor
	~WeightedGraph();
};

