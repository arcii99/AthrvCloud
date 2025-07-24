//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
   int i, j, n;

   printf("Enter the number of rows: ");
   scanf("%d", &n);

   // Top half of the pattern
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= n - i; j++)
         printf(" ");
      for (j = 1; j <= i; j++)
         printf("* ");
      printf("\n");
   }

   // Bottom half of the pattern
   for (i = n-1; i >= 1; i--) {
      for (j = 1; j <= n - i; j++)
         printf(" ");
      for (j = 1; j <= i; j++)
         printf("* ");
      printf("\n");
   }

   return 0;
}

/* 
Sample output for n=5:
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *
*/