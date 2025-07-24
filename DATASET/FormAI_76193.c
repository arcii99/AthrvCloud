//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>

int isPrime(int n) {
    if (n == 1)
        return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n, count = 0;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    return 0;
}