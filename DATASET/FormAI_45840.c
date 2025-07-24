//FormAI DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Matrix Operations program!\n");

  // Get user input for matrix size
  int size;
  printf("Enter the size of the matrix: ");
  scanf("%d", &size);

  // Declare matrices
  int A[size][size];
  int B[size][size];
  int C[size][size];

  // Get user input for matrix A
  printf("Enter the elements of matrix A:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  // Get user input for matrix B
  printf("Enter the elements of matrix B:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("B[%d][%d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  // Matrix addition
  printf("\nPerforming matrix addition...\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[i][j] = A[i][j] + B[i][j];
      printf("C[%d][%d] = %d\n", i, j, C[i][j]);
    }
  }

  // Matrix subtraction
  printf("\nPerforming matrix subtraction...\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[i][j] = A[i][j] - B[i][j];
      printf("C[%d][%d] = %d\n", i, j, C[i][j]);
    }
  }

  // Matrix multiplication
  printf("\nPerforming matrix multiplication...\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[i][j] = 0;
      for (int k = 0; k < size; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
      printf("C[%d][%d] = %d\n", i, j, C[i][j]);
    }
  }

  // Matrix transpose
  printf("\nPerforming matrix transpose...\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[i][j] = A[j][i];
      printf("C[%d][%d] = %d\n", i, j, C[i][j]);
    }
  }

  // Goodbye message
  printf("\nThank you for using the Matrix Operations program! Goodbye!\n");

  return 0;
}