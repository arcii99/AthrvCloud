//FormAI DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        message[i] = message[i] + key % i;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}