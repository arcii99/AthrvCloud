//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char* key = (unsigned char*) "SuperSecretKey";
    unsigned char* iv = (unsigned char*) "InitializationVe";
    const char* plain_text = "This is my secret message!";

    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 128, &aes_key) < 0) {
        printf("Encryption key error!\n");
        return 1;
    }

    int plain_text_len = strlen(plain_text);
    int num_blocks = (plain_text_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE;
    int padded_len = num_blocks * AES_BLOCK_SIZE;
    unsigned char* padded_text = (unsigned char*) calloc(padded_len, 1);

    memcpy(padded_text, plain_text, plain_text_len);

    for (int i = plain_text_len; i < padded_len; i++) {
        padded_text[i] = (unsigned char) (padded_len - plain_text_len);
    }

    unsigned char* cipher_text = (unsigned char*) malloc(padded_len);

    AES_cbc_encrypt(padded_text, cipher_text, padded_len, &aes_key, iv, AES_ENCRYPT);

    printf("Plaintext: %s\n", plain_text);

    printf("Key: %s\n", key);

    printf("IV: %s\n", iv);

    printf("Cipher Text: ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02X ", cipher_text[i]);
    }

    printf("\n");

    free(padded_text);
    free(cipher_text);

    return 0;
}