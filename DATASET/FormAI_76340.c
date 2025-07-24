//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *key) {
    int i, j, k = 0;
    int len = strlen(input);
    int keylen = strlen(key);
    for (i = 0; i < len; i++) {
        char c = input[i];
        int n = (int)c;
        for (j = 0; j < keylen; j++) {
            n ^= (int)key[j];
        }
        char encrypted = (char)n;
        output[k++] = encrypted;
    }
    output[k] = '\0';
}

int main() {
    char input[100], key[100], output[100];
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", input);
    getchar();
    printf("Enter the encryption key: ");
    scanf("%[^\n]", key);
    encrypt(input, output, key);
    printf("Encrypted message: %s\n", output);
    return 0;
}