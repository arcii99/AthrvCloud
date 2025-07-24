//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>

int main() {

  // Matrix 1
  int matrix1[3][3] = {{2, 4, 6},
                       {3, 5, 7},
                       {2, 4, 8}};

  // Matrix 2
  int matrix2[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

  // Matrix 3 (results matrix)
  int matrix3[3][3];

  // Operations:
  // Multiplication
  printf("Multiplication:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int sum = 0;
      for(int k = 0; k < 3; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      matrix3[i][j] = sum;
      printf("%d\t", matrix3[i][j]);
    }
    printf("\n");
  }

  // Transpose
  printf("\nTranspose:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      matrix3[j][i] = matrix1[i][j];
      printf("%d\t", matrix3[j][i]);
    }
    printf("\n");
  }

  // Addition and Subtraction
  printf("\nAddition and Subtraction:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d\t", matrix3[i][j]);
    }
    printf("\n");
  }

  return 0;
}