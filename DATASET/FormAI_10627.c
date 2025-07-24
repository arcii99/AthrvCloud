//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the input string
void encrypt(char* message, char* key)
{
    int msgLen = strlen(message), keyLen = strlen(key);
    char encrypted[msgLen];

    for (int i = 0; i < msgLen; i++) {
        // xor each character of message with
        // corresponding character of key
        encrypted[i] = message[i] ^ key[i % keyLen];
    }
    encrypted[msgLen] = '\0';

    printf("Encrypted Message: %s\n", encrypted);
}

int main()
{
    char message[100], key[100];

    printf("Enter a Message: ");
    fgets(message, 100, stdin);

    // remove trailing newline character from message
    message[strcspn(message, "\n")] = 0;

    printf("Enter a Key: ");
    fgets(key, 100, stdin);

    // remove trailing newline character from key
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);

    return 0;
}