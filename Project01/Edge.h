#pragma once
#include <string>
using std::string;
struct Edge
{
	string vertexColor = "White";
	bool visted = false;
	int vertex;
	int edgeWeight = 0;
	Edge* prev = nullptr;
	Edge* next = nullptr;
	Edge* twin = nullptr;
};
