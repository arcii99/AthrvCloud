//FormAI DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_BUF_SIZE 1024

void handleErrors(void);

int main(int argc, char **argv) {
    // Check input arguments
    if (argc != 3) {
        printf("Usage: ./encrypt <plaintext_file> <ciphertext_file>\n");
        exit(1);
    }

    // Read plaintext from file into buffer
    char *plaintext_filename = argv[1];
    FILE *plaintext_file = fopen(plaintext_filename, "r");
    if (plaintext_file == NULL) {
        printf("Error: cannot open plaintext file.\n");
        exit(1);
    }
    char plaintext[MAX_BUF_SIZE];
    memset(plaintext, 0, MAX_BUF_SIZE);
    fgets(plaintext, MAX_BUF_SIZE, plaintext_file);
    fclose(plaintext_file);

    // Generate encryption key and IV
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    // Create and initialize encryption context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        handleErrors();
    }

    // Initialize output buffer
    unsigned char ciphertext[MAX_BUF_SIZE];
    int ciphertext_len = 0;

    // Encrypt plaintext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen(plaintext))) {
        handleErrors();
    }
    int remaining_len = MAX_BUF_SIZE - ciphertext_len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &remaining_len)) {
        handleErrors();
    }
    ciphertext_len += remaining_len;

    // Write ciphertext to file
    char *ciphertext_filename = argv[2];
    FILE *ciphertext_file = fopen(ciphertext_filename, "w");
    if (ciphertext_file == NULL) {
        printf("Error: cannot open ciphertext file.\n");
        exit(1);
    }
    fwrite(ciphertext, sizeof(char), ciphertext_len, ciphertext_file);
    fclose(ciphertext_file);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}

void handleErrors(void) {
    printf("Error: OpenSSL error.\n");
    exit(1);
}