//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 256 // 256-bit symmetric key
#define BLOCKSIZE 16 // 16-byte block size
#define NUM_ROUNDS 14 // 14 rounds of encryption per block

typedef unsigned char byte;

byte key[KEY_LEN]; // The symmetric key used for encryption

// Utility functions
void get_key_from_user();
byte* read_file(char* filename, int* file_len);
void write_file(char* filename, byte* buffer, int len);
void print_hex(byte* buffer, int len);
void print_key();

// Shannon functions
byte* encrypt(byte* plaintext, int plaintext_len);
byte* decrypt(byte* ciphertext, int ciphertext_len);

int main()
{
    printf("*********************\n");
    printf("* Shannon Encryption *\n");
    printf("*********************\n\n");

    get_key_from_user();

    // Read file to encrypt
    char filename[] = "example.txt";
    int file_len = 0;
    byte* plaintext = read_file(filename, &file_len);

    // Encrypt the file contents
    byte* ciphertext = encrypt(plaintext, file_len);

    // Write the encrypted data to a new file
    char encrypted_filename[] = "example.enc";
    write_file(encrypted_filename, ciphertext, file_len);

    // Read the encrypted file into a new buffer
    byte* encrypted_buffer = read_file(encrypted_filename, &file_len);

    // Decrypt the encrypted file contents
    byte* decrypted_buffer = decrypt(encrypted_buffer, file_len);

    // Write the decrypted data to a new file
    char decrypted_filename[] = "example.dec";
    write_file(decrypted_filename, decrypted_buffer, file_len);

    free(plaintext);
    free(ciphertext);
    free(encrypted_buffer);
    free(decrypted_buffer);

    return 0;
}

void get_key_from_user() {
    printf("Enter the symmetric key (256 bits): ");

    for(int i = 0; i < KEY_LEN; i++) {
        scanf("%02hhx", &key[i]);
    }

    printf("\n");

    print_key();
}

byte* read_file(char* filename, int* file_len) {
    FILE* file;
    byte* buffer;

    file = fopen(filename, "rb");

    if(file == NULL) {
        fprintf(stderr, "ERROR: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get file length
    fseek(file, 0, SEEK_END);
    *file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer and read entire file
    buffer = malloc(*file_len);
    fread(buffer, *file_len, 1, file);

    fclose(file);

    return buffer;
}

void write_file(char* filename, byte* buffer, int len) {
    FILE* file;

    file = fopen(filename, "wb");

    if(file == NULL) {
        fprintf(stderr, "ERROR: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, len, 1, file);

    fclose(file);
}

void print_hex(byte* buffer, int len) {
    for(int i = 0; i < len; i++) {
        printf("%02x", buffer[i]);
    }
}

void print_key() {
    printf("The symmetric key is:\n");
    print_hex(key, KEY_LEN);
    printf("\n\n");
}

byte* encrypt(byte* plaintext, int plaintext_len) {
    // Pad plaintext with zeros if its length is not evenly divisible by BLOCKSIZE
    int padded_len = plaintext_len;
    if(padded_len % BLOCKSIZE != 0) {
        padded_len += BLOCKSIZE - (plaintext_len % BLOCKSIZE);
    }

    byte* padded_plaintext = malloc(padded_len);
    memcpy(padded_plaintext, plaintext, plaintext_len);
    memset(padded_plaintext + plaintext_len, 0, padded_len - plaintext_len);

    // Initialize the state
    int num_blocks = padded_len / BLOCKSIZE;
    byte state[num_blocks][BLOCKSIZE];
    memcpy(state, padded_plaintext, padded_len);

    // Perform the encryption
    for(int round = 0; round < NUM_ROUNDS; round++) {
        // XOR key with state
        for(int block = 0; block < num_blocks; block++) {
            for(int i = 0; i < BLOCKSIZE; i++) {
                state[block][i] ^= key[i];
            }
        }

        // Shuffle state
        // For each byte in the state, swap it with another byte in the state
        for(int block = 0; block < num_blocks; block++) {
            for(int i = 0; i < BLOCKSIZE; i++) {
                int other_block = rand() % num_blocks;
                int other_byte = rand() % BLOCKSIZE;

                byte temp = state[block][i];
                state[block][i] = state[other_block][other_byte];
                state[other_block][other_byte] = temp;
            }
        }
    }

    free(padded_plaintext);

    // Convert state to a linear buffer
    byte* ciphertext = malloc(padded_len);
    memcpy(ciphertext, state, padded_len);

    return ciphertext;
}

byte* decrypt(byte* ciphertext, int ciphertext_len) {
    // Initialize the state
    int num_blocks = ciphertext_len / BLOCKSIZE;
    byte state[num_blocks][BLOCKSIZE];
    memcpy(state, ciphertext, ciphertext_len);

    // Reverse the encryption rounds
    for(int round = NUM_ROUNDS - 1; round >= 0; round--) {
        // Unshuffle state
        // For each byte in the state, swap it with another byte in the state
        for(int block = 0; block < num_blocks; block++) {
            for(int i = 0; i < BLOCKSIZE; i++) {
                int other_block = rand() % num_blocks;
                int other_byte = rand() % BLOCKSIZE;

                byte temp = state[block][i];
                state[block][i] = state[other_block][other_byte];
                state[other_block][other_byte] = temp;
            }
        }

        // XOR key with state
        for(int block = 0; block < num_blocks; block++) {
            for(int i = 0; i < BLOCKSIZE; i++) {
                state[block][i] ^= key[i];
            }
        }
    }

    // Convert state to a linear buffer
    byte* plaintext = malloc(ciphertext_len);
    memcpy(plaintext, state, ciphertext_len);

    return plaintext;
}