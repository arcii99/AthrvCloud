//FormAI DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>

// Function prototypes
void add_matrix(int A[][3], int B[][3], int C[][3]);
void multiply_matrix(int A[][3], int B[][3], int C[][3]);

int main() {
  int i, j;
  int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrixB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int matrixC[3][3];

  printf("Matrix A:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrixA[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrixB[i][j]);
    }
    printf("\n");
  }

  // Perform matrix addition
  add_matrix(matrixA, matrixB, matrixC);
  printf("\nMatrix C (Sum of A and B):\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }

  // Perform matrix multiplication
  multiply_matrix(matrixA, matrixB, matrixC);
  printf("\nMatrix C (Product of A and B):\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }

  return 0;
}

// Function definitions
void add_matrix(int A[][3], int B[][3], int C[][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void multiply_matrix(int A[][3], int B[][3], int C[][3]) {
  int i, j, k;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      C[i][j] = 0;
      for (k = 0; k < 3; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}