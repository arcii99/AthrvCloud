//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

void printSecretMessage(unsigned char *secretMessage) {
    printf("\nThe secret message is: %s\n", secretMessage);
}

void encodeMessage(unsigned char *message, unsigned char *key) {
    unsigned char secretMessage[MAX_MESSAGE_LENGTH];
    int i, j, k;
    k = 0;

    for (i = 0; i < strlen(message); i++) {
        secretMessage[i] = message[i] ^ key[k];
        k++;
        if (k == strlen(key)) {
            k = 0;
        }
    }
    printSecretMessage(secretMessage);
}

void decodeMessage(unsigned char *secretMessage, unsigned char *key) {
    unsigned char message[MAX_MESSAGE_LENGTH];
    int i, j, k;
    k = 0;
    
    for (i = 0; i < strlen(secretMessage); i++) {
        message[i] = secretMessage[i] ^ key[k];
        k++;
        if (k == strlen(key)) {
            k = 0;
        }
    }
    printf("\nThe decoded message is: %s\n", message);
}

int main() {
    unsigned char message[MAX_MESSAGE_LENGTH];
    unsigned char key[MAX_MESSAGE_LENGTH];
    printf("Welcome to our top-secret message encoder!\n");
    printf("Please enter a message you would like to encode: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Please enter a secret key: ");
    fgets(key, MAX_MESSAGE_LENGTH, stdin);

    encodeMessage(message, key);

    printf("\n\nNow it's time to decode the message!\n");
    printf("Please enter the encoded message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Please enter the secret key: ");
    fgets(key, MAX_MESSAGE_LENGTH, stdin);

    decodeMessage(message, key);

    printf("Thanks for using our super-secret message encoder/decoder!");
    return 0;
}