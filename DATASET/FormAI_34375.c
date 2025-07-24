//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// function to initialize the array with random integers
void initializeArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }
}

// function to sort the array using bubble sort algorithm
void bubbleSort(int arr[]) {
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// function to print the array
void printArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // create an array of size ARRAY_SIZE
    int arr[ARRAY_SIZE];

    // initialize the random number generator
    srand(time(NULL));

    // initialize the array with random integers
    initializeArray(arr);

    // print the unsorted array
    printf("Unsorted Array:\n");
    printArray(arr);

    // start the timer
    clock_t start = clock();

    // sort the array using bubble sort algorithm
    bubbleSort(arr);

    // stop the timer
    clock_t end = clock();

    // calculate the execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // print the sorted array
    printf("Sorted Array:\n");
    printArray(arr);

    // print the execution time
    printf("Execution Time: %f seconds\n", executionTime);

    return 0;
}