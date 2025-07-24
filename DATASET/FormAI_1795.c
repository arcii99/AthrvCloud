//FormAI DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate a random array of integers
void generateRandomArray(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Function that implements bubble sort algorithm
void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // swap the elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[ARRAY_SIZE];
    generateRandomArray(array, ARRAY_SIZE);

    // Measure the time taken to sort the array using bubble sort
    clock_t start = clock();
    bubbleSort(array, ARRAY_SIZE);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d integers using bubble sort: %f seconds.\n", ARRAY_SIZE, time_taken);

    return 0;
}