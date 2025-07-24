//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt the message using the encryption key
void encrypt(char* message)
{
    int keyLen = strlen(KEY);
    int msgLen = strlen(message);
    int i, j;
    char newKey[msgLen], encryptedMsg[msgLen];

    // Generate a new key based on the message length and the original key
    for(i = 0, j = 0; i < msgLen; ++i, ++j)
    {
        if(j == keyLen) j = 0;
        newKey[i] = KEY[j];
    }
    newKey[i] = '\0';

    // Encrypt the message using the new key
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((message[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMsg);
}

int main()
{
    char message[100];

    // Get the message from the user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = 0;

    // Call the encrypt function to encrypt the message
    encrypt(message);

    return 0;
}