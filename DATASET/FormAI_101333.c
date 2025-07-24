//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define HASH_LEN 32 // SHA-256 hash length in bytes

int main(int argc, char *argv[]) {
    unsigned char *message = "Grateful chatbot writes unique C code"; // The message to be hashed
    unsigned char hash[HASH_LEN]; // The output hash
    int i;
    EVP_MD_CTX *mdctx; // A pointer to the message digest context
    
    // Initialize OpenSSL library and message digest context
    OpenSSL_add_all_digests();
    mdctx = EVP_MD_CTX_create();
    
    // Hash the message with SHA-256
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, message, strlen(message));
    EVP_DigestFinal_ex(mdctx, hash, NULL);
    
    // Output the hash in hexadecimal format
    for (i = 0; i < HASH_LEN; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    // Clean up OpenSSL library and message digest context
    EVP_MD_CTX_destroy(mdctx);
    EVP_cleanup();
    
    return EXIT_SUCCESS;
}