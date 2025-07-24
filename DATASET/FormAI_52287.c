//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key);

int main()
{
    char message[100], key[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);
    
    // Removing newline characters from input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char *message, char *key)
{
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    // Finding difference in lengths
    int diff = message_len - key_len;

    if (diff > 0)
    {
        // Padding key with itself until its length is equal to message length
        while (diff > 0)
        {
            strcat(key, key);
            key_len = strlen(key);
            diff = message_len - key_len;
        }
    }
    
    // XORing message with key
    for (int i = 0; i < message_len; i++)
    {
        message[i] ^= key[i];
    }
}