//FormAI DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

void print_hex(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the AES encryption program! Let's secure your message.\n");

    unsigned char key[] = "my_secret_key_123";
    unsigned char iv[] = "0123456789abcdef";

    // Initialize the AES encryption context
    AES_KEY aes_ctx;
    if (AES_set_encrypt_key(key, sizeof(key) * 8, &aes_ctx)) {
        printf("Failed to set AES encryption key.\n");
        return 1;
    }

    printf("Please enter the message you want to encrypt:\n");

    // Read user input from stdin and pad with zeroes to ensure it's a multiple of the block size
    unsigned char input[100];
    fgets(input, sizeof(input), stdin);
    int input_len = strlen(input);
    int padded_len = (((input_len - 1) / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    unsigned char padded_input[padded_len];
    memcpy(padded_input, input, input_len);
    memset(padded_input + input_len, 0, padded_len - input_len);

    // Encrypt the padded input using AES in CBC mode
    unsigned char output[padded_len];
    AES_cbc_encrypt(padded_input, output, padded_len, &aes_ctx, iv, AES_ENCRYPT);

    printf("Your encrypted message is: ");
    print_hex(output, padded_len);

    return 0;
}