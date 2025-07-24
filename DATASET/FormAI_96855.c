//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator!\n");

    int n; // user-entered number to generate primes up to
    printf("Please enter a positive integer to generate primes up to: ");
    scanf("%d", &n);

    // create an array to store whether each number is prime or not
    int primes[n+1];
    for (int i = 0; i <= n; i++) {
        primes[i] = 1; // initialize all as prime
    }

    // loop through all numbers up to n
    for (int i = 2; i <= n; i++) {
        if (primes[i]) { // if i is prime, mark its multiples as not prime
            for (int j = i*2; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    // print out all prime numbers up to n
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }

    printf("\nThanks for using the Prime Number Generator! Have a prime-tastic day!\n");

    return 0;
}