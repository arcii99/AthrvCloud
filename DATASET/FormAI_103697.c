//FormAI DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the message
void encrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; ++i)
        message[i] += key;  
}

// Function to decrypt the message
void decrypt(char* message, int key)
{
    int i;
    for(i = 0; message[i] != '\0'; ++i)
        message[i] -= key;
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}