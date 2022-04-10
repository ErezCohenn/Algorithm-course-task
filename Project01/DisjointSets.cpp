#include "DisjointSets.h"

DisjointSets::DisjointSets()
{
	forestOfGroups = nullptr;
	maxSize = 0;
	treeSize = 0;
	allocated = false;
}

void DisjointSets::CreateEmpty(int max)
{
	if (forestOfGroups)
	{
		delete[] forestOfGroups;
	}

	if (max > 0)
	{
		forestOfGroups = new Node[max];
		allocated = true;
		maxSize = max;

		for (int i = 0; i < max; i++)
		{
			forestOfGroups[i].parent = -1;
			forestOfGroups[i].size = 0;
		}

	}

	maxSize = max;
	treeSize = 0;
}

void DisjointSets::MakeSet(int newRepresentative)
{
	if (newRepresentative >= maxSize)
	{
		cout << "wrong input" << endl;
		exit(1);
	}

	forestOfGroups[newRepresentative].parent = newRepresentative;
	forestOfGroups[newRepresentative].size = 1;
	treeSize++;
}

int DisjointSets::Find(int Node)
{
	if (Node >= treeSize)
	{
		cout << "wrong input";
		exit(1);
	}

	if (forestOfGroups[Node].parent == Node)
	{
		return Node;
	}
	else
	{
		forestOfGroups[Node].parent = Find(forestOfGroups[Node].parent);
		return forestOfGroups[Node].parent;
	}
}

void DisjointSets::Union(int representativeSetx, int representativeSety)
{
	if (forestOfGroups[representativeSetx].parent != representativeSetx || forestOfGroups[representativeSety].parent != representativeSety) // if repx or repxy are not representative of set
	{
		cout << "wrong input";
		exit(1);
	}

	if (forestOfGroups[representativeSetx].size > forestOfGroups[representativeSety].size)
	{
		forestOfGroups[representativeSety].parent = representativeSetx;
		forestOfGroups[representativeSetx].size += forestOfGroups[representativeSety].size;
	}
	else
	{
		forestOfGroups[representativeSetx].parent = representativeSety;
		forestOfGroups[representativeSety].size += forestOfGroups[representativeSetx].size;
	}
}

DisjointSets::~DisjointSets()
{
	if (allocated)
	{
		delete[] forestOfGroups;
	}

	forestOfGroups = nullptr;
}
