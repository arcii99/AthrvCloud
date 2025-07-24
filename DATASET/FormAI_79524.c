//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int main() {
  int i, j;
  int matrix1[ROW][COL] = { {2, 4, 6}, {8, 10, 12}, {14, 16, 18} };
  int matrix2[ROW][COL] = { {1, 3, 5}, {7, 9, 11}, {13, 15, 17} };
  int matrixSum[ROW][COL], matrixDifference[ROW][COL], matrixProduct[ROW][COL];

  printf("Matrix 1:\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix 2:\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Sum:\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", matrixSum[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Difference:\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      matrixDifference[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ", matrixDifference[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Product:\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      matrixProduct[i][j] = 0;
      for (int k = 0; k < ROW; k++) {
        matrixProduct[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", matrixProduct[i][j]);
    }
    printf("\n");
  }

  return 0;
}