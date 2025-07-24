//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Helper function to print an array of integers
void print_int_array(int *arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Bubble sort implementation
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Merge sort implementation
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_helper(int *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort_helper(arr, l, m);
        merge_sort_helper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge_sort(int *arr, int size) {
    merge_sort_helper(arr, 0, size - 1);
}

// Quick sort implementation
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort_helper(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

void quick_sort(int *arr, int size) {
    quick_sort_helper(arr, 0, size - 1);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Create an array of random integers
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Copy the array to avoid sorting the already sorted array
    int arr_bubble[ARRAY_SIZE];
    memcpy(arr_bubble, arr, ARRAY_SIZE * sizeof(int));
    int arr_merge[ARRAY_SIZE];
    memcpy(arr_merge, arr, ARRAY_SIZE * sizeof(int));
    int arr_quick[ARRAY_SIZE];
    memcpy(arr_quick, arr, ARRAY_SIZE * sizeof(int));

    // Benchmark the sorting algorithms
    clock_t start_time, end_time;
    double time_taken;

    // Bubble sort benchmark
    start_time = clock();
    bubble_sort(arr_bubble, ARRAY_SIZE);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Bubble sort time taken: %f seconds\n", time_taken);
    // Uncomment to print sorted array
    // print_int_array(arr_bubble, ARRAY_SIZE);

    // Merge sort benchmark
    start_time = clock();
    merge_sort(arr_merge, ARRAY_SIZE);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Merge sort time taken: %f seconds\n", time_taken);
    // Uncomment to print sorted array
    // print_int_array(arr_merge, ARRAY_SIZE);

    // Quick sort benchmark
    start_time = clock();
    quick_sort(arr_quick, ARRAY_SIZE);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Quick sort time taken: %f seconds\n", time_taken);
    // Uncomment to print sorted array
    // print_int_array(arr_quick, ARRAY_SIZE);

    return 0;
}