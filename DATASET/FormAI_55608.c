//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

int main() {
  // Declare variables and initialize matrix
  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int sum = 0;
  
  // Print out original matrix
  printf("Original matrix:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  // Find the sum of all elements in the matrix
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      sum += matrix[i][j];
    }
  }
  printf("\nThe sum of all elements in the matrix is %d.\n", sum);
  
  // Transpose the matrix
  printf("\nTransposed matrix:\n");
  int transpose[3][2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      transpose[i][j] = matrix[j][i];
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }
  
  // Find the minimum and maximum element in the matrix
  int min = matrix[0][0];
  int max = matrix[0][0];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[i][j] < min) {
        min = matrix[i][j];
      }
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }
  printf("\nThe minimum element in the matrix is %d and the maximum is %d.\n", min, max);
  
  // Multiply each element in the matrix by 2 and print out the new matrix
  printf("\nMatrix multiplied by 2:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] *= 2;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}