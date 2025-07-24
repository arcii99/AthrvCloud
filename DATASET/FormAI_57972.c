//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int n) {
    int primes[n];
    primes[0] = 2;
    int count = 1;
    int num = 3;
    while (count < n) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
        num += 2;
    }
    printf("%d prime numbers found.\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}