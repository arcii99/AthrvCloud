//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] += key;
    }
}

void decrypt(char* message, int key)
{
    int len = strlen(message);
    for(int i = 0; i < len; i++)
    {
        message[i] -= key;
    }
}

int main()
{
    char* message = "Hello, World!";
    int key = 5;

    printf("Original message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}