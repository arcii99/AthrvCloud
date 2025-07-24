//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000

void multiply_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for(k = 0; k < COLS; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int i, j;

    // initialize matrices with random values
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // multiply matrices
    multiply_matrices(matrix1, matrix2, result);

    // print result matrix
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}