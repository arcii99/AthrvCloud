//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        message[i] = message[i] + key % 26;
        if (message[i] > 'z') {
            message[i] = message[i] - 26;
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

    printf("Encrypted message: %s", message);

    return 0;
}