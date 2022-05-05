#include "DisjointSets.h"

DisjointSets::DisjointSets()
{
	maxSize = 0;
	allocated = false;
}

void DisjointSets::CreateEmpty(int max)
{
	forest.clear();
	
	if (max > 0)
	{
		forest.reserve(max);
		allocated = true;
		maxSize = max;

		for (int i = 0; i < max; i++)
		{
			Node temp;

			temp.parent = -1;
			temp.size = 0;
			
			forest.push_back(temp);
		}
	}

	maxSize = max;
}

void DisjointSets::MakeSet(int newRepresentative)
{
	if (newRepresentative > maxSize)
	{
		throw "invalid input";
	}

	forest[newRepresentative].parent = newRepresentative;
	forest[newRepresentative].size = 1;
}

int DisjointSets::Find(int element)
{
	if (element > forest.size())
	{
		throw "invalid input";
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
		throw "invalid input";
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
