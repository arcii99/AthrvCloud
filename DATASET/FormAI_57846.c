//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for(int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int n) {
    if(n <= 1) {
        printf("There are no prime numbers less than or equal to %d\n", n);
        return;
    }
    printf("Prime numbers less than or equal to %d are: ", n);
    for(int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number to generate prime numbers: ");
    scanf("%d", &n);
    print_primes(n);
    return 0;
}