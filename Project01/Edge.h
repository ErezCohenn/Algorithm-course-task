# pragma once

struct Edge
{
	int vertex;
	int edgeWeight = 0;
	Edge* prev = nullptr;
	Edge* next = nullptr;
	Edge* twin = nullptr;
};