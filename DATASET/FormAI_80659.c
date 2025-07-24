//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the key used for encryption
const unsigned char key[] = "verysecretpassword";

// function that performs the encryption
void encrypt(char *input, char *output) {
    int input_length = strlen(input);
    int key_length = strlen(key);
    int i, j;

    for (i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[i] = '\0';
}

// function that performs the decryption
void decrypt(char *input, char *output) {
    int input_length = strlen(input);
    int key_length = strlen(key);
    int i, j;

    for (i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
    output[i] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char decrypted[100];

    // get input from the user
    printf("Enter text to encrypt: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    // perform encryption
    encrypt(plaintext, ciphertext);

    // print the results
    printf("\nOriginal text: %s\n", plaintext);
    printf("Encrypted text: %s\n", ciphertext);

    // perform decryption
    decrypt(ciphertext, decrypted);

    // print the decrypted text
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}