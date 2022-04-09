#pragma 
#include<iostream>
using namespace std;
#pragma once
#include "Edge.h"

class AdjacentList
{
	int listSize;
	Edge* head;
	Edge* tail;
public:
	AdjacentList()
	{ 
		makeEmptyList();
	}

	Edge* getHead() const { return head; }
	Edge* getTail() const { return tail; }
	void makeEmptyList();
	Edge* createNewEdge(Edge* next, Edge* prev, int weight, int vertex);
	Edge* insertEdgeToTail(int weight, int vertex);
	bool isEmptyList(AdjacentList& lst) const;
	void deleteAfter(Edge* toDelete);
};

