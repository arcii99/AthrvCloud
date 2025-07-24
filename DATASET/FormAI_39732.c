//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the key for encryption
unsigned char key[] = "thisiskeyforencryption";

// encryption function
char* encrypt(char* message) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    char* encryptedMessage = (char*) malloc((messageLength + 1) * sizeof(char));
    int i, j;
    for (i = 0; i<messageLength; i++) {
        j = (i % keyLength);
        encryptedMessage[i] = message[i] ^ key[j];
    }
    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

// decryption function
char* decrypt(char* encryptedMessage) {
    int messageLength = strlen(encryptedMessage);
    int keyLength = strlen(key);
    char* decryptedMessage = (char*) malloc((messageLength + 1) * sizeof(char));
    int i, j;
    for (i = 0; i<messageLength; i++) {
        j = (i % keyLength);
        decryptedMessage[i] = encryptedMessage[i] ^ key[j];
    }
    decryptedMessage[i] = '\0';
    return decryptedMessage;
}

int main() {
    char message[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    char* encryptedMessage = encrypt(message);
    printf("Encrypted message: %s\n", encryptedMessage);
    char* decryptedMessage = decrypt(encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);
    free(encryptedMessage);
    free(decryptedMessage);
    return 0;
}