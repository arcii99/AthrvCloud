//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void xor_buffer(unsigned char *buffer, size_t buffer_len, const unsigned char *key, size_t key_len) {
    size_t i;
    for (i = 0; i < buffer_len; i++) {
        buffer[i] ^= key[i % key_len];
    }
}

void encrypt_data(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len) {
    xor_buffer(data, data_len, key, key_len);
}

void decrypt_data(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len) {
    xor_buffer(data, data_len, key, key_len);
}

int main() {
    srand(time(NULL));
    unsigned char data[256] = "Hello, World!";
    unsigned char key[16];
    size_t i;
    
    // Generate random encryption key
    for (i = 0; i < sizeof(key); i++) {
        key[i] = rand() % 256;
    }
    
    // Print original data
    printf("Original Data: %s\n", data);
    
    // Encrypt data
    encrypt_data(data, strlen((char*)data), key, sizeof(key));
    
    // Print encrypted data
    printf("Encrypted Data: ");
    for (i = 0; i < strlen((char*)data); i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
    
    // Decrypt data
    decrypt_data(data, strlen((char*)data), key, sizeof(key));
    
    // Print decrypted data
    printf("Decrypted Data: %s\n", data);
    
    return 0;
}