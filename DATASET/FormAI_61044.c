//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key)
{
    int msgLen = strlen(message);
    for(int i = 0; i < msgLen; ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (((message[i] - 'a') + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
    }
}

void decrypt(char* message, int key)
{
    int msgLen = strlen(message);
    for(int i = 0; i < msgLen; ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (((message[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';
        }
    }
}

int main()
{
    int key;
    char message[100];

    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, 100, stdin); // read multiple words from user

    printf("Enter the key (shift): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("\nEncrypted message: %s", message);

    decrypt(message, key);
    printf("\nDecrypted message: %s", message);

    return 0;
}