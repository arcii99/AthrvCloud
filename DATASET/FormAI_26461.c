//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the prime numbers
#define P 23 
#define G 5 

// Function to generate the private key
int generatePrivateKey()
{
    int privateKey;
    srand(time(NULL));
    privateKey = rand()%P;
    return privateKey;
}

// Function to calculate the public key
int calculatePublicKey(int privateKey)
{
    int publicKey;
    publicKey = (int)pow(G,privateKey)%P;
    return publicKey;
}

// Function to generate the secret key
int generateSecretKey(int privateKey, int publicKey)
{
    int secretKey;
    secretKey = (int)pow(publicKey,privateKey)%P;
    return secretKey;
}

// Main function to test the implementation
int main()
{
    int privateKey1, privateKey2, publicKey1, publicKey2, secretKey1, secretKey2;
    char message[100];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Generating keys...\n\n");
    // Generate the private keys
    privateKey1 = generatePrivateKey();
    privateKey2 = generatePrivateKey();

    // Calculate the public keys
    publicKey1  = calculatePublicKey(privateKey1);
    publicKey2  = calculatePublicKey(privateKey2);

    // Generate the secret keys
    secretKey1 = generateSecretKey(privateKey1, publicKey2);
    secretKey2 = generateSecretKey(privateKey2, publicKey1);

    printf("Public Key 1: %d\n", publicKey1);
    printf("Public Key 2: %d\n\n", publicKey2);

    printf("Private Key 1: %d\n", privateKey1);
    printf("Private Key 2: %d\n\n", privateKey2);

    printf("Secret Key 1: %d\n", secretKey1);
    printf("Secret Key 2: %d\n\n", secretKey2);

    printf("Encrypting message...\n\n");

    // Encrypt the message
    for(int i=0; i<strlen(message); i++)
    {
        int temp = (int)message[i];
        temp = (temp*secretKey1)%P;
        message[i] = (char)temp;
    }

    printf("Encrypted Message: %s\n", message);

    // Decrypt the message
    for(int i=0; i<strlen(message); i++)
    {
        int temp = (int)message[i];
        temp = (temp*secretKey2)%P;
        message[i] = (char)temp;
    }

    printf("Decrypted Message: %s\n", message);

    return 0;
}