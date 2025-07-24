//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
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

void prime_generator(int n) {
    int primes[n + 1];
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= n; i++) {
        primes[i] = i;
    }
    for (int i = 2; i * i <= n; i++) {
        if (is_prime(i)) {
            for (int j = i * 2; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }
    printf("Prime numbers from 2 to %d: ", n);
    for (int i = 0; i <= n; i++) {
        if (primes[i] != 0) {
            printf("%d ", primes[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    prime_generator(n);
    return 0;
}