//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to find GCD of two numbers
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}

// Function to generate public and private keys
void generateKeys(int prime1, int prime2, int* publicKey, int* privateKey)
{
    int n = prime1 * prime2;    // Calculate n = pq
    int phi = (prime1 - 1) * (prime2 - 1);    // Calculate phi = (p - 1)(q - 1)
    int e = 2;    // Assume public key e to be 2 initially
    int gcd;

    // Calculate public key e
    while (e < phi)
    {
        gcd = GCD(e, phi);

        if (gcd == 1)
            break;
        else
            e++;
    }

    // Calculate private key d
    int d = 0, k = 1;
    while (1)
    {
        d = (k * phi + 1) / e;

        if ((k * phi + 1) % e == 0)
            break;

        k++;
    }

    // Assign public key and private key
    *publicKey = e;
    *privateKey = d;
}

// Function to encrypt the message
int encrypt(int message, int publicKey, int n)
{
    int temp = message;
    for (int i = 1; i < publicKey; i++)
    {
        temp *= message;
        temp %= n;
    }

    return temp;
}

// Function to decrypt the message
int decrypt(int message, int privateKey, int n)
{
    int temp = message;
    for (int i = 1; i < privateKey; i++)
    {
        temp *= message;
        temp %= n;
    }

    return temp;
}

int main()
{
    int prime1 = 7, prime2 = 17, publicKey, privateKey;
    generateKeys(prime1, prime2, &publicKey, &privateKey);
    printf("Public key: %d\nPrivate key: %d\n", publicKey, privateKey);

    int message = 5;
    int encryptedMessage = encrypt(message, publicKey, prime1 * prime2);
    printf("Encrypted message: %d\n", encryptedMessage);

    int decryptedMessage = decrypt(encryptedMessage, privateKey, prime1 * prime2);
    printf("Decrypted message: %d", decryptedMessage);

    return 0;
}