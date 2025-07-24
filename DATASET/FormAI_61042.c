//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    // Define plaintext message
    char plaintext[] = "This is a secret message.";

    // Generate encryption key
    char key[] = "mysecretkey";
    unsigned char iv[EVP_MAX_IV_LENGTH];
    memset(iv, 0, EVP_MAX_IV_LENGTH);

    // Set up encryption context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    int len;

    // Initialize encryption
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Get ciphertext output buffer size
    int ciphertext_len = strlen(plaintext) + EVP_CIPHER_CTX_block_size(ctx);
    unsigned char *ciphertext = malloc(ciphertext_len);

    // Encrypt plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen(plaintext));
    int ciphertext_len1 = len;

    // Finalize encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    int ciphertext_len2 = ciphertext_len1 + len;

    // Print ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len2; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Clean up memory
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}