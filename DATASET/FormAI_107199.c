//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
   if (n <= 1) {
      return false;
   }
   for (int i = 2; i < n; i++) {
      if (n % i == 0) {
         return false;
      }
   }
   return true;
}

void generate_primes(int n) {
   printf("The first %d prime numbers are:\n", n);
   int i = 2, count = 0;
   while (count < n) {
      if (is_prime(i)) {
         printf("%d ", i);
         count++;
      }
      i++;
   }
}

int main() {
   int n;
   printf("Enter the number of prime numbers to generate: ");
   scanf("%d", &n);
   generate_primes(n);
   return 0;
}