//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to find the greatest common divisor
int gcd(int x, int y) {
    int remainder;
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext;
    srand(time(NULL));
    // Choose two large prime numbers p and q
    p = rand() % 100 + 100;
    q = rand() % 100 + 100;
    // Calculate n and phi(n)
    n = p * q;
    phi = (p-1)*(q-1);
    // Choose a public key e (usually a small prime number)
    e = 7;
    // Verify that e and phi(n) are coprime
    while (gcd(e, phi) != 1) {
        e++;
    }
    // Calculate the private key d
    d = 0;
    while ((d * e) % phi != 1) {
        d++;
    }
    printf("Public key: (%d, %d)\nPrivate key: (%d, %d)\n", e, n, d, n);
    // Encrypt a message
    printf("Enter plaintext message: ");
    scanf("%d", &plaintext);
    ciphertext = (int) (pow(plaintext, e)) % n;
    printf("Encrypted message: %d\n", ciphertext);
    // Decrypt the message
    plaintext = (int) (pow(ciphertext, d)) % n;
    printf("Decrypted message: %d\n", plaintext);
    return 0; 
}