//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merges two sorted subarrays into one
void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

// Recursive function to perform merge sort
void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    int middle = size / 2;
    int left[middle], right[size - middle];

    for (int i = 0; i < middle; i++) {
        left[i] = arr[i];
    }

    for(int i = middle; i < size; i++) {
        right[i - middle] = arr[i];
    }
    
    merge_sort(left, middle);
    merge_sort(right, size - middle);
    merge(arr, left, middle, right, size - middle);
}

// Recursive function to perform quicksort
void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    clock_t start, end;
    double cpu_time_used;
    srand(time(0));

    // Generate a list of random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Measure the time taken to sort using merge sort
    start = clock();
    merge_sort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort took %f seconds\n", cpu_time_used);

    // Generate a new list of random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Measure the time taken to sort using quicksort
    start = clock();
    quicksort(arr, 0, SIZE-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quicksort took %f seconds\n", cpu_time_used);

    return 0;
}