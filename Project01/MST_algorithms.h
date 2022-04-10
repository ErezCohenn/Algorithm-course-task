#pragma once
#include "Graph.h"
#include "MinHeap.h"
#include "DisjointSets.h"
#include <vector>

using std::vector;

class MST_algorithms
{
public:
	int Prim(const WeightedGraph& graph);
	void initializePrim(int minWeight[], int parent[], bool vertexInMst[], int size);
	int countMSTWeight(int EdgeWeights[], int size);

};

