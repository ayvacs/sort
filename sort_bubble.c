#include "sort.h"

void bubbleSort(int arr[], int n) {
    int temp;

    // loop through the entire array (except for the last element)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            // if this element is greater than the next element...
            if (arr[j] > arr[j + 1]) {
                // bubble it towards the end (swap them)
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}