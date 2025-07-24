//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include<stdio.h>

int main() {
   int i, j, n;

   printf("Enter the value of n: ");
   scanf("%d", &n);

   for(i=0; i<n; i++) {
      for(j=i; j<n; j++) {
         printf("*");
      }
      printf("\n");
   }
   for(i=2; i<=n; i++) {
      for(j=0; j<i; j++) {
         printf("*");
      }
      printf("\n");
   }
   return 0;
}