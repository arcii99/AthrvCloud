//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// function to calculate the modular exponentiation
int modularExponentiation(int x, unsigned int y, int p) {
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main() {

    // p and q are prime numbers
    int p = 61;
    int q = 53;

    // n is the modulus for the public and private keys
    int n = p * q;

    // phi is the Euler's totient function
    int phi = (p - 1) * (q - 1);

    // choose an integer e such that e and phi(n) are coprime
    int e = 17;

    // check if e and phi(n) are coprime
    if (gcd(e, phi) != 1) {
        printf("e is not coprime with phi(n)\n");
        return 0;
    }

    // d is the multiplicative inverse of e modulo phi(n)
    int d = 0;
    int k = 1;
    while (1) {
        d = (k * phi + 1) / e;
        if ((k * phi + 1) % e == 0) {
            break;
        }
        k++;
    }

    printf("Public key: (%d,%d)\n", e, n);
    printf("Private key: (%d,%d)\n", d, n);

    // message to be encrypted
    int message = 1234;

    // encrypt the message using the public key (e, n)
    int cipher = modularExponentiation(message, e, n);

    // decrypt the message using the private key (d, n)
    int decrypted_message = modularExponentiation(cipher, d, n);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", cipher);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}