//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/conf.h>
#include<openssl/evp.h>
#include<openssl/err.h>

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(void)
{
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    unsigned char *iv = (unsigned char *)"0123456789012345";

    unsigned char plaintext[] = "This is a sample plaintext message to be encrypted.";

    int plaintext_len = strlen((char *)plaintext);

    unsigned char ciphertext[128];

    int ciphertext_len;

    unsigned char decryptedtext[128];
 
    int decryptedtext_len;

    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv,
                              ciphertext);

    printf("Ciphertext is:\n");

    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
                                  decryptedtext);

    decryptedtext[decryptedtext_len] = '\0';

    printf("Decrypted text is:\n");

    printf("%s\n", decryptedtext);

    return 0;
}