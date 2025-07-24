//FormAI DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
  int sumMatrix[ROWS][COLS];

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  printf("\nMatrix1 + Matrix2:\n");
  printMatrix(sumMatrix);
}

void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
  int productMatrix[ROWS][COLS];
  
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      productMatrix[i][j] = 0;

      for(int k = 0; k < COLS; k++) {
        productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  printf("\nMatrix1 * Matrix2:\n");
  printMatrix(productMatrix);
}

int main() {
  int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

  printf("Matrix1:\n");
  printMatrix(matrix1);

  printf("\nMatrix2:\n");
  printMatrix(matrix2);

  addMatrices(matrix1, matrix2);

  multiplyMatrices(matrix1, matrix2);

  return 0;
}