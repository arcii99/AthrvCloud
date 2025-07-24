//FormAI DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>

#define ROWS 3
#define COLS 3

void displayMatrix(int matrix[][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

void multiplyByScalar(int scalar, int matrix[][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++)
      matrix[i][j] *= scalar;
  }
}

void addMatrices(int matrixA[][COLS], int matrixB[][COLS], int result[][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++)
      result[i][j] = matrixA[i][j] + matrixB[i][j];
  }
}

int main() {
  int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[ROWS][COLS];

  printf("Matrix A:\n");
  displayMatrix(matrixA);

  printf("Matrix B:\n");
  displayMatrix(matrixB);

  printf("Matrix A multiplied by scalar 2:\n");
  multiplyByScalar(2, matrixA);
  displayMatrix(matrixA);

  printf("Adding Matrix A and B:\n");
  addMatrices(matrixA, matrixB, result);
  displayMatrix(result);

  return 0;
}