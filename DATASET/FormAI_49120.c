//FormAI DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encrypt(char *message, char *key)
{
    int msglen = strlen(message);
    int keylen = strlen(key);
    int i, j;

    for (i=0, j=0; i<msglen; i++, j++)
    {
        if (j == keylen)
            j = 0;
        message[i] = (message[i] + key[j]) % 256;
    }
}

void decrypt(char *message, char *key)
{
    int msglen = strlen(message);
    int keylen = strlen(key);
    int i, j;

    for (i=0, j=0; i<msglen; i++, j++)
    {
        if (j == keylen)
            j = 0;
        message[i] = (message[i] - key[j] + 256) % 256;
    }
}

int main()
{
    char message[100], key[100], encrypted[100], decrypted[100];

    printf("Enter message: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    fgets(key, 100, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}