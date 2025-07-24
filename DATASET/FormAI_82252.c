//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

void handleErrors(void) {
    printf("An error occurred.\n");
    ERR_print_errors_fp(stderr);
    exit(1);
}

int main(void) {
    int success;

    char plaintext[MAX_SIZE];
    printf("Enter the plaintext to encrypt: ");
    fgets(plaintext, MAX_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove trailing newline

    char key[MAX_SIZE];
    printf("Enter the key: ");
    fgets(key, MAX_SIZE, stdin);
    key[strcspn(key, "\n")] = 0; // Remove trailing newline

    char iv[MAX_SIZE];
    printf("Enter the initialization vector (IV): ");
    fgets(iv, MAX_SIZE, stdin);
    iv[strcspn(iv, "\n")] = 0; // Remove trailing newline

    /* Initialize OpenSSL library */
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();

    /* Initialize the cipher */
    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        handleErrors();
    }

    /* Set the cipher key and IV */
    success = EVP_EncryptInit_ex(ctx, cipher, NULL, (unsigned char*)key, (unsigned char*)iv);
    if (!success) {
        handleErrors();
    }

    /* Prepare the output buffer */
    unsigned char ciphertext[MAX_SIZE];
    int ciphertext_len = 0;

    /* Encrypt the plaintext */
    success = EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char*)plaintext, strlen(plaintext));
    if (!success) {
        handleErrors();
    }

    /* Finalize the encryption */
    int final_len = 0;
    success = EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len);
    if (!success) {
        handleErrors();
    }
    ciphertext_len += final_len;

    /* Print the encrypted ciphertext */
    printf("Encrypted Ciphertext: ");
    int i;
    for (i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    /* All done */
    printf("Done.\n");
    return 0;
}