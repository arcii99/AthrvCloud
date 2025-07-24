//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/sha.h>

#define BLOCK_SIZE 4096

// An asynchronous hash function that computes the SHA256 hash of a file
void async_sha256(char* filename) {
    FILE* fp = fopen(filename, "rb"); // Open file as binary
    if (!fp) {
        printf("Error: File not found\n");
        return;
    }

    // Instantiate storage for the hash and the input block
    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned char block[BLOCK_SIZE];
    SHA256_CTX context;
    SHA256_Init(&context);

    // Asynchronously read and update the hash for blocks of data
    size_t bytes_read;
    do {
        bytes_read = fread(block, sizeof(unsigned char), BLOCK_SIZE, fp);
        SHA256_Update(&context, block, bytes_read);
    } while (bytes_read == BLOCK_SIZE);

    SHA256_Final(hash, &context); // Finalize the hash
    fclose(fp); // close file

    // Print the hash value in hexadecimal format
    printf("SHA256 hash of %s:\n", filename);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]); // 02x formats to two places, using hexadecimal base
    }
    printf("\n");
}

int main() {
    async_sha256("example.txt"); // Run async SHA256 hash on example.txt file
    return 0;
}