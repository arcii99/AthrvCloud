//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This function is to generate a random key for encryption
void generate_key(uint8_t *key, size_t key_size) {
    for (size_t i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

// This function is to xor data with key for encryption or decryption
void xor_data(uint8_t *data, size_t data_size, uint8_t *key, size_t key_size) {
    for (size_t i = 0; i < data_size; i++) {
        data[i] ^= key[i % key_size];
    }
}

// This function is to encrypt the given data using the given key
void encrypt_data(uint8_t *data, size_t data_size, uint8_t *key, size_t key_size) {
    xor_data(data, data_size, key, key_size);
}

// This function is to decrypt the given data using the given key
void decrypt_data(uint8_t *data, size_t data_size, uint8_t *key, size_t key_size) {
    xor_data(data, data_size, key, key_size);
}

int main() {
    uint8_t data[] = "Hello World!";
    size_t data_size = sizeof(data) - 1; // minus 1 for null terminator
    uint8_t key[8];
    size_t key_size = sizeof(key);

    generate_key(key, key_size);
    printf("Original Data: %s\n", data);

    encrypt_data(data, data_size, key, key_size);
    printf("Encrypted Data: ");
    for (size_t i = 0; i < data_size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    decrypt_data(data, data_size, key, key_size);
    printf("Decrypted Data: %s\n", data);

    return 0;
}