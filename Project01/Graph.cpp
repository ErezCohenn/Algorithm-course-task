#include "Graph.h"
#include <stdlib.h>

bool WeightedGraph::isAdjacent(int u, int v)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "Invalid input";
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

void WeightedGraph::addEdge(int u, int v, int c)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "Invalid input";
		exit(1);
	}

	if (!isAdjacent(u, v))
	{
		Edge* firstTwin = adjListArray[u - 1]->insertEdgeToTail(c, v);
		Edge* secondTwin = adjListArray[v - 1]->insertEdgeToTail(c, u);
		firstTwin->twin = secondTwin;
		secondTwin->twin = firstTwin;
	}
}

 AdjacentList* WeightedGraph::getAdjList(int u) const
{
	if (u > numberOfVertex || u <= 0)
	{
		cout << "Invalid input";
		exit(1);
	}
	return adjListArray[u - 1];
}

void WeightedGraph::removeEdge(int u, int v)
{
	if (u > numberOfVertex || v > numberOfVertex || u <= 0 || v <= 0)
	{
		cout << "Invalid input";
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

Edge* WeightedGraph::getEdge(int u, int v) const
{
	Edge* currentEdge = adjListArray[u - 1]->getHead();

	while (currentEdge != nullptr)
	{
		if (currentEdge->vertex == v)
		{
			return currentEdge;
		}
		currentEdge = currentEdge->next;
	}
	return nullptr;
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
				currentEdge->twin->visted = true;
				edgesArr.push_back(currentEdge);
			}

			currentEdge = currentEdge->next;
		}
	}

	for (int i = 0; i < numberOfVertex; i++)
	{
		currentEdge = adjListArray[i]->getHead();
		while (currentEdge != nullptr)
		{
			currentEdge->visted = false;
			currentEdge = currentEdge->next;
		}
	}
	return edgesArr;
}

void WeightedGraph::makeEmptyGraph(int n)
{
	adjListArray.clear();

	for (int i = 0; i < n; i++)
	{
		adjListArray.push_back(new AdjacentList);
	}

	numberOfVertex = n;
}

WeightedGraph::~WeightedGraph()
{
	for (int i = 0; i < numberOfVertex; i++)
	{
		delete adjListArray[i];
	}
}

void WeightedGraph::visit(int u, vector<Colors>& color) const
{
	Edge* root = adjListArray[u]->getHead();
	color[u] = GRAY;
	while (root != nullptr)
	{
		if ((root != nullptr) && color[root->vertex - 1] == WHITE)
		{
			visit(root->vertex - 1, color);
		}
		root = root->next;
	}
	color[u] = BLACK;
}

bool WeightedGraph::isGraphLinked() const
{
	vector<Colors> color;
	for (int i = 0; i < numberOfVertex; i++)
	{
		color.push_back(WHITE);
	}

	visit(0, color);

	for (int i = 0; i < numberOfVertex; i++)
	{
		if (color[i] != BLACK)
			return false;
	}
	return true;
}