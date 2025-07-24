//FormAI DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *msg, int key) {
    int length = strlen(msg);
    for (int i = 0; i < length; i++) {
        if (msg[i] != ' ') {
            msg[i] += key;
        }
    }
}

void decrypt(char *msg, int key) {
    int length = strlen(msg);
    for (int i = 0; i < length; i++) {
        if (msg[i] != ' ') {
            msg[i] -= key;
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}