//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

char* encrypt(char* message, int key) {
    char* encryptedMessage = (char*) malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    int i;
    for(i=0; i<strlen(message); i++) {
        encryptedMessage[i] = message[i] + key;
    }
    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

char* decrypt(char* encryptedMessage, int key) {
    char* decryptedMessage = (char*) malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    int i;
    for(i=0; i<strlen(encryptedMessage); i++) {
        decryptedMessage[i] = encryptedMessage[i] - key;
    }
    decryptedMessage[i] = '\0';
    return decryptedMessage;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key;
    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter your key: ");
    scanf("%d", &key);

    char* encryptedMessage = encrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);
    return 0;
}