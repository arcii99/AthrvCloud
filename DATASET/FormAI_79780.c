//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int messageLen = strlen(message), keyLen = strlen(key), i, j;
    char newKey[messageLen], encryptedMsg[messageLen];

    // Generating new key by repeating the original key
    for(i = 0, j = 0; i < messageLen; ++i, ++j) {
        if(j == keyLen) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    // Encrypting the message using XOR operator
    for(i = 0; i < messageLen; ++i) {
        encryptedMsg[i] = ((message[i] ^ newKey[i]) + 65);
    }

    encryptedMsg[i] = '\0';

    printf("Encrypted message: %s", encryptedMsg);
}

int main() {
    char message[100], key[100];

    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the key to use for encryption: ");
    fgets(key, 100, stdin);

    encrypt(message, key);

    return 0;
}