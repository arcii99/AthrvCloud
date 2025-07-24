//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for (i = 0; i < msg_len; i++) {
        message[i] ^= key[i % key_len];
    }
}

void decrypt(char* message, char* key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for (i = 0; i < msg_len; i++) {
        message[i] ^= key[i % key_len];
    }
}

int main() {
    char message[1024], key[1024];

    printf("Welcome to the C Encryption program!\n\n");
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    printf("Encrypting message...\n");
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Decrypting message...\n");
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    printf("\nThank you for using the C Encryption program!\n");
    return 0;
}