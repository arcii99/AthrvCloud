//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main() {
   int rows, i, j, k, count = 0;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   for(i = rows; i >= 1; i--) {
      for(j = 1; j <= i; j++) {
         printf("%d ", j);
         count++;
      }
      for(k = count; k < rows * 2 - 1; k++) {
         printf("* ");
      }
      count = 0;
      printf("\n");
   }

   count = 0;
   for(i = 1; i <= rows; i++) {
      for(j = 1; j <= i; j++) {
         printf("%d ", j);
         count++;
      }
      for(k = count; k < rows * 2 - 1; k++) {
         printf("* ");
      }
      count = 0;
      printf("\n");
   }
   
   return 0;
}