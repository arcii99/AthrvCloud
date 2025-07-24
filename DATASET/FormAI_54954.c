//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {
   int i, j, k;

   // Print the upper half of the pattern
   for (i = 1; i <= 5; ++i) {
      k = i;
      for (j = 1; j <= 9; ++j) {
         if (j >= 6 - i && j <= 4 + i) {
            printf("%d", k);
            // Increment k for the next iteration
            ++k;
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   // Print the lower half of the pattern
   for (i = 4; i >= 1; --i) {
      k = i;
      for (j = 1; j <= 9; ++j) {
         if (j >= 6 - i && j <= 4 + i) {
            printf("%d", k);
            // Increment k for the next iteration
            ++k;
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   // Print a closing message
   printf("Yay! The pattern is complete!\n");

   return 0;
}