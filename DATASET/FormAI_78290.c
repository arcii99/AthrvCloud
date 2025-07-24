//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    int limit;
    do {
        printf("Enter a number greater than 1 to generate all prime numbers up to that number: ");
        scanf("%d", &limit);
    } while (limit <= 1);
    int primes[limit+1];
    for (int i = 0; i <= limit; i++) {
        primes[i] = 1;
    }
    for (int i = 2; i*i <= limit; i++) {
        if (primes[i] == 1) {
            for (int j = i*i; j <= limit; j += i) {
                primes[j] = 0;
            }
        }
    }
    printf("All prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (primes[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\nThank you for using the Prime Number Generator!\n");
    return 0;
}