//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) { // 1 is not a prime
        return 0;
    }
    for (int i = 2; i * i <= n; i++) { // check till square root of n
        if (n % i == 0) { // if i divides n, then n is not a prime
            return 0;
        }
    }
    return 1; // return true if n is prime
}

int main() {
    int n;
    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &n);

    int primes[n];
    primes[0] = 2; // the first prime number
    int count = 1; // count of prime numbers found

    for (int i = 3; count < n; i += 2) { // skip even numbers
        if (isPrime(i)) {
            primes[count] = i;
            count++;
        }
    }

    printf("The first %d prime numbers are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}