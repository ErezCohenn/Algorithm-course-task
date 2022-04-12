#include "MST_algorithms.h"

int MST_algorithms::Prim(const WeightedGraph& graph)
{
	int* parent = new int(graph.getGraphSize());
	int* minWeight = new int(graph.getGraphSize());
	bool* vertexInMst = new bool(graph.getGraphSize());
	MinHeap priority_queue;

	if (graph.getGraphSize() <= 0)
	{
		cout << "The graph is empty!";
		exit(1);
	}

	initializePrim(minWeight, parent, vertexInMst, graph.getGraphSize());

	priority_queue.Build(minWeight, graph.getGraphSize());

	while (!priority_queue.isEmpty())
	{
		Pair minVertex = priority_queue.DeleteMin();
		vertexInMst[minVertex.data - 1] = true;

		AdjacentList adjVertex = graph.getAdjList(minVertex.data - 1);
		Edge* adjEdge = adjVertex.getHead();

		while (adjEdge != nullptr)
		{
			if (!vertexInMst[adjEdge->vertex - 1] && adjEdge->edgeWeight < minWeight[adjEdge->vertex - 1])
			{
				minWeight[adjEdge->vertex - 1] = adjEdge->edgeWeight;
				parent[adjEdge->vertex - 1] = minVertex.data;
				priority_queue.DecreaseKey(priority_queue.getIndex(adjEdge->vertex - 1), minWeight[adjEdge->vertex - 1]);
			}

			adjEdge = adjEdge->next;
		}
	}

	return countMSTWeight(minWeight, graph.getGraphSize());


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
		cout << "wrong input";
		exit(1);
	}

	totalWeight = EdgeWeights[0];

	for (int i = 1; i < size; i++)
	{
		totalWeight += EdgeWeights[i];
	}

	return totalWeight;
}

int MST_algorithms::Kruskal(WeightedGraph& graph)
{
	int srcRepresentive, destRepresentive;
	vector<Edge*> forest;
	DisjointSets UnionFind;
	vector<Edge*> graphEdgesArray;
	int weight = 0;
	UnionFind.CreateEmpty(graph.getGraphSize());
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
	for (int i = 0; i < forest.size(); i++)
	{
		weight += forest[i]->edgeWeight;
	}


	return weight;
}

void MST_algorithms::Visit(int u, WeightedGraph& graph, vector<string>& color)
{
	Edge* root = graph.getAdjList(u).getHead();
	color[u] = "Gray";
	while (root != nullptr)
	{
		if ((root != nullptr) && color[root->vertex - 1] == "White")
		{
			Visit(root->vertex - 1, graph, color);
		}
		root = root->next;
	}
	color[u] = "Black";
}

bool MST_algorithms::isGraphLinked(WeightedGraph& graph)
{
	vector<string> color;
	for (int i = 0; i < graph.getGraphSize(); i++)
	{
		color.push_back("White");
	}


	Visit(0, graph, color);

	for (int i = 0; i < graph.getGraphSize(); i++)
	{
		if (color[i] != "Black")
			return false;
	}
	return true;
}

void MST_algorithms::Kruskal(WeightedGraph& graph)
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
