//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUMBERS 1000000

bool is_prime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main(void) {
    clock_t start, end;

    int primes[MAX_NUMBERS];
    int primes_count = 0;

    start = clock();

    for (int i = 2; i <= MAX_NUMBERS; i++) {
        if (is_prime(i)) {
            primes[primes_count] = i;
            primes_count++;
        }
    }

    end = clock();

    printf("Found %d primes in %lf seconds\n", primes_count, (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}