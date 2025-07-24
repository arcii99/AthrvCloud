//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main () {
   int series, row, column, count = 0;

   printf("Enter the number of rows in the pattern: ");
   scanf("%d", &series);

   for(row = 1; row <= series; row++) {
      for(column = 1; column <= row; column++) {
         printf("* ");
      }
      printf("\n");
      count++;
   }

   for(row = 1; row <= series-1; row++) {
      for(column = series-1; column >= row; column--) {
         printf("* ");
      }
      printf("\n");
      count++;
   }
   
   printf("Total number of lines printed: %d", count);
   
   return 0;
}