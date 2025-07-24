//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>

/* A fun and jolly implementation of a public-key algorithm! */

int main() {
    printf("Hello! Let's generate some encryption keys!\n");

    // Generate random numbers for p and q
    int p = 7;
    int q = 11;

    printf("Using p = %d and q = %d\n", p, q);

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("n = %d, phi = %d\n", n, phi);

    // Find a number e that is coprime to phi(n)
    int e = 3;
    while (e < phi) {
        int gcd = 1;
        for (int i = 2; i <= e && i <= phi; i++) {
            if (e % i == 0 && phi % i == 0) {
                gcd = i;
            }
        }

        if (gcd == 1) {
            break;
        } else {
            e++;
        }
    }

    printf("e = %d\n", e);

    // Find the modular inverse of e mod phi(n)
    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    printf("d = %d\n", d);

    printf("Your public key is (%d, %d)\n", e, n);
    printf("Your private key is (%d, %d)\n", d, n);

    printf("Encrypting message...\n");

    // Encrypt a message using the public key
    int message = 13;
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * message) % n;
    }

    printf("Ciphertext of %d is %d\n", message, ciphertext);

    printf("Decrypting message...\n");

    // Decrypt the ciphertext using the private key
    int decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * ciphertext) % n;
    }

    printf("Decrypted ciphertext of %d is %d\n", ciphertext, decrypted);

    printf("Yay! You did it!\n");

    return 0;
}