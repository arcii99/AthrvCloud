//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], char key[]) {
    int len = strlen(message);
    int keylen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < len; ++i, ++j) {
        if (j == keylen) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

int main() {
    char message[1000], key[100];

    printf("Enter the original message (max 1000 characters): ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);

    printf("\nEncrypted Message: %s", message);

    return 0;
}