//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Key generation function */
void generate_key(char *key, int key_len) {
    int i;
    for (i = 0; i < key_len; i++) {
        key[i] = rand() % 256; /* Generate random key */
    }
}

/* Encryption function */
void encrypt(char *input, char *output, char *key, int input_len, int key_len) {
    int i;
    for (i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len]; /* XOR encryption */
    }
}

/* Decryption function */
void decrypt(char *input, char *output, char *key, int input_len, int key_len) {
    encrypt(input, output, key, input_len, key_len); /* XOR decryption is the same as encryption */
}

int main() {
    char input[] = "Hello, world!"; /* Sample input */
    int input_len = strlen(input);
    char key[input_len];
    generate_key(key, input_len); /* Generate key */
    char encrypted[input_len];
    encrypt(input, encrypted, key, input_len, input_len); /* Encrypt input */
    char decrypted[input_len];
    decrypt(encrypted, decrypted, key, input_len, input_len); /* Decrypt encrypted data */
    printf("Original input: %s\n", input);
    printf("Encrypted data: ");
    int i;
    for (i = 0; i < input_len; i++) {
        printf("%02x", (unsigned char)encrypted[i]); /* Print encrypted data in hexadecimal format */
    }
    printf("\nDecrypted data: %s\n", decrypted);
    return 0;
}