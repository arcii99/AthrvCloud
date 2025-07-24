//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, char* key) {
    int msgLen = strlen(message);
    int keyLen = strlen(key);
    char* encryptedMsg = (char*) malloc(msgLen * sizeof(char));

    for(int i=0; i<msgLen; i++) {
        encryptedMsg[i] = (message[i] + key[i % keyLen]) % 128;
    }

    return encryptedMsg;
}

char* decrypt(char* encryptedMsg, char* key) {
    int msgLen = strlen(encryptedMsg);
    int keyLen = strlen(key);
    char* decryptedMsg = (char*) malloc(msgLen * sizeof(char));

    for(int i=0; i<msgLen; i++) {
        decryptedMsg[i] = (encryptedMsg[i] - key[i % keyLen] + 128) % 128;
    }

    return decryptedMsg;
}

int main() {
    printf("Welcome to the futuristic cryptography program!\n");

    char message[1000];
    char key[1000];
    printf("\nEnter your message: ");
    scanf("%[^\n]%*c", message);
    printf("Enter your secret key: ");
    scanf("%[^\n]%*c", key);

    char* encryptedMsg = encrypt(message, key);
    printf("\nEncrypted message is: %s\n", encryptedMsg);

    char* decryptedMsg = decrypt(encryptedMsg, key);
    printf("\nDecrypted message is: %s\n", decryptedMsg);

    free(encryptedMsg);
    free(decryptedMsg);

    return 0;
}