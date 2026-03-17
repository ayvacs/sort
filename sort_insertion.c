#include "sort.h"

// shift the elements of arr[0] -> arr[index] that are greater than key to the right
static int findInsertPos(int arr[], int i, int key) {
    int index = i - 1;
    while (index >= 0 && arr[index] > key) {
        arr[index + 1] = arr[index];
        index--;
    }
    return index + 1; // we offset by 1 because index is 1 position left of where the key should go!
}

void insertionSort(int arr[], int n) {
    // starting at the second element, we want to compare each element to the one before it
    for (int i = 1; i < n; i++) {
        int key = arr[i];

        // shift elements and find the greatest index
        int position = findInsertPos(arr, i, key);

        // set the final element to the greatest index
        arr[position] = key;
    }
}