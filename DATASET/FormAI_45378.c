//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUFFER_SIZE 1024

// Function to generate secure keys
void generate_key(unsigned char *key, int size) {
    FILE *fp = fopen("/dev/random", "r");
    fread(key, 1, size, fp);
    fclose(fp);
}

// Function to encrypt file
void encrypt_file(char *input_file, char *output_file, unsigned char *key) {
    // Open input and output files
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");

    // Initialize the encryption key and IV
    AES_KEY aes_key;
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    // Set encryption key
    AES_set_encrypt_key(key, 128, &aes_key);

    // Read input file and encrypt data
    unsigned char input_buffer[BUFFER_SIZE];
    unsigned char output_buffer[BUFFER_SIZE + AES_BLOCK_SIZE];
    int bytes_read, bytes_encrypted;
    while ((bytes_read = fread(input_buffer, 1, BUFFER_SIZE, fin)) > 0) {
        AES_cbc_encrypt(input_buffer, output_buffer, bytes_read, &aes_key, iv, AES_ENCRYPT);
        bytes_encrypted = fwrite(output_buffer, 1, bytes_read + AES_BLOCK_SIZE, fout);
    }

    // Close input and output files
    fclose(fin);
    fclose(fout);
}

// Function to decrypt file
void decrypt_file(char *input_file, char *output_file, unsigned char *key) {
    // Open input and output files
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");

    // Initialize the decryption key and IV
    AES_KEY aes_key;
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    // Set decryption key
    AES_set_decrypt_key(key, 128, &aes_key);

    // Read input file and decrypt data
    unsigned char input_buffer[BUFFER_SIZE + AES_BLOCK_SIZE];
    unsigned char output_buffer[BUFFER_SIZE];
    int bytes_read, bytes_decrypted;
    while ((bytes_read = fread(input_buffer, 1, BUFFER_SIZE + AES_BLOCK_SIZE, fin)) > 0) {
        AES_cbc_encrypt(input_buffer, output_buffer, bytes_read, &aes_key, iv, AES_DECRYPT);
        bytes_decrypted = fwrite(output_buffer, 1, bytes_read - AES_BLOCK_SIZE, fout);
    }

    // Close input and output files
    fclose(fin);
    fclose(fout);
}

int main(void) {
    // Initialize variables
    char input_file[] = "input.txt";
    char encrypted_file[] = "encrypted.bin";
    char decrypted_file[] = "decrypted.txt";
    unsigned char key[AES_BLOCK_SIZE];

    // Generate secure key
    generate_key(key, AES_BLOCK_SIZE);

    // Encrypt file
    encrypt_file(input_file, encrypted_file, key);
    printf("File encrypted successfully.\n");

    // Decrypt file
    decrypt_file(encrypted_file, decrypted_file, key);
    printf("File decrypted successfully.\n");

    return 0;
}