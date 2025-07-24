//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000 // Define the size of the array
#define MAX 1000000 // Define the maximum random number

// Bubble sort algorithm for sorting an array in ascending order
void bubbleSort(int arr[]) {
    int i, j;
    for (i = 0; i < SIZE-1; i++) {
        for (j = 0; j < SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion sort algorithm for sorting an array in ascending order
void insertionSort(int arr[]) {
    int i, j, key;
    for (i = 1; i < SIZE; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[SIZE];
    int i;

    // Generate random numbers and fill the array
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t t; // Define a clock variable to measure time

    // Execute bubble sort and measure time
    t = clock();
    bubbleSort(arr);
    t = clock() - t;
    double bubbleSortTime = ((double)t)/CLOCKS_PER_SEC;
    printf("Sorted array using bubble sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken by bubble sort: %f seconds\n", bubbleSortTime);

    // Execute insertion sort and measure time
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX;
    }
    t = clock();
    insertionSort(arr);
    t = clock() - t;
    double insertionSortTime = ((double)t)/CLOCKS_PER_SEC;
    printf("Sorted array using insertion sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken by insertion sort: %f seconds\n", insertionSortTime);

    if (bubbleSortTime < insertionSortTime) {
        printf("Bubble sort is faster than insertion sort\n");
    } else {
        printf("Insertion sort is faster than bubble sort\n");
    }

    return 0;
}