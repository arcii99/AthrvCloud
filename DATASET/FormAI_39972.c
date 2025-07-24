//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

bool is_prime(unsigned int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(unsigned int limit) {
    printf("The prime numbers between 1 and %u are:\n", limit);
    for (unsigned int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%u ", num);
        }
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter a positive integer limit: ");
    unsigned int limit;
    scanf("%u", &limit);
    generate_primes(limit);
    return 0;
}