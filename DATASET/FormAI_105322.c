//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 32 // in bytes

// sample plaintext and key
char *plaintext = "Sample plaintext for encryption.";
unsigned char key[KEY_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c, 0x26, 0x91, 0x7c, 0x5d, 0x9b, 0x5e, 0x6b, 0x4f, 0xbc, 0x96, 0x65, 0x6e, 0x1e, 0xf7, 0xcb, 0x9c};

// asynchronous encryption function
void encrypt(char *plaintext, unsigned char *key, size_t size) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *ciphertext, *iv;
    int ciphertext_len, iv_len = EVP_MAX_IV_LENGTH;

    // allocate memory for ciphertext and IV
    ciphertext = malloc(size + EVP_MAX_BLOCK_LENGTH);
    iv = malloc(iv_len);

    // create a new cipher context
    ctx = EVP_CIPHER_CTX_new();

    // initialize the cipher context
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // encrypt the plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, size);

    // finalize the encryption (adds padding and finalizes cipher context)
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);

    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, key, strlen(plaintext));
    return 0;
}