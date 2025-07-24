//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>

int main() {
   int n, i, j, k;
   
   printf("Enter the value of n: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {
      for (j = n; j > i; j--) {
         printf(" ");
      }
      
      for (k = 1; k <= i; k++) {
         printf("* ");
      }
      
      printf("\n");
   }

   return 0;
}