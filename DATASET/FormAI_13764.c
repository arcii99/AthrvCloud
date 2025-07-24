//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// encryption key
unsigned char key[] = { 'S', 'e', 'c', 'r', 'e', 't', 'K', 'e', 'y' };

// encryption function
void encrypt(char* message, char* encryptedMessage) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0; i < messageLen; i++) {
        encryptedMessage[i] = message[i] ^ key[i % keyLen];
    }
}

// decryption function
void decrypt(char* encryptedMessage, char* decryptedMessage) {
    int messageLen = strlen(encryptedMessage);
    int keyLen = strlen(key);

    for (int i = 0; i < messageLen; i++) {
        decryptedMessage[i] = encryptedMessage[i] ^ key[i % keyLen];
    }
}

int main() {
    char message[] = "This is a secret message.";
    char encryptedMessage[256];
    char decryptedMessage[256];

    encrypt(message, encryptedMessage);
    printf("Encrypted Message: %s\n", encryptedMessage);

    decrypt(encryptedMessage, decryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}