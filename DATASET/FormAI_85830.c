//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100000
#define COLS 1000

// function to fill the matrix with random values between 0 and 1
void fill_matrix(float matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (float)rand() / RAND_MAX;
        }
    }
}

// function to multiply two matrices and store the result in a third matrix
void matrix_multiply(float a[ROWS][COLS], float b[COLS][ROWS], float c[ROWS][ROWS]) {
    // use loop unrolling to optimize the multiplication process
    for (int i = 0; i < ROWS; i += 4) {
        for (int j = 0; j < ROWS; j += 4) {
            for (int k = 0; k < COLS; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j+1] += a[i][k] * b[k][j+1];
                c[i][j+2] += a[i][k] * b[k][j+2];
                c[i][j+3] += a[i][k] * b[k][j+3];
                
                c[i+1][j] += a[i+1][k] * b[k][j];
                c[i+1][j+1] += a[i+1][k] * b[k][j+1];
                c[i+1][j+2] += a[i+1][k] * b[k][j+2];
                c[i+1][j+3] += a[i+1][k] * b[k][j+3];
                
                c[i+2][j] += a[i+2][k] * b[k][j];
                c[i+2][j+1] += a[i+2][k] * b[k][j+1];
                c[i+2][j+2] += a[i+2][k] * b[k][j+2];
                c[i+2][j+3] += a[i+2][k] * b[k][j+3];
                
                c[i+3][j] += a[i+3][k] * b[k][j];
                c[i+3][j+1] += a[i+3][k] * b[k][j+1];
                c[i+3][j+2] += a[i+3][k] * b[k][j+2];
                c[i+3][j+3] += a[i+3][k] * b[k][j+3];
            }
        }
    }
}

int main() {
    float matrix_a[ROWS][COLS], matrix_b[COLS][ROWS], result_matrix[ROWS][ROWS];
    
    // seed the random generator with the current time
    srand(time(NULL));
    
    // fill the matrices with random values
    fill_matrix(matrix_a);
    fill_matrix(matrix_b);
    
    // multiply the matrices
    matrix_multiply(matrix_a, matrix_b, result_matrix);
    
    // print the result matrix, just to be sure
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%f ", result_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}