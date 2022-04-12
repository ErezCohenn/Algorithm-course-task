#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

using std::vector;
using std::endl;
using std::cout;

class DisjointSets
{
	vector<Node> forest;
	int maxSize;
	bool allocated;

public:
	DisjointSets();
	void CreateEmpty(int max);
	void MakeSet(int newRepresentative);
	int Find(int element);
	void Union(int representativeSetx, int representativeSety);	
};

