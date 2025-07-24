//FormAI DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    printf("Enter the message to be encrypted: ");
    char message[1000];
    fgets(message, 1000, stdin);

    printf("Enter the encryption key: ");
    int key;
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    decrypt(message, key);

    printf("Decrypted message: %s", message);

    return 0;
}