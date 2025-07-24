//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int count) {
    int num = 2;
    int primes[count];

    while (count > 0) {
        if (isPrime(num)) {
            primes[count-1] = num;
            count--;
        }
        num++;
    }

    printf("The first %d prime numbers are:\n", sizeof(primes)/sizeof(primes[0]));

    for (int i=0; i<sizeof(primes)/sizeof(primes[0]); i++) {
        printf("%d ", primes[i]);
    }
}

int main() {
    generatePrimes(20);
    
    return 0;
}