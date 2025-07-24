//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void encrypt(char message[]) {
    int i;
    int key = 5;

    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + key) % 26 + 'a';
    }
}

void decrypt(char message[]) {
    int i;
    int key = 5;

    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] - key + 26) % 26 + 'a';
    }
}

int main() {
    char message[MAX_SIZE];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    encrypt(message);
    printf("\nEncrypted Message: %s", message);

    decrypt(message);
    printf("\nDecrypted Message: %s", message);

    return 0;
}