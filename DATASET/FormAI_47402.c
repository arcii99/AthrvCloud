//FormAI DATASET v1.0 Category: Modern Encryption ; Style: unmistakable
#include <stdio.h>
#include <string.h>

char* encrypt(char* input, int key) {
    int len = strlen(input);
    char* encrypted = (char*) malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                encrypted[i] = (((input[i] - 65) + key) % 26) + 65;
            } else {
                encrypted[i] = (((input[i] - 97) + key) % 26) + 97;
            }
        } else {
            encrypted[i] = input[i];
        }
    }

    encrypted[len] = '\0';
    return encrypted;
}

void main() {
    int key = 3;
    char input[100];

    printf("Enter a message to encrypt: ");
    fgets(input, 100, stdin);

    printf("Original message: %s", input);

    char* encrypted = encrypt(input, key);

    printf("Encrypted message: %s", encrypted);

    free(encrypted);
}