//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
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

void gen_primes(int min, int max) {
    printf("Generating prime numbers between %d and %d\n\n", min, max);
    if (min < 2) {
        min = 2;
    }
    for (int i = min; i <= max; i++) {
        if (is_prime(i)) {
            printf("%d is a prime number.\n", i);
        }
    }
}

int main() {
    printf("Welcome to the Prime Number Generator!\n\n");
    int min, max;
    printf("Please enter the minimum value: ");
    scanf("%d", &min);
    printf("Please enter the maximum value: ");
    scanf("%d", &max);
    printf("\n");
    gen_primes(min, max);
    printf("\nThank you for using the Prime Number Generator!\n");
    return 0;
}