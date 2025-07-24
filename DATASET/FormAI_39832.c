//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {  // 1 is not a prime number
        return false;
    }
    for (int i = 2; i * i <= n; i++) {  // check divisibility up to square root of n
        if (n % i == 0) {  // if n is divisible by i
            return false;
        }
    }
    return true;
}

int main() {
    int limit;
    printf("Enter the limit to generate primes up to: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d:\n", limit);
    for (int n = 2; n <= limit; n++) { // generate primes up to limit
        if (is_prime(n)) {
            printf("%d ", n);
        }
    }
    printf("\n");
    return 0;
}