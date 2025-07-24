//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>

// Define size of matrix as a constant
#define N 3

// Function to print matrix
void print_matrix(int matrix[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[N][N], int matrix2[N][N], int result[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = 0;
            for(int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    // Declare matrices
    int matrix1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[N][N];
    
    // Print original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    
    // Add matrices
    add_matrices(matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2:\n");
    print_matrix(result);
    
    // Subtract matrices
    subtract_matrices(matrix1, matrix2, result);
    printf("Matrix 1 - Matrix 2:\n");
    print_matrix(result);
    
    // Multiply matrices
    multiply_matrices(matrix1, matrix2, result);
    printf("Matrix 1 * Matrix 2:\n");
    print_matrix(result);
    
    return 0;
}