//FormAI DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3 // Set the matrix size for this program

// Function to initialize matrix with random values
void init_random_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            matrix[i][j] = (double) rand() / RAND_MAX; // Random double between 0 and 1
        }
    }
}

// Function to print out a matrix
void print_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices together
void add_matrices(double matrix1[MATRIX_SIZE][MATRIX_SIZE], double matrix2[MATRIX_SIZE][MATRIX_SIZE], double result[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Sum of two matrices
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE], double result[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            result[j][i] = matrix[i][j]; // Transpose of a matrix
        }
    }
}

// Function to multiply two matrices together
void multiply_matrices(double matrix1[MATRIX_SIZE][MATRIX_SIZE], double matrix2[MATRIX_SIZE][MATRIX_SIZE], double result[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            double sum = 0.0;
            for(int k=0; k<MATRIX_SIZE; k++) {
                sum += matrix1[i][k] * matrix2[k][j]; // Multiply and sum of two matrices
            }
            result[i][j] = sum;
        }
    }
}

// Main function to test the matrix operations
int main() {
    // Initialize two matrices with random values
    double matrix1[MATRIX_SIZE][MATRIX_SIZE];
    double matrix2[MATRIX_SIZE][MATRIX_SIZE];

    srand(time(NULL)); // Seed the random number generator
    init_random_matrix(matrix1);
    init_random_matrix(matrix2);

    // Create a matrix to store the sum of matrix1 and matrix2
    double sum_matrix[MATRIX_SIZE][MATRIX_SIZE];
    add_matrices(matrix1, matrix2, sum_matrix);

    // Print out the original matrices and the sum matrix
    printf("Matrix1:\n");
    print_matrix(matrix1);

    printf("Matrix2:\n");
    print_matrix(matrix2);

    printf("Sum of Matrix1 and Matrix2:\n");
    print_matrix(sum_matrix);

    // Create a matrix to store the transpose of matrix1
    double transposed_matrix[MATRIX_SIZE][MATRIX_SIZE];
    transpose_matrix(matrix1, transposed_matrix);

    // Print out the original matrix and the transposed matrix
    printf("Original Matrix1:\n");
    print_matrix(matrix1);

    printf("Transposed Matrix1:\n");
    print_matrix(transposed_matrix);

    // Create a matrix to store the product of matrix1 and matrix2
    double product_matrix[MATRIX_SIZE][MATRIX_SIZE];
    multiply_matrices(matrix1, matrix2, product_matrix);

    // Print out the original matrices and the product matrix
    printf("Matrix1:\n");
    print_matrix(matrix1);

    printf("Matrix2:\n");
    print_matrix(matrix2);

    printf("Product of Matrix1 and Matrix2:\n");
    print_matrix(product_matrix);

    return 0;
}