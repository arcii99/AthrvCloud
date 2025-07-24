//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>

int main() {
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Create a 3x3 matrix
  int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}; // Create another 3x3 matrix
  int result[3][3]; // Create a third 3x3 matrix to store the result of matrix operations
  
  printf("Matrix 1:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix1[i][j]); // Display matrix1
    }
    printf("\n");
  }
  
  printf("\nMatrix 2:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]); // Display matrix2
    }
    printf("\n");
  }
  
  // Perform matrix addition
  printf("\nMatrix Addition:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j]; // Add corresponding elements of matrix1 and matrix2
      printf("%d ", result[i][j]); // Display the result of addition
    }
    printf("\n");
  }
  
  // Perform matrix subtraction
  printf("\nMatrix Subtraction:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtract corresponding elements of matrix1 and matrix2
      printf("%d ", result[i][j]); // Display the result of subtraction
    }
    printf("\n");
  }
  
  // Perform matrix multiplication
  printf("\nMatrix Multiplication:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int sum = 0;
      for(int k = 0; k < 3; k++) {
        sum += matrix1[i][k] * matrix2[k][j]; // Multiply corresponding elements of matrix1 and matrix2 and add them
      }
      result[i][j] = sum;
      printf("%d ", result[i][j]); // Display the result of multiplication
    }
    printf("\n");
  }
  
  return 0;
}