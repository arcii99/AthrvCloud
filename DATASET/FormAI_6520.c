//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>

int main() {
   int n, i, j, flag;
   printf("Enter the number of prime numbers you want to generate: ");
   scanf("%d", &n);
   int primes[n];

   // first two prime numbers
   primes[0] = 2;
   primes[1] = 3;
   int count = 2;

   // loop for generating prime numbers
   for (i = 5; count < n; i += 2) {
      flag = 1;
      // checking if i is prime
      for (j = 2; j * j <= i; j++) {
         if (i % j == 0) {
            flag = 0;
            break;
         }
      }
      if (flag == 1) {
         primes[count] = i;
         count++;
      }
   }

   // printing generated prime numbers
   for (i = 0; i < n; i++) {
      printf("%d ", primes[i]);
   }
   printf("\n");
   return 0;
}