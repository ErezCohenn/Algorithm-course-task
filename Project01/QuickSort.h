#pragma once
#include <iostream>
#include "Edge.h"
#include <vector>
using std::vector;
using std::swap;

class QuickSort
{
public:
	static void quickSort(vector<Edge*>& arr, int left, int right);
private:
	static int partition(vector<Edge*>& arr, int left, int right);
};
