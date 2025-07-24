//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
/* This program demonstrates a unique encryption technique using C language */

#include <stdio.h>
#include <string.h>

/* Function to encrypt the message */
void encrypt(char message[])
{
    int i;
    int key = 4; /* Key used for encryption */
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        message[i] = message[i] + key; /* Add key to each character */
    }
}

/* Function to decrypt the message */
void decrypt(char message[])
{
    int i;
    int key = 4; /* Key used for decryption */
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        message[i] = message[i] - key; /* Subtract key from each character */
    }
}

/* Main function */
int main()
{
    char message[100];

    /* Input message from user */
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    /* Encrypt and print the message */
    encrypt(message);
    printf("Encrypted message: %s", message);

    /* Decrypt and print the message */
    decrypt(message);
    printf("Decrypted message: %s", message);

    return 0;
}