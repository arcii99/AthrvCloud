//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this value to change the size of the array
const int ARRAY_SIZE = 100000;

// Fill the array with random numbers between 1 and 100
void fillArray(int* array) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100 + 1;
    }
}

// Bubble sort algorithm
void bubbleSort(int* array) {
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        for (int j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int* array = (int*) malloc(ARRAY_SIZE * sizeof(int));
    fillArray(array);

    // Start timer
    clock_t start = clock();

    bubbleSort(array);

    // Stop timer and calculate elapsed time
    clock_t stop = clock();
    double elapsed_time = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f seconds\n", elapsed_time);

    free(array);
    return 0;
}