//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function declarations
long int gcd(long int a, long int b);
long int modExp(long int base, long int exp, long int mod);
long int generatePrime();
long int generatePrivateKey(long int phi, long int e);
long int encrypt(long int message, long int e, long int n);
long int decrypt(long int cipher, long int d, long int n);

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Generate two large prime numbers
    long int p = generatePrime();
    long int q = generatePrime();

    // Calculate n and phi
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);

    // Choose a public key e
    long int e;
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // Calculate private key d
    long int d = generatePrivateKey(phi, e);

    // Print out public and private keys
    printf("Public key: (%ld, %ld)\n", e, n);
    printf("Private key: %ld\n", d);

    // Get message from user
    printf("Enter a message to encrypt: ");
    char message[100];
    scanf("%s", message);

    // Encrypt the message
    long int encrypted[strlen(message)];
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = encrypt((long int) message[i], e, n);
        printf("%ld ", encrypted[i]);
    }
    printf("\n");

    // Decrypt the message
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", (char) decrypt(encrypted[i], d, n));
    }
    printf("\n");

    return 0;
}

// Calculate the greatest common divisor of a and b
long int gcd(long int a, long int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Calculate (base ^ exp) % mod using modular exponentiation
long int modExp(long int base, long int exp, long int mod)
{
    long int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }

    return result;
}

// Generate a large prime number
long int generatePrime()
{
    long int prime;
    int isPrime = 0;
    do {
        // Generate a random number between 100 and 1000
        prime = rand() % 900 + 100;

        // Check if it's prime
        isPrime = 1;
        for (int i = 2; i <= sqrt(prime); i++) {
            if (prime % i == 0) {
                isPrime = 0;
                break;
            }
        }
    } while (!isPrime);

    return prime;
}

// Generate the private key d
long int generatePrivateKey(long int phi, long int e)
{
    long int d = 1;
    while ((d * e) % phi != 1 || d == e) {
        d++;
    }
    return d;
}

// Encrypt a message with the given public key
long int encrypt(long int message, long int e, long int n)
{
    return modExp(message, e, n);
}

// Decrypt a message with the given private key
long int decrypt(long int cipher, long int d, long int n)
{
    return modExp(cipher, d, n);
}