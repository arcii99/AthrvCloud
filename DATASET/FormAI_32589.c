//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the first 10,000 prime numbers using the Sieve of Eratosthenes algorithm. 
 * It utilizes bit arrays for memory efficiency and bitwise operations for faster processing. 
 * This program is optimized for both time and memory performance and is suitable for use in 
 * large-scale scientific computations that require fast and accurate prime number generation. 
 */

#define MAX_NUM 100000000
#define MAX_SIEVE (MAX_NUM/2)
#define MAX_BYTE (MAX_SIEVE/sizeof(char))
unsigned char sieve[MAX_BYTE];

int main(void) {
    int num_primes = 0, limit = sqrt(MAX_NUM);
    sieve[0] |= 0x01;
    for (int i = 1; i <= MAX_SIEVE; i++) {
        if (!(sieve[i/8] & (0x01 << (i%8)))) {
            int prime = (2*i) + 1;
            if (prime <= limit) {
                for (int j = (i*prime)+i; j <= MAX_SIEVE; j += prime) {
                    sieve[j/8] |= 0x01 << (j%8);
                }
            }
            num_primes++;
            if (num_primes == 10000) {
                printf("The 10,000th prime is %d\n", prime);
                break;
            }
        }
    }
    return 0;
}