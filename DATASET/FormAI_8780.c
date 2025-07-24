//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

int main()
{
    /* Encryption key and initialization vector */
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    /* Plaintext and ciphertext buffers */
    unsigned char *plaintext = (unsigned char *)"This is my secret message.";
    unsigned char ciphertext[256];

    /* AES context for encryption */
    AES_KEY aes_key;
    if(AES_set_encrypt_key(key, 256, &aes_key) < 0) {
        printf("Unable to set encryption key.");
        return -1;
    }

    /* Encrypt plaintext */
    AES_cbc_encrypt(plaintext, ciphertext, strlen(plaintext), &aes_key, iv, AES_ENCRYPT);

    /* Display ciphertext */
    printf("Ciphertext:\n");
    for(int i = 0; i < strlen(plaintext); i++) {
        printf("%02X", ciphertext[i]);
    }

    return 0;
}