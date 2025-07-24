//FormAI DATASET v1.0 Category: modern Encryption ; Style: bold
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char message[])
{
    int i, key = 3; // The key for encryption is set to 3

    // Loop through each character of the message
    for(i = 0; message[i] != '\0'; i++)
    {
        // Shift the character by the key value
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

int main()
{
    char message[100];

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    // Remove the newline character
    message[strlen(message) - 1] = '\0';

    // Print the original message
    printf("Original message: %s\n", message);

    // Encrypt the message
    encrypt(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}