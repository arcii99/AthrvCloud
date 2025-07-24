//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
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

int main() {
    int count = 0; // number of primes found
    int num = 2; // starting number
    
    printf("The first 50 prime numbers:\n");
    while (count < 50) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    
    return 0;
}