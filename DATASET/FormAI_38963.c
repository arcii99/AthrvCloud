//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>

// This is going to be an energetic example of how powerful matrix operations are!

int main() {
  printf("Are you ready to unleash the power of matrix operations?! Let's do this!\n");

  // First, let's define our matrices
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[3][3];

  // Let's print out our starting matrices
  printf("Matrix1:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Matrix2:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Now, let's perform some operations!

  // Addition
  printf("Adding the two matrices...\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  // Let's print out the result
  printf("Result of matrix addition:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Subtraction
  printf("Subtracting Matrix2 from Matrix1...\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  // Let's print out the result
  printf("Result of matrix subtraction:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Multiplication
  printf("Multiplying the two matrices...\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Let's print out the result
  printf("Result of matrix multiplication:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("WOW! Wasn't that amazing?! Matrix operations are so powerful and fun to perform!\n");

  return 0;
}