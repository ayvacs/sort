#include "sort.h"

int quickSort_partition(int arr[], int low, int high) {
    // initialize the pivot to the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // find the leftmost element greater than the pivot
        while (arr[i] <= p && i <= high - 1)
            i++;

        // find the rightmost element smaller than the pivot
        while (arr[j] > p && j >= low + 1)
            j--;

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort_recurse(int arr[], int low, int high) {
    if (low < high) {
        int p = quickSort_partition(arr, low, high);
        quickSort_recurse(arr, low, p - 1);
        quickSort_recurse(arr, p + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSort_recurse(arr, 0, n - 1);
}