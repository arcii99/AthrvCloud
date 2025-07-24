//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate greatest common divisor
int gcd(int a, int b) 
{
    if (b == 0) 
        return a;
    else 
        return gcd(b, a % b);
}

// Function to generate the public key
int generatePublicKey(int phi) 
{
    int e = 2; // starting value for e
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    return e;
}

// Function to generate the private key
int generatePrivateKey(int e, int phi) 
{
    int k = 1;
    while (1) {
        k += phi;
        if (k % e == 0)
            return k / e;
    }
}

// Function to encrypt a message
int encrypt(int message, int e, int n) 
{
    int cipher = fmod(pow(message, e), n);
    return cipher;
}

// Function to decrypt a cipher
int decrypt(int cipher, int d, int n) 
{
    int message = fmod(pow(cipher, d), n);
    return message;
}

int main() 
{
    int p = 19, q = 23; // Choose two prime numbers
    int n = p * q; // Calculate n
    int phi = (p - 1) * (q - 1); // Calculate phi
    int e = generatePublicKey(phi); // Generate public key
    int d = generatePrivateKey(e, phi); // Generate private key

    printf("Public key is (%d, %d)\n", e, n);
    printf("Private key is (%d, %d)\n", d, n);

    int message = 123;
    int cipher = encrypt(message, e, n);
    int decryptedMessage = decrypt(cipher, d, n);

    printf("Original message: %d\n", message);
    printf("Encrypted cipher: %d\n", cipher);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}