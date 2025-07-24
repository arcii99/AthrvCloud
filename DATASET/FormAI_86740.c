//FormAI DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key)
{
    int len = strlen(message);
    int i;
    for(i = 0; i < len; ++i)
    {
        message[i] = message[i] + key;
    }
}

void decrypt(char message[], int key)
{
    int len = strlen(message);
    int i;
    for(i = 0; i < len; ++i)
    {
        message[i] = message[i] - key;
    }
}

int main()
{
    char message[100];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key (must be an integer): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    decrypt(message, key);
    printf("Decrypted message: %s", message);
    return 0;
}