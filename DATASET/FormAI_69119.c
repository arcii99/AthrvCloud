//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define LOOP_COUNT 10000

int main() {
    srand(time(NULL));

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];

    // Initialize arrays with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    int result = 0;

    // Multiply the elements of the arrays
    clock_t start_time = clock();

    for (int j = 0; j < LOOP_COUNT; j++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            result += array1[i] * array2[i];
        }
    }

    clock_t end_time = clock();

    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Result: %d\n", result);
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}