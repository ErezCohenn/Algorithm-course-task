#pragma once
#include <iostream>

using std::swap;

template <class T>
class QuickSort
{
public:
    static void quickSort(T arr[], int left, int right)
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
    static T partition(T arr[], int left, int right)
    {
        T pivotValue = arr[left];
        T pivotPosition = left;

        for (int pos = left + 1; pos <= right; pos++)
        {
            if (arr[pos] < pivotValue)
            {
                swap(arr[pivotPosition + 1], arr[pos]);
                swap(arr[pivotPosition], arr[pivotPosition + 1]);
               
                pivotPosition++;
            }
        }
        return pivotPosition;
    }

};
