//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>

#define MAXSIZE 1000

void encrypt(char message[], int key) {
    int i = 0;
    char encryptedMessage[MAXSIZE];

    while(message[i] != '\0') {
        // shift each character by the key value
        encryptedMessage[i] = message[i] + key;
        i++;
    }

    encryptedMessage[i] = '\0';  // add terminator at the end of the string

    printf("Encrypted Message: %s\n", encryptedMessage);
}

void decrypt(char message[], int key) {
    int i = 0;
    char decryptedMessage[MAXSIZE];

    while(message[i] != '\0') {
        // shift each character back by the key value
        decryptedMessage[i] = message[i] - key;
        i++;
    }

    decryptedMessage[i] = '\0';  // add terminator at the end of the string

    printf("Decrypted Message: %s\n", decryptedMessage);
}

int main() {
    char message[MAXSIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAXSIZE, stdin);

    printf("Enter a value for the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}