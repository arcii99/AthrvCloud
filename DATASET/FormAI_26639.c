//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
#define ITERATIONS 500000

int main() {
    int array[SIZE];
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    clock_t start = clock();
    for (int j = 0; j < ITERATIONS; j++) {
        sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += array[i];
        }
    }
    clock_t end = clock();

    double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Time taken to execute %d iterations of loop: %lf seconds\n", ITERATIONS, time_elapsed_in_seconds);

    return 0;
}