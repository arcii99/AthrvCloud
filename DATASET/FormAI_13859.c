//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for the public key
typedef struct {
    unsigned long long modulus;
    unsigned long long exponent;
} PublicKey;

// Define a function to check if a number is prime
bool is_prime(unsigned long long n) {
    if (n <= 1) {
        return false;
    }
    for (unsigned long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Define a function to calculate the greatest common divisor
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Define a function to generate a random prime number
unsigned long long generate_prime() {
    while (true) {
        // Generate a random number between 10000 and 100000
        unsigned long long n = rand() % 90000 + 10000;
        if (is_prime(n)) {
            return n;
        }
    }
}

// Define a function to generate a public key
PublicKey generate_public_key() {
    unsigned long long p, q;
    do {
        // Generate two random prime numbers
        p = generate_prime();
        q = generate_prime();
    } while (p == q);
    // Calculate n
    unsigned long long n = p * q;
    // Calculate phi(n)
    unsigned long long phi = (p - 1) * (q - 1);
    unsigned long long e;
    do {
        // Generate a random number between 3 and phi(n) - 1
        e = rand() % (phi - 3) + 3;
    } while (gcd(e, phi) != 1);
    PublicKey public_key = {n, e};
    return public_key;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Generate a public key
    PublicKey public_key = generate_public_key();
    // Print the public key
    printf("Public Key:\nModulus: %llu\nExponent: %llu\n", public_key.modulus, public_key.exponent);
    return 0;
}