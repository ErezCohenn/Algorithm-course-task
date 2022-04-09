#pragma 
#include<iostream>
using namespace std;

struct Edge
{
	int vertex;
	int edgeWeight = 0;
	Edge* prev = nullptr;
	Edge* next = nullptr;
	Edge* twin = nullptr;
};

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

