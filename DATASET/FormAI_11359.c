//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
   // Prime numbers are greater than 1
   if(n <= 1) {
      return false;
   }
   
   // Check if n is divisible by any number less than itself
   for(int i = 2; i < n; i++) {
      if(n % i == 0) {
         return false;
      }
   }
   
   // n is not divisible by any number less than itself
   return true;
}

int main() {
   int n;
   printf("Enter the number of prime numbers you want: ");
   scanf("%d", &n);
   
   int count = 0; // Keep track of number of prime numbers found
   int num = 2; // Start checking for prime numbers from 2
   
   printf("The first %d prime numbers are:\n", n);
   
   while(count < n) {
      if(isPrime(num)) {
         printf("%d ", num);
         count++;
      }
      num++;
   }
   
   return 0;
}