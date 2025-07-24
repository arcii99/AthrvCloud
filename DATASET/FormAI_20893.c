//FormAI DATASET v1.0 Category: Modern Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3

void encrypt(char* message) {
    int length = strlen(message);

    for(int i=0; i<length; i++) {
        message[i] = message[i] + KEY;
    }
}

void decrypt(char* message) {
    int length = strlen(message);

    for(int i=0; i<length; i++) {
        message[i] = message[i] - KEY;
    }
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    encrypt(message);
    printf("\nEncrypted message: %s\n", message);

    decrypt(message);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}