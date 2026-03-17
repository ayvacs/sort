#include "sort.h"

void insertionSort(int arr[], int n) {
    // starting at the second element, we want to compare each element to the one before it
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int index = i - 1;

        // while the index before this one is greater than this one...
        while (index >= 0 && arr[index] > key) {
            arr[index + 1] = arr[index];
            index--;
        }

        // set the final element to the greatest index
        arr[index + 1] = key;
    }
}