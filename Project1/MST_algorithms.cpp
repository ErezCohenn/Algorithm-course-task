#include "MST_algorithms.h"

int MST_algorithms::Prim(const WeightedGraph& graph)
{

	int* parent = new int[graph.getGraphSize()];
	int* minWeight = new int[graph.getGraphSize()];
	bool* vertexInMst = new bool[graph.getGraphSize()];
	int totalWeight;

	MinHeap priority_queue;

	if (graph.getGraphSize() <= 0)
	{
		throw "invalid input";
	}

	initializePrim(minWeight, parent, vertexInMst, graph.getGraphSize());

	priority_queue.Build(minWeight, graph.getGraphSize());

	while (!priority_queue.isEmpty())
	{
		Pair minVertex = priority_queue.DeleteMin();
		vertexInMst[minVertex.data - 1] = true;

		AdjacentList* adjVertex = graph.getAdjList(minVertex.data);
		Edge* adjacentEdge = adjVertex->getHead();

		while (adjacentEdge != nullptr)
		{
			if (!vertexInMst[adjacentEdge->vertex - 1] && adjacentEdge->edgeWeight < minWeight[adjacentEdge->vertex - 1])
			{
				minWeight[adjacentEdge->vertex - 1] = adjacentEdge->edgeWeight;
				parent[adjacentEdge->vertex - 1] = minVertex.data;
				priority_queue.DecreaseKey(priority_queue.getIndex(adjacentEdge->vertex - 1), minWeight[adjacentEdge->vertex - 1]);
			}

			adjacentEdge = adjacentEdge->next;
		}
	}

	totalWeight = countMSTWeight(minWeight, graph.getGraphSize());

	delete[] parent;
	delete[] minWeight;
	delete[] vertexInMst;

	parent = nullptr;
	minWeight = nullptr;
	vertexInMst = nullptr;

	return totalWeight;


}

void MST_algorithms::initializePrim(int minWeight[], int parent[], bool vertexInMst[], int size)
{
	int straterVertex = rand() % size; // the first vertex to start the algorithm (V0)

	for (int i = 0; i < size; i++)
	{
		if (i == straterVertex)
		{
			minWeight[straterVertex] = 0;
		}
		else // minWeight initialize to infinity
		{
			minWeight[i] = INT32_MAX;
		}

		parent[i] = -1; // if parent[i] == -1 then i has no parent (nil)
		vertexInMst[i] = false;
	}
}

int MST_algorithms::countMSTWeight(int EdgeWeights[], int size)
{
	int totalWeight;

	if (size < 1)
	{
		throw "invalid input";
	}

	totalWeight = EdgeWeights[0];

	for (int i = 1; i < size; i++)
	{
		totalWeight += EdgeWeights[i];
	}

	return totalWeight;
}

bool MST_algorithms::isEdgeInMst(Edge* edgeToRemove, vector<Edge*>& Mst)
{
	for (int i = 0; i < Mst.size(); i++)
	{
		if (Mst[i]->vertex == edgeToRemove->vertex && Mst[i]->twin->vertex == edgeToRemove->twin->vertex)
		{
			return true;
		}
		else if (Mst[i]->vertex == edgeToRemove->twin->vertex && Mst[i]->twin->vertex == edgeToRemove->vertex)
		{
			return true;
		}
	}

	return false;
}

int MST_algorithms::Kruskal(const WeightedGraph& graph, vector<Edge*>& graphEdgesArray, vector<Edge*>& Mst)
{
	int srcRepresentive, destRepresentive;
	DisjointSets UnionFind;
	int weight = 0;

	UnionFind.CreateEmpty(graph.getGraphSize());


	for (int i = 0; i < graph.getGraphSize(); i++)
	{
		UnionFind.MakeSet(i);
	}

	for (int i = 0; i < graphEdgesArray.size(); i++)
	{
		srcRepresentive = UnionFind.Find(graphEdgesArray[i]->vertex - 1); // finds u representive
		destRepresentive = UnionFind.Find(graphEdgesArray[i]->twin->vertex - 1); // finds v representive
		if (srcRepresentive != destRepresentive)
		{
			Mst.push_back(graphEdgesArray[i]);
			UnionFind.Union(srcRepresentive, destRepresentive);
		}
	}
	for (int i = 0; i < Mst.size(); i++)
	{
		weight += Mst[i]->edgeWeight;
	}

	return weight;
}
