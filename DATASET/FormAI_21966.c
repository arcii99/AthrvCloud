//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void xor_encrypt(char *input, char *key, char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
}

int main() {
    char input[MAX_LENGTH];
    char key[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;

    printf("Enter input message: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_LENGTH, stdin);

    length = strlen(input) - 1;
    xor_encrypt(input, key, output, length);

    printf("\nEncrypted message: ");
    for (int i = 0; i < length; i++) {
        printf("%02x", output[i]);
    }

    xor_encrypt(output, key, input, length);

    printf("\nDecrypted message: %s\n", input);

    return 0;
}