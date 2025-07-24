//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define CHUNK_SIZE 512

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_str = argv[1];
    size_t input_len = strlen(input_str);

    // Initialize SHA256 context
    SHA256_CTX sha_ctx;
    SHA256_Init(&sha_ctx);

    // Divide input string into 512 chunks
    size_t num_chunks = input_len / CHUNK_SIZE;
    size_t last_chunk_size = input_len % CHUNK_SIZE;

    for (size_t i = 0; i < num_chunks; i++) {
        char chunk[CHUNK_SIZE];
        strncpy(chunk, input_str + i * CHUNK_SIZE, CHUNK_SIZE);
        SHA256_Update(&sha_ctx, chunk, CHUNK_SIZE);
    }

    // Process the last chunk
    char last_chunk[CHUNK_SIZE];
    strncpy(last_chunk, input_str + num_chunks * CHUNK_SIZE, last_chunk_size);
    SHA256_Update(&sha_ctx, last_chunk, last_chunk_size);

    // Finalize hash computation
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha_ctx);

    // Print hash as hexadecimal string
    printf("Input string: %s\n", input_str);
    printf("Hash:");
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}