//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to compute gcd
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to generate public and private keys
void generateKeys(int p, int q, int *n, int *e, int *d) {
    // calculate n
    *n = p * q;

    // calculate totient
    int totient = (p - 1) * (q - 1);

    // choose public key
    for (int i = 2; i < totient; i++) {
        if (gcd(i, totient) == 1) {
            *e = i;
            break;
        }
    }

    // calculate private key
    int k = 1;
    while (1) {
        if ((1 + k * totient) % *e == 0) {
            *d = (1 + k * totient) / *e;
            break;
        }
        k++;
    }
}

// function to encrypt message
void encrypt(int message, int e, int n) {
    int result = pow(message, e);
    result = result % n;
    printf("Encrypted message: %d\n", result);
}

// function to decrypt message
void decrypt(int message, int d, int n) {
    int result = pow(message, d);
    result = result % n;
    printf("Decrypted message: %d\n", result);
}

int main() {
    int p, q, n, e, d;
    printf("Enter value of p: ");
    scanf("%d", &p);
    printf("Enter value of q: ");
    scanf("%d", &q);

    generateKeys(p, q, &n, &e, &d);
    printf("Public key: %d\n", e);
    printf("Private key: %d\n", d);
    printf("Modulus: %d\n", n);

    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    encrypt(message, e, n);
    decrypt(message, d, n);

    return 0;
}