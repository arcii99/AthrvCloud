//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void generate_primes(int min, int max) {
    bool* sieve = calloc(max + 1, sizeof(bool));
    for (int i = 2; i * i <= max; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j <= max; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (int i = min; i <= max; i++) {
        if (!sieve[i]) {
            printf("%d\n", i);
        }
    }

    free(sieve);
}

int main() {
    int min = 1, max = 100;
    generate_primes(min, max);
    return 0;
}