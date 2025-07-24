//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>

int main() {
    int primes[1000];
    primes[0] = 2;  // 2 is the first prime number
    int count = 1;
    int num = 3;

    while (count < 1000) {
        int is_prime = 1;  // Assume num is prime
        for (int i = 0; i < count; i++) {
            if (num % primes[i] == 0) {
                is_prime = 0;  // num is divisible by a prime number
                break;
            }
        }
        if (is_prime) {
            primes[count] = num;
            count++;
        }
        num++;
    }

    // Print all the prime numbers
    for (int i = 0; i < 1000; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}