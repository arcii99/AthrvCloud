//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* text, char* key)
{
    int key_length = strlen(key);

    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] ^ key[i % key_length];
    }
}

void decrypt(char* text, char* key)
{
    int key_length = strlen(key);

    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] ^ key[i % key_length];
    }
}

int main()
{
    char text[100];
    char key[100];

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    printf("\nOriginal text: %s", text);

    encrypt(text, key);

    printf("\nEncrypted text: %s", text);

    decrypt(text, key);

    printf("\nDecrypted text: %s", text);

    return 0;
}