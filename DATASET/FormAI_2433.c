//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to merge two sorted arrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int leftIndex = 0;
    int rightIndex = 0;
    int arrIndex = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[arrIndex++] = left[leftIndex++];
        }
        else {
            arr[arrIndex++] = right[rightIndex++];
        }
    }

    // Copy remaining elements of left array
    while (leftIndex < leftSize) {
        arr[arrIndex++] = left[leftIndex++];
    }

    // Copy remaining elements of right array
    while (rightIndex < rightSize) {
        arr[arrIndex++] = right[rightIndex++];
    }
}

// Function to merge sort array
void mergeSort(int arr[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];

        // Creating left subarray
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }

        // Creating right subarray
        for (int i = mid; i < n; i++) {
            right[i - mid] = arr[i];
        }

        // Recursively sort left subarray
        mergeSort(left, mid);

        // Recursively sort right subarray
        mergeSort(right, n - mid);

        // Merge left and right subarrays
        merge(arr, left, mid, right, n-mid);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    
    // Randomizing array elements
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array before sorting:\n");
    printArray(arr, ARRAY_SIZE);

    mergeSort(arr, ARRAY_SIZE);

    printf("Array after sorting:\n");
    printArray(arr, ARRAY_SIZE);

    return 0;
}