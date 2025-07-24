//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum length of plaintext message
#define MAX_LEN 100

// Define structures for public and private keys
typedef struct {
    int n;
    int e;
} public_key_t;

typedef struct {
    int n;
    int d;
} private_key_t;

// Function to generate prime numbers
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generatePrimeNum() {
    int prime = rand() % 1000;
    while (!isPrime(prime)) {
        prime = rand() % 1000;
    }
    return prime;
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to generate the public and private keys
void generateKeys(public_key_t *pub_key, private_key_t *priv_key) {
    int p = generatePrimeNum();
    int q = generatePrimeNum();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }
    int k = 2;
    int d = (1 + (k * phi)) / e;
    while (d < 0) {
        k++;
        d = (1 + (k * phi)) / e;
    }
    pub_key->n = n;
    pub_key->e = e;
    priv_key->n = n;
    priv_key->d = d;
}

// Function to encrypt a message using the public key
void encrypt(int *plaintext, int *cipher, int len, public_key_t pub_key) {
    for (int i = 0; i < len; i++) {
        cipher[i] = (int)pow(plaintext[i], pub_key.e) % pub_key.n;
    }
}

// Function to decrypt a message using the private key
void decrypt(int *cipher, int *plaintext, int len, private_key_t priv_key) {
    for (int i = 0; i < len; i++) {
        plaintext[i] = (int)pow(cipher[i], priv_key.d) % priv_key.n;
    }
}

int main() {
    srand(time(NULL));
    int plaintext[MAX_LEN];
    int cipher[MAX_LEN];
    int decrypted[MAX_LEN];
    public_key_t pub_key;
    private_key_t priv_key;
    generateKeys(&pub_key, &priv_key);
    char msg[MAX_LEN];
    printf("Enter a message to encrypt: ");
    fgets(msg, MAX_LEN, stdin);
    int len = strlen(msg);
    printf("Public key: (%d, %d)\n", pub_key.n, pub_key.e);
    printf("Private key: (%d, %d)\n", priv_key.n, priv_key.d);
    for (int i = 0; i < len; i++) {
        plaintext[i] = (int)msg[i];
    }
    encrypt(plaintext, cipher, len, pub_key);
    printf("Encrypted message: ");
    for (int i = 0; i < len; i++) {
        printf("%d", cipher[i]);
    }
    printf("\n");
    decrypt(cipher, decrypted, len, priv_key);
    printf("Decrypted message: ");
    for (int i = 0; i < len; i++) {
        printf("%c", (char)decrypted[i]);
    }
    printf("\n");
    return 0;
}