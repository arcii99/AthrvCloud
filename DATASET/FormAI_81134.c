//FormAI DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    clock_t t;
    int arr[ARRAY_SIZE];
    
    // Randomize array elements
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    
    printf("Array before sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Insertion sort
    printf("\nInsertion sort:\n");
    t = clock();
    insertion_sort(arr, ARRAY_SIZE);
    t = clock() - t;
    printf("Time elapsed: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    
    // Merge sort
    printf("\nMerge sort:\n");
    t = clock();
    merge_sort(arr, 0, ARRAY_SIZE - 1);
    t = clock() - t;
    printf("Time elapsed: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    
    // Quick sort
    printf("\nQuick sort:\n");
    t = clock();
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    t = clock() - t;
    printf("Time elapsed: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    
    printf("\nArray after sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

/**
 * Insertion sort implementation.
 * Sorts the given array of size n in ascending order.
 */
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/**
 * Merge sort implementation.
 * Sorts the given array of size n in ascending order.
 */
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * Merges two subarrays of arr[].
 * First subarray is arr[l..m].
 * Second subarray is arr[m+1..r].
 */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temp arrays
    int L[n1], R[n2];
    
    // Copy data to temp arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    
    // Merge temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Quick sort implementation.
 * Sorts the given array of size n in ascending order.
 */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * Partitioning step of quick sort.
 * Picks last element as pivot and places it at its correct position
 * in sorted array. All elements smaller than pivot are put before it
 * and all elements greater than pivot are put after it.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}