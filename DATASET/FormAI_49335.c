//FormAI DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

/* Encrypt plain text with AES algorithm using the key */
int aes_encrypt(unsigned char *plain_text, int plain_text_len, unsigned char *key, unsigned char *encrypted_text)
{
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 128, &aes_key) < 0) {
        return -1;
    }
    int encrypted_len = 0;
    // Encrypt one block at a time
    while (encrypted_len + AES_BLOCK_SIZE <= plain_text_len) {
        AES_encrypt(plain_text + encrypted_len, encrypted_text + encrypted_len, &aes_key);
        encrypted_len += AES_BLOCK_SIZE;
    }
    // Pad last block with zeros if necessary
    if (encrypted_len < plain_text_len) {
        unsigned char last_block[AES_BLOCK_SIZE];
        memset(last_block, 0, AES_BLOCK_SIZE);
        memcpy(last_block, plain_text + encrypted_len, plain_text_len - encrypted_len);
        AES_encrypt(last_block, encrypted_text + encrypted_len, &aes_key);
    }
    return 0;
}

/* Decrypt encrypted text with AES algorithm using the key */
int aes_decrypt(unsigned char *encrypted_text, int encrypted_text_len, unsigned char *key, unsigned char *decrypted_text)
{
    AES_KEY aes_key;
    if (AES_set_decrypt_key(key, 128, &aes_key) < 0) {
        return -1;
    }
    int decrypted_len = 0;
    // Decrypt one block at a time
    while (decrypted_len + AES_BLOCK_SIZE <= encrypted_text_len) {
        AES_decrypt(encrypted_text + decrypted_len, decrypted_text + decrypted_len, &aes_key);
        decrypted_len += AES_BLOCK_SIZE;
    }
    // Remove zero padding from last block if necessary
    if (decrypted_len < encrypted_text_len) {
        int pad_len = encrypted_text_len - decrypted_len;
        if (memchr(encrypted_text + decrypted_len, 0, pad_len) == NULL) {
            return -1; // Invalid padding
        }
        decrypted_len += pad_len;
    }
    return decrypted_len;
}

int main()
{
    unsigned char key[] = "0123456789abcdef"; // 128-bit key (16 bytes)
    unsigned char plain_text[] = "Hello, world! This is a secret message."; // Arbitrary message
    int plain_text_len = strlen((char *)plain_text);
    int encrypted_text_len = plain_text_len + AES_BLOCK_SIZE - (plain_text_len % AES_BLOCK_SIZE);
    unsigned char encrypted_text[encrypted_text_len];
    unsigned char decrypted_text[encrypted_text_len];

    aes_encrypt(plain_text, plain_text_len, key, encrypted_text);
    aes_decrypt(encrypted_text, encrypted_text_len, key, decrypted_text);

    printf("Plain text: %s\n", plain_text);
    printf("Encrypted text: ");
    for (int i = 0; i < encrypted_text_len; i++) {
        printf("%02x", encrypted_text[i]);
    }
    printf("\n");
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}