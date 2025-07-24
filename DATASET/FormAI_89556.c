//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototype */
void encrypt(char *message, int key);

int main()
{
    char message[1000];
    int key;

    /* Read message and encryption key */
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    /* Encrypt the message */
    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);

    return 0;
}

/* Function to encrypt the message using the key */
void encrypt(char *message, int key)
{
    int i;

    /* Traverse through message and perform encryption */
    for(i = 0; i < strlen(message); i++)
    {
        /* Ignore spaces */
        if(message[i] == ' ')
            continue;

        /* Encrypt uppercase characters */
        if(message[i] >= 'A' && message[i] <= 'Z')
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';

        /* Encrypt lowercase characters */
        if(message[i] >= 'a' && message[i] <= 'z')
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }

    return;
}