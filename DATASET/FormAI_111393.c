//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int is_prime(int number) {
    int i;

    if (number <= 1) {
        return 0;
    }

    for (i = 2; i < number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int max_number, i, prime_count = 0;

    printf("Please enter the maximum number to test for primality: ");
    scanf("%d", &max_number);

    for (i = 2; i <= max_number; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            prime_count++;
        }
    }

    printf("\nFound %d prime numbers between 2 and %d\n", prime_count, max_number);

    return 0;
}