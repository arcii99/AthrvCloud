//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *in_file = argv[1];
    char *out_file = argv[2];
    unsigned char key[KEY_SIZE/8]; // 256-bit key
    unsigned char iv[AES_BLOCK_SIZE]; // 128-bit initialization vector
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;
    
    // initialize key and iv with random bytes
    FILE *urandom = fopen("/dev/urandom", "rb");
    if (urandom == NULL) {
        printf("Error: Unable to open /dev/urandom\n");
        return 1;
    }
    fread(key, 1, KEY_SIZE/8, urandom);
    fread(iv, 1, AES_BLOCK_SIZE, urandom);
    fclose(urandom);

    // initialize AES encryption context
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, KEY_SIZE, &aes_key) < 0) {
        printf("Error: Unable to initialize AES encryption context\n");
        return 1;
    }

    // open input and output files
    FILE *in = fopen(in_file, "rb");
    if (in == NULL) {
        printf("Error: Unable to open input file\n");
        return 1;
    }
    FILE *out = fopen(out_file, "wb");
    if (out == NULL) {
        printf("Error: Unable to open output file\n");
        fclose(in);
        return 1;
    }

    // write key and iv to output file
    fwrite(key, 1, KEY_SIZE/8, out);
    fwrite(iv, 1, AES_BLOCK_SIZE, out);

    // encrypt input file using AES-CBC mode
    AES_cbc_encrypt(buffer, buffer, BUFFER_SIZE, &aes_key, iv, AES_ENCRYPT);
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        AES_cbc_encrypt(buffer, buffer, bytes_read, &aes_key, iv, AES_ENCRYPT);
        bytes_written = fwrite(buffer, 1, bytes_read, out);
        if (bytes_written != bytes_read) {
            printf("Error: Unable to write encrypted data to output file\n");
            fclose(in);
            fclose(out);
            return 1;
        }
    }
    
    // close input and output files
    fclose(in);
    fclose(out);

    printf("File encrypted successfully!\n");
    return 0;
}