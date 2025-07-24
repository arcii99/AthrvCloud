//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000000
#define NUM_ITERATIONS 5000

void initializeArray(int array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int main() {
    int inputArray[ARRAY_SIZE];
    int i, j;
    long long totalSum = 0;
    struct timeval start, end;

    initializeArray(inputArray, ARRAY_SIZE);

    gettimeofday(&start, NULL);

    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            totalSum += inputArray[j];
        }
    }

    gettimeofday(&end, NULL);

    printf("Total Sum: %lld\n", totalSum);
    printf("Average Time Per Iteration: %f microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / (float) NUM_ITERATIONS);

    return 0;
}