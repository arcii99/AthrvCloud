//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_gen(int *primes, int max_num) {
    int prime_count = 0;
    for (int i = 2; i <= max_num; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }
}

int main() {
    int max_num = 100;
    int primes[max_num];
    prime_gen(primes, max_num);

    for (int i = 0; i < max_num; i++) {
        printf("%d ", primes[i]);
    }
    
    return 0;
}