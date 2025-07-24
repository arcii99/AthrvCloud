//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key)
{
    int len_input = strlen(input);
    int len_key = strlen(key);

    int i, j;

    for(i = 0; i < len_input; i++)
    {
        input[i] ^= key[i % len_key];
    }
}

void decrypt(char *input, char *key)
{
    int len_input = strlen(input);
    int len_key = strlen(key);

    int i, j;

    for(i = 0; i < len_input; i++)
    {
        input[i] ^= key[i % len_key];
    }
}

int main()
{
    char *message = "Hello, World!";
    char *key = "secret";

    printf("Original Message: %s\n", message);
    
    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);
    
    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}