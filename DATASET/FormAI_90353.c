//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void handleErrors(void)
{
    /* Print error message and exit */
    fprintf(stderr, "Error occurred.\n");
    exit(EXIT_FAILURE);
}

void generateKey(unsigned char *key, int keyLen)
{
    if (!RAND_bytes(key, keyLen)) {
        handleErrors();
    }
}

void generateIV(unsigned char *iv, int ivLen)
{
    if (!RAND_bytes(iv, ivLen)) {
        handleErrors();
    }
}

int encrypt(unsigned char *plaintext, int plaintextLen,
            unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext)
{
    /* Create and initialise cipher context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    int len = 0, ciphertextLen = 0;

    /* Encrypt plaintext into ciphertext */
    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLen)) {
        handleErrors();
    }
    ciphertextLen = len;

    /* Finalise encryption and add padding as necessary */
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        handleErrors();
    }
    ciphertextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertextLen;
}

int decrypt(unsigned char *ciphertext, int ciphertextLen,
            unsigned char *key, unsigned char *iv,
            unsigned char *plaintext)
{
    /* Create and initialise cipher context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    int len = 0, plaintextLen = 0;

    /* Decrypt ciphertext into plaintext */
    if (!EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLen)) {
        handleErrors();
    }
    plaintextLen = len;

    /* Finalise decryption and remove padding as necessary */
    if (!EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        handleErrors();
    }
    plaintextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    plaintext[plaintextLen] = '\0';

    return plaintextLen;
}

int main(void)
{
    unsigned char plaintext[] = "Hello, World!";
    int plaintextLen = strlen((char *)plaintext);

    unsigned char ciphertext[plaintextLen + EVP_MAX_BLOCK_LENGTH];
    memset(ciphertext, 0, sizeof(ciphertext));

    unsigned char decrypted[plaintextLen + 1];
    memset(decrypted, 0, sizeof(decrypted));

    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    generateKey(key, EVP_CIPHER_key_length(EVP_aes_256_cbc()));
    generateIV(iv, EVP_CIPHER_iv_length(EVP_aes_256_cbc()));

    int ciphertextLen = encrypt(plaintext, plaintextLen, key, iv, ciphertext);
    int decryptedLen = decrypt(ciphertext, ciphertextLen, key, iv, decrypted);

    printf("Input:\t \'%s\'\n", plaintext);
    printf("Key:\t\'%s\'\n", key);
    printf("IV:\t\'%s\'\n", iv);
    printf("Ciphertext:\t");
    for(int i=0; i<ciphertextLen; i++) printf("%02x ", ciphertext[i]);
    printf("\n");
    printf("Decrypted:\t\'%s\'\n", decrypted);

    return EXIT_SUCCESS;
}