//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
    char message[MAX_LENGTH];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter a key to use for encryption: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key)
{
    int i;

    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
    }
}

void decrypt(char *message, int key)
{
    int i;

    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}