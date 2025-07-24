//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>

int main() {
   int n, i, j, row, col;
   printf("Enter the number of rows and columns of the matrix:\n");
   scanf("%d %d", &row, &col);

   int matrix[row][col];

   printf("Enter the elements of the matrix:\n");

   for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("\nMatrix before Transpose:\n");

   for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
         printf("%d\t", matrix[i][j]);
      }
      printf("\n");
   }

   printf("\nMatrix after Transpose:\n");

   for(i = 0; i < col; i++){
      for(j = 0; j < row; j++){
         printf("%d\t", matrix[j][i]);
      }
      printf("\n");
   }

   return 0;
}