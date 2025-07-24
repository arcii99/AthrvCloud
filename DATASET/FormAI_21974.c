//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>
#define N 1000

/* Function prototypes */
void populateMatrix(int matrix[][N], int rows, int cols);
void printMatrix(int matrix[][N], int rows, int cols);
void addMatrix(int matrix1[][N], int matrix2[][N], int resultMatrix[][N], int rows, int cols);
void subtractMatrix(int matrix1[][N], int matrix2[][N], int resultMatrix[][N], int rows, int cols);

/* Main program */
int main() {
    int matrix1[N][N], matrix2[N][N], resultMatrix[N][N];
    int rows = N, cols = N;

    printf("Populating matrices...\n");
    populateMatrix(matrix1, rows, cols);
    populateMatrix(matrix2, rows, cols);

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows, cols);
    
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows, cols);

    printf("\nAdding matrices...\n");
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            addMatrix(matrix1, matrix2, resultMatrix, rows, cols);
        }
    }
    printf("\nResult Matrix After Addition:\n");
    printMatrix(resultMatrix, rows, cols);
    
    printf("\nSubtracting matrices...\n");
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            subtractMatrix(matrix1, matrix2, resultMatrix, rows, cols);
        }
    }
    printf("\nResult Matrix After Subtraction:\n");
    printMatrix(resultMatrix, rows, cols);

    return 0;
}

/* Function to populate matrix with random data */
void populateMatrix(int matrix[][N], int rows, int cols) {
    srand(time(NULL));  // To generate random data using time as the seed
    #pragma omp parallel for
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = rand() % 100;  // Limiting the random data generation to numbers between 0 and 99
        }
    }
}

/* Function to print matrix */
void printMatrix(int matrix[][N], int rows, int cols) {
    #pragma omp parallel for
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
void addMatrix(int matrix1[][N], int matrix2[][N], int resultMatrix[][N], int rows, int cols) {
    #pragma omp parallel for
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/* Function to subtract two matrices */
void subtractMatrix(int matrix1[][N], int matrix2[][N], int resultMatrix[][N], int rows, int cols) {
    #pragma omp parallel for
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}