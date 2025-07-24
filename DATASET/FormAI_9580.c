//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main() {
  printf("Welcome to the Matrix Operations Program!\n");

  // Initialize matrices
  int matrix1[3][3] = {{2, 3, 4}, {1, 5, 2}, {7, 6, 8}};
  int matrix2[3][3] = {{5, 1, 0}, {2, 3, 7}, {4, 6, 9}};

  printf("Matrix 1:\n");
  // Display first matrix
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Matrix 2:\n");
  // Display second matrix
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Addition of two matrices:\n");
  // Perform matrix addition
  int result[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Multiplication of two matrices:\n");
  // Perform matrix multiplication
  int product[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      product[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        product[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", product[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Transpose of Matrix 1:\n");
  // Perform matrix transpose
  int transpose[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transpose[j][i] = matrix1[i][j];
    }
  }

  // Print transposed matrix
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Thanks for using the Matrix Operations Program!\n");
  
  return 0;
}