//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// The following constants are used for the generation of the public and private keys
const int P_MIN = 500;
const int P_MAX = 1500;
const int G_MIN = 2;
const int G_MAX = 5;

// Function to calculate modular exponentiation
int mod_exp(int base, int exponent, int mod) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

// Function to generate a random prime number
int generate_prime(int min, int max) {
    int prime = rand() % (max - min + 1) + min;
    int i, is_prime;
    while(1) {
        is_prime = 1;
        for(i = 2; i <= sqrt(prime); i++) {
            if(prime % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) {
            return prime;
        }
        prime++;
    }
}

// Function to generate a random generator g of a prime p
int generate_generator(int prime) {
    int g = rand() % (prime - 1) + 1;
    int i;
    for(i = 1; i < prime - 1; i++) {
        if(mod_exp(g, i, prime) == 1) {
            return generate_generator(prime);
        }
    }
    return g;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate prime numbers p and q (q is not used in this algorithm)
    int p = generate_prime(P_MIN, P_MAX);
    int q = (p - 1) / 2;

    // Generate generator g of prime p
    int g = generate_generator(p);

    // Generate random secret key a
    int a = rand() % (p - 2) + 1;

    // Calculate public key A
    int A = mod_exp(g, a, p);

    // Print out public and private keys
    printf("Public Key (p,g,A): (%d,%d,%d)\n", p, g, A);
    printf("Private Key (a): %d\n", a);

    return 0;
}