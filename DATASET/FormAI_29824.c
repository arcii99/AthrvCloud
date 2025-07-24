//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000 // set array size

// function to generate random array of integers
void generateArray(int *arr, int size) {
    srand(time(NULL)); // seed for random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // generate random number between 0 and 999
    }
}

// function to print array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to perform bubble sort algorithm
void bubbleSort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];

    generateArray(arr, ARRAY_SIZE);

    printf("Initial Array: ");
    printArray(arr, ARRAY_SIZE);

    clock_t start = clock(); // start clock

    bubbleSort(arr, ARRAY_SIZE);

    clock_t end = clock(); // end clock

    printf("Sorted Array: ");
    printArray(arr, ARRAY_SIZE);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // calculate time taken

    printf("Bubble Sort Algorithm took %f seconds to execute \n", time_taken);

    return 0;
}