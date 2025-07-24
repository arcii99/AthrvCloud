//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void print_primes(int lower, int upper) {
    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int lower, upper;
    printf("Enter lower and upper limits to generate prime numbers:\n");
    scanf("%d %d", &lower, &upper);
    print_primes(lower, upper);
    return 0;
}