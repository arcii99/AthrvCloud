//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
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

void generate_primes(int n) {
    int count = 0;
    printf("The first %d prime numbers are:\n", n);
    for (int i = 2; count < n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}