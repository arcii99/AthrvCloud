//FormAI DATASET v1.0 Category: modern Encryption ; Style: lively
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

int main()
{
    unsigned char key[] = "thisismysecretkey";
    unsigned char iv[] = "initalvector1234";

    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 128, &aes_key) < 0) {
        fprintf(stderr, "Could not set encryption key.");
        exit(EXIT_FAILURE);
    }

    char* plain_text = "This is my secret message";
    size_t input_length = strlen(plain_text);

    // Pad the input if the length is not a multiple of BLOCK_SIZE
    size_t padded_input_length = ((input_length + BLOCK_SIZE -1) / BLOCK_SIZE) * BLOCK_SIZE;
    unsigned char* padded_input = calloc(padded_input_length, sizeof(unsigned char));
    memcpy(padded_input, plain_text, input_length);

    unsigned char *output = calloc(padded_input_length, sizeof(unsigned char));

    AES_cbc_encrypt(padded_input, output, padded_input_length, &aes_key, iv, AES_ENCRYPT);

    printf("Encrypted message: ");
    for (size_t i = 0; i < padded_input_length; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    free(padded_input);
    free(output);

    return 0;
}