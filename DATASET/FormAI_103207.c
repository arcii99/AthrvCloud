//FormAI DATASET v1.0 Category: Benchmarking ; Style: bold
// Bold and Unique C Benchmarking Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Function that generates random integers
void generateRandomInts(int* arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

// Function that swaps two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for the Bubble Sort algorithm
void bubbleSort(int* arr) {
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        for (int j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function for the Quick Sort algorithm
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high-1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[high]);

        int pi = i+1;

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    generateRandomInts(arr);

    printf("Initial Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Benchmarking Bubble Sort
    printf("Bubble Sort:\n");
    clock_t start_bubble = clock();
    bubbleSort(arr);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n\n", time_bubble);

    // Generating new array for Quick Sort
    generateRandomInts(arr);

    printf("Initial Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Benchmarking Quick Sort
    printf("Quick Sort:\n");
    clock_t start_quick = clock();
    quickSort(arr, 0, ARRAY_SIZE-1);
    clock_t end_quick = clock();
    double time_quick = ((double) (end_quick - start_quick)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n\n", time_quick);

    return 0;
}