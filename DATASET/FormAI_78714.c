//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Defines the public and private key structs
typedef struct {
    long long n;
    long long e;
} PublicKey;

typedef struct {
    long long n;
    long long d;
} PrivateKey;

// Function to generate a random prime number
int isPrime(long long num) {
    long long i;
    if (num == 2 || num == 3)
        return 1;
    if (num == 1 || num % 2 == 0)
        return 0;
    for (i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return 0;
    return 1;
}

// Function to generate a random prime between two numbers
long long generatePrime(long long start, long long end) { 
    long long num;
    while (1) {
        num = rand() % (end - start) + start;
        if (isPrime(num))
            return num;
    }
}

// Function to generate the public and private keys
void generateKeys(PublicKey *pubKey, PrivateKey *privKey) { 
    long long p, q, n, totient, e, d;

    // Generates two random prime numbers
    p = generatePrime(1000000, 2000000);
    q = generatePrime(2000000, 3000000);

    // Calculates n and totient
    n = p * q;
    totient = (p - 1) * (q - 1);

    // Generates a random public key
    e = generatePrime(2, totient - 1);

    // Calculates the private key
    d = 1;
    while ((d * e) % totient != 1 || d == e) {
        d++;
    }

    // Sets the values of the public and private keys
    pubKey->n = privKey->n = n;
    pubKey->e = e;
    privKey->d = d;
}

// Encrypts a message using a public key
long long encrypt(PublicKey key, long long message) {
    long long i, result = 1;
    for(i = 0; i < key.e; i++) {
        result = (result * message) % key.n;
    }
    return result;
}

// Decrypts a message using a private key
long long decrypt(PrivateKey key, long long message) {
    long long i, result = 1;
    for(i = 0; i < key.d; i++) {
        result = (result * message) % key.n;
    }
    return result;
}

// Main function to test the implementation
int main() {
    PublicKey pubKey;
    PrivateKey privKey;
    long long message, encrypted, decrypted;

    // Generates public and private keys
    generateKeys(&pubKey, &privKey);

    // Tests encryption and decryption
    printf("Enter a message to encrypt: ");
    scanf("%lld", &message);

    encrypted = encrypt(pubKey, message);
    printf("Encrypted message: %lld\n", encrypted);

    decrypted = decrypt(privKey, encrypted);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}