//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>

/* This program generates prime numbers using the Sieve of Eratosthenes algorithm. It has a time complexity of O(n*log(log(n))). */

int main() {
    int n, i, j;

    printf("Enter the maximum number to generate primes up to: ");
    scanf("%d", &n);

    int is_prime[n+1];
    for(i=2; i<=n; i++) {
        is_prime[i] = 1;
    }

    for(i=2; i*i<=n; i++) {
        if(is_prime[i]) {
            for(j=i*2; j<=n; j+=i) {
                is_prime[j] = 0;
            }
        }
    }

    printf("The prime numbers up to %d are:\n", n);
    for(i=2; i<=n; i++) {
        if(is_prime[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}