#include "MST_algorithms.h"
#include "QuickSort.h"
using std::pair;


int* MST_algorithms::Prim(WeightedGraph& graph)
{
	int* parent = new int(graph.getGraphSize());
	pair<int, int>* minWeight = new pair<int, int>[graph.getGraphSize()]; // first = index of vertex in queue, second = minWeight
	bool* vertexInMst = new bool(graph.getGraphSize());
	MinHeap priority_queue;

	if (graph.getGraphSize() <= 0)
	{
		return nullptr;
	}

	minWeight[0].first = 0; // vertex 1 is the first vertex to start the algorithm
	minWeight[0].second = 0;

	parent[0] = -1; // vertex 1 has no parent

	for (int i = 1; i < graph.getGraphSize(); i++)
	{
		minWeight[i].first = i;
		minWeight[i].second = INT32_MAX; // minWeight initialize to infinity
		parent[i] = -1;
	}

	int* temp = new int(graph.getGraphSize());

	for (int i = 0; i < graph.getGraphSize(); i++)
	{
		temp[i] = minWeight[i].second;
	}

	priority_queue.Build(temp, graph.getGraphSize());

	while (!priority_queue.isEmpty())
	{
		Pair minVertex = priority_queue.DeleteMin();
		vertexInMst[minVertex.data - 1] = true;

		AdjacentList* adjVertex = graph.getAdjList(minVertex.data - 1);
		Edge* adjEdge = adjVertex->getHead();

		while (adjEdge != nullptr)
		{
			if (!vertexInMst[adjEdge->vertex - 1] && adjEdge->edgeWeight < minWeight[adjEdge->vertex - 1])
			{
				minWeight[adjEdge->vertex - 1] = adjEdge->edgeWeight;
				parent[adjEdge->vertex - 1] = minVertex.data;
				priority_queue.DecreaseKey(adjEdge->vertex - 1, minWeight[adjEdge->vertex - 1]); // the index of v is need to update: îöáéò äããé?
			}
		}
	}

	return parent;
}









































Edge* MST_algorithms::Kruskal(WeightedGraph& graph)
{
	int srcRepresentive, destRepresentive;
	vector<Edge*> forest;
	DisjointSets UnionFind;
	vector<Edge*> graphEdgesArray;

	graphEdgesArray = graph.getEdgesArr();
	QuickSort::quickSort(graphEdgesArray, 0, graphEdgesArray.size() - 1);

	for (int i = 1; i <= graph.getGraphSize(); i++)
	{
		UnionFind.MakeSet(i);
	}

	for (int i = 0; i < graphEdgesArray.size(); i++)
	{
		srcRepresentive = UnionFind.Find(graphEdgesArray[i]->vertex); // finds u representive
		destRepresentive = UnionFind.Find(graphEdgesArray[i]->twin->vertex); // finds v representive
		if (srcRepresentive != destRepresentive)
		{
			forest.push_back(graphEdgesArray[i]);
			UnionFind.Union(srcRepresentive, destRepresentive);
		}
	}

}
