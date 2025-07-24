//FormAI DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

int main(void) {
    // Define the secret key
    unsigned char key[] = "MySecretKey12345";
    const uint32_t key_size = strlen((char*)key);

    // Define the message to encrypt
    unsigned char message[] = "Hello, World!";
    const uint32_t message_size = strlen((char*)message);

    // Define the initialization vector
    unsigned char iv[] = "0001020304050607";

    // Define the padded input and output buffers
    uint32_t padded_message_size = ((message_size + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char padded_message[padded_message_size];
    memset(padded_message, 0, sizeof(padded_message));
    memcpy(padded_message, message, message_size);

    uint32_t output_size = padded_message_size + AES_BLOCK_SIZE;
    unsigned char output[output_size];
    memset(output, 0, sizeof(output));

    // Create the AES key and context, and initialize the encryptor
    AES_KEY aes_key;
    AES_set_encrypt_key(key, key_size * 8, &aes_key);

    // Encrypt the message using AES-CBC
    AES_cbc_encrypt(
        padded_message,            // Input buffer
        output,                    // Output buffer
        padded_message_size,       // Input length
        &aes_key,                  // AES key
        iv,                        // Initialization vector
        AES_ENCRYPT                // Encryption mode
    );

    // Print the encrypted message
    printf("Encrypted message: ");
    for (uint32_t i = 0; i < output_size; i++) {
        printf("%02X", output[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}