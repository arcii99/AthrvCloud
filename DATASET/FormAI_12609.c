//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function to check if a number is prime */
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

/* Function to generate and print prime numbers */
void generate_primes(int n) {
    int count = 0;
    printf("The first %d prime numbers are:\n", n);
    for (int i = 2; count < n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

/* Main function */
int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}