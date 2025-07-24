//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int array[ARRAY_SIZE];

int main() {
    srand(time(NULL));
    clock_t start, end;
    double time_taken;

    // Fill array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    printf("Performing benchmarking test...\n");

    // Bubble Sort
    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time Taken: %f seconds\n", time_taken);

    // Selection Sort
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int min_index = i;
        for (int j = i+1; j < ARRAY_SIZE; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time Taken: %f seconds\n", time_taken);

    return 0;
}