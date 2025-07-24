//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main(void) {

    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for the arrays
    int *array_a = malloc(sizeof(int) * ARRAY_SIZE);
    int *array_b = malloc(sizeof(int) * ARRAY_SIZE);

    // Initialize the arrays with random values between 0 and 100
    srand(1); // Seed the random number generator
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array_a[i] = rand() % 100;
        array_b[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Perform the benchmarking operation
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array_a[i] * array_b[i];
    }

    // End the timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Display the results
    printf("The dot product of the arrays is: %d\n", sum);
    printf("The benchmarking operation took %.2f seconds.\n", cpu_time_used);

    // Free the memory used by the arrays
    free(array_a);
    free(array_b);

    return 0;
}