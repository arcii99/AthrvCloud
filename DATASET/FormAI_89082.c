//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main() {
   int rows, i, j, space=1;
   printf("Enter number of rows: ");
   scanf("%d",&rows);

   space = rows-1;
   for (j=1; j<=rows; j++) {
      for (i=1; i<=space; i++) {
         printf(" ");
      }
      space--;
      for (i=1; i<=2*j-1; i++) {
         printf("*");
      }
      printf("\n");
   }

   space = 1;
   for (j=1; j<=rows-1; j++) {
      for (i=1; i<=space; i++) {
         printf(" ");
      }
      space++;
      for (i=1; i<=2*(rows-j)-1; i++) {
         printf("*");
      }
      printf("\n");
   }
   return 0;
}