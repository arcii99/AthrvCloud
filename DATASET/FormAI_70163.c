//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>

int main() {
   int n, i, flag = 0;
   printf("Enter a positive integer: ");
   scanf("%d", &n);

   for(i = 2; i <= n/2; ++i) {
      // condition for non-prime
      if(n%i == 0) {
         flag = 1;
         break;
      }
   }

   if (n == 1) {
      printf("1 is not a prime number.\n");
   } 
   else {
      if (flag == 0) {
         printf("%d is a prime number.\n", n);
      } 
      else {
         printf("%d is not a prime number.\n", n);
      }
   }

   return 0;
}