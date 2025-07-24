//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the key generation function
void generate_key(unsigned char key[], int length) {
    srand(time(NULL));
    for(int i=0; i<length; i++) {
        key[i] = rand() % 256;
    }
}

// Define the encryption function
void encrypt(unsigned char *input, int input_len, unsigned char *key, int key_len, unsigned char *output) {
    for(int i=0; i<input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

// Define the decryption function
void decrypt(unsigned char *input, int input_len, unsigned char *key, int key_len, unsigned char *output) {
    for(int i=0; i<input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

int main() {
    unsigned char key[32];
    unsigned char input[256];
    unsigned char output[256];

    // Prompt user to enter input message
    printf("Enter your message to be encrypted:\n");
    fgets(input, 256, stdin);
    int input_len = strlen(input) - 1;

    // Generate key
    generate_key(key, 32);

    // Encrypt input message
    encrypt(input, input_len, key, 32, output);
    printf("Encrypted message: ");
    for(int i=0; i<input_len; i++) {
        printf("%02X", output[i]);
    }
    printf("\n");

    // Decrypt encrypted message
    decrypt(output, input_len, key, 32, input);
    printf("Decrypted message: %s\n", input);

    return 0;
}