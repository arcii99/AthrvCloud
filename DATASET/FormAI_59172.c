//FormAI DATASET v1.0 Category: modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Function to encrypt a message
void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

// Function to decrypt a message
void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

int main() {
    int message_length = 100; // Max message length
    unsigned char key[] = "happycode123456"; // Encryption key
    unsigned char iv[] = "codeiscool876543"; // Initialization vector
    unsigned char message[message_length];
    unsigned char ciphertext[message_length];
    unsigned char decrypted[message_length];
    
    printf("Enter your happy secret message: ");
    fgets(message, sizeof(message), stdin); // Reading input message from user
    
    // Padding the message to fit block size
    int padding_length = 0;
    if (message_length % AES_BLOCK_SIZE != 0) {
        padding_length = AES_BLOCK_SIZE - (message_length % AES_BLOCK_SIZE);
    }
    memset(message + message_length, padding_length, padding_length);
    
    // Encrypting the message
    encrypt(message, message_length + padding_length, key, iv, ciphertext);
    printf("Your encrypted happy message: ");
    for (int i = 0; i < message_length + padding_length; ++i) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    // Decrypting the message
    decrypt(ciphertext, message_length + padding_length, key, iv, decrypted);
    decrypted[message_length] -= decrypted[message_length] & 0x0f; // Removing the padding
    printf("Your decrypted happy message: %s\n", decrypted);
    
    return 0;
}