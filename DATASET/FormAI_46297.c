//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 500

bool is_prime(int n);
void print_primes(int from, int to);

int main() {
    int n;

    printf("Enter the maximum number to check for primes: ");
    scanf("%d", &n);

    printf("The prime numbers from 2 to %d are:\n", n);
    print_primes(2, n);

    return 0;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void print_primes(int from, int to) {
    int count = 0;
    for (int i = from; i <= to; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nFound %d primes between %d and %d.\n", count, from, to);
}