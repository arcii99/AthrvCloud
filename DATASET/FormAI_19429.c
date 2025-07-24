//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to our exciting Matrix Operations program!\n");

  // Creating a matrix
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printf("Our Matrix is:\n");  
  // Printing out the matrix
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  // Transposing the matrix
  printf("The Transpose of our Matrix is:\n");
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[j][i]);
    }
    printf("\n");
  }

  printf("\n");

  // Adding two matrices
  printf("Let's add a second matrix to our original matrix...\n");
  int matrix2[3][3] = {{5, 6, 7}, {8, 9, 10}, {11, 12, 13}};
  int result[3][3];
  printf("Our second matrix is:\n");
  // Printing out the second matrix
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  // Adding matrices
  printf("The sum of both matrices is:\n");
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      result[i][j] = matrix[i][j] + matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  // Multiplying two matrices
  printf("Let's multiply a third matrix with our original matrix...\n");
  int matrix3[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  int product[3][3];
  printf("Our third matrix is:\n");
  // Printing out the third matrix
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix3[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  // Multiplying matrices
  printf("The product of both matrices is:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      product[i][j]=0;
      for(int k=0;k<3;k++){
        product[i][j]+=matrix[i][k]*matrix3[k][j];
      }
      printf("%d ",product[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Thank you for using our amazing Matrix Operations program!\n");
  return 0;
}