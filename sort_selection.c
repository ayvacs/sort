#include "sort.h"

void selectionSort(int arr[], int n) {
    // loop through the entire array
    for (int i = 0; i < n - 1; i++) {
        // find the smallest value in the remaining portion of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        // swap these two values
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}