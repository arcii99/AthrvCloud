//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>

// Function declaration
int isPrime(int num);

int main() {
   int n, i;
   
   printf("Enter the number of prime numbers to generate: ");
   scanf("%d", &n);
   
   if (n < 1) {
       printf("Invalid input. Exiting...\n");
       return 0;
   }
   
   int count = 0;
   int num = 2; // Start with the first prime number
   
   while (count < n) {
       if (isPrime(num)) {
           printf("%d ", num);
           count++;
       }
       num++;
   }
   
   printf("\n");
   return 0;
}

// Function to check if a number is prime or not
int isPrime(int num) {
   int i;
   
   // Handle special cases
   if (num <= 1) {
       return 0; // not prime
   }
   
   // Check for factors
   for (i = 2; i <= num/2; i++) {
       if (num % i == 0) {
           return 0; // not prime
       }
   }
   
   return 1; // prime
}