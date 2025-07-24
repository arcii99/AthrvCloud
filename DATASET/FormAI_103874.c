//FormAI DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int n, i, j, space = 1;
   printf("Enter the number of rows:\n");
   scanf("%d",&n);
   space = n - 1;
   for (j = 1; j<=n; j++) {
      for (i = 1; i<=space; i++) {
         printf(" ");
      }
      space--;
      for (i = 1; i<= 2*j-1; i++) {
         printf("*");
      }
      printf("\n");
   }
   space = 1;
   for (j = 1; j<= n - 1; j++) {
      for (i = 1; i<= space; i++) {
         printf(" ");
      }
      space++;
      for (i = 1; i<= 2*(n-j)-1; i++) {
         printf("*");
      }
      printf("\n");
   }
   return 0;
}