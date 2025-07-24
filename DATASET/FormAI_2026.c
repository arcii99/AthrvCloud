//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void generate_hash(const char* input, char* hash_output, const EVP_MD* md) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();

    // Initialize the hash function
    EVP_DigestInit(context, md);

    // Update the hash with the input data
    EVP_DigestUpdate(context, input, strlen(input));

    // Finalize the hash and write the result to the output buffer
    unsigned int hash_output_length;
    EVP_DigestFinal(context, hash_output, &hash_output_length);
    EVP_MD_CTX_free(context);
}

int main() {
    const char* input = "Hello, world!";
    const EVP_MD* md = EVP_sha256();
    char hash_output[EVP_MAX_MD_SIZE];

    generate_hash(input, hash_output, md);

    printf("Input: %s\n", input);
    printf("Hash: ");
    for (int i = 0; i < EVP_MD_size(md); i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");

    return 0;
}