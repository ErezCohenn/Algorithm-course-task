#pragma once
#include <iostream>
#include <vector>
#include "ForestOfGroups.h"

using std::vector;
using std::endl;
using std::cout;

class DisjointSets
{
	Node* Node;
	int treeSize;
	int maxSize;
	bool allocated;

public:
	DisjointSets();
	void CreateEmpty(int max);
	void MakeSet(int newRepresentative);
	int Find(int Node);
	void Union(int representativeSetx, int representativeSety);
	~DisjointSets();
	void print() //need to be deleted for submission
	{
		for (int i = 0; i < treeSize; i++)
		{
			cout << "node: " << i << " parent: " << tree[i].parent << " size: " << tree[i].size << endl;
		}
		cout << "finished" << endl;
	}
};

