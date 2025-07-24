//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

void print_hex(const unsigned char *mem, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02X", mem[i]);
    }
}

bool encrypt(const unsigned char *plaintext, size_t plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext, size_t *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return false;
    }

    int rc = EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    rc = EVP_EncryptUpdate(ctx, ciphertext, (int*)ciphertext_len, plaintext, plaintext_len);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int tmp_len;
    rc = EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &tmp_len);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    *ciphertext_len += tmp_len;
    EVP_CIPHER_CTX_free(ctx);
    return true;
}

bool decrypt(const unsigned char *ciphertext, size_t ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext, size_t *plaintext_len) {
    EVP_CIPHER_CTX *ctx;
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return false;
    }

    int rc = EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    rc = EVP_DecryptUpdate(ctx, plaintext, (int*)plaintext_len, ciphertext, ciphertext_len);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int tmp_len;
    rc = EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &tmp_len);
    if (rc != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    *plaintext_len += tmp_len;
    EVP_CIPHER_CTX_free(ctx);
    return true;
}

int main(int argc, char *argv[]) {
    unsigned char *key = (unsigned char *)"6cMxDPARkL4v1Fr7Yu7H1enQRGYVcLy0";
    unsigned char *iv = (unsigned char *)"1a2b3c4d5e6f7g8h";
    unsigned char *plaintext = (unsigned char *)"This is a cryptography program";
    size_t plaintext_len = strlen((char*)plaintext);

    unsigned char ciphertext[BUF_SIZE];
    size_t ciphertext_len;

    if (!encrypt(plaintext, plaintext_len, key, iv, ciphertext, &ciphertext_len)) {
        printf("Error encrypting message\n");
        return EXIT_FAILURE;
    }

    printf("Ciphertext: ");
    print_hex(ciphertext, ciphertext_len);
    printf("\n");

    unsigned char decrypted_plaintext[BUF_SIZE];
    size_t decrypted_plaintext_len;

    if (!decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext, &decrypted_plaintext_len)) {
        printf("Error decrypting message\n");
        return EXIT_FAILURE;
    }

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return EXIT_SUCCESS;
}