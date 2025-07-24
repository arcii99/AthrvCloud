//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>

void encrypt(char *message, char *key);

int main() {
    char message[100], key[10];
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key for encryption: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char *message, char *key) {
    int message_len = strlen(message) - 1;
    int key_len = strlen(key) - 1;

    if (message_len <= 0 || key_len <= 0) {
        printf("Invalid message or key!");
        return;
    }

    for (int i = 0, j = 0; i < message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }

        message[i] += key[j];

        if (message[i] > 'z') {
            message[i] -= 26;
        }
    }
}