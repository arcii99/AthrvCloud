//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main() {
   int matrix1[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
   int matrix2[3][3] = {{1,1,1},
                        {2,2,2},
                        {3,3,3}};   // Creating two 3x3 matrices

   // Displaying the initial matrices
   printf("Initial Matrix1:\n");
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ",matrix1[i][j]);
      }
      printf("\n");
   }

   printf("\nInitial Matrix2:\n");
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ",matrix2[i][j]);
      }
      printf("\n");
   }

   // Matrix addition
   int sum_matrix[3][3];
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
      }
   }

   // Displaying the sum matrix
   printf("\nSum of Matrix1 and Matrix2:\n");
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ",sum_matrix[i][j]);
      }
      printf("\n");
   }

   // Transpose of matrix1
   int transpose_matrix[3][3];
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         transpose_matrix[i][j] = matrix1[j][i];
      }
   }

   // Displaying the transpose matrix
   printf("\nTranspose of Matrix1:\n");
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ",transpose_matrix[i][j]);
      }
      printf("\n");
   }

   // Matrix multiplication
   int product_matrix[3][3] = {0};
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         for(int k=0;k<3;k++) {
            product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
         }
      }
   }

   // Displaying the product matrix
   printf("\nProduct of Matrix1 and Matrix2:\n");
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ",product_matrix[i][j]);
      }
      printf("\n");
   }

   return 0;
}