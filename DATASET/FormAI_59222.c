//FormAI DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h> // AES encryption library

int main()
{
    // Message to be encrypted
    char message[] = "Hello, this is a secret message!";

    // Encryption key of length 128 bits (16 bytes)
    unsigned char key[] = "0123456789abcdef";

    // Initialization Vector (IV) used for CBC mode
    unsigned char iv[] = "abcdefghijklmnop";

    // Initialize AES encryption context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);

    // Calculate number of blocks to be encrypted
    size_t message_len = strlen(message);
    int blocks = (message_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE;

    // Allocate memory for encrypted and decrypted messages
    unsigned char *encrypted_message = calloc(blocks * AES_BLOCK_SIZE, 1);
    unsigned char *decrypted_message = calloc(blocks * AES_BLOCK_SIZE, 1);

    // Encrypt message using CBC mode
    AES_cbc_encrypt((unsigned char*)message, encrypted_message, message_len, &aes_key, iv, AES_ENCRYPT);

    // Decrypt message using CBC mode
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(encrypted_message, decrypted_message, blocks * AES_BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);

    // Print original and decrypted messages
    printf("Original message : %s\n", message);
    printf("Encrypted message : ");
    for(int i = 0; i < blocks * AES_BLOCK_SIZE; i++)
        printf("%02x", encrypted_message[i]);
    printf("\n");
    printf("Decrypted message : %s\n", decrypted_message);

    // Free memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}