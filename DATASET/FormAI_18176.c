//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext);

int main()
{
    char plaintext[100] = "Hello, World!";
    char key[100] = "secretkey";
    char ciphertext[100];

    encrypt(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

void encrypt(char *plaintext, char *key, char *ciphertext)
{
    int i;
    int n = strlen(plaintext);
    int key_len = strlen(key);

    for (i = 0; i < n; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[n] = '\0';
}