//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100000
#define MAX_LOOP_COUNT 100000

int main() {
    int array[MAX_ARRAY_SIZE];
    int i, j, temp;
    double elapsed_time;
    clock_t start_clock, finish_clock;

    // populate the array with random integers
    srand(time(NULL));
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    // perform bubble sort
    start_clock = clock();
    for (i = 0; i < MAX_LOOP_COUNT; i++) {
        for (j = 0; j < MAX_ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    finish_clock = clock();

    // calculate the elapsed time
    elapsed_time = (double)(finish_clock - start_clock) / CLOCKS_PER_SEC;

    printf("Bubble sort of %d integers, %d times\n", MAX_ARRAY_SIZE, MAX_LOOP_COUNT);
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}