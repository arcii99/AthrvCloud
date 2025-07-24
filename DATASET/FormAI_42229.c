//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrices
#define ROWS 3
#define COLS 3

typedef struct {
    double real;
    double imag;
} Complex;

void print_matrix(Complex matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%lf + %lf i\t", matrix[i][j].real, matrix[i][j].imag);
        }
        printf("\n");
    }
}

void add_matrices(Complex matrix1[ROWS][COLS], Complex matrix2[ROWS][COLS], Complex result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j].real = matrix1[i][j].real + matrix2[i][j].real;
            result[i][j].imag = matrix1[i][j].imag + matrix2[i][j].imag;
        }
    }
}

void subtract_matrices(Complex matrix1[ROWS][COLS], Complex matrix2[ROWS][COLS], Complex result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j].real = matrix1[i][j].real - matrix2[i][j].real;
            result[i][j].imag = matrix1[i][j].imag - matrix2[i][j].imag;
        }
    }
}

void multiply_matrices(Complex matrix1[ROWS][COLS], Complex matrix2[ROWS][COLS], Complex result[ROWS][COLS]) {
    Complex temp; // Temporary variable to store the sum of products
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp.real = 0;
            temp.imag = 0;
            for (int k = 0; k < ROWS; k++) {
                temp.real += matrix1[i][k].real * matrix2[k][j].real - matrix1[i][k].imag * matrix2[k][j].imag;
                temp.imag += matrix1[i][k].real * matrix2[k][j].imag + matrix1[i][k].imag * matrix2[k][j].real;
            }
            result[i][j] = temp;
        }
    }
}

int main() {
    // Define two matrices
    Complex matrix1[ROWS][COLS] = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}, {{13, 14}, {15, 16}, {17, 18}}};
    Complex matrix2[ROWS][COLS] = {{{19, 20}, {21, 22}, {23, 24}}, {{25, 26}, {27, 28}, {29, 30}}, {{31, 32}, {33, 34}, {35, 36}}};
    Complex result[ROWS][COLS];

    // Print the matrices before the operations
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2);

    // Add the matrices and print the result
    printf("\nAdd:\n");
    add_matrices(matrix1, matrix2, result);
    print_matrix(result);

    // Subtract the matrices and print the result
    printf("\nSubtract:\n");
    subtract_matrices(matrix1, matrix2, result);
    print_matrix(result);

    // Multiply the matrices and print the result
    printf("\nMultiply:\n");
    multiply_matrices(matrix1, matrix2, result);
    print_matrix(result);

    return 0;
}