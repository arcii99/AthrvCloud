//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

/*
 * This program implements AES encryption and decryption using OpenSSL library.
 * It prompts for a plain text message, an encryption key, and performs AES encryption
 * followed by decryption to obtain the plain text message back as output.
 *
 */

int main() {
    printf("Welcome to AES Encryption program!\n\n");

    // Prompt for plain text message
    printf("Enter plain text message to encrypt: ");
    char plaintext[256];
    fgets(plaintext, 256, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Prompt for encryption key
    unsigned char key[32];
    printf("Enter 128-bit encryption key (16 characters): ");
    fgets(key, 32, stdin);
    key[strcspn(key, "\n")] = 0;

    // Generate initialization vector
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Perform encryption using AES key and IV
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    unsigned char ciphertext[strlen(plaintext)+1];
    AES_cbc_encrypt(plaintext, ciphertext, strlen(plaintext)+1, &aes_key, iv, AES_ENCRYPT);

    printf("\nEncryption key: %s\n", key);
    printf("Initialization vector: ");
    for(int i=0; i<AES_BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n\nEncrypted message: ");
    for(int i=0; i<strlen(plaintext)+1; i++) {
        printf("%02x", ciphertext[i]);
    }

    // Perform decryption using AES key and IV
    AES_set_decrypt_key(key, 128, &aes_key);
    char decryptedtext[strlen(plaintext)+1];
    AES_cbc_encrypt(ciphertext, decryptedtext, strlen(plaintext)+1, &aes_key, iv, AES_DECRYPT);
    printf("\n\nDecrypted message: %s\n", decryptedtext);

    return 0;
}