//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

double A[N][N], B[N][N], C[N][N];

void matrix_mult() {
    // multiply matrices A and B to obtain C
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double) rand() / RAND_MAX;
            B[i][j] = (double) rand() / RAND_MAX;
        }
    }

    clock_t t1, t2;
    double time_taken;

    t1 = clock(); // start time
    matrix_mult(); // call matrix multiplication function
    t2 = clock(); // end time

    time_taken = (double) (t2 - t1) / CLOCKS_PER_SEC;

    printf("Matrix Multiplication benchmark results:\n");
    printf("Number of elements: %d\n", N*N);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}