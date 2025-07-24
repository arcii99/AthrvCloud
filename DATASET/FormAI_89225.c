//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000

int main() {
    srand(time(NULL));
    int matrix[ROWS][COLS], product[COLS][ROWS];
    int i, j, k;
    clock_t start, end;
    double cpu_time_used;

    // Initialize Matrix Randomly
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 1000;
        }
    }

    // Start Timer
    start = clock();

    // Multiply Rows of Matrix by Full Column of Product
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int sum = 0;
            for (k = 0; k < ROWS; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            product[i][j] = sum;
        }
    }

    // Stop Timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print Results
    printf("Matrix Multiplication Result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    printf("Time Taken: %f seconds\n", cpu_time_used);

    return 0;
}