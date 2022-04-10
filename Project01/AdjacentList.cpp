#include "AdjacentList.h"
void AdjacentList::makeEmptyList()
{
	head = tail = nullptr;
	listSize = 0;
}


Edge* AdjacentList::createNewEdge(Edge* next, Edge* prev, int weight, int vertex)
{
	Edge* newEdge;

	newEdge = new(Edge);
	newEdge->next = next;
	newEdge->prev = prev;
	newEdge->edgeWeight = weight;
	newEdge->vertex = vertex;

	return newEdge;
}

Edge* AdjacentList::insertEdgeToTail(int weight, int vertex)
{
	Edge* newTail = createNewEdge(nullptr, nullptr, weight, vertex);

	if (head == nullptr && tail == nullptr)
	{
		head = tail = newTail;
	}
	else
	{
		tail->next = newTail;
		newTail->prev = tail;
		tail = newTail;

	}
	listSize++;
	return newTail;
}

bool AdjacentList::isEmptyList(AdjacentList lst)
{
	return (head == nullptr);
}

void AdjacentList::deleteAfter(Edge* toDelete)
{
	if (head == toDelete && tail == toDelete)
	{
		head = tail = nullptr;
	}
	else if (head == toDelete)
	{
		head = toDelete->next;
		head->prev = nullptr;
	}
	else if (tail == toDelete)
	{
		tail = toDelete->prev;
		tail->next = nullptr;
	}
	else
	{
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
	}
	listSize--;
	delete[] toDelete;
}
