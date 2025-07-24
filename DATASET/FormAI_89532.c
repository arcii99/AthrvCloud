//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_primes = 10;
    int n = 2;
    while (num_primes > 0) {
        if (is_prime(n)) {
            printf("%d ", n);
            num_primes--;
        }
        n++;
    }
    return 0;
}