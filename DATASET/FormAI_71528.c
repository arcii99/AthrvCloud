//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <openssl/evp.h>

int main() {

    char *plaintext = "This is a sensitive data";
    char *key = "MySecretKey";

    // Encrypt the data
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    int len = 0, ciphertext_len = 0;
    unsigned char ciphertext[1024] = {0};

    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);

    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen(plaintext));
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    printf("Encrypted data: %s\n", ciphertext);

    // Decrypt the data
    char decrypted[1024] = {0};

    ctx = EVP_CIPHER_CTX_new();

    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);
    EVP_DecryptUpdate(ctx, decrypted, &len, ciphertext, ciphertext_len);
    ciphertext_len = len;

    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);

    EVP_CIPHER_CTX_free(ctx);

    printf("Decrypted data: %s\n", decrypted);

    return 0;
}