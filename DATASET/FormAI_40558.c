//FormAI DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform XOR encryption
void encrypt(char *input, char *key, char *output) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int key_index = 0;

    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[key_index];

        key_index++;
        if (key_index == key_len) {
            key_index = 0;
        }
    }
}

int main() {
    char input_text[100];
    char key[100];
    char encrypted_text[100];

    printf("Enter text to be encrypted: ");
    fgets(input_text, 100, stdin);
    input_text[strcspn(input_text, "\n")] = 0;

    printf("Enter encryption key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt(input_text, key, encrypted_text);
    printf("Encrypted text: %s\n", encrypted_text);

    return 0;
}