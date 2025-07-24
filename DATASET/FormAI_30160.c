//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Let's do some Matrix operations with a cheerful twist! \n");

  // Creating matrices
  int matrix_1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  int matrix_2[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
  };

  // Printing the matrices
  printf("Matrix 1: \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix_1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix 2: \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix_2[i][j]);
    }
    printf("\n");
  }

  // Adding the matrices
  int added_matrix[3][3];
  printf("\nAdding Matrix 1 and Matrix 2...\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      added_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
  }

  // Printing the added matrix
  printf("\nAdded Matrix: \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", added_matrix[i][j]);
    }
    printf("\n");
  }

  // Multiplying the matrices
  int multiplied_matrix[3][3];
  printf("\nMultiplying Matrix 1 and Matrix 2...\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int sum = 0;
      for(int k = 0; k < 3; k++) {
        sum += matrix_1[i][k] * matrix_2[k][j];
      }
      multiplied_matrix[i][j] = sum;
    }
  }

  // Printing the multiplied matrix
  printf("\nMultiplied Matrix: \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", multiplied_matrix[i][j]);
    }
    printf("\n");
  }

  // Transposing the matrix
  int transposed_matrix[3][3];
  printf("\nTransposing Added Matrix...\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      transposed_matrix[j][i] = added_matrix[i][j];
    }
  }

  // Printing the transposed matrix
  printf("\nTransposed Matrix: \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", transposed_matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nThat was fun! \n");
  
  return 0;
}