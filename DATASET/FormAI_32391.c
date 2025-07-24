//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

int main() {
   int size, row, col, space;

   printf("Enter the size of the pattern: ");
   scanf("%d", &size);

   /* Upper half of the pattern */
   for (row = 0; row < size/2; row++) {
      for (space = 0; space < size/2 - row; space++)
         printf(" ");
      for (col = 0; col < row*2 + 1; col++)
         printf("*");
      printf("\n");
   }

   /* Middle row for odd sized patterns */
   if (size % 2 == 1) {
      for (col = 0; col < size; col++)
         printf("*");
      printf("\n");
   }

   /* Lower half of the pattern */
   for (row = size/2 + 1; row < size; row++) {
      for (space = 0; space < row - size/2; space++)
         printf(" ");
      for (col = 0; col < (size-row)*2 - 1; col++)
         printf("*");
      printf("\n");
   }

   return 0;
}