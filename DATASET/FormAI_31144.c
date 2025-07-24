//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

#define KEY_LENGTH 2048
#define PUB_EXPONENT 65537

#define RSA_ALGORITHM EVP_sha256()

EVP_PKEY * generateRSAKeyPair()
{
    EVP_PKEY_CTX * pctx;
    EVP_PKEY * pkey = NULL;

    pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    if (!pctx) {
        fprintf(stderr, "Unable to initialize RSA key generation context\n");
        return NULL;
    }

    if (EVP_PKEY_keygen_init(pctx) <= 0) {
        fprintf(stderr, "Unable to initialize RSA key generation\n");
        EVP_PKEY_CTX_free(pctx);
        return NULL;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(pctx, KEY_LENGTH) <= 0) {
        fprintf(stderr, "Unable to set RSA key length\n");
        EVP_PKEY_CTX_free(pctx);
        return NULL;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_pubexp(pctx, PUB_EXPONENT) <= 0) {
        fprintf(stderr, "Unable to set RSA public exponent\n");
        EVP_PKEY_CTX_free(pctx);
        return NULL;
    }

    if (EVP_PKEY_keygen(pctx, &pkey) <= 0) {
        fprintf(stderr, "Unable to generate RSA key pair\n");
        EVP_PKEY_CTX_free(pctx);
        return NULL;
    }

    EVP_PKEY_CTX_free(pctx);

    return pkey;
}

int rsaEncrypt(EVP_PKEY *pkey, const char *plaintext, unsigned char **ciphertext, size_t *ciphertext_len)
{
    EVP_PKEY_CTX *pctx = NULL;
    EVP_CIPHER_CTX *ctx = NULL;
    size_t plaintext_len = strlen(plaintext), ciphertext_output_len, block_size;
    int ret = 0;

    if (pkey == NULL) {
        return -1;
    }

    // Generate symmetric key and IV
    unsigned char *key = (unsigned char *) malloc(EVP_CIPHER_key_length(RSA_ALGORITHM));
    unsigned char *iv = (unsigned char *) malloc(EVP_CIPHER_iv_length(RSA_ALGORITHM));
    if (!key || !iv) {
        fprintf(stderr, "Malloc failed\n");
        ret = -1; goto exit;
    }

    memset(key, 0, EVP_CIPHER_key_length(RSA_ALGORITHM));
    memset(iv, 0, EVP_CIPHER_iv_length(RSA_ALGORITHM));

    if (!EVP_BytesToKey(RSA_ALGORITHM, EVP_sha1(), NULL,
        (const unsigned char *)"secret_key", strlen("secret_key"), 0, key, iv)) {
        fprintf(stderr, "Unable to generate key and IV\n");
        ret = -1; goto exit;
    }

    // Initialize the context
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Unable to initialize encryption context\n");
        ret = -1; goto exit;
    }

    if (!EVP_EncryptInit_ex(ctx, RSA_ALGORITHM, NULL, key, iv)) {
        fprintf(stderr, "Unable to initialize encryption\n");
        ret = -1; goto exit;
    }

    // Determine block size and required ciphertext size
    block_size = EVP_CIPHER_block_size(EVP_CIPHER_CTX_cipher(ctx));
    ciphertext_output_len = plaintext_len + block_size - 1;
    ciphertext_output_len -= ciphertext_output_len % block_size;
    *ciphertext = (unsigned char *) malloc(ciphertext_output_len);
    if (*ciphertext == NULL) {
        fprintf(stderr, "Malloc failed\n");
        ret = -1; goto exit;
    }

    // Encrypt the plaintext
    pctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!pctx) {
        fprintf(stderr, "Unable to create EVP context for RSA encryption\n");
        ret = -1; goto exit;
    }
    if (EVP_PKEY_encrypt_init(pctx) <= 0) {
        fprintf(stderr, "Unable to initialize encryption context for RSA\n");
        ret = -1; goto exit;
    }
    if (EVP_PKEY_CTX_set_rsa_padding(pctx, RSA_PKCS1_PADDING) <= 0) {
        fprintf(stderr, "Unable to set padding for RSA context\n");
        ret = -1; goto exit;
    }

    *ciphertext_len = ciphertext_output_len;
    if (EVP_PKEY_encrypt(pctx, *ciphertext, ciphertext_len, (const unsigned char *)plaintext, plaintext_len) <= 0) {
        fprintf(stderr, "Unable to encrypt plaintext using RSA\n");
        ret = -1; goto exit;
    }

exit:
    if (pctx) {
        EVP_PKEY_CTX_free(pctx);
    }
    if (ctx) {
        EVP_CIPHER_CTX_free(ctx);
    }
    if (key) {
        free(key);
    }
    if (iv) {
        free(iv);
    }
    return ret;
}

