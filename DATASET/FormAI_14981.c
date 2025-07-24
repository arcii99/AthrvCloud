//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: medieval
// Medieval Prime Number Generator
// By Sir Chat-A-Lot

#include <stdio.h>

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

int main() {
    int lower, upper;
    printf("Hark! Enter the lower bound of thy search: ");
    scanf("%d", &lower);
    printf("And the upper bound: ");
    scanf("%d", &upper);

    printf("\nVerily, these are the prime numbers betwixt %d and %d:\n", lower, upper);

    for (int i = lower; i <= upper; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }

    printf("\nThus endeth the list of primes, m'lady/m'lord.\n");
    return 0;
}