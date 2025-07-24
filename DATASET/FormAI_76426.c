//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char message[], char key[])
{
    int messagelen = strlen(message);
    int keylen = strlen(key);
    int keypos = 0;
    
    // Applying Vigenere Cipher
    for (int i = 0; i < messagelen; i++)
    {
        message[i] = (message[i] + key[keypos]) % 26;
        message[i] += 'A';
        keypos++;
        if (keypos == keylen)
            keypos = 0;
    }
}

// Function to decrypt the message
void decrypt(char message[], char key[])
{
    int messagelen = strlen(message);
    int keylen = strlen(key);
    int keypos = 0;

    // Reversing Vigenere Cipher
    for (int i = 0; i < messagelen; i++)
    {
        message[i] -= 'A';
        message[i] = (message[i] - key[keypos] + 26) % 26;
        message[i] += 'A';
        keypos++;
        if (keypos == keylen)
            keypos = 0;
    }
}

int main()
{
    char message[100], key[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    fgets(key, 100, stdin);
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);
    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);
    return 0;
}