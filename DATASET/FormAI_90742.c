//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LEN 32
#define BLOCK_SIZE 16

void encrypt_message(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext){
    EVP_CIPHER_CTX *ctx = NULL;
    int len = 0, ciphertext_len = 0;

    ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
    ciphertext_len += len;

    EVP_EncryptFinal_ex(ctx, ciphertext+ciphertext_len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt_message(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext){
    EVP_CIPHER_CTX *ctx = NULL;
    int len = 0, plaintext_len = 0;

    ctx = EVP_CIPHER_CTX_new();

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    plaintext_len += len;

    EVP_DecryptFinal_ex(ctx, plaintext+plaintext_len, &len);
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    unsigned char key[KEY_LEN], iv[BLOCK_SIZE], plaintext[512], ciphertext[512];
    int plaintext_len = 0, ciphertext_len = 0;

    // generate random key
    RAND_bytes(key, KEY_LEN);

    // generate random initialization vector
    RAND_bytes(iv, BLOCK_SIZE);

    printf("\n\nCyberpunk Cryptography\n");
    printf("==========================================\n");
    printf("Enter the message to encrypt: ");
    fgets((char *)plaintext, 512, stdin);
    plaintext_len = strlen((char *)plaintext) - 1;
    printf("Plaintext: %s\n", plaintext);

    // encrypt the plaintext message
    encrypt_message(plaintext, plaintext_len, key, iv, ciphertext);
    ciphertext_len = strlen((char *)ciphertext);

    printf("\nCiphertext: ");
    for(int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // decrypt the ciphertext message
    decrypt_message(ciphertext, ciphertext_len, key, iv, plaintext);
    plaintext_len = strlen((char *)plaintext);

    printf("\nPlaintext (Decrypted): %s\n", plaintext);

    return 0;
}