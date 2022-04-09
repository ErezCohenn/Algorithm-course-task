#include "DisjointSets.h"

DisjointSets::DisjointSets()
{
	tree = nullptr;
	maxSize = 0;
	treeSize = 0;
	allocated = false;
}

void DisjointSets::CreateEmpty(int max)
{
	if (tree)
	{
		delete[] tree;
	}

	if (max > 0)
	{
		tree = new Element[max];
		allocated = true;
		maxSize = max;

		for (int i = 0; i < max; i++)
		{
			tree[i].parent = -1;
			tree[i].size = 0;
		}
		
	}
	
	maxSize = max;
	treeSize = 0;	
}

void DisjointSets::MakeSset(int newRepresentative)
{
	if (newRepresentative >= maxSize)
	{
		cout << "wrong input" << endl;
		exit(1);
	}

	tree[newRepresentative].parent = newRepresentative;
	tree[newRepresentative].size = 1;
	treeSize++;
}

int DisjointSets::Find(int element)
{
	if (tree[element].parent == element)
	{
		return element;
	}
	else
	{
		tree[element].parent = Find(tree[element].parent);

		return tree[element].parent;
	}
}

void DisjointSets::Union(int representativeSetx, int representativeSety)
{
	if (tree[representativeSetx].parent != representativeSetx || tree[representativeSety].parent != representativeSety) // if repx or repxy are not representative of set
	{
		cout << "wrong input";
		exit(1);
	}
	
	if (tree[representativeSetx].size > tree[representativeSety].size)
	{
		tree[representativeSety].parent = representativeSetx;
		tree[representativeSetx].size += tree[representativeSety].size;
	}
	else
	{
		tree[representativeSetx].parent = representativeSety;
		tree[representativeSety].size += tree[representativeSetx].size;
	}
}
