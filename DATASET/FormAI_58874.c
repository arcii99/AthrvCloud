//FormAI DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char *message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[200];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 200, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}