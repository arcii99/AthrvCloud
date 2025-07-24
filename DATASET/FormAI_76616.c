//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key that is used for encryption
const char KEY = 'A';

void encrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char current = message[i];
        // Shift the character by the key value
        message[i] = (current + KEY) % 256;
    }
}

void decrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char current = message[i];
        // Reverse the shift by the key value
        message[i] = (current - KEY + 256) % 256;
    }
}

int main() {
    // Message to encrypt
    char message[] = "Hello, World!";
    printf("Original Message: %s\n", message);

    // Encrypt the message and print encrypted message
    encrypt(message);
    printf("Encrypted Message: %s\n", message);

    // Decrypt the message and print decrypted message
    decrypt(message);
    printf("Decrypted Message: %s\n", message);

    return 0;
}