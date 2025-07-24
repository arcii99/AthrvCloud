//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1) {
        return 0;
    }
 
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
 
        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0) {
        x1 += m0;
    }
 
    return x1;
}

int main() {
    int p = 7, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 3, d;

    // Find public key exponent
    while (gcd(e, phi) != 1) {
        e++;
    }

    // Find private key exponent
    d = modInverse(e, phi);

    int message = 123; // the message to be encrypted
    int encrypted = fmod(pow(message, e), n); // encryption
    int decrypted = fmod(pow(encrypted, d), n); // decryption

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}