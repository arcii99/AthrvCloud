//FormAI DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[] = "mysecretkey12345";
    unsigned char in[] = "I love you more than words can describe";
    unsigned char out[256];
    unsigned char dec[256];

    // Initialize AES encryption context
    AES_KEY aes_ctx;
    if (AES_set_encrypt_key(key, 128, &aes_ctx) != 0) {
        printf("AES encryption key failed\n");
        return -1;
    }

    // Perform AES encryption
    int len = strlen(in);
    AES_encrypt(in, out, &aes_ctx);

    // Print encrypted text
    printf("Encrypted text: ");
    for (int i = 0; i < len; i++) {
        printf("%02x", out[i]);
    }
    printf("\n");

    // Initialize AES decryption context
    if (AES_set_decrypt_key(key, 128, &aes_ctx) != 0) {
        printf("AES decryption key failed\n");
        return -1;
    }

    // Perform AES decryption
    AES_decrypt(out, dec, &aes_ctx);

    // Null terminate decrypted text
    dec[len] = '\0';

    // Print decrypted text
    printf("Decrypted text: %s\n", dec);

    return 0;
}