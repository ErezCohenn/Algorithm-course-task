#pragma once
#include<iostream>
#include "Edge.h"

class AdjacentList
{
	int listSize;
	Edge* head = nullptr;
	Edge* tail = nullptr;
public:
	Edge* getHead() const { return head; }
	Edge* getTail() const { return tail; }
	AdjacentList() { makeEmptyList(); }
	void makeEmptyList();
	Edge* createNewEdge(Edge* next, Edge* prev, int weight, int vertex);
	Edge* insertEdgeToTail(int weight, int vertex);
	bool isEmptyList(AdjacentList lst);
	void deleteAfter(Edge* toDelete);
	AdjacentList(const AdjacentList& h) = delete;
	AdjacentList& operator=(const AdjacentList& h) = delete;
	~AdjacentList();
};

