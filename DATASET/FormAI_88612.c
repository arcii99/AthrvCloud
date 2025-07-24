//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef struct {
    int p, q, n, e, d;
} RSAKey;

// This function calculates the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// This function calculates the least common multiple (LCM)
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// This function generates two distinct random primes
void generateRandomPrimes(int *p, int *q) {
    int primes[SIZE], count = 0;
    for (int i = 2; i < SIZE; i++) {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            primes[count++] = i;
        }
    }
    *p = primes[rand() % count];
    *q = primes[rand() % count];
    while (*p == *q) {
        *q = primes[rand() % count];
    }
}

// This function generates public and private keys
void generateKeys(RSAKey *key) {
    generateRandomPrimes(&(key->p), &(key->q));
    key->n = key->p * key->q;
    int phi = lcm(key->p - 1, key->q - 1);
    do {
        key->e = rand() % phi;
    } while (gcd(key->e, phi) != 1);
    int k = 1;
    while (((k * phi) + 1) % key->e) {
        k++;
    }
    key->d = (k * phi + 1) / key->e;
}

// This function encrypts a message using the public key
void encrypt(char *message, RSAKey key, int *cipher) {
    for (int i = 0; message[i]; i++) {
        cipher[i] = fmod(pow(message[i], key.e), key.n);
    }
}

// This function decrypts a cipher text using the private key
void decrypt(int *cipher, RSAKey key, char *message) {
    for (int i = 0; cipher[i]; i++) {
        message[i] = fmod(pow(cipher[i], key.d), key.n);
    }
}

int main() {
    RSAKey key;
    generateKeys(&key);
    printf("Public Key (e, n): (%d, %d)\n", key.e, key.n);
    printf("Private Key (d, n): (%d, %d)\n\n", key.d, key.n);

    char message[SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();

    int cipher[SIZE] = {0};
    encrypt(message, key, cipher);

    printf("Encryption Complete.\n");
    printf("Cipher Text: ");
    for (int i = 0; cipher[i]; i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");

    char decryptedMessage[SIZE] = {0};
    decrypt(cipher, key, decryptedMessage);

    printf("Decryption Complete.\n");
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}