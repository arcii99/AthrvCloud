//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk Cryptography Implementation

void encrypt(char* message, char* key) {
    int length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == key_length) j = 0;
        message[i] = message[i] ^ key[j];
    }
}

void decrypt(char* message, char* key) {
    int length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == key_length) j = 0;
        message[i] = message[i] ^ key[j];
    }
}

int main() {
    char message[100];
    char key[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}