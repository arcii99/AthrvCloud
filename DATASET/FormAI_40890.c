//FormAI DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
/*
 * This matrix operations program is for badass developers only!
 * Written by: Linus Torvalds
 * Date: 21/10/2021
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS 3

// Function to add two matrices
void add_matrices(int matrix1[][COLUMNS], int matrix2[][COLUMNS], int result[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[][COLUMNS], int matrix2[][COLUMNS], int result[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][COLUMNS], int matrix2[][COLUMNS], int result[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            result[i][j] = 0;
            for(int k=0; k<COLUMNS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLUMNS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLUMNS];

    // Add matrices
    add_matrices(matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2 =\n");
    print_matrix(result);

    // Subtract matrices
    subtract_matrices(matrix1, matrix2, result);
    printf("Matrix 1 - Matrix 2 =\n");
    print_matrix(result);

    // Multiply matrices
    multiply_matrices(matrix1, matrix2, result);
    printf("Matrix 1 * Matrix 2 =\n");
    print_matrix(result);

    return 0;
}