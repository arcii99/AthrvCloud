//FormAI DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_TESTS 1000000
#define ARRAY_SIZE 1000

int main(void) {
    int i, j, res;
    int sum = 0;
    int array[ARRAY_SIZE];

    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
    }

    clock_t start = clock();
    for (i = 0; i < NUM_OF_TESTS; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            sum += array[j];
        }
    }
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed for %d tests: %.5f seconds\n", NUM_OF_TESTS, elapsed_time);

    return 0;
}