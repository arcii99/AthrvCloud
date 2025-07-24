//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("How many prime numbers would you like to generate?\n");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);
    printPrimes(n);
    return 0;
}