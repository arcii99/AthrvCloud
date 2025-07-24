//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the public and private keys */
typedef struct {
    int e;
    int n;
} PublicKey;

typedef struct {
    int d;
    int n;
} PrivateKey;

/* Helper function to calculate the greatest common divisor of two numbers */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

/* Helper function to generate a random prime number */
int generatePrime(int min, int max) {
    int prime, i;
    srand(time(NULL));

    /* Generate a random number between min and max */
    prime = rand() % (max - min + 1) + min;

    /* Check if the number is prime */
    for (i = 2; i <= prime / 2; i++) {
        if (prime % i == 0) {
            return generatePrime(min, max);
        }
    }

    return prime;
}

/* Helper function to generate public and private keys */
void generateKeys(PublicKey *pubKey, PrivateKey *privKey) {
    int p, q, totient, e, d;

    /* Generate two distinct primes */
    do {
        p = generatePrime(100, 999);
        q = generatePrime(100, 999);
    } while (p == q);

    /* Calculate n */
    pubKey->n = p * q;
    privKey->n = p * q;

    /* Calculate the totient of n */
    totient = (p - 1) * (q - 1);

    /* Choose a random number for e */
    do {
        e = generatePrime(2, totient - 1);
    } while (gcd(e, totient) != 1);

    /* Calculate d */
    d = 0;
    while ((e * d) % totient != 1) {
        d++;
    }

    /* Set the public and private keys */
    pubKey->e = e;
    privKey->d = d;
}

/* Encrypt a message using the public key */
int encrypt(int message, PublicKey pubKey) {
    int c = 1, i;

    /* Calculate c = message^e mod n */
    for (i = 0; i < pubKey.e; i++) {
        c = (c * message) % pubKey.n;
    }

    return c;
}

/* Decrypt a message using the private key */
int decrypt(int message, PrivateKey privKey) {
    int m = 1, i;

    /* Calculate m = message^d mod n */
    for (i = 0; i < privKey.d; i++) {
        m = (m * message) % privKey.n;
    }

    return m;
}

int main() {
    PublicKey pubKey;
    PrivateKey privKey;
    int message, encrypted, decrypted;

    /* Generate the key pair */
    generateKeys(&pubKey, &privKey);

    /* Get the message to encrypt */
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);

    /* Encrypt the message */
    encrypted = encrypt(message, pubKey);

    /* Output the encrypted message */
    printf("Encrypted message: %d\n", encrypted);

    /* Decrypt the message */
    decrypted = decrypt(encrypted, privKey);

    /* Output the decrypted message */
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}