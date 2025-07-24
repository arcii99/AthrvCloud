//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the matrix
#define N 1000

double A[N][N], B[N][N], C[N][N];

int main(void) {

    clock_t start, end;
    double cpu_time_used;

    // Initialize the matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = ((double) rand() / (double) RAND_MAX);
            B[i][j] = ((double) rand() / (double) RAND_MAX);
            C[i][j] = 0;
        }
    }

    // Start the timer
    start = clock();

    // Perform matrix multiplication
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Stop the timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the result and the execution time
    printf("Resulting Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    printf("Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}