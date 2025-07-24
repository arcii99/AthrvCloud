//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>

// define the matrix dimensions
#define ROWS 3
#define COLS 3

// prototype the matrix functions
void print_matrix(int matrix[][COLS]);
void add_matrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]);
void multiply_matrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]);

int main() {
    // initialize the matrices
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];

    // print out the initial matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // add the matrices and print the result
    printf("Result of matrix addition:\n");
    add_matrices(matrix1, matrix2, result);
    print_matrix(result);

    // multiply the matrices and print the result
    printf("Result of matrix multiplication:\n");
    multiply_matrices(matrix1, matrix2, result);
    print_matrix(result);

    return 0;
}

void print_matrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply_matrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < ROWS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}