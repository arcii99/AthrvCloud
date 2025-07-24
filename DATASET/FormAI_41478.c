//FormAI DATASET v1.0 Category: modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key) {
    for(int i = 0; message[i] != '\0'; ++i) {
        message[i] = (message[i] + key) % 128;
    }
}

void decrypt(char* message, int key) {
    for(int i = 0; message[i] != '\0'; ++i) {
        message[i] = (message[i] - key + 128) % 128;
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);
    getchar();

    printf("Enter a key: ");
    scanf("%d", &key);
    getchar();

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}