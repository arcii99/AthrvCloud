//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main() {
  int matrix1[2][2] = {{1, 2}, {3, 4}};
  int matrix2[2][2] = {{5, 6}, {7, 8}};
  int result[2][2];

  printf("Matrix 1:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("Matrix 2:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  // Addition
  printf("Addition:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Subtraction
  printf("Subtraction:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Multiplication
  printf("Multiplication:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      result[i][j] = 0;
      for(int k = 0; k < 2; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Transpose
  printf("Transpose of Matrix 1:\n");
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", matrix1[j][i]);
    }
    printf("\n");
  }

  return 0;
}