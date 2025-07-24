//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS 3

// Function prototypes
void printMatrix(int matrix[][COLUMNS], int rows, int columns);
void addMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns);
void subtractMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns);
void multiplyMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns);

int main() {
  int matrix1[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[ROWS][COLUMNS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[ROWS][COLUMNS];

  // Add the matrices
  addMatrices(matrix1, matrix2, result, ROWS, COLUMNS);
  printf("Matrix1 + Matrix2:\n");
  printMatrix(result, ROWS, COLUMNS);

  // Subtract the matrices
  subtractMatrices(matrix1, matrix2, result, ROWS, COLUMNS);
  printf("Matrix1 - Matrix2:\n");
  printMatrix(result, ROWS, COLUMNS);

  // Multiply the matrices
  multiplyMatrices(matrix1, matrix2, result, ROWS, COLUMNS);
  printf("Matrix1 * Matrix2:\n");
  printMatrix(result, ROWS, COLUMNS);

  return 0;
}

// Function to print a matrix
void printMatrix(int matrix[][COLUMNS], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to add two matrices
void addMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  }
}

// Function to subtract two matrices
void subtractMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result[i][j] = A[i][j] - B[i][j];
    }
  }
}

// Function to multiply two matrices
void multiplyMatrices(int A[][COLUMNS], int B[][COLUMNS], int result[][COLUMNS], int rows, int columns) {
  int sum;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      sum = 0;
      for (int k = 0; k < rows; k++) {
        sum += A[i][k] * B[k][j];
      }
      result[i][j] = sum;
    }
  }
}