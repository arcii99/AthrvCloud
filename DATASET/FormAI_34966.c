//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(unsigned char *key, unsigned char *message, unsigned char *ciphertext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_encrypt(message, ciphertext, &aes_key);
}

void decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *message) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_decrypt(ciphertext, message, &aes_key);
}

int main() {
    unsigned char key[32] = "thisisakey123456"; // 16, 24, or 32 characters
    unsigned char message[128] = "hello world"; // any string of text
    
    printf("Message: %s\n", message);
    
    // Encrypt the message
    unsigned char ciphertext[sizeof(message)];
    encrypt(key, message, ciphertext);
    printf("Encrypted: ");
    for(int i=0; i<sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    
    // Decrypt the message
    unsigned char decrypted_message[sizeof(message)];
    decrypt(key, ciphertext, decrypted_message);
    printf("\nDecrypted: %s\n", decrypted_message);
    
    return 0;
}