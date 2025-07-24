//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// function to generate the public and private keys
void generateKeys(int p, int q, int* n, int* e, int* d) {
    // calculate n
    *n = p * q;

    // calculate phi(n)
    int phi = (p - 1) * (q - 1);

    // choose e (public key)
    int i;
    for (i = 2; i < phi; i++) {
        if (isPrime(i) && (phi % i != 0)) {
            *e = i;
            break;
        }
    }

    // choose d (private key)
    int k = 1;
    while (1) {
        k = k + phi;
        if (k % *e == 0) {
            *d = k / *e;
            break;
        }
    }
}

// function to encrypt a message using the public key
void encrypt(char* message, int len, int n, int e, int* encryptedMsg) {
    int i;
    for (i = 0; i < len; i++) {
        encryptedMsg[i] = (int) pow(message[i], e) % n;
    }
}

// function to decrypt a message using the private key
void decrypt(int* encryptedMsg, int len, int n, int d, char* decryptedMsg) {
    int i;
    for (i = 0; i < len; i++) {
        decryptedMsg[i] = (char) pow(encryptedMsg[i], d) % n;
    }
}

// main function
int main() {
    int p = 17;
    int q = 19;

    int n, e, d;
    generateKeys(p, q, &n, &e, &d);

    char message[50] = "Hello, World!";
    int len = strlen(message);

    int encryptedMsg[len];
    encrypt(message, len, n, e, encryptedMsg);

    char decryptedMsg[len];
    decrypt(encryptedMsg, len, n, d, decryptedMsg);

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", encryptedMsg[i]);
    }
    printf("\n");
    printf("Decrypted Message: %s\n", decryptedMsg);

    return 0;
}