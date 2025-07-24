//FormAI DATASET v1.0 Category: modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message
void encrypt(char *message, int key)
{
    int message_length = strlen(message);
    
    // Loop through each character in the message
    for (int i = 0; i < message_length; i++)
    {
        // Ignore spaces and punctuation
        if (message[i] != ' ' && message[i] != ',' && message[i] != '.' && message[i] != '?')
        {
            // Shift the character by the key value
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

int main()
{
    // Get the message to encrypt from the user
    char message[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character
    
    // Get the encryption key from the user
    int key;
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    // Encrypt the message
    encrypt(message, key);
    
    // Print the encrypted message
    printf("\nEncrypted Message: %s\n", message);
    
    return 0;
}