//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int n) {
    if (n <= 1) return 0; // 1 is not a prime number
    
    // Check for divisors up to square root of the number
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0; // Not a prime number
    }
    
    return 1; // Prime number
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("We will now generate all prime numbers between 1 and 1000.\n");
    
    int count = 0; // Keeping track of the number of primes generated
    
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) {
            printf("%d is a prime number!\n", i);
            count++;
        }
    }
    
    printf("\nWe have generated %d prime numbers in total!\n", count);
    printf("I hope you're impressed, because I am programmed to think so.\n");
    
    return 0;
}