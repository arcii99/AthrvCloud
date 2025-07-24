//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
   int rows = 6;
   int cols = 6;
   int i, j;

   // Print top half of pattern
   for (i = 0; i < rows / 2; i++) {
      for (j = 0; j < cols - i; j++) {
         if (j == i || j == cols - i - 1) {
            printf("*");
         } else if (j > i && j < cols - i - 1) {
            printf("-");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   // Print middle row of pattern
   for (j = 0; j < cols; j++) {
      if (j == cols / 2) {
         printf("*");
      } else {
         printf("-");
      }
   }
   printf("\n");

   // Print bottom half of pattern
   for (i = rows / 2 - 1; i >= 0; i--) {
      for (j = cols - i - 1; j >= 0; j--) {
         if (j == i || j == cols - i - 1) {
            printf("*");
         } else if (j > i && j < cols - i - 1) {
            printf("-");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   return 0;
}