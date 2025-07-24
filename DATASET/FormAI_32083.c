//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to my super exciting C Matrix Operations program!\n");

  // Initializing matrices
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int C[3][3];
  int i, j;

  printf("Matrix A:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  // Matrix addition
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  printf("\nMatrix C (A + B):\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Matrix subtraction
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }

  printf("\nMatrix C (A - B):\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Matrix multiplication
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      C[i][j] = 0;
      for(int k=0; k<3; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  printf("\nMatrix C (A * B):\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  printf("\nThat's it folks! I hope you enjoyed my program.\n");

  return 0;
}