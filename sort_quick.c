#include "sort.h"

static void findI(int* i, int arr[], int high, int p) {
    while (arr[*i] <= p && (*i) <= high - 1)
        (*i)++;
}

static void findJ(int* j, int arr[], int low, int p) {
    while (arr[*j] > p && (*j) >= low + 1)
        (*j)--;
}

static int partition(int arr[], int low, int high) {
    // initialize the pivot to the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // find the leftmost element greater than the pivot
        findI(&i, arr, high, p);

        // find the rightmost element smaller than the pivot
        findJ(&j, arr, low, p);

        // if the leftmost element is less than the rightmost element, swap them
        if (i < j)
            _sort__swap(arr, i, j);
    }

    // swap these two values
    _sort__swap(arr, low, j);
    
    return j;
}

static void recurse(int arr[], int low, int high) {
    if (low >= high)
        return;

    int p = partition(arr, low, high);
    recurse(arr, low, p - 1);
    recurse(arr, p + 1, high);
}

void quickSort(int arr[], int n) {
    recurse(arr, 0, n - 1);
}