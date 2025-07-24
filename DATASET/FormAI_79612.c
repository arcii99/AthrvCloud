//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main() {
   int i, j, n;

   printf("Enter the value of n: ");
   scanf("%d", &n);

   // Upper Half
   for (i = 0; i < n; i++) {
      for (j = i; j < n; j++) {
         printf("*");
      }
      printf("\n");
   }

   // Lower Half
   for (i = 1; i < n; i++) {
      for (j = 0; j <= i; j++) {
         printf("*");
      }
      printf("\n");
   }

   return 0;
}