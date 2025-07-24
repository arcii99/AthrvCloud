//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
   int n = 7;
   int i, j;
   
   printf("Let's print a happy C pattern!\n\n");

   for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
         if (i == 1 || i == n || j == 1 || j == n || i == j || j == (n - i + 1))
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }
   
   printf("\nYay! We did it! The C pattern is so happy :)\n");
   return 0;
}