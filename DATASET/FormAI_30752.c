//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

int main() {
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int i, j, sum;

  // Initialize matrix with random values
  srand(time(NULL));
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] = rand();
    }
  }

  // Calculate row sums in parallel
  #pragma omp parallel for schedule(static) reduction(+:sum)
  for (i = 0; i < MATRIX_SIZE; i++) {
    sum = 0;
    for (j = 0; j < MATRIX_SIZE; j++) {
      sum += matrix[i][j];
    }
    printf("Row %d sum: %d\n", i, sum);
  }

  // Calculate column sums in parallel
  #pragma omp parallel for schedule(static) reduction(+:sum)
  for (j = 0; j < MATRIX_SIZE; j++) {
    sum = 0;
    for (i = 0; i < MATRIX_SIZE; i++) {
      sum += matrix[i][j];
    }
    printf("Column %d sum: %d\n", j, sum);
  }

  return 0;
}