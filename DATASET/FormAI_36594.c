//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 4 // This is the key used for encryption

void encrypt(char* text, int key)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char)((text[i] - 'a' + key) % 26 + 'a');
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char)((text[i] - 'A' + key) % 26 + 'A');
        }
    }
}

void decrypt(char* text, int key)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char)((text[i] - 'a' - key + 26) % 26 + 'a');
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char)((text[i] - 'A' - key + 26) % 26 + 'A');
        }
    }
}

int main()
{
    char input[1000];

    printf("Enter text to encrypt: ");
    fgets(input, 1000, stdin);

    encrypt(input, KEY);

    printf("Encrypted text: %s\n", input);

    decrypt(input, KEY);

    printf("Decrypted text: %s\n", input);

    return 0;
}