//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include<stdio.h>

int main() {
   int n, i, j, k;
   printf("Enter the value for n:");
   scanf("%d",&n);
   for(i = 1; i <= n; i++) {
      for(j = 1; j <= n-i; j++)
         printf(" ");
      for(k = 1; k <= 2 * i - 1; k++)
         printf("*");
      printf("\n");
   }
   return 0;
}