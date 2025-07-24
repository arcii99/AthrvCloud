//FormAI DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>
#define KEY 5

void encrypt(char message[]) {
    int length = strlen(message);
    for(int i = 0; i < length; i++) {
        message[i] += KEY;
    }
}

void decrypt(char message[]) {
    int length = strlen(message);
    for(int i = 0; i < length; i++) {
        message[i] -= KEY;
    }
}

int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    encrypt(message);
    printf("Encrypted message: %s", message);

    decrypt(message);
    printf("Decrypted message: %s", message);

    return 0;
}