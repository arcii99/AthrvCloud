//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Define the maximum prime number value for generating key pairs */
#define MAX_PRIME 100

/* Define the maximum value for p and q in the algorithm */
#define MAX_P_Q_VALUE 1000

/* Define the public key structure */
struct PublicKey {
    int n;
    int e;
};

/* Define the private key structure */
struct PrivateKey {
    int d;
};

/* Function to check if a number is prime */
int isPrime(int number) {
    int i;
    for (i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

/* Function to generate a prime number */
int generatePrime() {
    int prime;
    do {
        prime = rand() % MAX_PRIME + 1;
    } while (!isPrime(prime));
    return prime;
}

/* Function to calculate greatest common divisor */
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to generate key pairs */
void generateKeyPair(struct PublicKey *publicKey, struct PrivateKey *privateKey) {
    int p, q, n, phi, e, d;
    
    /* Generate two random prime numbers */
    p = generatePrime();
    q = generatePrime();
    
    /* Calculate n and phi */
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    /* Select a value for e that is relatively prime to phi */
    do {
        e = rand() % MAX_P_Q_VALUE + 2;
    } while (gcd(e, phi) != 1);
    
    /* Calculate d */
    d = 2;
    while ((d * e) % phi != 1) {
        d++;
    }
    
    /* Assign values to the public and private keys */
    publicKey->n = n;
    publicKey->e = e;
    
    privateKey->d = d;
}

/* Function to encrypt a message */
int encrypt(int message, struct PublicKey publicKey) {
    int encrypted = 1;
    int i;
    for (i = 0; i < publicKey.e; i++) {
        encrypted = (encrypted * message) % publicKey.n;
    }
    return encrypted;
}

/* Function to decrypt a message */
int decrypt(int message, struct PrivateKey privateKey, struct PublicKey publicKey) {
    int decrypted = 1;
    int i;
    for (i = 0; i < privateKey.d; i++) {
        decrypted = (decrypted * message) % publicKey.n;
    }
    return decrypted;
}

int main() {
    struct PublicKey publicKey;
    struct PrivateKey privateKey;
    
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Generate key pairs */
    generateKeyPair(&publicKey, &privateKey);
    
    /* Print out the public and private keys */
    printf("Public key: n=%d e=%d\n", publicKey.n, publicKey.e);
    printf("Private key: d=%d\n", privateKey.d);
    
    /* Encrypt and decrypt a message */
    int originalMessage = 123;
    printf("Original message: %d\n", originalMessage);
    int encryptedMessage = encrypt(originalMessage, publicKey);
    printf("Encrypted message: %d\n", encryptedMessage);
    int decryptedMessage = decrypt(encryptedMessage, privateKey, publicKey);
    printf("Decrypted message: %d\n", decryptedMessage);
    
    return 0;
}