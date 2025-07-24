//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

void encrypt(char* message, const char* key) {
    size_t len = strlen(key);
    size_t message_length = strlen(message);
    for (size_t i = 0; i < message_length; ++i) {
        message[i] ^= key[i % len];
    }
}

void decrypt(char* message, const char* key) {
    encrypt(message, key);
}

int main() {
    char message[256] = "Life is like a box of chocolates, you never know what you're gonna get.";
    char key[256] = "encryption";

    printf("Original message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}