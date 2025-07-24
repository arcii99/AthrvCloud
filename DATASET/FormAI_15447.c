//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *plaintext, int key)
{
    int i;
    char c;
    int len = strlen(plaintext);

    for(i = 0; i < len; i++)
    {
        c = plaintext[i];

        if(c >= 'a' && c <= 'z')
        {
            c = c + key;

            if(c > 'z')
            {
                c = c - 'z' + 'a' - 1;
            }

            plaintext[i] = c;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c = c + key;

            if(c > 'Z')
            {
                c = c - 'Z' + 'A' - 1;
            }

            plaintext[i] = c;
        }
    }
}

void decrypt(char *ciphertext, int key)
{
    int i;
    char c;
    int len = strlen(ciphertext);

    for(i = 0; i < len; i++)
    {
        c = ciphertext[i];

        if(c >= 'a' && c <= 'z')
        {
            c = c - key;

            if(c < 'a')
            {
                c = c + 'z' - 'a' + 1;
            }

            ciphertext[i] = c;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c = c - key;

            if(c < 'A')
            {
                c = c + 'Z' - 'A' + 1;
            }

            ciphertext[i] = c;
        }
    }
}