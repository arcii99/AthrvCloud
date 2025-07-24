//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);
void print_primes(int start, int end);

int main() {
    int start, end;

    printf("Enter the range of numbers to check for primes: ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are:\n", start, end);
    print_primes(start, end);

    return 0;
}

// check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// print all primes between the given range
void print_primes(int start, int end) {
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }

    printf("\n");
}