//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char msg[])
{
    int len = strlen(msg); // Get the length of the message
    for (int i = 0; i < len; ++i)
    {
        msg[i] = msg[i] + 1; // Add 1 to each character
    }
}

// Function to decrypt the message
void decrypt(char msg[])
{
    int len = strlen(msg); // Get the length of the message
    for (int i = 0; i < len; ++i)
    {
        msg[i] = msg[i] - 1; // Subtract 1 from each character
    }
}

int main()
{
    char message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message);

    printf("Decrypted message: %s\n", message);

    return 0;
}