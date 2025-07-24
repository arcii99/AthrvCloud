//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000

// Function to initialize the matrix with random values
void init_matrix(int matrix[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print the matrix
void print_matrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result[ROWS][COLS];

    init_matrix(matrix1);
    init_matrix(matrix2);

    printf("Matrix 1:\n");
    print_matrix(matrix1);

    printf("Matrix 2:\n");
    print_matrix(matrix2);

    multiply_matrices(matrix1, matrix2, result);

    printf("Result:\n");
    print_matrix(result);

    return 0;
}