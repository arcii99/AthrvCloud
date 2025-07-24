//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, j, k;
   int rows = 10, cols = 5;
   int c[rows][cols];
   srand(time(NULL));

   // Filling in random values for the matrix
   for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
         c[i][j] = rand() % 100;
      }
   }

   // Printing out the matrix before sorting
   printf("Original matrix:\n");
   for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
         printf("%d\t", c[i][j]);
      }
      printf("\n");
   }

   // Sorting the matrix
   for(k = 0; k < cols; k++) {
      for(i = 0; i < rows - 1; i++) {
         for(j = 0; j < rows - i - 1; j++) {
            if(c[j][k] > c[j+1][k]) {
               // Swapping elements in the matrix
               int temp = c[j][k];
               c[j][k] = c[j+1][k];
               c[j+1][k] = temp;
            }
         }
      }
   }

   // Printing out the sorted matrix
   printf("\nSorted matrix:\n");
   for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
         printf("%d\t", c[i][j]);
      }
      printf("\n");
   }

   return 0;
}