//FormAI DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>

int main() {
   int n = 7, spaces = n - 1;
   for (int i = 1; i <= n; i++) {

      for (int j = 1; j <= spaces; j++)
         printf(" ");

      spaces--;

      for (int j = 1; j <= 2 * i - 1; j++)
         printf("*");

      printf("\n");
   }

   spaces = 1;

   for (int i = 1; i <= n - 1; i++) {

      for (int j = 1; j <= spaces; j++)
         printf(" ");

      spaces++;

      for (int j = 1; j <= 2 * (n - i) - 1; j++)
         printf("*");

      printf("\n");
   }

   return 0;
}