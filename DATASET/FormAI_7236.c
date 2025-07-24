//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ENCRYPTION_KEY 5

// Function to encrypt a character
char encryptChar(char c) {
    return c + ENCRYPTION_KEY;
}

// Function to decrypt a character
char decryptChar(char c) {
    return c - ENCRYPTION_KEY;
}

int main() {

    char buffer[BUFFER_SIZE];
    char encryptedBuffer[BUFFER_SIZE];
    char decryptedBuffer[BUFFER_SIZE];

    printf("Enter a message to be encrypted: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Encrypting the message
    for(int i = 0; i < strlen(buffer); i++) {
        encryptedBuffer[i] = encryptChar(buffer[i]);
    }

    printf("Encrypted message: %s\n", encryptedBuffer);

    // Decrypting the message
    for(int i = 0; i < strlen(encryptedBuffer); i++) {
        decryptedBuffer[i] = decryptChar(encryptedBuffer[i]);
    }

    printf("Decrypted message: %s\n", decryptedBuffer);

    return 0;
}