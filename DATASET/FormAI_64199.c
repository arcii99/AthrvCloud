//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function to generate a random prime number */
int generatePrime(int min, int max) {
    int num = rand() % (max - min + 1) + min;
    int i;

    if (num % 2 == 0 || num % 3 == 0) {
        return generatePrime(min, max);
    }

    for (i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return generatePrime(min, max);
        }
    }

    return num;
}

/* Function to calculate the greatest common divisor */
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

/* Function to generate public and private keys */
void generateKeys(int *publicKey, int *privateKey, int p, int q) {
    int phi = (p - 1) * (q - 1);
    int n = p * q;
    int e = 2;

    /* Find a relative prime number to phi */
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        } else {
            e++;
        }
    }

    /* Calculate d, the inverse of e */
    int i = 1;
    int d = -1;
    while (d == -1) {
        if ((i * phi + 1) % e == 0) {
            d = (i * phi + 1) / e;
        }
        i++;
    }

    *publicKey = e;
    *privateKey = d;
}

/* Function to encrypt a message */
int encrypt(int m, int publicKey, int n) {
    return (int)fmod(pow(m, publicKey), n);
}

/* Function to decrypt a message */
int decrypt(int c, int privateKey, int n) {
    return (int)fmod(pow(c, privateKey), n);
}

int main() {
    int p, q, publicKey, privateKey, n, m, c, decrypted;

    /* Seed the random number generator */
    srand(time(0));

    /* Generate two prime numbers */
    p = generatePrime(1000, 5000);
    q = generatePrime(5000, 10000);

    /* Generate the public and private keys */
    generateKeys(&publicKey, &privateKey, p, q);

    /* Calculate n */
    n = p * q;

    /* Get a message from the user */
    printf("Enter a message to encrypt: ");
    scanf("%d", &m);

    /* Encrypt the message */
    c = encrypt(m, publicKey, n);
    printf("Encrypted message: %d\n", c);

    /* Decrypt the message */
    decrypted = decrypt(c, privateKey, n);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}