//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main() {
   int i, j, rows, columns;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   printf("Enter the number of columns: ");
   scanf("%d", &columns);

   // Nested loop to print C pattern
   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= columns; j++) {
         if (i == 1 || i == rows || j == 1)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }

   return 0;
}