//FormAI DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void xor(char *str, char *key, int len) {
    int key_len = strlen(key);
    for (int i = 0; i < len; i++) {
        str[i] ^= key[i % key_len];
    }
}

int main() {
    char plain_text[MAX_LENGTH];
    char key[MAX_LENGTH];

    printf("Enter plaintext: ");
    scanf("%[^\n]", plain_text);

    printf("Enter key: ");
    scanf(" %[^\n]", key);

    int len = strlen(plain_text);

    xor(plain_text, key, len);

    printf("Encrypted text: %s\n", plain_text);

    xor(plain_text, key, len);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}