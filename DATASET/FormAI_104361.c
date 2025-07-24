//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key);

int main() {
    printf("Welcome to the Brave Encryption System!\n");

    char input[100];
    printf("Please enter the message you want to encrypt: ");
    scanf("%s", input);

    char key[11];
    printf("Please enter an encryption key (10 characters): ");
    scanf("%s", key);

    encrypt(input, key);

    printf("Your encrypted message is: %s\n", input);

    return 0;
}

void encrypt(char *input, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    // Xor each character in input with corresponding character in key
    for (int i = 0; i < input_len; i++) {
        input[i] ^= key[i % key_len];
    }
}