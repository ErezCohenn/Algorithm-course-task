#include "DisjointSets.h"

DisjointSets::DisjointSets()
{
	forest = nullptr;
	maxSize = 0;
	treeSize = 0;
	allocated = false;
}

void DisjointSets::CreateEmpty(int max)
{
	if (forest)
	{
		delete[] forest;
	}

	if (max > 0)
	{
		forest = new Node[max];
		allocated = true;
		maxSize = max;

		for (int i = 0; i < max; i++)
		{
			forest[i].parent = -1;
			forest[i].size = 0;
		}

	}

	maxSize = max;
	treeSize = 0;
}

void DisjointSets::MakeSet(int newRepresentative)
{
	if (newRepresentative > maxSize)
	{
		cout << "wrong input" << endl;
		exit(1);
	}

	forest[newRepresentative].parent = newRepresentative;
	forest[newRepresentative].size = 1;
	treeSize++;
}

int DisjointSets::Find(int element)
{
	if (element > treeSize)
	{
		cout << "wrong input";
		exit(1);
	}

	if (forest[element].parent == element)
	{
		return element;
	}
	else
	{
		forest[element].parent = Find(forest[element].parent);

		return forest[element].parent;
	}
}

void DisjointSets::Union(int representativeSetx, int representativeSety)
{
	if (forest[representativeSetx].parent != representativeSetx || forest[representativeSety].parent != representativeSety) // if repx or repxy are not representative of set
	{
		cout << "wrong input";
		exit(1);
	}

	if (forest[representativeSetx].size > forest[representativeSety].size)
	{
		forest[representativeSety].parent = representativeSetx;
		forest[representativeSetx].size += forest[representativeSety].size;
	}
	else
	{
		forest[representativeSetx].parent = representativeSety;
		forest[representativeSety].size += forest[representativeSetx].size;
	}
}

DisjointSets::~DisjointSets()
{
	if (allocated)
	{
		//delete[] forest;
	}

	forest = nullptr;
}
