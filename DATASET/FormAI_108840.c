//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

int main() {
   int i, j, k;

   //First half of C
   for(i = 0; i < 5; i++) {
      printf("*");
      for(j = 0; j < i; j++)
         printf(" ");
      printf("*\n");
   }

   k = 0;
   //Second half of C
   for(i = 5; i > 0; i--) {
      for(j = k; j > 0; j--)
         printf(" ");
      printf("*");
      for(j = i; j < 5; j++)
         printf(" ");
      printf("*\n");
      k++;
   }

   return 0;
}