//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// function to encrypt the message
void encrypt(char* msg, int key)
{
    int i;

    for(i = 0; msg[i] != '\0'; ++i)
        msg[i] += key;   
}

// function to decrypt the message
void decrypt(char* msg, int key)
{
    int i;

    for(i = 0; msg[i] != '\0'; ++i)
        msg[i] -= key;
}

int main()
{
    char message[100];
    int key;

    // input message and key from user
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    // encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    // decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}