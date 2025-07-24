//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int rows, cols, i, j;

   printf("Enter the number of rows and columns:\n");
   scanf("%d %d", &rows, &cols);

   // initialize a 2D array
   int matrix[rows][cols];

   // take input from user
   printf("Enter the elements of the matrix:\n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("The matrix is:\n");
   // print the matrix
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   return 0;
}