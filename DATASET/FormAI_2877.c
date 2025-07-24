//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>

int isPrime(int n) {
    int i;
    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0 || n == 1) {
        return 0;
    }

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, n;
    printf("Enter an integer to generate all the prime numbers up to that number: ");
    scanf("%d", &n);

    printf("\nGenerating all prime numbers up to %d:\n", n);

    for (i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}