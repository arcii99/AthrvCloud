//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printPrimes(int n) {
    for (int num = 2; num <= n; ++num) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
}

int main() {
    int n;
    printf("Enter the limit for prime number generation: ");
    scanf("%d", &n);
    printPrimes(n);
    return 0;
}