//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key
#define KEY "MySecretKey12345"

// Safe string copy to prevent buffer overflow
void safeStrCpy(char *dest, const char *src, size_t destSize) {
    size_t i;
    for (i = 0; i < destSize && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i == destSize) {
        dest[i - 1] = '\0';
    } else {
        dest[i] = '\0';
    }
}

// Encrypt function
void encrypt(char *str, size_t strSize) {
    size_t keyLen = strlen(KEY);
    size_t i;
    for (i = 0; i < strSize; i++) {
        str[i] ^= KEY[i % keyLen];
    }
}

int main() {
    char originalMessage[256];
    safeStrCpy(originalMessage, "Hello World! This is my secret message.", sizeof(originalMessage));
    size_t messageLen = strlen(originalMessage);

    // Encrypt the message
    encrypt(originalMessage, messageLen);

    // Print the encrypted message
    printf("Encrypted message: %s\n", originalMessage);

    // Decrypt the message
    encrypt(originalMessage, messageLen);

    // Print the decrypted message
    printf("Decrypted message: %s\n", originalMessage);

    return 0;
}