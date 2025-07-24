//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) {
        message[i] ^= key[i % key_len];
    }
}

void decrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) {
        message[i] ^= key[i % key_len];
    }
}

int main() {
    char message[100];
    char key[100];
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}