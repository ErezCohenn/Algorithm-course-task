#include "MST_algorithms.h"
#include "Graph.h"
#include "Edge.h"
#include "main_functions.h"
#include <iostream>

using namespace std;

void main(int argc, char* argv[])
{
	WeightedGraph graph;
	Edge* edteToDelete = nullptr;
	
	makeGraphFromFileInput(argc, argv, graph, edteToDelete);

	graph.printGraph();

	MST_algorithms test;

	int res = test.Prim(graph);

	cout << "Prim:" << res;
}