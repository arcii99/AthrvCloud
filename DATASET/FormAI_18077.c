//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include<stdio.h>

int main() {

  // greet the user
  printf("Hello there, let's do some matrix operations!\n");

  // initialize the matrices
  int matrix1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  int matrix2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
  
  // print out the matrices
  printf("matrix1:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("matrix2:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // add the matrices together
  int sum_matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  // print out the sum matrix
  printf("sum_matrix (matrix1 + matrix2):\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", sum_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // transpose of matrix1
  int transpose_matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      transpose_matrix[i][j] = matrix1[j][i];
    }
  }

  // print out the transposed matrix
  printf("transpose_matrix (transpose of matrix1):\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", transpose_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // exit the program
  printf("That was fun! Thanks for doing matrix operations with me :)\n");
  return 0;
}