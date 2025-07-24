//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

// Struct for holding encryption/decryption context
typedef struct Context {
    unsigned char key[KEY_SIZE];
    unsigned char prev_block[BLOCK_SIZE];
    bool is_initialized;
} Context;

// Function to generate random 16-byte key
void gen_key(unsigned char* key) {
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, key, KEY_SIZE);
    close(fd);
}

// Function to initialize context with key
void init_context(Context* ctx, unsigned char* key) {
    memcpy(ctx->key, key, KEY_SIZE);
    memset(ctx->prev_block, 0, BLOCK_SIZE);
    ctx->is_initialized = true;
}

// Function to encrypt/decrypt data block using CBC mode
void cbc_cipher(Context* ctx, unsigned char* block, bool is_encrypting) {
    if (!ctx->is_initialized) {
        printf("Context not initialized!\n");
        exit(1);
    }
    if (is_encrypting) {
        // XOR data block with previous ciphertext block
        for (int i = 0; i < BLOCK_SIZE; i++) {
            block[i] ^= ctx->prev_block[i];
        }
        // AES encrypt data block
        // [Implementation omitted]
        // Update previous ciphertext block with encrypted block
        memcpy(ctx->prev_block, block, BLOCK_SIZE);
    } else {
        // Decrypt data block using AES
        // [Implementation omitted]
        // XOR decrypted block with previous ciphertext block
        for (int i = 0; i < BLOCK_SIZE; i++) {
            block[i] ^= ctx->prev_block[i];
        }
        // Update previous ciphertext block with original ciphertext block
        memcpy(ctx->prev_block, block, BLOCK_SIZE);
    }
}

// Function to read file into buffer
unsigned char* read_file(char* filename, size_t* size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }
    struct stat st;
    fstat(fd, &st);
    size_t file_size = st.st_size;
    unsigned char* buffer = malloc(file_size);
    read(fd, buffer, file_size);
    close(fd);
    *size = file_size;
    return buffer;
}

// Function to write buffer to file
void write_file(char* filename, unsigned char* buffer, size_t size) {
    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }
    write(fd, buffer, size);
    close(fd);
}

// Function to encrypt or decrypt file using CBC mode
void cbc_file(char* in_filename, char* out_filename, unsigned char* key, bool is_encrypting) {
    // Read file into buffer
    size_t in_size;
    unsigned char* in_buffer = read_file(in_filename, &in_size);
    // Initialize context with key
    Context ctx;
    init_context(&ctx, key);
    // Allocate output buffer
    size_t out_size = (in_size / BLOCK_SIZE) * BLOCK_SIZE;
    if (in_size % BLOCK_SIZE != 0) out_size += BLOCK_SIZE;
    unsigned char* out_buffer = malloc(out_size);
    memset(out_buffer, 0, out_size);
    // Encrypt/decrypt each block
    for (int i = 0; i < in_size; i += BLOCK_SIZE) {
        unsigned char* block = &in_buffer[i];
        cbc_cipher(&ctx, block, is_encrypting);
        memcpy(&out_buffer[i], block, BLOCK_SIZE);
    }
    // Write output buffer to file
    write_file(out_filename, out_buffer, out_size);
    // Free buffers
    free(in_buffer);
    free(out_buffer);
}

int main() {
    // Generate key and encrypt file
    unsigned char key[KEY_SIZE];
    gen_key(key);
    cbc_file("test.txt", "test_encrypted.txt", key, true);
    // Decrypt file with same key
    cbc_file("test_encrypted.txt", "test_decrypted.txt", key, false);
    return 0;
}