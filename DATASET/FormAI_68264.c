//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include<stdio.h>

int main() {
   int i, j, k, n; // Variables for loops and input
   printf("Enter a value for n: ");
   scanf("%d", &n); // Taking input from user
   for(i = n; i >= 1; i--) {
      for(j = n-1; j >= i; j--) {
         printf(" ");
      }
      for(k = 1; k <= i*2-1; k++) {
         printf("*");
      }
      printf("\n");
   }
   for(i = 2; i <= n; i++) {
      for(j = n-1; j >= i; j--) {
         printf(" ");
      }
      for(k = 1; k <= i*2-1; k++) {
         printf("*");
      }
      printf("\n");
   }
   return 0; // End of Program
}