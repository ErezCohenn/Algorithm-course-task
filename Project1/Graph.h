#pragma once
#include<vector>
#include <iterator>
#include "AdjacentList.h"
#include "Edge.h"

using std::vector;
using std::cout;

class WeightedGraph
{
public:
	enum Colors { WHITE, GRAY, BLACK };
	int numberOfVertex;
	vector<AdjacentList*> adjListArray;

public:
	WeightedGraph(int amountOfVertexes = 0)
	{
		makeEmptyGraph(amountOfVertexes);
	}
	void makeEmptyGraph(int n);
	bool isAdjacent(int u, int v);
	void addEdge(int u, int v, int c);
	AdjacentList* getAdjList(int u) const;
	void removeEdge(int u, int v);
	vector<Edge*> getEdgesArr()const;
	Edge* getEdge(int u, int v) const;
	int getGraphSize() const { return numberOfVertex; }
	void visit(int u, vector<Colors>& color) const;
	bool isGraphLinked() const;
	~WeightedGraph();
};

