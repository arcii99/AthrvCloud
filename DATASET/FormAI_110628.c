//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
/***************************************************************
* Matrix Operations Example Program
* 
* This program performs basic operations on matrices, such as 
* addition, subtraction, multiplication, and determination of 
* transpose and determinant.
*
* Written by: [Your Name]
* Date: [Current Date]
***************************************************************/

#include <stdio.h>

// Function to add two matrices
void add_matrices(int m, int n, int arr1[m][n], int arr2[m][n]){
  printf("\n Addition of the two matrices: \n");
  int res[m][n]; // array to store the result
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = arr1[i][j] + arr2[i][j];
      printf("%d ", res[i][j]); // printing the result matrix
    }
    printf("\n"); // moving to the next row
  }
}

// Function to subtract two matrices
void sub_matrices(int m, int n, int arr1[m][n], int arr2[m][n]){
  printf("\n Subtraction of the two matrices: \n");
  int res[m][n]; // array to store the result
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = arr1[i][j] - arr2[i][j];
      printf("%d ", res[i][j]); // printing the result matrix
    }
    printf("\n"); // moving to the next row
  }
}

// Function to multiply two matrices
void multiply_matrices(int m1, int n1, int m2, int n2, int arr1[m1][n1], int arr2[m2][n2]){
  if(n1 != m2){
    printf("\n Cannot perform multiplication. Number of columns of first matrix should be equal to number of rows of second matrix.");
  } else {
    printf("\n Multiplication of the two matrices: \n");
    int res[m1][n2]; // array to store the result
    for(int i = 0; i < m1; i++){
      for(int j = 0; j < n2; j++){
        res[i][j] = 0; // initializing the element to 0 
        for(int k = 0; k < n1; k++){
          res[i][j] += arr1[i][k] * arr2[k][j];
        }
        printf("%d ", res[i][j]); // printing the result matrix
      }
      printf("\n"); // moving to the next row
    }
  }
}

// Function to determine the transpose of a matrix
void transpose_matrix(int m, int n, int arr[m][n]){
  printf("\n Transpose of the matrix: \n");
  int res[n][m]; // array to store the result
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      res[i][j] = arr[j][i];
      printf("%d ", res[i][j]); // printing the result matrix
    }
    printf("\n"); // moving to the next row
  }
}

// Function to determine the determinant of a matrix
int determinant_matrix(int n, int arr[n][n]){
  if(n == 1){
    return arr[0][0];
  }
  if(n == 2){
    return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
  }
  int det = 0;
  for(int i = 0; i < n; i++){
    int temp[n-1][n-1]; // array to store the sub-matrix
    for(int j = 1; j < n; j++){
      int k = 0;
      for(int l = 0; l < n; l++){
        if(l != i){
          temp[j-1][k++] = arr[j][l];
        }
      }
    }
    det += arr[0][i] * determinant_matrix(n-1, temp) * ((i%2 == 0) ? 1 : -1); // recursive call to determine the determinant of sub-matrix
  }
  return det;
}

int main() {
  int rows, cols;
  printf("Enter the number of rows in the matrix: ");
  scanf("%d", &rows);
  printf("Enter the number of columns in the matrix: ");
  scanf("%d", &cols);

  int matrix1[rows][cols], matrix2[rows][cols];
  printf("\n Enter the elements of the first matrix: \n");
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("Element[%d][%d]: ", i+1, j+1);
      scanf("%d", &matrix1[i][j]);
    }
  }
  printf("\n Enter the elements of the second matrix: \n");
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("Element[%d][%d]: ", i+1, j+1);
      scanf("%d", &matrix2[i][j]);
    }
  }

  add_matrices(rows, cols, matrix1, matrix2);
  sub_matrices(rows, cols, matrix1, matrix2);
  multiply_matrices(rows, cols, rows, cols, matrix1, matrix2);
  transpose_matrix(rows, cols, matrix1);
  printf("\n Determinant of the first matrix is: %d", determinant_matrix(rows, matrix1));

  return 0;
}