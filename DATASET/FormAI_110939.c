//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random prime number
int isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int getPrime() {
    int n;
    do {
        n = rand() % 100 + 2;
    } while (!isPrime(n));
    return n;
}

// Function to calculate the greatest common divider of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate a public and private key
void generateKeys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    do {
        *e = rand() % (phi - 2) + 2;
    } while (gcd(*e, phi) != 1);
    int k = 1;
    while ((k * phi + 1) % *e != 0) {
        k++;
    }
    *d = (k * phi + 1) / *e;
}

// Function to encrypt a message using public key
int encrypt(int m, int e, int n) {
    return (int) pow(m, e) % n;
}

// Function to decrypt a message using private key
int decrypt(int c, int d, int n) {
    return (int) pow(c, d) % n;
}

int main() {
    srand(time(0));
    int p = getPrime();
    int q = getPrime();
    int n, e, d;
    generateKeys(p, q, &n, &e, &d);
    int m = 1234;
    int c = encrypt(m, e, n);
    int r = decrypt(c, d, n);
    printf("Generated primes: %d, %d\n", p, q);
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);
    printf("Original message: %d\n", m);
    printf("Encrypted message: %d\n", c);
    printf("Decrypted message: %d\n", r);
    return 0;
}