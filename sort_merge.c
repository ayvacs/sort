#include "sort.h"

// copy data from the original arrays into the left and right temporary arrays
static void copySubarrays(int arr[], int left, int mid, int len_left, int temp_left[], int len_right, int temp_right[]) {
	for (int i = 0; i < len_left; i++)
		temp_left[i] = arr[left + i];
	for (int j = 0; j < len_right; j++)
		temp_right[j] = arr[mid + 1 + j];
}

// take two sorted subarrays and combine them into one larger sorted array
static void merge(int arr[], int left, int mid, int right) {
	// calculate the size of the left and right subarrays
	int len_left = mid - left + 1;
	int len_right = right - mid;
	
	// temporary arrays to store the two halves
	int temp_left[len_left];
	int temp_right[len_right];
	
	// copy data from the original arrays into the left and right temporary arrays
    copySubarrays(arr, left, mid, len_left, temp_left, len_right, temp_right);
	
    // pointers
	int i = 0;
	int j = 0;
	int k = left;
	
	// compare elements from both temporary arrays, and copy the smaller one into the original array
	while (i < len_left && j < len_right)
        arr[k++] = (temp_left[i] <= temp_right[j])
            ? temp_left[i++]
            : temp_right[j++];
	
	// copy any remaining elements from the left and right arrays
	while (i < len_left)
		arr[k++] = temp_left[i++];
	while (j < len_right)
		arr[k++] = temp_right[j++];
}

static void recurse(int arr[], int left, int right) {
    if (left >= right)
        return;

    // find the middle
    int mid = left + (right - left) / 2;
    
    // recursively sort the first and second halves
    recurse(arr, left, mid);
    recurse(arr, mid + 1, right);
    
    // merge the newly sorted halves
    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int length) {
	recurse(arr, 0, length - 1);
}