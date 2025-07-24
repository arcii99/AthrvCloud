//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

/* Function to encrypt plain text */
void encrypt(char* plain_text, char* key) {
    int i;
    for (i = 0; i < plain_text[i] != '\0'; i++) {
        plain_text[i] = plain_text[i] ^ key[i % strlen(key)];
    }
}

/* Function to decrypt cipher text */
void decrypt(char* cipher_text, char* key) {
    int i;
    for (i = 0; i < cipher_text[i] != '\0'; i++) {
        cipher_text[i] = cipher_text[i] ^ key[i % strlen(key)];
    }
}

int main() {
    char* plain_text = "This is a sample text to encrypt and decrypt";
    char key[10] = "mykey";
    char* cipher_text = malloc(strlen(plain_text) + 1);
    strcpy(cipher_text, plain_text);

    /* Print original plain text */
    printf("Original Plain Text: %s\n", plain_text);

    /* Encrypt and print cipher text */
    encrypt(cipher_text, key);
    printf("Cipher Text: %s\n", cipher_text);

    /* Decrypt and print original plain text */
    decrypt(cipher_text, key);
    printf("Decrypted Plain Text: %s\n", cipher_text);

    free(cipher_text);
    return 0;
}