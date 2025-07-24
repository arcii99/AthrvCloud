//FormAI DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define matrix dimensions
#define ROWS 3
#define COLS 3

// Function prototypes
void printMatrix(int matrix[ROWS][COLS]);
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void scalarProduct(int scalar, int matrix[ROWS][COLS], int result[ROWS][COLS]);

int main() {
  // Define matrices
  int matrix1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  int matrix2[ROWS][COLS] = { {-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9} };
  int result1[ROWS][COLS], result2[ROWS][COLS], result3[ROWS][COLS];

  // Add matrices
  addMatrices(matrix1, matrix2, result1);

  // Print result
  printf("Matrix 1:\n");
  printMatrix(matrix1);
  printf("Matrix 2:\n");
  printMatrix(matrix2);
  printf("Matrix 1 + Matrix 2:\n");
  printMatrix(result1);

  // Scalar product
  scalarProduct(2, matrix1, result2);
  scalarProduct(-3, matrix2, result3);

  // Print results
  printf("2 * Matrix 1:\n");
  printMatrix(result2);
  printf("-3 * Matrix 2:\n");
  printMatrix(result3);

  return 0;
}

void printMatrix(int matrix[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void scalarProduct(int scalar, int matrix[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = scalar * matrix[i][j];
    }
  }
}