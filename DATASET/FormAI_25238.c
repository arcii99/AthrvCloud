//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    int i;
    bool prime = true;

    if (num < 2) {
        return false;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {
    int num, i;
    printf("Enter the nth number of prime numbers: ");
    scanf("%d", &num);

    int *primes = malloc(num * sizeof(int));
    primes[0] = 2;
    int current = 2;

    for (i = 1; i < num; i++) {
        do {
            current++;
        } while (!is_prime(current));

        primes[i] = current;
    }

    printf("The first %d prime numbers are:\n", num);
    for (i = 0; i < num; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
    return 0;
}