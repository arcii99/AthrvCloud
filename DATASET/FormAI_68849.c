//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>

#define ROWS 3
#define COLS 3

void matrix_add(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_multiply(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    int i, j, k;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            C[i][j] = 0;
            for(k = 0; k < ROWS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_print(int A[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int C[ROWS][COLS];

    printf("Matrix A:\n");
    matrix_print(A);

    printf("\nMatrix B:\n");
    matrix_print(B);

    printf("\nMatrix addition A + B:\n");
    matrix_add(A, B, C);
    matrix_print(C);

    printf("\nMatrix multiplication A * B:\n");
    matrix_multiply(A, B, C);
    matrix_print(C);

    return 0;
}