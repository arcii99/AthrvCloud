//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b)
{
    if (a == 0) 
        return b;
    return gcd(b % a, a);
}

// Function to find modular inverse of a number using Extended Euclidean algorithm
int findModInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply Extended Euclidean algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make sure x1 is positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to generate public and private key pair
void generateKeyPair(int p, int q, int *publicKey, int *privateKey, int *n)
{
    // Calculate n
    *n = p * q;

    // Calculate Euler's Totient function for n
    int phi_n = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi_n, and gcd(e, phi_n) = 1
    int e;
    for (e = 2; e < phi_n; e++)
    {
        if (gcd(e, phi_n) == 1)
            break;
    }

    *publicKey = e;

    // Calculate modular multiplicative inverse of e modulo phi_n
    *privateKey = findModInverse(e, phi_n);
}

// Function to encrypt a message using public key
int encrypt(int message, int publicKey, int n)
{
    int ciphertext = 1;
    for (int i = 0; i < publicKey; i++)
        ciphertext = (ciphertext * message) % n;
    return ciphertext;
}

// Function to decrypt a message using private key
int decrypt(int ciphertext, int privateKey, int n)
{
    int message = 1;
    for (int i = 0; i < privateKey; i++)
        message = (message * ciphertext) % n;
    return message;
}

int main()
{
    int p = 17, q = 19;
    int publicKey, privateKey, n;
    generateKeyPair(p, q, &publicKey, &privateKey, &n);

    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n", privateKey);
    printf("n: %d\n", n);

    int message = 123;
    int ciphertext = encrypt(message, publicKey, n);
    printf("Encrypted message: %d\n", ciphertext);

    int decryptedMessage = decrypt(ciphertext, privateKey, n);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}