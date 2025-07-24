//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int n) {
    int prime_count = 0, next_prime = 2;
    
    while (prime_count < n) {
        if (is_prime(next_prime)) {
            printf("%d ", next_prime);
            prime_count++;
        }
        next_prime++;
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);
    generate_primes(n);
    printf("\n");
}