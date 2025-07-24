//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000 // Change this to increase/decrease the size of the arrays to compare

int main() {
    int i, j;
    double time_taken;

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE]; // Create two arrays of the desired size

    srand(time(0)); // Seed the random number generator with the current time

    /* Fill both arrays with random numbers between 0 and 99 */
    for (i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    /* Start the clock and perform operation A: nested loops to find the sum of the differences between corresponding
       elements of the two arrays */
    clock_t start = clock();
    int sum_diff_a = 0;

    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            sum_diff_a += abs(array1[i] - array2[j]);
        }
    }

    clock_t end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time taken in seconds
    printf("Time taken for operation A: %f seconds\n", time_taken);

    /* Start the clock and perform operation B: single loop to find the sum of the differences between corresponding
       elements of the two arrays */
    start = clock();
    int sum_diff_b = 0;

    for (i = 0; i < ARRAY_SIZE; i++) {
        sum_diff_b += abs(array1[i] - array2[i]);
    }

    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time taken in seconds
    printf("Time taken for operation B: %f seconds\n", time_taken);

    /* Determine which operation was faster */
    if (sum_diff_a < sum_diff_b) {
        printf("Operation A was faster and returned a smaller sum.\n");
    } else if (sum_diff_b < sum_diff_a) {
        printf("Operation B was faster and returned a smaller sum.\n");
    } else {
        printf("Both operations took the same amount of time and returned the same sum.\n");
    }

    return 0;
}