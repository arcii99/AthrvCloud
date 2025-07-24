//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to generate a public key
void generatePublicKey(int p, int q, int *n, int *e) {
    // Calculate n: n = pq
    *n = p * q;
    // Calculate totient function: phi(n) = (p-1)(q-1)
    int phi = (p - 1) * (q - 1);
    // Find e: 1 < e < phi(n) and gcd(e, phi(n)) = 1
    for(int i = 2; i < phi; i++) {
        if(phi % i == 0) continue; // Not a prime factor
        int flag = 0;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = 1; // i is not a prime
                break;
            }
        }
        if(flag == 1) continue; // i is not a prime number
        if(phi % i != 0) {
            *e = i;
            break;
        }
    }
}

// Function to find the multiplicative inverse of e
int findInverse(int e, int phi) {
    int d = 0;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    int q, r, x, y;

    while (e > 0) {
        q = phi / e;
        r = phi - q * e;
        x = x2 - q * x1;
        y = y2 - q * y1;
        phi = e;
        e = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }

    if (phi == 1) {
        d = y2;
    }

    return d;
}

// Function to encrypt the message
int encrypt(int message, int e, int n) {
    int cipher = 1;
    for(int i = 0; i < e; i++) {
        cipher = (cipher * message) % n;
    }
    return cipher;
}

// Function to decrypt the message
int decrypt(int cipher, int d, int n) {
    int message = 1;
    for(int i = 0; i < d; i++) {
        message = (message * cipher) % n;
    }
    return message;
}

int main() {
    // User inputs
    int p, q, n, e, d;
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the value of q: ");
    scanf("%d", &q);

    // Generate public key
    generatePublicKey(p, q, &n, &e);
    printf("Public key: (%d, %d)\n", n, e);

    // Find inverse of e
    int phi = (p - 1) * (q - 1);
    d = findInverse(e, phi);

    // User inputs message
    int message;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    // Encrypt message
    int cipher = encrypt(message, e, n);
    printf("Encrypted message: %d\n", cipher);

    // Decrypt message
    message = decrypt(cipher, d, n);
    printf("Decrypted message: %d\n", message);

    return 0;
}