//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>

int is_prime(int n, int i) {
    if (i == 1) {
        return 1;
    }
    else {
        if (n % i == 0) {
            return 0;
        }
        else {
            return is_prime(n, i-1);
        }
    }
}

void prime_numbers(int n, int i) {
    if (i <= n) {
        if (is_prime(i, i-1)) {
            printf("%d ", i);
        }
        prime_numbers(n, i+1);
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);
    prime_numbers(n, 2);
    return 0;
}