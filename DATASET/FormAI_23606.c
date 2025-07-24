//FormAI DATASET v1.0 Category: Modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#define BUF_LEN 1024

int main(int argc, char **argv) {

    EVP_CIPHER_CTX *ctx;
    unsigned char key[] = "secretkey123";
    unsigned char iv[] = "0123456789123456";
    unsigned char inbuf[BUF_LEN];
    unsigned char outbuf[BUF_LEN + EVP_MAX_BLOCK_LENGTH];
    int inlen, outlen, tmplen;

    /* Initialize the EVP library for cryptographic functions */
    EVP_CIPHER_CTX_init(ctx);
    ctx = EVP_CIPHER_CTX_new();

    /* Initialize encryption context */
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Read in the input file and encrypt it */
    FILE *inputfp = fopen(argv[1], "rb");
    FILE *outputfp = fopen(argv[2], "wb");

    while ((inlen = fread(inbuf, 1, BUF_LEN, inputfp)) > 0) {
        /* Encrypt the input data */
        EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen);
        fwrite(outbuf, 1, outlen, outputfp);
    }

    /* Finalize the encryption */
    EVP_EncryptFinal_ex(ctx, outbuf, &outlen);
    fwrite(outbuf, 1, outlen, outputfp);

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);
    fclose(inputfp);
    fclose(outputfp);

    printf("File %s successfully encrypted to %s.\n", argv[1], argv[2]);

    return 0;
}