//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Euclid's Algorithm for gcd computation
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Modulo Exponentiation
int moduloExp(int base, int exp, int m) {
    int result = 1;
    base = base % m;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % m;
        exp = exp >> 1;
        base = (base * base) % m;
    }
    return result;
}

// Generate random prime number within specified range
int genPrime(int min, int max) {
    int num, i, flag;
    while (1) {
        num = rand() % (max - min + 1) + min;
        // Check for prime using sieve of eratosthenes
        if (num == 1)
            continue;
        flag = 1;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            return num;
    }
}

// Generate public key (e, n) and private key (d, n)
void genKeys(int bitlen) {
    int p, q, n, phi, e, d;
    p = genPrime(pow(2, bitlen - 1), pow(2, bitlen) - 1); // Generate large prime number within range of bit length
    q = genPrime(pow(2, bitlen - 1), pow(2, bitlen) - 1); // Generate another large prime number within range of bit length
    while (p == q) {
        q = genPrime(pow(2, bitlen - 1), pow(2, bitlen) - 1); // If both random prime numbers are equal, generate a different one
    }
    n = p * q;
    phi = (p - 1) * (q - 1); // Euler's totient function
    // Choose public key 'e' such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);
    // Compute private key 'd' such that (d * e) mod phi(n) = 1
    d = moduloExp(e, -1, phi);
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    genKeys(8); // Generate public and private keys for 8-bit long integers
    return 0;
}