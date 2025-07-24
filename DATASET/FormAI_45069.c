//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix1[100][100], matrix2[100][100], result[100][100];
  int rows1, rows2, cols1, cols2;

  printf("Welcome to the Matrix Operations Program!\n");
  printf("Let's start by creating the first matrix.\n");

  // Asking for the matrix1 input
  printf("Enter the number of rows and columns for matrix1, separated by a space: ");
  scanf("%d %d", &rows1, &cols1);

  printf("Enter the elements of matrix1:\n");
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  // Asking for the matrix2 input
  printf("\nGreat! Now let's create the second matrix.\n");
  printf("Enter the number of rows and columns for matrix2, separated by a space: ");
  scanf("%d %d", &rows2, &cols2);

  printf("Enter the elements of matrix2:\n");
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < cols2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Displaying matrix1 and matrix2
  printf("\nHere are your matrices:\n");
  printf("Matrix1:\n");
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix2:\n");
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < cols2; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  // Performing matrix addition
  if (rows1 == rows2 && cols1 == cols2) {
    printf("\nLet's add these matrices together!\n");

    for (int i = 0; i < rows1; i++) {
      for (int j = 0; j < cols1; j++) {
        result[i][j] = matrix1[i][j] + matrix2[i][j];
      }
    }

    printf("Here is the result of the addition:\n");
    for (int i = 0; i < rows1; i++) {
      for (int j = 0; j < cols1; j++) {
        printf("%d ", result[i][j]);
      }
      printf("\n");
    }
  }

  // Performing matrix multiplication
  if (cols1 == rows2) {
    printf("\nLet's multiply these matrices together!\n");

    for (int i = 0; i < rows1; i++) {
      for (int j = 0; j < cols2; j++) {
        result[i][j] = 0;

        for (int k = 0; k < cols1; k++) {
          result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }

    printf("Here is the result of the multiplication:\n");
    for (int i = 0; i < rows1; i++) {
      for (int j = 0; j < cols2; j++) {
        printf("%d ", result[i][j]);
      }
      printf("\n");
    }
  }

  // Error message if matrices cannot be added or multiplied
  if (rows1 != rows2 || cols1 != cols2) {
    printf("\nOops, these matrices cannot be added together because they have different dimensions.\n");
  }
  if (cols1 != rows2) {
    printf("\nOops, these matrices cannot be multiplied together because the number of columns in matrix1 does not match the number of rows in matrix2.\n");
  }

  printf("\nThank you for using the Matrix Operations Program! Have a great day!\n");
  return 0;
}