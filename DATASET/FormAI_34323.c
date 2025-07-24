//FormAI DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++)
        message[i] = message[i] + key;
}

void decrypt(char *message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++)
        message[i] = message[i] - key;
}

int main() {
    char message[100], ch;
    int i, key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}