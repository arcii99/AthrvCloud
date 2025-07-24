//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, int key) {
    int i = 0;
    while (input[i] != '\0') {
       input[i] ^= key;
       i++;
    }
}

void decrypt(char *input, int key) {
    int i = 0;
    while (input[i] != '\0') {
       input[i] ^= key;
       i++;
    }
}

int main() {
    char message[100], encryptedMessage[100], decryptedMessage[100];
    int key;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypting the message
    strcpy(encryptedMessage, message);
    encrypt(encryptedMessage, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypting the encrypted message
    strcpy(decryptedMessage, encryptedMessage);
    decrypt(decryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}