//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] += key;
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] -= key;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    decrypt(message, key);

    printf("Decrypted message: %s", message);

    return 0;
}