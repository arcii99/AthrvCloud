//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_str, char *key) {
    int len = strlen(key);
    int i, j = 0;
    for (i = 0; i < strlen(input_str); i++) {
        input_str[i] = input_str[i] ^ key[j % len];
        j++;
    }
}

void decrypt(char *input_str, char *key) {
    int len = strlen(key);
    int i, j = 0;
    for (i = 0; i < strlen(input_str); i++) {
        input_str[i] = input_str[i] ^ key[j % len];
        j++;
    }
}

int main() {
    char input_str[100], key[100];
    printf("Enter a string to encrypt: ");
    fgets(input_str, 100, stdin);
    strtok(input_str, "\n");
    printf("Enter a key: ");
    fgets(key, 100, stdin);
    strtok(key, "\n");
    encrypt(input_str, key);
    printf("Encrypted string: %s\n", input_str);
    decrypt(input_str, key);
    printf("Decrypted string: %s\n", input_str);
    return 0;
}