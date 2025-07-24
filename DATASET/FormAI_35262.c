//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000 // Maximum length of input message
#define PRIME_MIN 100 // Minimum value of prime numbers generated
#define PRIME_MAX 1000 // Maximum value of prime numbers generated

/* Function to check if number is prime */
int isPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
        return 0;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/* Function to generate random prime number */
int generatePrime()
{
    int prime;
    do {
        prime = rand() % (PRIME_MAX - PRIME_MIN + 1) + PRIME_MIN;
    } while (!isPrime(prime));
    return prime;
}

/* Function to calculate greatest common divisor */
int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* Function to calculate modular exponentiation */
int modExp(int a, int b, int m) {
    int result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return result;
}

/* Function to generate public and private keys */
void generateKeys(int *n, int *e, int *d)
{
    int p, q, phi, publicKey, privateKey;
    /* Generate prime numbers */
    p = generatePrime();
    q = generatePrime();
    /* Calculate modulus */
    *n = p * q;
    /* Calculate Euler's totient function */
    phi = (p - 1) * (q - 1);
    /* Generate public key */
    do {
        publicKey = rand() % phi + 1;
    } while (gcd(publicKey, phi) != 1);
    *e = publicKey;
    /* Generate private key */
    int k = 1;
    do {
        privateKey = (k * phi + 1) / publicKey;
        k++;
    } while (gcd(privateKey, phi) != 1);
    *d = privateKey;
}

/* Function to encrypt message */
void encrypt(int *msg, int n, int e, int len) {
    int i;
    for (i = 0; i < len; i++) {
        msg[i] = modExp(msg[i], e, n);
    }
}

/* Function to decrypt message */
void decrypt(int *msg, int n, int d, int len) {
    int i;
    for (i = 0; i < len; i++) {
        msg[i] = modExp(msg[i], d, n);
    }
}

int main()
{
    int i, len, n, e, d;
    int message[MAX_LENGTH];
    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    len = strlen(message);
    for (i = 0; i < len; i++) {
        message[i] = (int)message[i];
    }
    /* Generate keys */
    generateKeys(&n, &e, &d);
    /* Encrypt message */
    encrypt(message, n, e, len);
    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", message[i]);
    }
    /* Decrypt message */
    decrypt(message, n, d, len);
    printf("\nDecrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", (char)message[i]);
    }
    return 0;
}