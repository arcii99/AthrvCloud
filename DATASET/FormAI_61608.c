//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include<stdio.h>

int main() {
   int rows, i, j, k;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   for (i = 1; i <= rows; i++) {
      for (j = rows; j >= i; j--) {
         printf("*");
      }
      printf("\n");
   }

   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
         printf(" ");
      }
      for (k = rows; k >= i; k--) {
         printf("*");
      }
      printf("\n");
   }

   for (i = 1; i <= rows; i++) {
      for (j = rows; j >= i; j--) {
         printf("*");
      }
      printf("\n");
   }

   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i-1; j++) {
         printf(" ");
      }
      for (k = rows-1; k >= i; k--) {
         printf("*");
      }
      printf("\n");
   }

   return 0;
}