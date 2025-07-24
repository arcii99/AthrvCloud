//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char* input, char* key, char* output) {
    int len = strlen(input);
    int key_len = strlen(key);
    for(int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
    output[len] = '\0';
}

void decrypt(char* input, char* key, char* output) {
    encrypt(input, key, output);
}

int main() {
    char input[MAX_LENGTH];
    char key[MAX_LENGTH];
    char output[MAX_LENGTH];
    printf("Enter the message to encrypt: ");
    fgets(input,MAX_LENGTH,stdin);
    printf("Enter the encryption key: ");
    fgets(key,MAX_LENGTH,stdin);
    encrypt(input, key, output);
    printf("Encrypted message: %s\n", output);
    decrypt(output, key, input);
    printf("Decrypted message: %s\n", input);
    return 0;
}