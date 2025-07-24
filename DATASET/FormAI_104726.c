//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretkey"

void encrypt(char* input, char* output, char* key) {
    int key_length = strlen(key);

    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }

    output[strlen(input)] = '\0';
}

void decrypt(char* input, char* output, char* key) {
    int key_length = strlen(key);

    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }

    output[strlen(input)] = '\0';
}

int main() {
    char input[100], output[100], decrypt_output[100];

    printf("Enter text: ");
    fgets(input, 100, stdin);

    encrypt(input, output, KEY);

    printf("Encrypted text: %s\n", output);

    decrypt(output, decrypt_output, KEY);

    printf("Decrypted text: %s\n", decrypt_output);

    return 0;
}