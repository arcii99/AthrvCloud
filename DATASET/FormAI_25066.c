//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MATRIX_SIZE 2000
#define NUM_LOOPS 1000

int main() {
    int i, j, k, sum;

    double mat1[MATRIX_SIZE][MATRIX_SIZE];
    double mat2[MATRIX_SIZE][MATRIX_SIZE];
    double result[MATRIX_SIZE][MATRIX_SIZE];

    // Initialize matrices with random values
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    // Benchmarking - start timer
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Multiply matrices NUM_LOOPS times
    for (int n = 0; n < NUM_LOOPS; n++) {
        for (i = 0; i < MATRIX_SIZE; i++) {
            for (j = 0; j < MATRIX_SIZE; j++) {
                sum = 0;
                for (k = 0; k < MATRIX_SIZE; k++) {
                    sum += mat1[i][k] * mat2[k][j];
                }
                result[i][j] = sum;
            }
        }
    }

    // Benchmarking - stop timer
    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    // Display benchmark results
    printf("Matrix multiplication benchmark:\n");
    printf("Matrix size: %d x %d\n", MATRIX_SIZE, MATRIX_SIZE);
    printf("Number of loops: %d\n", NUM_LOOPS);
    printf("Elapsed time: %f seconds\n", time_taken);
    printf("Avg time per loop: %f microseconds\n", time_taken / NUM_LOOPS * 1e6);

    return 0;
}