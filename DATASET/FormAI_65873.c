//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "Knuth"

void encrypt(char *input, int input_len, char *key, char *output) {
    int key_len = strlen(key);
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

int main(void) {
    char input[100], output[100];
    int input_len;
    printf("Enter the text to encrypt: ");
    fgets(input, 100, stdin);
    input_len = strlen(input) - 1; // Remove '\n' character
    encrypt(input, input_len, KEY, output);
    printf("Encrypted text: %s\n", output);
    return 0;
}