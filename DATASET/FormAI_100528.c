//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int start, int end) {
    printf("Generating primes between %d and %d...\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    printf("Done\n");
}

int main() {
    printf("Welcome to the Prime Number Generator\n");
    printf("Enter the starting number: ");
    int start;
    scanf("%d", &start);
    printf("Enter the ending number: ");
    int end;
    scanf("%d", &end);
    generate_primes(start, end);
    printf("Thank you for using the Prime Number Generator\n");
    return 0;
}