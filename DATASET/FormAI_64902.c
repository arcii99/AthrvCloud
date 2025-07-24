//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define NUM_RUNS 10000

int main(void) {
    // Initialize variables
    int i, j, temp;
    long int total_time = 0;
    clock_t start_time, end_time;
    int numbers[MAX_NUMBER];

    // Generate random numbers array
    srand(time(NULL));
    for (i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = rand() % MAX_NUMBER;
    }

    // Bubble Sort
    start_time = clock();
    for (i = 0; i < NUM_RUNS; i++) {
        for (j = 0; j < MAX_NUMBER - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    end_time = clock();
    total_time += end_time - start_time;

    // Selection Sort
    start_time = clock();
    for (i = 0; i < NUM_RUNS; i++) {
        for (j = 0; j < MAX_NUMBER - 1; j++) {
            int min_idx = j;
            for (int k = j + 1; k < MAX_NUMBER; k++) {
                if (numbers[k] < numbers[min_idx]) {
                    min_idx = k;
                }
            }
            temp = numbers[j];
            numbers[j] = numbers[min_idx];
            numbers[min_idx] = temp;
        }
    }
    end_time = clock();
    total_time += end_time - start_time;

    // Print results
    printf("Bubble sort took %ld clocks (%f seconds) to run.\n", total_time/NUM_RUNS, ((double)total_time)/CLOCKS_PER_SEC/NUM_RUNS);
    return 0;
}