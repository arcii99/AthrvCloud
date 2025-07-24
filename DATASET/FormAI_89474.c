//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main() {
   int rows, i, j;
   printf("Enter number of rows: ");
   scanf("%d", &rows);

   // Upper part of the pattern
   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
         printf("%d", j);
      }
      for (j = i * 2; j <= rows * 2; j++) {
         printf(" ");
      }
      for (j = i; j >= 1; j--) {
         printf("%d", j);
      }
      printf("\n");
   }

   // Lower part of the pattern
   for (i = rows - 1; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
         printf("%d", j);
      }
      for (j = i * 2; j <= rows * 2; j++) {
         printf(" ");
      }
      for (j = i; j >= 1; j--) {
         printf("%d", j);
      }
      printf("\n");
   }
   return 0;
}