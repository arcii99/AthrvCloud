//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {

    int messageLen = strlen(message), keyLen = strlen(key);
    char *encryptedMessage = calloc(messageLen + 1, sizeof(char));

    for (int i = 0; i < messageLen; i++) {
        encryptedMessage[i] = message[i] ^ key[i % keyLen];
    }

    printf("Encrypted message: %s\n", encryptedMessage);
}

void decrypt(char *encryptedMessage, char *key) {

    int messageLen = strlen(encryptedMessage), keyLen = strlen(key);
    char *decryptedMessage = calloc(messageLen + 1, sizeof(char));

    for (int i = 0; i < messageLen; i++) {
        decryptedMessage[i] = encryptedMessage[i] ^ key[i % keyLen];
    }

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {

    char message[100], key[50];
    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter key to encrypt the message: ");
    scanf(" %s", key);

    encrypt(message, key);

    char encryptedMessage[100];
    strcpy(encryptedMessage, message);
    printf("Enter key to decrypt the message: ");
    scanf(" %s", key);

    decrypt(encryptedMessage, key);

    return 0;
}