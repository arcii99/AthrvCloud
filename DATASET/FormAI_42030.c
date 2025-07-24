//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

double matrix_a[MATRIX_SIZE][MATRIX_SIZE];
double matrix_b[MATRIX_SIZE][MATRIX_SIZE];
double matrix_c[MATRIX_SIZE][MATRIX_SIZE];

void matrix_mul_naive() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix_c[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

void matrix_mul_optimized() {
    #pragma omp parallel for
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            double sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            matrix_c[i][j] = sum;
        }
    }
}

int main() {
    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix_a[i][j] = rand();
            matrix_b[i][j] = rand();
        }
    }

    // Calculate execution time of naive implementation
    clock_t t1 = clock();
    matrix_mul_naive();
    clock_t t2 = clock();

    // Calculate execution time of optimized implementation
    clock_t t3 = clock();
    matrix_mul_optimized();
    clock_t t4 = clock();

    // Print results
    printf("Execution time of naive implementation: %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    printf("Execution time of optimized implementation: %f seconds\n", (double)(t4 - t3) / CLOCKS_PER_SEC);

    return 0;
}