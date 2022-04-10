#pragma once
#include <iostream>
#include "Edge.h"
#include <vector>
using std::vector;
using std::swap;


class QuickSort
{
public:
	static void quickSort(vector<Edge*> arr, int left, int right)
	{
		if (left < right)
		{
			int pivot = partition(arr, left, right);

			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
		return; //base case
	}

private:
	static int partition(vector<Edge*> arr, int left, int right)
	{
		int pivotValue = arr[left]->edgeWeight;
		int pivotPosition = left;

		for (int pos = left + 1; pos <= right; pos++)
		{
			if (arr[pos]->edgeWeight < pivotValue)
			{
				swap(arr[pivotPosition + 1], arr[pos]);
				swap(arr[pivotPosition], arr[pivotPosition + 1]);

				pivotPosition++;
			}
		}
		return pivotPosition;
	}
};
