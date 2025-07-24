//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char *input, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    // Generate random seed based on current time
    srand(time(NULL));

    // Build encryption key from input and random numbers
    char encryption_key[input_len + key_len];

    int i, j;
    for (i = 0; i < input_len; i++) {
        if (i < key_len) {
            encryption_key[i] = key[i];
        } else {
            encryption_key[i] = rand() % 94 + 32;
        }
    }

    // Encrypt input message
    char encrypted[input_len + 1];

    for (i = 0; i < input_len; i++) {
        int input_char_ascii = (int) input[i] - 32;
        int key_char_ascii = (int) encryption_key[i] - 32;

        int encrypted_char_ascii = (input_char_ascii + key_char_ascii) % 94 + 32;
        encrypted[i] = (char) encrypted_char_ascii;
    }

    encrypted[input_len] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

int main() {
    // Get input message from console
    char input[100];

    printf("Enter message to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    // Get encryption key from console
    char key[100];

    printf("Enter encryption key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;

    // Encrypt input message and output result
    encrypt(input, key);

    return 0;
}