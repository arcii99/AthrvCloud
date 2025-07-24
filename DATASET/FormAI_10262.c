//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// function to generate prime numbers up to n
void generate_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

// main function to run the program
int main() {
    int n;

    printf("Enter the maximum number: ");
    scanf("%d", &n);

    printf("The prime numbers up to %d are: ", n);
    generate_primes(n);

    printf("\n");

    return 0;
}