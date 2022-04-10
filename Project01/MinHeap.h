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
	Pair* data;
	vector<int> indenciesArr;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node) { return(2 * node + 1); };
	static int Right(int node) { return (2 * node + 2); };
	static int Parent(int node) { return ((node - 1) / 2); };
	void FixHeap(int node);

	
public:
	MinHeap();
	MinHeap(const MinHeap& h) = delete;
	MinHeap& operator=(const MinHeap& h) = delete;
	~MinHeap();

	void CreateEmpty(int max);
	const Pair& Min() const;
	Pair DeleteMin();
	int Insert(Pair& item);
	int getHeapSize() const { return heapSize; };
	int getIndex(int value) const { return indenciesArr[value]; }
	void DecreaseKey(int place, int newKey);
	bool isEmpty();
	void Build(int arr[], int size);
	void print() // need to delete for submission
	{
		for (int i = 0; i < heapSize; i++)
		{
			cout << "key: " << data[i].key << " vertex: " << data[i].data << endl;
		}
	} 
};