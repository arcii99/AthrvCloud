//FormAI DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include <stdio.h>

/* This program performs various operations on a 3x3 matrix */

int main() {
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int scalar = 2;
  int determinant;

  /* Printing the original matrix */
  printf("Original Matrix:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  /* Adding the scalar value to each element in the matrix */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      matrix[i][j] += scalar;
    }
  }

  /* Printing the updated matrix */
  printf("Scalar Addition Matrix:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  /* Subtracting the first row from the second row */
  for(int i = 0; i < 3; i++) {
    matrix[1][i] -= matrix[0][i];
  }

  /* Printing the updated matrix */
  printf("Row Subtraction Matrix:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  /* Finding the determinant of the matrix */
  determinant = (matrix[0][0]*matrix[1][1]*matrix[2][2]) +   
                (matrix[1][0]*matrix[2][1]*matrix[0][2]) +
                (matrix[2][0]*matrix[0][1]*matrix[1][2]) -
                (matrix[0][2]*matrix[1][1]*matrix[2][0]) -
                (matrix[1][2]*matrix[2][1]*matrix[0][0]) -
                (matrix[2][2]*matrix[0][1]*matrix[1][0]);

  /* Printing the determinant */
  printf("Determinant of the Matrix: %d\n", determinant);

  return 0;
}