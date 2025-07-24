//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000    // Define the maximum size of the array
#define NUM_ITERATIONS 100  // Number of times the sorting algorithm will be executed

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform QuickSort algorithm on an array
void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];  // Select the pivot element
        int i = left - 1, j = right + 1;

        while (1) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);

            if (i >= j) break;

            swap(&arr[i], &arr[j]);
        }

        quickSort(arr, left, i - 1);
        quickSort(arr, j + 1, right);
    }
}

int main() {
    int i, j;
    int arr[MAX_SIZE];
    double total_time = 0;

    // Initialize the array with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using QuickSort algorithm and measure the time
    for (i = 0; i < NUM_ITERATIONS; i++) {
        clock_t begin = clock();

        quickSort(arr, 0, MAX_SIZE - 1);

        clock_t end = clock();
        total_time += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    // Print the sorted array and the average time it took to sort
    printf("Sorted Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nAverage time to sort: %lf seconds\n", total_time / NUM_ITERATIONS);

    return 0;
}