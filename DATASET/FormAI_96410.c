//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16
#define FILE_READ_CHUNK_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *infile = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");

    if (!infile || !outfile) {
        fprintf(stderr, "Could not open files\n");
        exit(EXIT_FAILURE);
    }

    // initialize encryption algorithm context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Failed to initialize encryption context\n");
        exit(EXIT_FAILURE);
    }

    // set encryption algorithm and key
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);
    unsigned char key[EVP_CIPHER_CTX_key_length(ctx)];
    // generate a random key for encryption
    if (!RAND_bytes(key, sizeof(key))) {
        fprintf(stderr, "Failed to generate encryption key\n");
        exit(EXIT_FAILURE);
    }
    EVP_CIPHER_CTX_set_key_length(ctx, sizeof(key));
    EVP_EncryptInit_ex(ctx, NULL, NULL, key, NULL);

    // read file data in chunks and encrypt each chunk
    unsigned char inbuf[FILE_READ_CHUNK_SIZE];
    unsigned char outbuf[FILE_READ_CHUNK_SIZE + BLOCK_SIZE];
    int bytes_read, bytes_written;
    while ((bytes_read = fread(inbuf, 1, FILE_READ_CHUNK_SIZE, infile)) > 0) {
        if (!EVP_EncryptUpdate(ctx, outbuf, &bytes_written, inbuf, bytes_read)) {
            // error occurred during encryption
            fprintf(stderr, "Encryption failed\n");
            exit(EXIT_FAILURE);
        }
        fwrite(outbuf, 1, bytes_written, outfile);
    }
    if (!EVP_EncryptFinal_ex(ctx, outbuf, &bytes_written)) {
        // error occurred during finalization
        fprintf(stderr, "Failed to finalize encryption\n");
        exit(EXIT_FAILURE);
    }
    fwrite(outbuf, 1, bytes_written, outfile);

    // cleanup and exit
    fclose(infile);
    fclose(outfile);
    EVP_CIPHER_CTX_free(ctx);

    // delete the original plain text file
    if (remove(argv[1]) != 0) {
        fprintf(stderr, "Failed to delete plain text file %s\n", argv[1]);
    }

    return 0;
}