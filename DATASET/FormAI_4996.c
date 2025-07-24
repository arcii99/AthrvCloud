//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: thoughtful
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i=2; i*i<=num; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate an array of primes
int* generatePrimes(int n) {
    int* primes = (int*)malloc(sizeof(int)*n);
    int num = 2;
    for (int i=0; i<n; ) {
        if (isPrime(num)) {
            primes[i] = num;
            i++;
        }
        num++;
    }
    return primes;
}

// Function to print the prime numbers
void printPrimes(int* primes, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    int* primes = generatePrimes(n);
    printf("The first %d prime numbers are:\n", n);
    printPrimes(primes, n);
    free(primes);
    return 0;
}