//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to generate prime numbers up to n
void generate_prime_numbers(int n) {
    printf("Prime numbers up to %d:\n", n);

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    generate_prime_numbers(n);

    return 0;
}