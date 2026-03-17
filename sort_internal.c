#include "sort.h"
#include "sort_internal.h"

void _sort__swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}