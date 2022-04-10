#pragma once
#include<iostream>
#include "Edge.h"
using namespace std;

class AdjacentList
{
	int listSize;
	Edge* head;
	Edge* tail;
public:
	Edge* getHead() const { return head; }
	Edge* getTail() const { return tail; }
	AdjacentList() { makeEmptyList(); }
	void makeEmptyList();
	Edge* createNewEdge(Edge* next, Edge* prev, int weight, int vertex);
	Edge* insertEdgeToTail(int weight, int vertex);
	bool isEmptyList(AdjacentList lst);
	void deleteAfter(Edge* toDelete);
};

