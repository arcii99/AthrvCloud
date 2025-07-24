//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define IN_BUF_SIZE 1024
#define OUT_BUF_SIZE 1024

void handle_error(const char *error_msg) {
    fprintf(stderr, "%s\n", error_msg);
    ERR_print_errors_fp(stderr);
    exit(1);
}

void print_hex(const unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handle_error("Failed to create cipher context");

    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    if (!EVP_BytesToKey(cipher, EVP_sha256(), NULL, "password", strlen("password"), 1, key, iv)) {
        handle_error("Failed to generate key and IV");
    }

    // Encrypt
    unsigned char in_buf[IN_BUF_SIZE], out_buf[OUT_BUF_SIZE];
    int out_len = 0, total_len = 0;
    if (!EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv)) {
        handle_error("Failed to initialize encryption");
    }
    while (1) {
        int in_len = fread(in_buf, 1, IN_BUF_SIZE, stdin);
        if (in_len <= 0) {
            break;
        }
        if (!EVP_EncryptUpdate(ctx, out_buf, &out_len, in_buf, in_len)) {
            handle_error("Failed to encrypt data");
        }
        fwrite(out_buf, 1, out_len, stdout);
        total_len += out_len;
    }
    if (!EVP_EncryptFinal_ex(ctx, out_buf, &out_len)) {
        handle_error("Failed to finalize encryption");
    }
    fwrite(out_buf, 1, out_len, stdout);
    total_len += out_len;

    // Decrypt
    if (!EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv)) {
        handle_error("Failed to initialize decryption");
    }
    fseek(stdin, 0, SEEK_SET); // Reset file pointer
    total_len = 0; // Reset length counter
    while (1) {
        int in_len = fread(in_buf, 1, IN_BUF_SIZE, stdin);
        if (in_len <= 0) {
            break;
        }
        if (!EVP_DecryptUpdate(ctx, out_buf, &out_len, in_buf, in_len)) {
            handle_error("Failed to decrypt data");
        }
        fwrite(out_buf, 1, out_len, stdout);
        total_len += out_len;
    }
    if (!EVP_DecryptFinal_ex(ctx, out_buf, &out_len)) {
        handle_error("Failed to finalize decryption");
    }
    fwrite(out_buf, 1, out_len, stdout);
    total_len += out_len;
    printf("Total data length: %d bytes\n", total_len);

    // Cleanup
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}