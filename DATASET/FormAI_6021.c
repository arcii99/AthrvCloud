//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>

void encrypt(char* message) {
    int key = 23;
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char* message) {
    int key = 23;
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    encrypt(message);

    printf("Encrypted message: %s\n", message);

    decrypt(message);

    printf("Decrypted message: %s", message);

    return 0;
}