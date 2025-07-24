//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main() {
   int rows, i, j, k;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   for (i = 1; i <= rows; i++) {
      for (j = i; j <= rows - 1; j++) {
         printf(" ");
      }
      for (k = 1; k <= i; k++) {
         printf("* ");
      }
      printf("\n");
   }

   for (i = rows - 1; i >= 1; i--) {
      for (j = rows - 1; j >= i; j--) {
         printf(" ");
      }
      for (k = i; k >= 1; k--) {
         printf("* ");
      }
      printf("\n");
   }

   return 0;
}