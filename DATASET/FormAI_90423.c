//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Generate two prime numbers
    int p = 11;
    int q = 7;

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 3;
    while (e < phi) {
        int gcd = fmax(p, q);
        if (phi % e == 0 && gcd == 1) {
            break;
        } else {
            e++;
        }
    }

    // Calculate d such that d*e ≡ 1 (mod phi)
    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    // Generate a message and encrypt it
    int message = 123;
    int cipher = pow(message, e);
    cipher = fmod(cipher, n);

    // Decrypt the cipher
    int decrypted = pow(cipher, d);
    decrypted = fmod(decrypted, n);

    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", cipher);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}