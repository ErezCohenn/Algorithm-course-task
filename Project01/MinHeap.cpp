#include "MinHeap.h"


MinHeap::MinHeap()
{
	data = nullptr;
	maxSize = 0;
	heapSize = 0;
	allocated = 0;
}

MinHeap::~MinHeap()
{
	if (allocated)
	{
		delete[] data;
	}

	data = nullptr;
}

void MinHeap::CreateEmpty(int max)
{
	if (data)
	{
		delete[] data;
		indenciesArr.clear();
	}

	if (max > 0)
	{
		data = nullptr;
		data = new Pair[max];
		indenciesArr.reserve(max);
		allocated = 1;
	}

	maxSize = max;
	heapSize = 0;
}

const Pair& MinHeap::Min() const
{
	if (heapSize > 0)
	{
		return data[0];
	}

	else
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
}

Pair MinHeap::DeleteMin()
{
	if (heapSize < 1)
	{
		cout << "Invalid input" << endl;
		exit(1);
	}

	Pair min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	indenciesArr[data[0].data - 1] = 0;
	FixHeap(0);

	return min;
}

void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left].key < data[node].key))
	{
		min = left;
	}
	else
	{
		min = node;
	}

	if ((right < heapSize) && (data[right].key < data[min].key))
	{
		min = right;
	}

	if (min != node)
	{
		swap(data[node], data[min]);
		swap(indenciesArr[data[node].data - 1], indenciesArr[data[min].data - 1]);
		
		FixHeap(min);
	}
}

void MinHeap::DecreaseKey(int place, int newKey)
{
	if (place >= heapSize || place < 0) 
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	
	Pair item = data[place];
	item.key = newKey;
	
	while ((place > 0) && data[Parent(place)].key > item.key)
	{
		data[place] = data[Parent(place)];
		indenciesArr[data[place].data - 1] = place;
		place = Parent(place);
	}

	data[place] = item;
	indenciesArr[data[place].data - 1] = place;
}

bool MinHeap::isEmpty()
{
	if (heapSize == 0)
	{
		return true;
	}
	else if (heapSize < 0)
	{
		cout << "Invalid input";
		exit(1);
	}
	else
		return false;
}

void MinHeap::Build(int arr[], int size)
{
	CreateEmpty(size);

	for (int i = 0; i < size; i++)
	{
		Pair node;

		node.data = i + 1;
		node.key = arr[i];
		data[i] = node;
		indenciesArr.push_back(i);
	}

	heapSize = size;

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}	
}
