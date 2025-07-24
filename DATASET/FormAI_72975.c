//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define MAX_PRIMES 100

int main() {
    int n, i, j, count = 0;
    int primes[MAX_PRIMES];
    bool isPrime;

    primes[count++] = 2; // 2 is the first prime
    
    for (n = 3; count < MAX_PRIMES; n += 2) { // check odd numbers only
        isPrime = true;
        
        for (i = 0; i < count; i++) {
            if (n % primes[i] == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            primes[count++] = n; // store prime number
        }
    }

    for (i = 0; i < MAX_PRIMES; i++) {
        printf("%d ", primes[i]);
    }
    
    return 0;
}