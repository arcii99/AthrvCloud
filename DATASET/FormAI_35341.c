//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

/* Linus Torvalds style Prime Number Generator Program */
int isPrime(int number) {
    int i;
    if (number <= 1) {
        return 0;
    }
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit = 100;

    printf("Linus Torvalds style Prime Number Generator Program\n\n");
    printf("Generating prime numbers up to %d\n\n", limit);

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}