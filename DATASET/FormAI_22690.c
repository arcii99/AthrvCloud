//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>

int main() {
  int m = 3, n = 3;
  int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int b[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
  int c[3][3];

  printf("Matrix A:\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("Matrix B:\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  // Matrix Addition
  printf("Matrix Addition (A + B):\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      c[i][j] = a[i][j] + b[i][j];
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Matrix Subtraction
  printf("Matrix Subtraction (A - B):\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      c[i][j] = a[i][j] - b[i][j];
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Matrix Multiplication
  printf("Matrix Multiplication (A * B):\n");
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      c[i][j] = 0;
      for(int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}