//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "abcdefghijklmnopqrstuvwxyz" //encryption key

void encrypt(char *input, char *output) {
    int i, j;
    int len = strlen(input);
    int key_len = strlen(KEY);
    for(i=0; i<len; i++) {
        j = i % key_len; //get key character for current position
        output[i] = input[i] ^ KEY[j]; //encrypt input character with key character
    }
    output[i] = '\0'; //add null terminator
}

void decrypt(char *input, char *output) {
    int i, j;
    int len = strlen(input);
    int key_len = strlen(KEY);
    for(i=0; i<len; i++) {
        j = i % key_len; //get key character for current position
        output[i] = input[i] ^ KEY[j]; //decrypt input character with key character
    }
    output[i] = '\0'; //add null terminator
}

int main() {
    char input[100], output[100];
    printf("Enter text to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; //remove newline character from input
    encrypt(input, output);
    printf("Encrypted text: %s\n", output);
    decrypt(output, input);
    printf("Decrypted text: %s\n", input);
    return 0;
}