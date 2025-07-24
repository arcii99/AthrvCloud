//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int num, i, j, k;
   printf("Enter a number: ");
   scanf("%d", &num);

   for (i = 1; i <= num; i++) {
      for (j = 1; j <= num-i; j++) {
         printf(" ");
      }

      for (k = 1; k <= i*2-1; k++) {
         printf("*");
      }

      printf("\n");
   }

   return 0;
}