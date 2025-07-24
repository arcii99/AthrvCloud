//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int p = 61, q = 53; // Our two prime numbers
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Finding e: a coprime of phi
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    } 

    // Finding d: the multiplicative inverse of e (mod phi)
    int d = inverse(e, phi);

    printf("p = %d\nq = %d\nn = %d\nphi = %d\ne = %d\nd = %d\n", p, q, n, phi, e, d);

    // Encrypting a message M
    int M = 12345;
    int encrypted = (int) pow(M, e) % n;
    printf("Encrypted message: %d\n", encrypted);

    // Decrypting the message
    int decrypted = (int) pow(encrypted, d) % n;
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Extended Euclidean algorithm to find the inverse of e modulo phi
int inverse(int e, int phi) {
    int x1 = 1, x2 = 0, y1 = 0, y2 = 1;
    int q, r, x, y;

    while (phi > 0) {
        q = e / phi;
        r = e % phi;
        x = x1 - q * x2;
        y = y1 - q * y2;
        e = phi;
        phi = r;
        x1 = x2;
        x2 = x;
        y1 = y2;
        y2 = y;
    }

    if (y1 < 0) {
        y1 += x1;
    }

    return y1;
}