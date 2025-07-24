//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_SIZE 1000000

// Function to initialize an array with random integers
void initializeArray(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}

// Function to perform selection sort on an array of integers
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Main function to benchmark the selection sort algorithm
int main() {
    int array[ARRAY_SIZE];
    initializeArray(array, ARRAY_SIZE);

    uint64_t start = 0, end = 0;
    start = clock(); // Start the timer

    selectionSort(array, ARRAY_SIZE); // Call the selectionSort function

    end = clock(); // End the timer
    printf("Time taken to sort %d integers using selection sort: %lu microseconds\n", ARRAY_SIZE, (end - start));

    return 0;
}