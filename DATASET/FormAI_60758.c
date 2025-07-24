//FormAI DATASET v1.0 Category: Matrix operations ; Style: bold
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int i, j, k;
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrixC[ROWS][COLS], matrixD[ROWS][COLS], matrixE[ROWS][COLS];
    printf("Matrix A:\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
          printf("%d ", matrixA[i][j]);
      }
      printf("\n");
    }
    printf("\nMatrix B:\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
          printf("%d ", matrixB[i][j]);
      }
      printf("\n");
    }

    // Addition of two matrices
    printf("\nAddition of Matrix A and Matrix B:\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
          matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
          printf("%d ", matrixC[i][j]);
      }
      printf("\n");
    }

    // Subtraction of two matrices
    printf("\nSubtraction of Matrix A and Matrix B:\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
          matrixD[i][j] = matrixA[i][j] - matrixB[i][j];
          printf("%d ", matrixD[i][j]);
      }
      printf("\n");
    }

    // Multiplication of two matrices
    printf("\nMultiplication of Matrix A and Matrix B:\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
          for (k = 0; k < COLS; k++) {
              matrixE[i][j] += matrixA[i][k] * matrixB[k][j];
          }
          printf("%d ", matrixE[i][j]);
      }
      printf("\n");
    }
    return 0;
}