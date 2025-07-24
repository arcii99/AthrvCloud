//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
}

int main() {
    int n;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    printf("Generating first %d primes: ", n);
    print_primes(n);
    return 0;
}