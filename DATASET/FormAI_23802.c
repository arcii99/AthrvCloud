//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>

int main() {
   int i, j, flag, n;
   printf("Enter the value of n: ");
   scanf("%d", &n);
   printf("\nPrime numbers between 1 and %d are:\n", n);

   // 1 is not prime so we start from 2
   for (i = 2; i <= n; i++) {
      flag = 0;
     
      // Check if the current number i is prime
      for (j = 2; j <= i/2; j++) {
         if (i%j == 0) {
            flag = 1;
            break;
         }
      }

      // If the current number i is prime,
      // print it to the console
      if (flag == 0)
         printf("%d\n", i);
   }

   return 0;
}