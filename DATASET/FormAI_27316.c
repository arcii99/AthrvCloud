//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// defining a function to check if a number is prime or not
int isPrime(int n) {
    int i, flag = 1;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

// defining a function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// defining a function to generate public and private keys
void generateKeys(int p, int q, int *e, int *d, int *n) {
    int phiN, publicKey, privateKey;
    *n = p * q;
    phiN = (p - 1) * (q - 1);
    publicKey = 2;
    while (publicKey < phiN) {
        if (gcd(publicKey, phiN) == 1) {
            break;
        }
        publicKey++;
    }
    privateKey = 1;
    while ((privateKey * publicKey) % phiN != 1) {
        privateKey++;
    }
    *e = publicKey;
    *d = privateKey;
}

// defining a function to encrypt data using public key
void encrypt(int plaintext, int e, int n, int *ciphertext) {
    *ciphertext = fmod(pow(plaintext, e), n);
}

// defining a function to decrypt data using private key
void decrypt(int ciphertext, int d, int n, int *plaintext) {
    *plaintext = fmod(pow(ciphertext, d), n);
}

int main() {
    int p, q, e, d, n, plaintext, ciphertext, decryptedtext;
    printf("Enter a prime number p: ");
    scanf("%d", &p);
    if (!isPrime(p)) {
        printf("%d is not a prime number, exiting.\n", p);
        return 1;
    }
    printf("Enter a prime number q: ");
    scanf("%d", &q);
    if (!isPrime(q)) {
        printf("%d is not a prime number, exiting.\n", q);
        return 1;
    }
    generateKeys(p, q, &e, &d, &n);
    printf("Public key (e,n): (%d,%d)\n", e, n);
    printf("Private key (d,n): (%d,%d)\n", d, n);
    printf("Enter plaintext to encrypt: ");
    scanf("%d", &plaintext);
    encrypt(plaintext, e, n, &ciphertext);
    printf("Ciphertext: %d\n", ciphertext);
    decrypt(ciphertext, d, n, &decryptedtext);
    printf("Decrypted text: %d\n", decryptedtext);
    return 0;
}