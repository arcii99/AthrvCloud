//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   int rows, count = 0, count1 = 0, k = 0;

   printf("Enter number of rows: ");
   scanf("%d", &rows);

   for (int i = 1; i <= rows; ++i) {
      for (int space = 1; space <= rows - i; ++space) {
         printf("  ");
         ++count;
      }

      while (k != 2 * i - 1) {
         if (count <= rows - 1) {
            printf("%d ", i + k);
            ++count;
         } else {
            ++count1;
            printf("%d ", (i + k - 2 * count1));
         }

         ++k;
      }
      count1 = k = count = 0;

      printf("\n");
   }  
   return 0;
}