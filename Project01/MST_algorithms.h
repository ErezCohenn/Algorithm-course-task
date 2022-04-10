#pragma once
#include "Graph.h"
#include "MinHeap.h"
#include "DisjointSets.h"
#include <vector>
#include "Edge.h"

using std::vector;

class MST_algorithms
{
public:
	int* Prim(WeightedGraph& graph);

	Edge* Kruskal(WeightedGraph& graph);

};

