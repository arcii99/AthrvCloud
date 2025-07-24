//FormAI DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key)
{
    int i, j;
    char *ciphertext = malloc(sizeof(char) * strlen(plaintext) + 1);
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++)
    {
        if (j >= strlen(key))
            j = 0;
        ciphertext[i] = ((plaintext[i] + key[j]) % 126) + 1;
    }
    ciphertext[i] = '\0';
    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key)
{
    int i, j;
    char *plaintext = malloc(sizeof(char) * strlen(ciphertext) + 1);
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++)
    {
        if (j >= strlen(key))
            j = 0;
        plaintext[i] = ((ciphertext[i] - key[j] + 126) % 126) - 1;
    }
    plaintext[i] = '\0';
    printf("Decrypted text: %s\n", plaintext);
}

int main()
{
    char *plaintext = "Hello World";
    char *key = "secret";
    printf("Original text: %s\n", plaintext);
    encrypt(plaintext, key);
    char *ciphertext = "wN^X9zY#\n\n\n\n\n\n";
    decrypt(ciphertext, key);
    return 0;
}