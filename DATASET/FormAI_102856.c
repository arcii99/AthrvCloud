//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = (input[i] ^ key[i % key_len]);
    }
    output[i] = '\0';
}

void decrypt(char *input, char *output, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = (input[i] ^ key[i % key_len]);
    }
    output[i] = '\0';
}

int main() {
    char input[1000], output[1000], key[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    printf("Enter the key: ");
    scanf("%s", key);
    encrypt(input, output, key);
    printf("Encrypted string: %s\n", output);
    decrypt(output, input, key);
    printf("Original string: %s\n", input);
    return 0;
}