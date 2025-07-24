//FormAI DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j = 0;

    // Multi-variable style
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = ((message[i] - 'a' + (key[j] - 'a')) % 26) + 'a';
    }
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j = 0;

    // Multi-variable style
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = ((((message[i] - 'a') - (key[j] - 'a')) + 26) % 26) + 'a';
    }
}

int main() {
    char message[100], key[100];
    printf("Enter the message you want to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}