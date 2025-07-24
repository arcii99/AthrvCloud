//FormAI DATASET v1.0 Category: modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i;

    // Apply XOR operation on corresponding characters
    for (i = 0; i < messageLength; i++) {
        message[i] = message[i] ^ key[i % keyLength];
    }
}

void decrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i;

    // Apply XOR operation on corresponding characters
    for (i = 0; i < messageLength; i++) {
        message[i] = message[i] ^ key[i % keyLength];
    }
}

int main() {
    char message[1000], key[1000];
    printf("Enter the message: ");
    fgets(message, 1000, stdin);

    printf("Enter the key: ");
    fgets(key, 1000, stdin);

    // Remove newline characters
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    printf("\nOriginal Message: %s\n", message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}