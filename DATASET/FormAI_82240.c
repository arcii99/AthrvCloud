//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_KEY_LENGTH 100

void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main()
{
    char message[MAX_STRING_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, char* key)
{
    int i, j, k;
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for(i = 0, j = 0; i < messageLen; ++i, ++j)
    {
        if(j == keyLen)
            j = 0;

        k = (message[i] + key[j]) % 26;

        message[i] = k + 'A';
    }
}

void decrypt(char* message, char* key)
{
    int i, j, k;
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for(i = 0, j = 0; i < messageLen; ++i, ++j)
    {
        if(j == keyLen)
            j = 0;

        k = (message[i] - key[j] + 26) % 26;

        message[i] = k + 'A';
    }
}