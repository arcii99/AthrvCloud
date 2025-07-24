//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(){
  int A[N][N], B[N][N], C[N][N];
  int i, j, k;

  // Initialize matrices A and B with random values
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      A[i][j] = rand() % 100;
      B[i][j] = rand() % 100;
    }
  }

  // Compute matrix multiplication C = A x B
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      C[i][j] = 0;
      for (k = 0; k < N; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // Print the result matrix C
  printf("Result Matrix:\n");
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}