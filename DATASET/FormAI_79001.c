//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYPTO_KEY 42

void encrypt(char* message) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + CRYPTO_KEY) % 256;
    }
}

void decrypt(char* message) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - CRYPTO_KEY + 256) % 256;
    }
}

int main() {
    char message[256];

    printf("Enter a message to encrypt: ");
    fgets(message, 256, stdin);

    encrypt(message);

    printf("\nEncrypted message: %s\n", message);

    decrypt(message);

    printf("\nDecrypted message: %s\n", message);

    return 0;
}