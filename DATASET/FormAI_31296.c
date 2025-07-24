//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

  int matrix[5][5];
  int sum = 0;

  // Fill matrix with random numbers
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix[i][j] = rand() % 1000;
    }
  }

  // Print the matrix
  printf("The matrix:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Compute the sum of the diagonal elements
  for (int i = 0; i < 5; i++) {
    sum += matrix[i][i];
  }

  // Print the sum
  printf("\nThe sum of the diagonal elements: %d\n", sum);

  // Transpose the matrix
  printf("\nThe transposed matrix:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", matrix[j][i]);
    }
    printf("\n");
  }

  // Find the maximum element in the matrix
  int max = matrix[0][0];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }

  // Print the max element
  printf("\nThe maximum element in the matrix: %d\n", max);

  return 0;
}