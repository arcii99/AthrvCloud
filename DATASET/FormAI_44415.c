//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define PRIME_NUMBER 17
#define PUBLIC_KEY 7

// Function to check if a given number is prime
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to generate a random private key
int generatePrivateKey()
{
    int privateKey;
    srand(time(NULL));
    privateKey = rand() % 10;
    return privateKey;
}

// Function to generate a shared key
int generateSharedKey(int publicKey, int privateKey)
{
    int sharedKey;
    sharedKey = (int)(pow(publicKey, privateKey)) % PRIME_NUMBER;
    return sharedKey;
}

int main(void)
{
    char message[MAX_LENGTH];
    int privateKey, sharedKey, encrypted[MAX_LENGTH], decrypted[MAX_LENGTH];
    int i;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message); // read input until new line

    printf("Encrypting message...\n");

    // Generate private key
    privateKey = generatePrivateKey();

    // Generate shared key
    sharedKey = generateSharedKey(PUBLIC_KEY, privateKey);

    // Encrypt message using shared key
    for (i = 0; i < strlen(message); i++)
    {
        encrypted[i] = message[i] + sharedKey;
    }

    // Print encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < strlen(message); i++)
    {
        printf("%c", encrypted[i]);
    }

    // Decrypt message using shared key
    for (i = 0; i < strlen(message); i++)
    {
        decrypted[i] = encrypted[i] - sharedKey;
    }

    // Print decrypted message
    printf("\nDecrypted message: ");
    for (i = 0; i < strlen(message); i++)
    {
        printf("%c", decrypted[i]);
    }

    return 0;
}