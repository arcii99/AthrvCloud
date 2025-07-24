//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include<stdio.h>

int main() {
   int n = 5; // number of rows to be printed
   int i, j; // loop variables
   
   // loop to print the upper half of the pattern
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j == 0 || j == n-1 || i == 0)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }
   
   // loop to print the lower half of the pattern
   for (i = n-1; i > 0; i--) {
      for (j = 0; j < n; j++) {
         if (i == 1 || j == 0 || j == n-1)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }
   
   return 0;
}