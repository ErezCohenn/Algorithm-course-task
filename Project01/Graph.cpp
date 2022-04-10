#include "Graph.h"
#include <stdlib.h>

bool WeightedGraph::IsAdjacent(int u, int v)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "invalid input";
		exit(1);
	}
	Edge* currentEdge = adjListArray[u - 1]->getHead();

	while (currentEdge != nullptr)
	{
		if (currentEdge->vertex == v)
		{
			return true;
		}
		currentEdge = currentEdge->next;
	}
	return false;
}

void WeightedGraph::AddEdge(int u, int v, int c)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "invalid input";
		exit(1);
	}
	if (!IsAdjacent(u, v))
	{
		Edge* firstTwin = adjListArray[u - 1]->insertEdgeToTail(c, v);
		Edge* secondTwin = adjListArray[v - 1]->insertEdgeToTail(c, u);
		firstTwin->twin = secondTwin;
		secondTwin->twin = firstTwin;
	}
}

AdjacentList* WeightedGraph::GetAdjList(int u)
{
	if (u > numberOfVertex || u <= 0)
	{
		cout << "invalid input";
		exit(1);
	}
	return adjListArray[u - 1];
}

void WeightedGraph::RemoveEdge(int u, int v)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "invalid input";
		exit(1);
	}
	bool edgeToDeleteFound = false;
	Edge* currentEdge = adjListArray[u - 1]->getHead();


	while (currentEdge != nullptr && edgeToDeleteFound == false)
	{
		if (currentEdge->vertex == v)
		{
			adjListArray[v - 1]->deleteAfter(currentEdge->twin);
			adjListArray[u - 1]->deleteAfter(currentEdge);
			edgeToDeleteFound = true;
		}
		else
		{
			currentEdge = currentEdge->next;
		}
	}
}

vector<Edge*> WeightedGraph::getEdgesArr()
{
	Edge* currentEdge;
	vector<Edge*> edgesArr;
	for (int i = 0; i < numberOfVertex; i++)
	{
		currentEdge = adjListArray[i]->getHead();
		while (currentEdge != nullptr)
		{
			if (currentEdge->visted == false)
			{
				currentEdge->visted = true;
				edgesArr.push_back(currentEdge);
			}
		}
	}
	return edgesArr;
}

void WeightedGraph::printGraph()
{
	for (int i = 0; i < numberOfVertex; i++)
	{
		Edge* currentEdgeInAdjList = adjListArray[i]->getHead();
		cout << "Vertex " << i + 1 << " neighbors: " << endl;
		while (currentEdgeInAdjList != nullptr)
		{

			cout << currentEdgeInAdjList->vertex << ", weight of edge: " << currentEdgeInAdjList->edgeWeight << endl;
			currentEdgeInAdjList = currentEdgeInAdjList->next;
		}
	}
}

WeightedGraph::~WeightedGraph()
{
	for (int i = 0; i < numberOfVertex; i++)
	{
		delete[] adjListArray[i];
	}
}

void WeightedGraph::MakeEmptyGraph(int n)
{
	for (int i = 0; i < n; i++)
	{
		adjListArray.push_back(new AdjacentList);
	}
}