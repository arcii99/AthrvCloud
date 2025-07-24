//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PUBLIC_KEY 65537

int main()
{
    // Generate random numbers for prime factors
    srand(time(NULL));
    int prime1 = rand() % 1000 + 1000;
    int prime2 = rand() % 1000 + 1000;

    // Calculate modulus
    int modulus = prime1 * prime2;

    // Calculate Euler's Totient function
    int totient = (prime1 - 1) * (prime2 - 1);

    // Find public key
    int public_key = PUBLIC_KEY;

    // Find private key
    int private_key = 0;
    for(int i=1; i<=totient; i++)
    {
        if((i * public_key) % totient == 1)
        {
            private_key = i;
            break;
        }
    }

    // Display public key, private key and modulus
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Modulus: %d\n", modulus);

    // Take user input for message to be encrypted
    char message[1000];
    printf("Enter message to be encrypted: ");
    fgets(message, 1000, stdin);

    // Perform encryption
    int encrypted_message[1000];
    for(int i=0; i<strlen(message); i++)
    {
        encrypted_message[i] = (int)message[i];
        for(int j=1; j<public_key; j++)
        {
            encrypted_message[i] *= encrypted_message[i];
            encrypted_message[i] %= modulus;
        }
    }

    // Display encrypted message
    printf("Encrypted message: ");
    for(int i=0; i<strlen(message); i++)
    {
        printf("%d ", encrypted_message[i]);
    }

    // Perform decryption
    char decrypted_message[1000];
    for(int i=0; i<strlen(message); i++)
    {
        int encrypt_temp = encrypted_message[i];
        for(int j=1; j<private_key; j++)
        {
            encrypted_message[i] *= encrypt_temp;
            encrypted_message[i] %= modulus;
        }
        decrypted_message[i] = (char)encrypted_message[i];
    }

    // Display decrypted message
    printf("\nDecrypted message: %s\n", decrypted_message);

    return 0;
}