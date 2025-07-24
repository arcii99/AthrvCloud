//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the message
void encrypt(char *message, char *key) {
    int i, j;
    int msgLen = strlen(message);
    int keyLen = strlen(key);
    char newKey[msgLen]; // new key for encryption

    // generate new key by repeating the original key to match the length of message
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    // encrypt the message using XOR operation
    for (i = 0; i < msgLen; ++i)
        message[i] = message[i] ^ newKey[i];
}

int main() {
    char message[100];
    char key[50];

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    fgets(key, 50, stdin);

    // remove newline characters from input
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // encrypt the message
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}