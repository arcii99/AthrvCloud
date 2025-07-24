//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

// Function to generate random matrix
void generateRandomMatrix(float matrix[][MATRIX_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = (float)rand()/(float)(RAND_MAX/10.0);
        }
    }
}

// Function to multiply two matrices
void matrixMultiplication(float matrix1[][MATRIX_SIZE], float matrix2[][MATRIX_SIZE], float resultMatrix[][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            resultMatrix[i][j] = 0;
            for(int k = 0; k < MATRIX_SIZE; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    float matrix1[MATRIX_SIZE][MATRIX_SIZE];
    float matrix2[MATRIX_SIZE][MATRIX_SIZE];
    float resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

    generateRandomMatrix(matrix1);
    generateRandomMatrix(matrix2);

    clock_t start = clock();
    matrixMultiplication(matrix1, matrix2, resultMatrix);
    clock_t end = clock();

    double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time for matrix multiplication of size %d*%d: %f seconds.", MATRIX_SIZE, MATRIX_SIZE, timeTaken);
    return 0;
}