#pragma once


struct Edge
{
	bool visted = false;
	int vertex;
	int edgeWeight = 0;
	Edge* prev = nullptr;
	Edge* next = nullptr;
	Edge* twin = nullptr;
};
