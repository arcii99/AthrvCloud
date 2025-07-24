//FormAI DATASET v1.0 Category: Matrix operations ; Style: high level of detail
/* 
A matrix operation program that generates a random matrix and performs several operations on the matrix. 
The program will display the original matrix, transposed matrix, matrix addition, and matrix multiplication 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3 //Number of rows in matrix
#define COLS 3 //Number of columns in matrix


//Function to generate random values for the matrix
void generateMatrix(int matrix[ROWS][COLS]) {
  int i, j;
  srand(time(NULL)); //Seed the random number generator
 
  for (i=0; i < ROWS; i++) {
     for (j=0; j < COLS; j++) {
        matrix[i][j] = rand()%10; //Generate random integer from 0-9
     }
  }
}


//Function to print the matrix
void printMatrix(int matrix[ROWS][COLS], char* name) {
  int i, j;
  
  printf("\nThe %s matrix is: \n", name);
  for (i=0; i < ROWS; i++) {
     for (j=0; j < COLS; j++) {
        printf("%d ", matrix[i][j]);
     }
     printf("\n");
  }
}


//Function to transpose the matrix (swap rows with columns)
void transposeMatrix(int matrix[ROWS][COLS], int transposed[ROWS][COLS]) {
  int i, j;
   
  for (i=0; i < ROWS; i++) {
     for (j=0; j < COLS; j++) {
        transposed[j][i] = matrix[i][j];
     }
  }
}


//Function to add two matrices
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int added[ROWS][COLS]) {
  int i, j;
   
  for (i=0; i < ROWS; i++) {
     for (j=0; j < COLS; j++) {
        added[i][j] = matrix1[i][j] + matrix2[i][j];
     }
  }
}


//Function to multiply two matrices
void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int product[ROWS][COLS]) {
  int i, j, k;
  int sum;
   
  for (i=0; i < ROWS; i++) {
     for (j=0; j < COLS; j++) {
        sum = 0;
        for (k=0; k < ROWS; k++) {
           sum += matrix1[i][k] * matrix2[k][j];
        }
        product[i][j] = sum;
     }
  }
}


int main() {
   int matrixA[ROWS][COLS];
   int matrixB[ROWS][COLS];
   int transposedA[ROWS][COLS];
   int transposedB[ROWS][COLS];
   int added[ROWS][COLS];
   int product[ROWS][COLS];
   
   printf("Generating matrices...\n");
   generateMatrix(matrixA);
   generateMatrix(matrixB);
   
   printMatrix(matrixA, "A");
   printMatrix(matrixB, "B");
   
   transposeMatrix(matrixA, transposedA);
   transposeMatrix(matrixB, transposedB);
   
   printMatrix(transposedA, "Transposed A");
   printMatrix(transposedB, "Transposed B");
   
   addMatrices(matrixA, matrixB, added);
   printMatrix(added, "Matrix Addition");
   
   multiplyMatrices(matrixA, matrixB, product);
   printMatrix(product, "Matrix Multiplication");
   
   return 0;
}