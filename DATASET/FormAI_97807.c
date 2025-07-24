//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16 // AES operates on 16 bytes at a time

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key); // 128 here refers to key size
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *iv = (unsigned char *)"0123456789abcdef";
    unsigned char *plaintext = (unsigned char *)"This is a test message.";
    int plaintext_len = strlen(plaintext) + 1; // include null terminator
    int ciphertext_len = ((plaintext_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE; // round up to nearest multiple of AES_BLOCK_SIZE
    unsigned char ciphertext[ciphertext_len];
    unsigned char decrypted_plaintext[plaintext_len];

    encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    printf("Encrypted Message: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);
    printf("Decrypted Message: %s\n", decrypted_plaintext);

    return 0;
}