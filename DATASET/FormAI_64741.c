//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random array of integers
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));  // seed the random number generator

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // randomly generate integers between 0 and 99
    }
}

// function to print an array of integers
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to perform a bubble sort on an array of integers
void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size = 1000;
    int arr[size];
    double elapsedTime;

    // generate a random array of size 1000
    generateRandomArray(arr, size);

    // display the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // perform bubble sort and measure the time taken
    clock_t start = clock();  // get the starting time
    bubbleSort(arr, size);
    clock_t end = clock();  // get the ending time

    // display the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // calculate the time taken and display it
    elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", elapsedTime);

    return 0;
}