//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int n) {
    printf("Generating all prime numbers less than or equal to %d...\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}