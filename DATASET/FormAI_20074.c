//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRIME_MIN 100
#define PRIME_MAX 100000
#define MAX_MESSAGE_LENGTH 512

typedef struct PublicKey {
    int n;
    int e;
} PublicKey;

typedef struct PrivateKey {
    int n;
    int d;
} PrivateKey;

int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }

    if (num < 2 || num % 2 == 0) {
        return 0;
    }

    for (int i = 3; i*i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int generatePrime(int min, int max) {
    int num = rand() % (max - min + 1) + min;

    while (!isPrime(num)) {
        num = rand() % (max - min + 1) + min;
    }

    return num;
}

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int generateE(int phi) {
    int e = rand() % (phi-2) + 2;

    while (gcd(phi, e) != 1) {
        e = rand() % (phi-2) + 2;
    }

    return e;
}

PrivateKey generatePrivateKey(int p, int q, int e) {
    PrivateKey privateKey;

    int phi = (p-1) * (q-1);
    privateKey.n = p*q;
    privateKey.d = 1;

    while ((privateKey.d * e) % phi != 1) {
        privateKey.d++;
    }

    return privateKey;
}

PublicKey generatePublicKey(int p, int q, int e) {
    PublicKey publicKey;

    publicKey.n = p*q;
    publicKey.e = e;

    return publicKey;
}

int modPow(int base, int exponent, int modulus) {
    int result = 1;
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        base = (base * base) % modulus;
        exponent = exponent / 2;
    }

    return result;
}

void encrypt(char* message, int messageLength, int* encryptedMessage, int* encryptedMessageLength, PublicKey publicKey) {
    for (int i = 0; i < messageLength; i++) {
        encryptedMessage[i] = modPow(message[i], publicKey.e, publicKey.n);
    }

    *encryptedMessageLength = messageLength;
}

void decrypt(int* encryptedMessage, int encryptedMessageLength, char* decryptedMessage, int* decryptedMessageLength, PrivateKey privateKey) {
    for (int i = 0; i < encryptedMessageLength; i++) {
        decryptedMessage[i] = modPow(encryptedMessage[i], privateKey.d, privateKey.n);
    }

    *decryptedMessageLength = encryptedMessageLength;
}

int main() {
    srand(time(NULL));

    printf("Generating prime numbers...\n");

    int p = generatePrime(PRIME_MIN, PRIME_MAX);
    int q = generatePrime(PRIME_MIN, PRIME_MAX);

    printf("p: %d, q: %d\n", p, q);

    printf("Generating keys...\n");

    int phi = (p-1) * (q-1);
    int e = generateE(phi);

    printf("e: %d\n", e);

    PrivateKey privateKey = generatePrivateKey(p, q, e);
    PublicKey publicKey = generatePublicKey(p, q, e);

    printf("Private key: n = %d, d = %d\n", privateKey.n, privateKey.d);
    printf("Public key: n = %d, e = %d\n", publicKey.n, publicKey.e);

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    int messageLength = strlen(message)-1;

    int encryptedMessage[MAX_MESSAGE_LENGTH];
    int encryptedMessageLength;
    encrypt(message, messageLength, encryptedMessage, &encryptedMessageLength, publicKey);

    char decryptedMessage[MAX_MESSAGE_LENGTH];
    int decryptedMessageLength;
    decrypt(encryptedMessage, encryptedMessageLength, decryptedMessage, &decryptedMessageLength, privateKey);

    printf("Encrypted message: ");
    for (int i = 0; i < encryptedMessageLength; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}