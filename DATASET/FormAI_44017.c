//FormAI DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void encrypt(char text[], int key);
void decrypt(char text[], int key);

// main function
int main()
{
    char message[1000] = "This is a secret message";
    int key = 10;

    // print original message
    printf("Original message: %s\n", message);

    // encrypt message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // decrypt message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

// function to encrypt text
void encrypt(char text[], int key)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
    }
}

// function to decrypt text
void decrypt(char text[], int key)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}