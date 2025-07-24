//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>

int main() {
   int i, j, rows=5;
   printf("This program generates a unique C graph representation!");

   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }

   for (i = rows-1; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }

   return 0;
}