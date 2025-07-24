//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000 // 100 million elements
#define NUM_ITERATIONS 100 // number of times to iterate through array

int main() {
    int *arr = malloc(sizeof(int) * ARRAY_SIZE); // allocate memory for array

    // initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // calculate time taken to access array elements
    clock_t start_time = clock();
    int sum = 0;
    for (int j = 0; j < NUM_ITERATIONS; j++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            sum += arr[i];
        }
    }
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sum of array elements: %d\n", sum);
    printf("Time taken to access array elements: %f seconds\n", time_taken);

    free(arr); // free memory allocated for array
    return 0;
}