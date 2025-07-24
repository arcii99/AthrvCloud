//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 256

void encrypt(char *str, char *key) {
    int i, j = 0;
    int len = strlen(str);
    int key_len = strlen(key);

    for (i = 0; i < len; i++) {
        int k = key[j++ % key_len];
        str[i] ^= k;
    }
}

void decrypt(char *str, char *key) {
    encrypt(str, key);
}

int main() {
    char plaintext[KEY_LENGTH];
    char key[KEY_LENGTH];

    printf("Enter the string to encrypt: ");
    fgets(plaintext, KEY_LENGTH, stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    printf("Enter the key: ");
    fgets(key, KEY_LENGTH, stdin);
    key[strlen(key) - 1] = '\0';

    printf("\nPlaintext: %s\nKey: %s\n", plaintext, key);

    encrypt(plaintext, key);
    printf("Encrypted: %s\n", plaintext);

    decrypt(plaintext, key);
    printf("Decrypted: %s\n", plaintext);

    return 0;
}