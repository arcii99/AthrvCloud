//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key) {
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}