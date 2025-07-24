//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

int main() {
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    memset(key, 0, sizeof(key));
    memset(iv, 0, sizeof(iv));

    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &aes_key) < 0) {
        fprintf(stderr, "AES key initialization failed");
        exit(1);
    }

    unsigned char data[] = "The quick brown fox jumps over the lazy dog";

    size_t data_len = strlen(data);

    if (data_len % AES_BLOCK_SIZE != 0) {
        fprintf(stderr, "Data size must be a multiple of AES_BLOCK_SIZE");
        exit(1);
    }

    unsigned char encrypted_data[data_len];
    AES_cbc_encrypt(data, encrypted_data, data_len, &aes_key, iv, AES_ENCRYPT);
    printf("Encrypted data: %s\n", encrypted_data);

    unsigned char decrypted_data[data_len];
    AES_cbc_encrypt(encrypted_data, decrypted_data, data_len, &aes_key, iv, AES_DECRYPT);
    printf("Decrypted data: %s\n", decrypted_data);

    return 0;
}