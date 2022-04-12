#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pair.h"

using std::vector;
using std::string;
using std::swap;
using std::cout;
using std::endl;


class MinHeap
{
	vector<Pair> data;
	vector<int> indenciesArr;
	int maxSize;
	int allocated;
	static int Left(int node) { return(2 * node + 1); };
	static int Right(int node) { return (2 * node + 2); };
	static int Parent(int node) { return ((node - 1) / 2); };
	void FixHeap(int node);
	
public:
	MinHeap();
	void CreateEmpty(int max);
	const Pair& Min() const;
	Pair DeleteMin();
	int getHeapSize() const { return data.size(); };
	int getIndex(int value) const { return indenciesArr[value]; }
	void DecreaseKey(int place, int newKey);
	bool isEmpty();
	void Build(int arr[], int size);
};