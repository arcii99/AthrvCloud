//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

int main() {

    int limit;
    printf("Please enter the limit: ");
    scanf("%d", &limit);

    int primes[limit];
    primes[0] = 2; // The first prime number
    int count = 1; // The current count of the prime numbers found
    bool isPrime;

    // Check all odd numbers starting from 3
    for (int i = 3; i <= limit; i += 2) {
        isPrime = true;
        for (int j = 0; j < count; j++) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[count] = i;
            count++;
        }
    }

    printf("The prime numbers up to %d are:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}