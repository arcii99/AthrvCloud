//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>

int main()
{
  int matrix1[3][3] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9} }; 

  int matrix2[3][3] = { {9, 8, 7},
                        {6, 5, 4},
                        {3, 2, 1} }; 

  int add[3][3], sub[3][3], mul[3][3];
  
  printf("Matrix 1:\n");
  for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
          printf("%d ", matrix1[i][j]);
      }
      printf("\n");
  }
  
  printf("\nMatrix 2:\n");
  for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
          printf("%d ", matrix2[i][j]);
      }
      printf("\n");
  }

  // Matrix Addition
  printf("\nMatrix Addition:\n");
  for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
          add[i][j] = matrix1[i][j] + matrix2[i][j];
          printf("%d ", add[i][j]);
      }
      printf("\n");
  }

  // Matrix Subtraction
  printf("\nMatrix Subtraction:\n");
  for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
          sub[i][j] = matrix1[i][j] - matrix2[i][j];
          printf("%d ", sub[i][j]);
      }
      printf("\n");
  }

  // Matrix Multiplication
  printf("\nMatrix Multiplication:\n");
  for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
          mul[i][j] = 0;
          for(int k=0; k<3; k++) {
              mul[i][j] += matrix1[i][k] * matrix2[k][j];
          }
          printf("%d ", mul[i][j]);
      }
      printf("\n");
  }

  return 0;
}