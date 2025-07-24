//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

/**
 * This program benchmarks the performance of bubble sort and quick sort
 * on a randomly generated array of integers.
 */

// Function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Quick sort function
void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[right]);
        int p = i+1;
        quick_sort(arr, left, p-1);
        quick_sort(arr, p+1, right);
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(NULL)); // Seed the random number generator

    // Generate random array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand_int(0, 1000);
    }

    printf("Original array: ");
    print_array(arr, SIZE);

    // Benchmark bubble sort
    clock_t start = clock();
    bubble_sort(arr, SIZE);
    clock_t end = clock();
    double bubble_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array (bubble sort): ");
    print_array(arr, SIZE);
    printf("Time taken (bubble sort): %f seconds\n", bubble_sort_time);

    // Generate random array again (unsorted)
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand_int(0, 1000);
    }

    printf("\nOriginal array: ");
    print_array(arr, SIZE);

    // Benchmark quick sort
    start = clock();
    quick_sort(arr, 0, SIZE-1);
    end = clock();
    double quick_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array (quick sort): ");
    print_array(arr, SIZE);
    printf("Time taken (quick sort): %f seconds\n", quick_sort_time);

    return 0;
}