int rsaDecrypt(EVP_PKEY *pkey, const unsigned char *ciphertext, size_t ciphertext_len, char **plaintext)
{
    EVP_PKEY_CTX *pctx = NULL;
    EVP_CIPHER_CTX *ctx = NULL;
    size_t block_size;
    int ret = 0;

    if (pkey == NULL) {
        return -1;
    }

    // Generate symmetric key and IV
    unsigned char *key = (unsigned char *) malloc(EVP_CIPHER_key_length(RSA_ALGORITHM));
    unsigned char *iv = (unsigned char *) malloc(EVP_CIPHER_iv_length(RSA_ALGORITHM));
    if (!key || !iv) {
        fprintf(stderr, "Malloc failed\n");
        ret = -1; goto exit;
    }

    memset(key, 0, EVP_CIPHER_key_length(RSA_ALGORITHM));
    memset(iv, 0, EVP_CIPHER_iv_length(RSA_ALGORITHM));

    if (!EVP_BytesToKey(RSA_ALGORITHM, EVP_sha1(), NULL,
        (const unsigned char *)"secret_key", strlen("secret_key"), 0, key, iv)) {
        fprintf(stderr, "Unable to generate key and IV\n");
        ret = -1; goto exit;
    }

    // Initialize the context
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Unable to initialize decryption context\n");
        ret = -1; goto exit;
    }

    if (!EVP_DecryptInit_ex(ctx, RSA_ALGORITHM, NULL, key, iv)) {
        fprintf(stderr, "Unable to initialize encryption\n");
        ret = -1; goto exit;
    }

    // Determine block size and plaintext size
    block_size = EVP_CIPHER_block_size(EVP_CIPHER_CTX_cipher(ctx));
    unsigned char *plaintext_output = (unsigned char *) malloc(ciphertext_len + block_size);
    if (plaintext_output == NULL) {
        fprintf(stderr, "Malloc failed\n");
        ret = -1; goto exit;
    }

    // Decrypt the ciphertext
    pctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!pctx) {
        fprintf(stderr, "Unable to create EVP context for RSA decryption\n");
        ret = -1; goto exit;
    }
    if (EVP_PKEY_decrypt_init(pctx) <= 0) {
        fprintf(stderr, "Unable to initialize encryption context for RSA\n");
        ret = -1; goto exit;
    }
    if (EVP_PKEY_CTX_set_rsa_padding(pctx, RSA_PKCS1_PADDING) <= 0) {
        fprintf(stderr, "Unable to set padding for RSA context\n");
        ret = -1; goto exit;
    }

    size_t plaintext_len = 0;
    if (EVP_PKEY_decrypt(pctx, plaintext_output, &plaintext_len, ciphertext, ciphertext_len) <= 0) {
        fprintf(stderr, "Unable to decrypt ciphertext using RSA\n");
        ret = -1; goto exit;
    }

    *plaintext = (char *) malloc(plaintext_len + 1);
    if (*plaintext == NULL) {
        fprintf(stderr, "Malloc failed\n");
        ret = -1; goto exit;
    }

    strncpy(*plaintext, (char *) plaintext_output, plaintext_len);
    (*plaintext)[plaintext_len] = '\0';

exit:
    if (pctx) {
        EVP_PKEY_CTX_free(pctx);
    }
    if (ctx) {
        EVP_CIPHER_CTX_free(ctx);
    }
    if (key) {
        free(key);
    }
    if (iv) {
        free(iv);
    }
    if (plaintext_output) {
        free(plaintext_output);
    }
    return ret;
}

int main(int argc, char *argv[])
{
    EVP_PKEY *keypair = NULL;
    unsigned char *ciphertext = NULL;
    size_t ciphertext_len;
    char *plaintext = NULL;

    // Generate keypair
    keypair = generateRSAKeyPair();
    if (keypair == NULL) {
        fprintf(stderr, "Unable to generate RSA keypair\n");
        return EXIT_FAILURE;
    }

    // Encrypt plaintext
    if (rsaEncrypt(keypair, "Hello world!", &ciphertext, &ciphertext_len) < 0) {
        fprintf(stderr, "Unable to encrypt plaintext\n");
        return EXIT_FAILURE;
    }

    // Decrypt ciphertext
    if (rsaDecrypt(keypair, ciphertext, ciphertext_len, &plaintext) < 0) {
        fprintf(stderr, "Unable to decrypt ciphertext\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", plaintext);

    EVP_PKEY_free(keypair);
    free(ciphertext);
    free(plaintext);

    return EXIT_SUCCESS;
}