//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) {  // 1 and below are not considered prime
        return 0;
    }
    for (int i = 2; i*i <= n; i++) {  // checks up to square root of n
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int num) {
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int limit;
    printf("Enter limit: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d: ", limit);
    generate_primes(limit);
    printf("\n");
    return 0;
}