//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRIME 1000000

int primeNumbers[MAX_PRIME];
int primeIndex = 0;

// Function to check if a number is prime or not
bool isPrime(int num)
{
    if (num <= 1)
        return false;

    int i;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to generate prime numbers
void generatePrimeNumbers()
{
    int i;

    for (i = 2; i <= MAX_PRIME; i++)
    {
        if (isPrime(i))
        {
            primeNumbers[primeIndex] = i;
            primeIndex++;
        }
    }
}

// Function to generate the public and private keys
void generateKeys(int p, int q, int *public, int *private)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 0, d = 0;

    while (true)
    {
        int randomIndex = rand() % primeIndex;
        e = primeNumbers[randomIndex];

        if ((e < phi) && (phi % e != 0) && isPrime(e))
            break;
    }

    int k = 1;
    while (true)
    {
        d = (k * phi + 1) / e;
        if (((k * phi + 1) % e == 0) && isPrime(d))
            break;
        k++;
    }

    *public = e;
    *private = d;
}

// Function to encrypt the message
int encrypt(int message, int pubKey, int n)
{
    int cipher = pow(message, pubKey);
    cipher = cipher % n;
    return cipher;
}

// Function to decrypt the message
int decrypt(int cipher, int privKey, int n)
{
    int message = pow(cipher, privKey);
    message = message % n;
    return message;
}

int main()
{
    srand((int)time(NULL));
    generatePrimeNumbers();

    int p, q, public, private;

    // Get prime numbers p and q
    printf("Enter prime number p: ");
    scanf("%d", &p);
    while (!isPrime(p))
    {
        printf("%d is not prime. Enter another number: ", p);
        scanf("%d", &p);
    }

    printf("Enter prime number q: ");
    scanf("%d", &q);
    while (!isPrime(q))
    {
        printf("%d is not prime. Enter another number: ", q);
        scanf("%d", &q);
    }

    // Generate keys
    generateKeys(p, q, &public, &private);

    printf("Public key: %d\n", public);
    printf("Private key: %d\n", private);

    // Get message to encrypt
    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    // Encrypt message
    int cipher = encrypt(message, public, p * q);
    printf("Encrypted message: %d\n", cipher);

    // Decrypt message
    int decryptedMessage = decrypt(cipher, private, p * q);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}