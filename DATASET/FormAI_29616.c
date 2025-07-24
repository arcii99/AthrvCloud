//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int i, j;
    int sum_matrix[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Sum of matrices:\n");
    print_matrix(sum_matrix);
}

void subtract_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int i, j;
    int diff_matrix[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            diff_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Difference of matrices:\n");
    print_matrix(diff_matrix);
}

void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int i, j, k;
    int product_matrix[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            product_matrix[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Product of matrices:\n");
    print_matrix(product_matrix);
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    add_matrices(matrix1, matrix2);
    subtract_matrices(matrix1, matrix2);
    multiply_matrices(matrix1, matrix2);

    return 0;
}