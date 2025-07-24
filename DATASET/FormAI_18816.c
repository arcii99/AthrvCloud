//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>

int main() {
   int matrix1[10][10], matrix2[10][10], result[10][10];
   int rows1, cols1, rows2, cols2, i, j, k;
    
   printf("Enter number of rows for matrix 1: ");
   scanf("%d", &rows1);
   printf("Enter number of columns for matrix 1: ");
   scanf("%d", &cols1);
   
   printf("Enter number of rows for matrix 2: ");
   scanf("%d", &rows2);
   printf("Enter number of columns for matrix 2: ");
   scanf("%d", &cols2);

   if(cols1 != rows2) {
      printf("Invalid matrix dimensions\n");
      return 0;
   }

   printf("Enter values for matrix 1:\n");
   for(i=0; i<rows1; i++) {
      for(j=0; j<cols1; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("Enter values for matrix 2:\n");
   for(i=0; i<rows2; i++) {
      for(j=0; j<cols2; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }

   //Matrix Multiplication
   for(i=0; i<rows1; i++) {
      for(j=0; j<cols2; j++) {
         result[i][j] = 0;
         for(k=0; k<cols1; k++) {
            result[i][j] += matrix1[i][k] * matrix2[k][j];
         }
      }
   }

   printf("\n------------------\nResult Matrix:\n");
   for(i=0; i<rows1; i++) {
      for(j=0; j<cols2; j++) {
         printf("%d ", result[i][j]);
      }
      printf("\n");
   }

   return 0;
}