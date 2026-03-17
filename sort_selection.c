#include "sort.h"

static int minIndex(int arr[], int n, int i) {
    // find the smallest value in the remaining portion of the array (for arr of length n, search range i + 1 -> n)
    int ret = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[ret])
            ret = j;
    return ret;
}

void selectionSort(int arr[], int n) {
    // loop through the entire array (except the last element)
    for (int i = 0; i < n - 1; i++)
        // swap the current index and the smallest value in the remaining portion of the array
        _sort__swap(arr, i, minIndex(arr, n, i));
}