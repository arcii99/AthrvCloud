//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int n) {
    if (n <= 1) {
        return;
    }
    int i;
    for (i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n = 100;
    printf("Prime numbers between 1 and %d are: ", n);
    generatePrimes(n);
    return 0;
}