//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, char* key);

int main() {
    char message[100];
    char key[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key: ");
    fgets(key, 100, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char* message, char* key) {
    int lenMessage = strlen(message);
    int lenKey = strlen(key);

    for (int i = 0; i < lenMessage; i++) {
        message[i] = message[i] ^ key[i % lenKey];
    }
}