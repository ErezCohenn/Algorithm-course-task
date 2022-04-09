#pragma once
#include <iostream>
#include <vector>
#include "Element.h"

using std::vector;
using std::endl;
using std::cout;

class DisjointSets
{
	Element* tree;
	int treeSize;
	int maxSize;
	bool allocated;

public:
	DisjointSets();
	void CreateEmpty(int max);
	void MakeSset(int newRepresentative);
	int Find(int element);
	void Union(int representativeSetx, int representativeSety);
	void print() //need to be deleted for submission
	{
		for (int i = 0; i < treeSize; i++)
		{
			cout << "node: " << i << " parent: " << tree[i].parent << " size: " << tree[i].size << endl;
		}
		cout << "finished" << endl;
	}
};

