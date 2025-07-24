//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_nums(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            count++;
            printf("%d ", i);
        }
    }
    printf("\nTotal: %d\n", count);
}

int main() {
    int n;
    printf("Enter a number to generate all primes up to it: ");
    scanf("%d", &n);
    printf("Prime numbers:\n");
    prime_nums(n);
    return 0;
}