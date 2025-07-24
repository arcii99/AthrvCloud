//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define ROWS 3
#define COLS 3

// function to print the matrix
void print_matrix(double complex A[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%.2lf + %.2lfi ", creal(A[i][j]), cimag(A[i][j]));
        }
        printf("\n");
    }
}

void matrix_addition(double complex A[][COLS], double complex B[][COLS], double complex C[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_subtraction(double complex A[][COLS], double complex B[][COLS], double complex C[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrix_multiplication(double complex A[][COLS], double complex B[][COLS], double complex C[][COLS]) {
    int i, j, k;
    double complex sum;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            sum = 0;
            for(k = 0; k < ROWS; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    double complex A[ROWS][COLS] = {{1+2*I, 2+3*I, 3+4*I}, {4+5*I, 5+6*I, 6+7*I}, {7+8*I, 8+9*I, 9+10*I}};
    double complex B[ROWS][COLS] = {{10+9*I, 9+8*I, 8+7*I}, {7+6*I, 6+5*I, 5+4*I}, {4+3*I, 3+2*I, 2+1*I}};
    double complex C[ROWS][COLS];

    printf("Matrix A:\n");
    print_matrix(A);

    printf("\nMatrix B:\n");
    print_matrix(B);

    printf("\nMatrix A + B:\n");
    matrix_addition(A, B, C);
    print_matrix(C);

    printf("\nMatrix A - B:\n");
    matrix_subtraction(A, B, C);
    print_matrix(C);

    printf("\nMatrix A * B:\n");
    matrix_multiplication(A, B, C);
    print_matrix(C);

    return 0;
}