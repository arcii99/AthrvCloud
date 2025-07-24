//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main() {
   int i, j, n;

   printf("Enter the number of rows: ");
   scanf("%d", &n);

   for(i = 0; i < n; i++) {
      for(j = 0; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }
   
   for(i = n-1; i >= 0; i--) {
      for(j = 0; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }

   return 0;
}