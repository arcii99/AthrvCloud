//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

int main() {
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int resultMatrix[3][3] = {0};
  int i, j, k;

  //Matrix Addition
  printf("Matrix Addition\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", resultMatrix[i][j]);
    }
    printf("\n");
  }

  //Matrix Subtraction
  printf("\nMatrix Subtraction\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ", resultMatrix[i][j]);
    }
    printf("\n");
  }

  //Matrix Multiplication
  printf("\nMatrix Multiplication\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", resultMatrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}