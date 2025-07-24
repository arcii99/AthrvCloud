//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

int main(int argc, char *argv[])
{
    AES_KEY aes_key;
    unsigned char aes_key_data[AES_BLOCK_SIZE] = "ThisIsOurSecret";
    unsigned char iv[AES_BLOCK_SIZE] = "InitializationVe";
    unsigned char plain_text[] = "This should be kept secret";
    unsigned char cipher_text[sizeof(plain_text)];
    unsigned char decrypted_text[sizeof(plain_text)];

    // Initialize the AES key
    if (AES_set_encrypt_key(aes_key_data, AES_BLOCK_SIZE * 8, &aes_key) < 0) {
        printf("Could not set encryption key.\n");
        return 1;
    }

    // Perform encryption
    AES_cbc_encrypt(plain_text, cipher_text, sizeof(plain_text), &aes_key, iv, AES_ENCRYPT);

    // Print cipher text
    printf("Cipher Text: ");
    for (int i = 0; i < sizeof(cipher_text); i++)
        printf("%02x ", cipher_text[i]);
    printf("\n");

    // Initialize the AES key for decryption
    if (AES_set_decrypt_key(aes_key_data, AES_BLOCK_SIZE * 8, &aes_key) < 0) {
        printf("Could not set decryption key.\n");
        return 1;
    }

    // Perform decryption
    AES_cbc_encrypt(cipher_text, decrypted_text, sizeof(cipher_text), &aes_key, iv, AES_DECRYPT);

    // Print decrypted text
    printf("Decrypted Text: ");
    for (int i = 0; i < sizeof(decrypted_text); i++)
        printf("%c", decrypted_text[i]);
    printf("\n");

    return 0;
}