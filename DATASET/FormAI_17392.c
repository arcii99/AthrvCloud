//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

void generate_primes(int n) {
    printf("The first %d prime numbers are:\n", n);
    
    int count = 0;
    int i = 2;
    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Invalid number of primes requested.\n");
        return 0;
    }
    
    generate_primes(n);
    
    return 0;
}